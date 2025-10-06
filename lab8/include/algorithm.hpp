#pragma once
#include "ring.hpp"

template <typename T> class Algorithm
{
  public:
    bool find(const Ring<T> &ring, const T &value) const;
    void sort(Ring<T> &ring) const;
};

template <typename T> void Algorithm<T>::sort(Ring<T> &ring) const
{
    if (ring.getSize() <= 1)
        return;

    std::vector<T> elements;
    typename Ring<T>::Iterator it = ring.begin();

    for (size_t i = 0; i < ring.getSize(); i++)
    {
        elements.push_back(*it);
        ++it;
    }

    for (size_t i = 0; i < elements.size() - 1; i++)
    {
        for (size_t j = 0; j < elements.size() - i - 1; j++)
        {
            if (elements[j] > elements[j + 1])
            {
                std::swap(elements[j], elements[j + 1]);
            }
        }
    }

    Ring<T> temp;
    for (const auto &elem : elements)
    {
        temp.push_back(elem);
    }

    ring = std::move(temp);
}

template <typename T> bool Algorithm<T>::find(const Ring<T> &ring, const T &value) const
{
    if (ring.empty())
        return false;

    typename Ring<T>::Iterator it = ring.begin();
    for (size_t i = 0; i < ring.getSize(); i++)
    {
        if (*it == value)
            return true;
        ++it;
    }

    return false;
}