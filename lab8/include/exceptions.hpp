#pragma once
#include <stdexcept>
#include <string>

class RingException : public std::runtime_error
{
  public:
    using std::runtime_error::runtime_error;
};

class IteratorException : public RingException
{
  public:
    using RingException::RingException;
};

class EmptyRingException : public RingException
{
  public:
    EmptyRingException() : RingException("Operation on empty ring") {}
};

class InvalidIteratorException : public IteratorException
{
  public:
    InvalidIteratorException() : IteratorException("Iterator does not belong to this ring") {}
};

class InfiniteLoopException : public IteratorException
{
  public:
    InfiniteLoopException() : IteratorException("Infinite loop detected") {}
};