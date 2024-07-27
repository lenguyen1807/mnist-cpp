#ifndef LAYER_H
#define LAYER_H

#include <functional>
#include <string>
#include "matrix.h"
#include "utils.h"

class Layer
{
public:
    Layer(
        size_t inputSize, 
        size_t outputSize,
        const std::string& activation,
        bool randomInit = false 
    );

    void Print();
    void Compute(const MatrixPtr& input);
    void ZeroGradient();
    MatrixPtr GetOutput() const;

private:
    MatrixPtr m_PreActiv;
    MatrixPtr m_AfterActiv;
    MatrixPtr m_Weight;
    MatrixPtr m_Gradient;
    std::string m_ActivationName;
    std::function<double(double)> m_Activation;
};

#endif // LAYER_H