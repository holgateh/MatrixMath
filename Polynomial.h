#pragma once
#include <vector>
class Polynomial
{
    private:
        std::vector<float> coeff; 
    public:
        Polynomial(std::vector<float> coeff);

    private:

    public:
        void reduce(float root);
        void printPolynomial();
        
}