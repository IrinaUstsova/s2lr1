#include "Vector.h"

Vector::Vector() {
    _data = new int[10];
    _size = 0;
    _mem = 10;
}

Vector::Vector(const Vector &other) {
    _size = other._size;
    _data = new int[_size];
    for (size_t i = 0; i < _size; ++i) {
        _data[i] = other._data[i];
    }
    _mem = _size;
}

Vector::Vector(const size_t &size, const int &initValue) {
    _size = size;
    _data = new int[size];
    for (size_t i = 0; i < size; ++i) {
        _data[i] = (&initValue)[i];
    }
    _mem = _size;
}

Vector &Vector::operator=(const Vector &other) {
    if(&other == this){
        return *this;
    }
    if(_size == other._size){
        for (size_t i = 0; i < _size; ++i) {
            _data[i] = other._data[i];
        }
        return *this;
    }
    else{
        _size = other._size;
        delete[] _data;
        _data = new int[_size];
        for (size_t i = 0; i < _size; ++i) {
            _data[i] = other._data[i];
        }
        _mem = _size;
        return *this;
    }
}

Vector::~Vector() {
 delete[] _data;
}

int &Vector::operator[](const size_t &index) {
    if (index < _size){
        return _data[index];
    }
    else{
        std::cerr << "Invalid index\n";
        return _data[0];
    }
}

size_t Vector::size() const {
    return _size;
}

int Vector::find(const int &value) const {
    for (int i = 0; i < _size; ++i) {
        if(_data[i] == value)return i;
    }
    return -1;
}

void Vector::push_back(const int &value) {
    if (_size == _mem){
        _data = (int*) realloc(_data, (_size + 10) * sizeof (int));
        _mem += 10;
    }
    _data[_size] = value;
    _size ++;
}

void Vector::replace(const int &oldValue, const int &newValue) {
    for (size_t i = 0; i < _size; ++i) {
        if(_data[i] == oldValue){
            _data[i] = newValue;
            return;
        }
    }
}

std::ostream& operator<<(std::ostream &out, Vector &vector) {
    for (size_t i = 0; i < vector._size; ++i) {
        out << vector._data[i] << " ";
    }
    out << "\n";
    return out;
}
