#include <vector>
#include <cmath>
#include "Vector.cpp"
#include "Matrix.cpp"

class WeightMatrix
{
private:
    Matrix weights_;
    Vector biases_;
public:
    WeightMatrix(size_t input_size, size_t output_size) : weights_(output_size, input_size), biases_(output_size) {
        weights_.xavier_init();
        biases_.xavier_init();
    }

    // Wx + b
    Vector multiply(const Vector& input) const {
        return weights_.multiply(input) += biases_;
    }

    void update(const Vector& gradient, float learning_rate) {
        // update weights
        for (size_t i = 0; i < weights_.rows(); i++) {
            for (size_t j = 0; j < weights_.cols(); j++) {
                weights_.at(i, j) -= learning_rate * gradient[i] * weights_.at(i, j);
            }
        }
        // update biases
        for (size_t i = 0; i < biases_.size(); i++) {
            biases_[i] -= learning_rate * gradient[i];
        }
    }

    float& at(size_t i, size_t j) {return weights_.at(i, j);}
    const float& at(size_t i, size_t j) const {return weights_.at(i, j);}
    
    size_t input_size() const {return weights_.cols();}
    size_t output_size() const {return weights_.rows();}
};