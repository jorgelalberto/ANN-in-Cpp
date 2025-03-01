#pragma once
#include <vector>
#include <iostream>
#include <random>

class Vector {
    private:
        // func to fill vector w/data
        std::vector<float> data_;
    public:
        /* Constructors */
        // def
        Vector();
        // init w/all 0's
        Vector(size_t size);
        // copy over given vector
        Vector(const std::vector<float>& data);
        // copy constructor (for deep copies)
        Vector(const Vector& other);

        /* Assignment Operators */
        Vector& operator=(const Vector& other);
        float operator[](size_t index);
        const float operator[](size_t index) const;
        size_t size() const;
        Vector& operator+=(const Vector& other);
        Vector& hadamard(const Vector& other);

        /* 
            Vector initializtion does not matter much, except in special cases
            For now we will use uniform random initialization, later we can update.
        */
       void uniform_init();
};