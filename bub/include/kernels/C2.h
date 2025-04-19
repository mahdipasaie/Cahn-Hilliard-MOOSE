#pragma once
#include "ADKernelGrad.h"


class C2 : public ADKernelGrad
{
public:
  static InputParameters validParams();

  C2(const InputParameters & parameters);

protected:
  ADRealGradient precomputeQpResidual() override;
  const Real _M;
  const ADVariableGradient & _grad_mu;
};