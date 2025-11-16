#include "vect2.hpp"

vect2::vect2() {
    _data[0] = 0;
    _data[1] = 0;
}

vect2::vect2(int x, int y) {
    _data[0] = x;
    _data[1] = y;
}

vect2::vect2(const vect2& other) {
    _data[0] = other._data[0];
    _data[1] = other._data[1];
}

vect2& vect2::operator=(const vect2& other) {
    if (this != &other) {
        _data[0] = other._data[0];
        _data[1] = other._data[1];
    }
    return *this;
}

int& vect2::operator[](int index) {
    return _data[index];
}

int vect2::operator[](int index) const {
    return _data[index];
}

vect2& vect2::operator+=(const vect2& other) {
    _data[0] += other._data[0];
    _data[1] += other._data[1];
    return *this;
}

vect2& vect2::operator-=(const vect2& other) {
    _data[0] -= other._data[0];
    _data[1] -= other._data[1];
    return *this;
}

vect2& vect2::operator*=(int scalar) {
    _data[0] *= scalar;
    _data[1] *= scalar;
    return *this;
}

vect2& vect2::operator++() {
    ++_data[0];
    ++_data[1];
    return *this;
}

vect2 vect2::operator++(int) {
    vect2 temp(*this);
    ++(*this);
    return temp;
}

vect2& vect2::operator--() {
    --_data[0];
    --_data[1];
    return *this;
}

vect2 vect2::operator--(int) {
    vect2 temp(*this);
    --(*this);
    return temp;
}

vect2 vect2::operator+(const vect2& other) const {
    return vect2(_data[0] + other._data[0], _data[1] + other._data[1]);
}

vect2 vect2::operator-(const vect2& other) const {
    return vect2(_data[0] - other._data[0], _data[1] - other._data[1]);
}

vect2 vect2::operator*(int scalar) const {
    return vect2(_data[0] * scalar, _data[1] * scalar);
}

vect2 vect2::operator-() const {
    return vect2(-_data[0], -_data[1]);
}

bool vect2::operator==(const vect2& other) const {
    return _data[0] == other._data[0] && _data[1] == other._data[1];
}

bool vect2::operator!=(const vect2& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const vect2& v) {
    os << "{" << v._data[0] << ", " << v._data[1] << "}";
    return os;
}

vect2 operator*(int scalar, const vect2& v) {
    return v * scalar;
}
