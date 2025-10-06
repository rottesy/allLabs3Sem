#pragma once

#include "exceptions.hpp"
#include "node.hpp"
#include <iostream>
#include <vector>

template <typename T> class Ring
{
    Node<T> *head = nullptr;
    size_t size = 0;

    bool containsNode(Node<T> *node) const
    {
        if (!node || empty())
            return false;

        Node<T> *current = head;
        for (size_t i = 0; i < size; i++)
        {
            if (current == node)
                return true;
            current = current->next;
        }
        return false;
    }

    Node<T> *getTail() const
    {
        if (empty())
            return nullptr;

        Node<T> *current = head;
        for (size_t i = 1; i < size; i++)
        {
            current = current->next;
        }
        return current;
    }

    void bubbleSortOptimized()
    {
        if (size <= 1)
            return;

        bool swapped;
        for (size_t i = 0; i < size - 1; i++)
        {
            swapped = false;
            Node<T> *current = head;

            for (size_t j = 0; j < size - i - 1; j++)
            {
                
                if (Node<T> *nextNode = current->next; current->data > nextNode->data)
                {
                    std::swap(current->data, nextNode->data);
                    swapped = true;
                }
                current = current->next;
            }

            if (!swapped)
                break;
        }
    }

  public:
    class Iterator
    {
        Node<T> *ptr;
        Node<T> *start;
        size_t iterations = 0;
        size_t max_iterations;

      public:
        Iterator() : ptr(nullptr), start(nullptr), max_iterations(0) {}
        Iterator(Node<T> *node, size_t ring_size) : ptr(node), start(node), max_iterations(ring_size) {}

        T &operator*()
        {
            if (!ptr)
                throw IteratorException("Dereferencing null iterator");
            return ptr->data;
        }

        const T &operator*() const
        {
            if (!ptr)
                throw IteratorException("Dereferencing null iterator");
            return ptr->data;
        }

        Iterator &operator++()
        {
            if (!ptr)
                throw IteratorException("Incrementing null iterator");
            if (iterations >= max_iterations && max_iterations > 0)
            {
                throw InfiniteLoopException();
            }
            ptr = ptr->next;
            iterations++;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const Iterator &other) const { return ptr == other.ptr; }

        bool operator!=(const Iterator &other) const { return !(*this == other); }

        bool completedCycle() const { return ptr == start && iterations > 0; }

        Node<T> *getNode() const { return ptr; }
    };

    Ring() = default;

    Ring(const Ring &other) : size(other.size)
    {
        if (other.empty())
            return;

        head = new Node<T>(other.head->data);
        Node<T> *current = head;
        Node<T> *otherCurrent = other.head->next;

        for (size_t i = 1; i < size; i++)
        {
            current->next = new Node<T>(otherCurrent->data);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
        current->next = head;
    }

    Ring(Ring &&move) noexcept : head(move.head), size(move.size)
    {
        move.head = nullptr;
        move.size = 0;
    }

    ~Ring()
    {
        try
        {
            clear();
        }
        catch (...)
        {
            head = nullptr;
            size = 0;
        }
    }

    Ring &operator=(const Ring &other)
    {
        if (this == &other)
            return *this;

        Ring temp(other);
        swap(temp);
        return *this;
    }

    Ring &operator=(Ring &&move) 
    {
        if (this == &move)
            return *this;

        clear();
        head = move.head;
        size = move.size;

        move.head = nullptr;
        move.size = 0;

        return *this;
    }

    bool operator==(const Ring &other) const
    {
        if (size != other.size)
            return false;

        auto it1 = begin();
        auto it2 = other.begin();

        for (size_t i = 0; i < size; i++)
        {
            if (*it1 != *it2)
                return false;
            ++it1;
            ++it2;
        }
        return true;
    }

    bool operator!=(const Ring &other) const { return !(*this == other); }

    bool empty() const { return size == 0; }
    size_t getSize() const { return size; }

    void swap(Ring &other) noexcept
    {
        std::swap(head, other.head);
        std::swap(size, other.size);
    }

    Iterator begin() const { return Iterator(head, size); }
    Iterator end() const { return Iterator(nullptr, size); }

    Iterator insert(Iterator pos, const T &value)
    {
        auto *newNode = new Node<T>(value);

        if (empty())
        {
            head = newNode;
            head->next = head;
            size++;
            return Iterator(head, size);
        }

        Node<T> *current = pos.getNode();
        if (!current)
        {
            push_back(value);
            return Iterator(newNode, size);
        }

        if (!containsNode(current))
        {
            delete newNode;
            throw InvalidIteratorException();
        }

        Node<T> *prev = head;
        size_t steps = 0;
        while (prev->next != current && steps < size)
        {
            prev = prev->next;
            steps++;
        }

        if (steps >= size)
        {
            delete newNode;
            throw IteratorException("Invalid iterator position");
        }

        prev->next = newNode;
        newNode->next = current;

        if (current == head)
        {
            head = newNode;
        }

        size++;
        return Iterator(newNode, size);
    }

    Iterator erase(Iterator pos)
    {
        if (empty())
            throw EmptyRingException();

        Node<T> *current = pos.getNode();
        if (!current || !containsNode(current))
        {
            throw InvalidIteratorException();
        }

        Node<T> *nextNode = current->next;

        if (size == 1)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node<T> *prev = head;
            size_t steps = 0;
            while (prev->next != current && steps < size)
            {
                prev = prev->next;
                steps++;
            }

            if (steps >= size)
            {
                throw IteratorException("Cannot find node to erase");
            }

            prev->next = nextNode;
            if (current == head)
            {
                head = nextNode;
            }
            delete current;
        }

        size--;
        return Iterator(nextNode, size);
    }

    void clear()
    {
        while (!empty())
        {
            pop_front();
        }
    }

    T &front()
    {
        if (empty())
            throw EmptyRingException();
        return head->data;
    }

    const T &front() const
    {
        if (empty())
            throw EmptyRingException();
        return head->data;
    }

    T &back()
    {
        if (empty())
            throw EmptyRingException();
        return getTail()->data;
    }

    const T &back() const
    {
        if (empty())
            throw EmptyRingException();
        return getTail()->data;
    }

    void push_back(const T &value)
    {
        auto *newNode = new Node<T>(value);

        if (empty())
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node<T> *tail = getTail();
            tail->next = newNode;
            newNode->next = head;
        }
        size++;
    }

    void push_front(const T &value)
    {
        auto *newNode = new Node<T>(value);

        if (empty())
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node<T> *tail = getTail();
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
        size++;
    }

    void pop_back()
    {
        if (empty())
            throw EmptyRingException();

        if (size == 1)
        {
            pop_front();
            return;
        }

        Node<T> *current = head;
        Node<T> *prev = nullptr;

        for (size_t i = 1; i < size; i++)
        {
            prev = current;
            current = current->next;
        }

        prev->next = head;
        delete current;
        size--;
    }

    void pop_front()
    {
        if (empty())
            throw EmptyRingException();

        if (size == 1)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node<T> *tail = getTail();
            Node<T> *temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
        size--;
    }

    void print() const
    {
        if (empty())
        {
            std::cout << "Ring is empty" << std::endl;
            return;
        }

        Iterator it = begin();
        for (size_t i = 0; i < size; i++)
        {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;
    }

    void sort() { bubbleSortOptimized(); }
};