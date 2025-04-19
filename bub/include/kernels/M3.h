#pragma once

#include "ADKernelGrad.h"

class M3 : public ADKernelGrad
{
public:
  static InputParameters validParams();
  M3(const InputParameters & parameters);

protected:
  virtual ADRealGradient precomputeQpResidual() override;

private:
  const ADVariableGradient & _grad_c;
  const Real _lambda;
};
