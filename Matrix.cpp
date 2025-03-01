#include <vector>
#include <cmath>
#include "Vector.cpp"

class Matrix
{
private:
    /* data */
    size_t rows_;
    size_t cols_;
    vector<float> data_; // data_[i*cols_ + j] = data[i][j]

public:
    Matrix(size_t rows, size_t cols) : data_(rows * cols, 0.0f), rows_(rows), cols_(cols) {}
    void xavier_init() {
        float limit = sqrt(6.0f / (rows_*cols_));
        for (size_t i = 0; i < rows_*cols_; i++) {
            // bound is now -1 to 1
            // cast to float to avoid integer division
            data_[i] = (static_cast<float>(rand()) / RAND_MAX * 2.0f - 1.0f) * limit;
        }
    }

    Vector multiply(const Vector& other) const {
        if (cols_ != other.size()) {
            throw std::invalid_argument("Matrix multiplication dimension mismatch");
        }
        Vector result(rows_);
        for (size_t i = 0; i < rows_; i++) {
            float sum = 0.0f;
            for (size_t j = 0; j < cols_; j++) {
                sum += data_[i*cols_ + j] * other[j];
            }
            result[i] = sum;
        }
        return result;
    }

    float& at(size_t i, size_t j) {return data_[i*cols_ + j];}
    const float& at(size_t i, size_t j) const {return data_[i*cols_ + j];}

    size_t rows() const {return rows_;}
    size_t cols() const {return cols_;}
};