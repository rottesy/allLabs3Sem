#include <iostream>

template<typename T>
T findMin(const T* begin,const T* end)
{
    if(begin == end)
    {
        std::cout << "Array cannot be empty" << "\n";
    }

    T minVal = *begin;
    for (const T* it = begin + 1;it != end;it++)
    {
        if (*it > minVal)
        {
            minVal = *it;
        }
    }
    return minVal;
}

int main()
{
    
    return 0;
}
