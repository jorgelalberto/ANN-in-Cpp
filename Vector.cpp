#include "Vector.h"

Vector::Vector() : data_() {}
Vector::Vector(size_t size) : data_(size, 0.0f) {};
Vector::Vector(const std::vector<float>& data) : data_(data) {};
Vector::Vector(const Vector& other) : data_(other.data_) {};

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        data_ = other.data_;
    }
    return *this;
}
float Vector::operator[](size_t index) { return data_[index]; }

const float Vector::operator[](size_t index) const { return data_[index]; }

size_t Vector::size() const { return data_.size(); }

Vector& Vector::operator+=(const Vector& other) {
    if (other.size() != size()) { throw std::invalid_argument("Dimension mismatch"); }
    for (size_t i=0; i<size(); ++i) { data_[i] += other.data_[i]; }
    return *this;
}
Vector& Vector::hadamard(const Vector& other) {
    if (other.size() != size()) { throw std::invalid_argument("Dimension mismatch"); }
    for (size_t i=0; i<size(); ++i) { data_[i] *= other.data_[i]; }
    return *this;
}

/* 
    Vector initializtion does not matter much, except in special cases
    For now we will use uniform random initialization, later we can update.
*/
void Vector::uniform_init() {
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<float> dis(-1.0, 1.0);
for (size_t i = 0; i < size(); i++) {
    data_[i] = dis(gen);
}
}