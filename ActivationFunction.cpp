#include <vector.cpp>
#include "Vector.cpp"
#include "Matrix.cpp"

class ActivationFunction
{
public:
    virtual ~ActivationFunction() = default;
    virtual Vector forward(const Vector& input) const = 0;
    virtual Vector backward(const Vector& input, const Vector& gradient) const = 0;
};

// inherits from activation function
class ReLU : public ActivationFunction
{
class Sigmoid : public ActivationFunction
{