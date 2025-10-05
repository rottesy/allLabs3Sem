#include <fstream>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>


namespace Constants
{
const int MIN_YEAR = 1900;
const int MAX_YEAR = 2100;
const int MIN_MONTH = 1;
const int MAX_MONTH = 12;
const int MIN_DAY = 1;
const int MAX_DAY = 31;
const int MIN_QUANTITY = 0;
const int MAX_QUANTITY = 1000000;
const double MIN_PRICE = 0.0;
const double MAX_PRICE = 100000000.0;
const int MIN_PRODUCTS = 1;
const int MAX_PRODUCTS = 10000;
const int LINES_PER_PRODUCT = 6;
const int MAX_FILENAME_LENGTH = 255;
const int INITIAL_BUFFER_CAPACITY = 16;
}

class Date
{
  private:
    int year;
    int month;
    int day;

    bool isLeapYear(int y) const { return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); }

    int getDaysInMonth(int m, int y) const
    {
        switch (m)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return 31;
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
            case 2:
                return isLeapYear(y) ? 29 : 28;
            default:
                return 0;
        }
    }

    bool isValidDate(int y, int m, int d) const
    {
        if (y < Constants::MIN_YEAR || y > Constants::MAX_YEAR)
            return false;
        if (m < Constants::MIN_MONTH || m > Constants::MAX_MONTH)
            return false;
        if (d < Constants::MIN_DAY || d > getDaysInMonth(m, y))
            return false;
        return true;
    }

  public:
    Date() : year(2000), month(1), day(1) {}

    Date(int y, int m, int d)
    {
        if (!isValidDate(y, m, d))
        {
            throw std::invalid_argument("Invalid date");
        }
        year = y;
        month = m;
        day = d;
    }

    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }

    friend std::ostream &operator<<(std::ostream &os, const Date &date)
    {
        os << date.year << "\n" << date.month << "\n" << date.day << "\n";
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Date &date)
    {
        int y, m, d;
        if (!(is >> y >> m >> d))
        {
            throw std::runtime_error("Failed to read date");
        }
        if (!date.isValidDate(y, m, d))
        {
            throw std::invalid_argument("Invalid date");
        }
        date.year = y;
        date.month = m;
        date.day = d;
        return is;
    }
};

class Product
{
  private:
    std::string name;
    int quantity;
    double price;
    Date receiptDate;

    bool isValidProduct() const
    {
        return !name.empty() && quantity >= Constants::MIN_QUANTITY && price >= Constants::MIN_PRICE;
    }

  public:
    Product() : name(""), quantity(0), price(0.0), receiptDate() {}

    Product(const std::string &n, int q, double p, int year, int month, int day)
        : name(n), quantity(q), price(p), receiptDate(year, month, day)
    {
        if (!isValidProduct())
        {
            throw std::invalid_argument("Invalid product data");
        }
    }

    Product(const Product &other) = default;
    Product &operator=(const Product &other) = default;
    Product(Product &&other) noexcept = default;
    Product &operator=(Product &&other) noexcept = default;

    int getQuantityByYear(int targetYear) const { return (receiptDate.getYear() == targetYear) ? quantity : 0; }

    friend std::ostream &operator<<(std::ostream &os, const Product &product)
    {
        os << product.name << "\n" << product.quantity << "\n" << product.price << "\n" << product.receiptDate;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Product &product)
    {
        std::string name;
        int quantity;
        double price;
        Date date;

        if (!std::getline(is, name))
        {
            throw std::runtime_error("Failed to read product name");
        }

        // Trim whitespace
        size_t start = name.find_first_not_of(" \t\n\r");
        size_t end = name.find_last_not_of(" \t\n\r");
        if (start == std::string::npos)
        {
            throw std::runtime_error("Product name cannot be empty");
        }
        name = name.substr(start, end - start + 1);

        if (!(is >> quantity >> price))
        {
            throw std::runtime_error("Failed to read product quantity or price");
        }

        is >> date;

        product.name = name;
        product.quantity = quantity;
        product.price = price;
        product.receiptDate = date;

        if (!product.isValidProduct())
        {
            throw std::invalid_argument("Invalid product data");
        }

        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return is;
    }
};

class ProductManager
{
  private:
    Product *products;
    int size;

    void cleanup()
    {
        delete[] products;
        products = nullptr;
        size = 0;
    }

    void clearInputBuffer() { std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }

    Product *readProductsFromStream(std::ifstream &inFile, int &outSize)
    {
        Product *buffer = nullptr;
        int capacity = Constants::INITIAL_BUFFER_CAPACITY;
        int count = 0;

        buffer = new Product[capacity];

        inFile.clear();
        inFile.seekg(0, std::ios::beg);

        if (!inFile.good())
        {
            delete[] buffer;
            throw std::runtime_error("Cannot read from file");
        }

        while (inFile.good() && !inFile.eof())
        {
            try
            {
                Product product;
                inFile >> product;

                if (inFile.fail())
                {
                    break;
                }

               
                if (count >= capacity)
                {
                    int newCapacity = std::min(capacity * 2, Constants::MAX_PRODUCTS);
                    Product *newBuffer = new Product[newCapacity];
                    for (int i = 0; i < count; i++)
                    {
                        newBuffer[i] = std::move(buffer[i]);
                    }
                    delete[] buffer;
                    buffer = newBuffer;
                    capacity = newCapacity;
                }

                if (count < Constants::MAX_PRODUCTS)
                {
                    buffer[count] = std::move(product);
                    count++;
                }
                else
                {
                    break;
                }
            }
            catch (const std::exception &e)
            {
                
                if (inFile.eof())
                    break;
                inFile.clear();
                std::string dummy;
                std::getline(inFile, dummy);
            }
        }

        outSize = count;
        return buffer;
    }

  public:
    ProductManager() : products(nullptr), size(0) {}

    ~ProductManager() { cleanup(); }

    ProductManager(const ProductManager &) = delete;
    ProductManager &operator=(const ProductManager &) = delete;

    ProductManager(ProductManager &&other) noexcept : products(other.products), size(other.size)
    {
        other.products = nullptr;
        other.size = 0;
    }

    ProductManager &operator=(ProductManager &&other) noexcept
    {
        if (this != &other)
        {
            cleanup();
            products = other.products;
            size = other.size;
            other.products = nullptr;
            other.size = 0;
        }
        return *this;
    }

    int getTotalQuantityByYear(int targetYear) const
    {
        int total = 0;
        for (int i = 0; i < size; i++)
        {
            total += products[i].getQuantityByYear(targetYear);
        }
        return total;
    }

    bool writeToFile(const std::string &filename) const
    {
        if (!products || size == 0)
        {
            std::cerr << "Error: No products to write\n";
            return false;
        }

        std::ofstream outFile(filename);
        if (!outFile.is_open())
        {
            std::cerr << "Error: Cannot open file for writing\n";
            return false;
        }

        for (int i = 0; i < size; i++)
        {
            outFile << products[i];
        }

        if (!outFile.good())
        {
            std::cerr << "Error: Write operation failed\n";
            return false;
        }

        std::cout << "Successfully wrote " << size << " products to file\n";
        return true;
    }

    bool readFromFile(const std::string &filename)
    {
        std::ifstream inFile(filename);
        if (!inFile.is_open())
        {
            std::cerr << "Error: Cannot open file for reading\n";
            return false;
        }

        try
        {
            int newSize = 0;
            Product *newProducts = readProductsFromStream(inFile, newSize);
            inFile.close();

            if (newSize == 0)
            {
                delete[] newProducts;
                std::cerr << "Error: No valid products found in file\n";
                return false;
            }

            cleanup();
            products = newProducts;
            size = newSize;

            std::cout << "Successfully read " << size << " products from file\n";
            return true;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error reading from file: " << e.what() << "\n";
            cleanup();
            return false;
        }
    }

    bool inputManually()
    {
        int count;
        std::cout << "Enter number of products to input: ";

        if (!(std::cin >> count))
        {
            std::cerr << "Error: Invalid input\n";
            std::cin.clear();
            clearInputBuffer();
            return false;
        }
        clearInputBuffer();

        if (count < Constants::MIN_PRODUCTS || count > Constants::MAX_PRODUCTS)
        {
            std::cerr << "Error: Invalid product count\n";
            return false;
        }

        cleanup();
        products = new Product[count];
        int successfulInputs = 0;

        for (int i = 0; i < count; i++)
        {
            std::cout << "\nProduct " << (i + 1) << ":\n";

            try
            {
                std::string name;
                int quantity;
                double price;
                int year, month, day;

                std::cout << "Name: ";
                if (!std::getline(std::cin, name) || name.empty())
                {
                    throw std::runtime_error("Name cannot be empty");
                }

                std::cout << "Quantity: ";
                if (!(std::cin >> quantity) || quantity < Constants::MIN_QUANTITY)
                {
                    throw std::invalid_argument("Invalid quantity");
                }
                clearInputBuffer();

                std::cout << "Price: ";
                if (!(std::cin >> price) || price < Constants::MIN_PRICE)
                {
                    throw std::invalid_argument("Invalid price");
                }
                clearInputBuffer();

                std::cout << "Date (year month day): ";
                if (!(std::cin >> year >> month >> day))
                {
                    throw std::runtime_error("Invalid date");
                }
                clearInputBuffer();

                products[successfulInputs] = Product(name, quantity, price, year, month, day);
                successfulInputs++;
                std::cout << "Product added successfully!\n";
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error: " << e.what() << " - Please try again\n";
                std::cin.clear();
                clearInputBuffer();
                i--;
            }
        }

        size = successfulInputs;
        std::cout << "Successfully created " << successfulInputs << " products\n";
        return successfulInputs > 0;
    }

    bool createSampleProducts()
    {
        cleanup();
        const int sampleSize = 3;

        try
        {
            products = new Product[sampleSize];
            products[0] = Product("Laptop", 5, 50000.0, 2023, 10, 15);
            products[1] = Product("Mouse", 20, 1500.0, 2024, 1, 10);
            products[2] = Product("Keyboard", 8, 3000.0, 2023, 12, 5);
            size = sampleSize;
            std::cout << "Sample products created successfully!\n";
            return true;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error creating sample products\n";
            cleanup();
            return false;
        }
    }

    bool hasProducts() const { return products != nullptr && size > 0; }
};

class Menu
{
  private:
    ProductManager manager;

    int getMenuChoice()
    {
        int choice;
        while (true)
        {
            std::cout << "\n=== Product Management ===\n";
            std::cout << "1. Input products manually\n";
            std::cout << "2. Use sample products\n";
            std::cout << "3. Read products from file\n";
            std::cout << "4. Exit\n";
            std::cout << "Choice: ";

            if (!(std::cin >> choice))
            {
                std::cout << "Invalid input\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (choice >= 1 && choice <= 4)
            {
                return choice;
            }
            std::cout << "Please enter 1-4\n";
        }
    }

    void processProducts()
    {
        if (!manager.hasProducts())
        {
            std::cout << "No products to process\n";
            return;
        }

        std::string filename;
        std::cout << "Enter filename to save: ";
        std::getline(std::cin, filename);

        if (manager.writeToFile(filename))
        {
            int year;
            std::cout << "Enter year to count: ";

            if (!(std::cin >> year))
            {
                std::cout << "Invalid year\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            int total = manager.getTotalQuantityByYear(year);
            std::cout << "Total quantity for year " << year << ": " << total << std::endl;
        }
    }

  public:
    void run()
    {
        while (true)
        {
            try
            {
                int choice = getMenuChoice();

                switch (choice)
                {
                    case 1:
                        if (manager.inputManually())
                        {
                            processProducts();
                        }
                        break;
                    case 2:
                        if (manager.createSampleProducts())
                        {
                            processProducts();
                        }
                        break;
                    case 3:
                    {
                        std::string filename;
                        std::cout << "Enter filename: ";
                        std::getline(std::cin, filename);
                        if (manager.readFromFile(filename))
                        {
                            processProducts();
                        }
                        break;
                    }
                    case 4:
                        std::cout << "Goodbye!\n";
                        return;
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error: " << e.what() << "\n";
            }
        }
    }
};

int main()
{
    Menu menu;
    menu.run();
    return 0;
}