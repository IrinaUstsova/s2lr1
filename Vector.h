#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
    int* _data;
    size_t _size;
    size_t _mem;
public:
    Vector();
    Vector(const Vector& other);
    Vector(const size_t& size, const int& initValue);
    Vector& operator=(const Vector& other);
    ~Vector();
    int& operator[](const size_t& index);
    size_t size() const;
    int find(const int& value) const;
    void push_back(const int& value);
    void replace(const int& oldValue, const int& newValue);
    friend std::ostream& operator<<(std::ostream& out, Vector& vector);
};

std::ostream& operator<<(std::ostream& out, Vector& vector);

#endif