#pragma once
#include "exceptions.hpp"
#include "ring.hpp"


template <typename T> class Algorithm
{
  public:
    bool find(const Ring<T> &ring, const T &value) const;
    void sort(Ring<T> &ring) const;

    template <typename Predicate> bool anyOf(const Ring<T> &ring, Predicate pred) const;

    template <typename Predicate> typename Ring<T>::Iterator findIf(const Ring<T> &ring, Predicate pred) const;
};

template <typename T> void Algorithm<T>::sort(Ring<T> &ring) const
{
    if (ring.empty())
        return;
    ring.sort();
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

template <typename T> template <typename Predicate> bool Algorithm<T>::anyOf(const Ring<T> &ring, Predicate pred) const
{
    if (ring.empty())
        return false;

    typename Ring<T>::Iterator it = ring.begin();
    for (size_t i = 0; i < ring.getSize(); i++)
    {
        if (pred(*it))
            return true;
        ++it;
    }
    return false;
}

template <typename T>
template <typename Predicate>
typename Ring<T>::Iterator Algorithm<T>::findIf(const Ring<T> &ring, Predicate pred) const
{
    if (ring.empty())
        return ring.end();

    typename Ring<T>::Iterator it = ring.begin();
    for (size_t i = 0; i < ring.getSize(); i++)
    {
        if (pred(*it))
            return it;
        ++it;
    }
    return ring.end();
}