#pragma once

#include "node.hpp"
#include <iostream>
#include <stdexcept>
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
                throw std::runtime_error("Dereferencing null iterator");
            return ptr->data;
        }

        const T &operator*() const
        {
            if (!ptr)
                throw std::runtime_error("Dereferencing null iterator");
            return ptr->data;
        }

        Iterator &operator++()
        {
            if (!ptr)
                throw std::runtime_error("Incrementing null iterator");
            if (iterations >= max_iterations && max_iterations > 0)
            {
                throw std::runtime_error("Iterator: infinite loop detected");
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

        friend bool operator==(const Iterator &lhs, const Iterator &rhs) { return lhs.ptr == rhs.ptr; }

        friend bool operator!=(const Iterator &lhs, const Iterator &rhs) { return lhs.ptr != rhs.ptr; }

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

    ~Ring() { clear(); }

    Ring &operator=(const Ring &other)
    {
        if (this == &other)
            return *this;

        Ring temp(other);
        swap(temp);
        return *this;
    }

    Ring &operator=(Ring &&move) noexcept
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

    friend bool operator==(const Ring &lhs, const Ring &rhs)
    {
        if (lhs.size != rhs.size)
            return false;

        auto it1 = lhs.begin();
        auto it2 = rhs.begin();

        for (size_t i = 0; i < lhs.size; i++)
        {
            if (*it1 != *it2)
                return false;
            ++it1;
            ++it2;
        }
        return true;
    }

    friend bool operator!=(const Ring &lhs, const Ring &rhs) { return !(lhs == rhs); }

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
        Node<T> *newNode = new Node<T>(value);

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
            throw std::invalid_argument("Iterator does not belong to this ring");
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
            throw std::runtime_error("Invalid iterator position");
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
            return end();

        Node<T> *current = pos.getNode();
        if (!current || !containsNode(current))
        {
            throw std::invalid_argument("Invalid iterator for erase");
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
                throw std::runtime_error("Cannot find node to erase");
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
        {
            throw std::out_of_range("Ring is empty");
        }
        return head->data;
    }

    const T &front() const
    {
        if (empty())
        {
            throw std::out_of_range("Ring is empty");
        }
        return head->data;
    }

    T &back()
    {
        if (empty())
        {
            throw std::out_of_range("Ring is empty");
        }

        Node<T> *current = head;
        for (size_t i = 1; i < size; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    const T &back() const
    {
        if (empty())
        {
            throw std::out_of_range("Ring is empty");
        }

        Node<T> *current = head;
        for (size_t i = 1; i < size; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    void push_back(const T &value)
    {
        Node<T> *newNode = new Node<T>(value);

        if (empty())
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node<T> *tail = head;
            for (size_t i = 1; i < size; i++)
            {
                tail = tail->next;
            }
            tail->next = newNode;
            newNode->next = head;
        }
        size++;
    }

    void push_front(const T &value)
    {
        Node<T> *newNode = new Node<T>(value);

        if (empty())
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node<T> *tail = head;
            for (size_t i = 1; i < size; i++)
            {
                tail = tail->next;
            }

            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
        size++;
    }

    void pop_back()
    {
        if (empty())
            return;

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
            return;

        if (size == 1)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node<T> *tail = head;
            for (size_t i = 1; i < size; i++)
            {
                tail = tail->next;
            }

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
};