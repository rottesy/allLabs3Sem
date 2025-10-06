#pragma once
#include <stdexcept>
#include <string>

class RingException : public std::runtime_error {
public:
    explicit RingException(const std::string& message) 
        : std::runtime_error(message) {}
};

class IteratorException : public RingException {
public:
    explicit IteratorException(const std::string& message) 
        : RingException("Iterator error: " + message) {}
};

class EmptyRingException : public RingException {
public:
    EmptyRingException() 
        : RingException("Operation on empty ring") {}
};

class InvalidIteratorException : public IteratorException {
public:
    InvalidIteratorException() 
        : IteratorException("Iterator does not belong to this ring") {}
};

class InfiniteLoopException : public IteratorException {
public:
    InfiniteLoopException() 
        : IteratorException("Infinite loop detected") {}
};