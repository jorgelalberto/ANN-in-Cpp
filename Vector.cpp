#include <vector>
#include <iostream>
#include <random>

using namespace std;

class Vector {
    private:
        vector<float> data_;
    public:
        // Constructors
        // default constructor
        Vector() : data_() {}

        // constructor with a size
        Vector(size_t size) : data_(size, 0.0f) {};
        // constructor with a vector
        Vector(const vector<float>& data) : data_(data) {};
        // copy constructor
        Vector(const Vector& other) : data_(other.data_) {};

        // Assignment Operators
        Vector& operator=(const Vector& other) {
            if (this != &other) {
                data_ = other.data_;
            }
            return *this;
        }

        float& operator[](size_t index) {
            return data_[index];
        }

        const float& operator[](size_t index) const {
            return data_[index];
        }

        size_t size() const {
            return data_.size();
        }

        Vector& operator+=(const Vector& other) {
            if (other.size() != size()) {
                throw std::invalid_argument("Vector addition dimension mismatch");
            }
            for (size_t i = 0; i < size(); i++) data_[i] += other.data_[i];
            return *this;
        }

        Vector& hadamard(const Vector& other) {
            if (other.size() != size()) {
                throw std::invalid_argument("Vector addition dimension mismatch");
            }
            for (size_t i = 0; i < size(); i++) data_[i] *= other.data_[i];
            return *this;
        }

        /*
        Vector intialization does not matter much, so we will just do uniform initialization
        But typically he initialization is done for 
        */
       void uniform_init() {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<float> dis(-1.0, 1.0);
        for (size_t i = 0; i < size(); i++) {
            data_[i] = dis(gen);
        }
       }
};