#include "C2.h"

registerMooseObject("bubApp", C2);

InputParameters
C2::validParams()
{
  InputParameters params = ADKernelGrad::validParams();
  params.addParam<Real>("M", 1, "Coefficient");  
  params.addCoupledVar("mu", "mu"); 
  return params;
}

C2::C2(const InputParameters & parameters)
  : ADKernelGrad(parameters),
    _M(getParam<Real>("M")),
    _grad_mu(adCoupledGradient("mu"))

{
}

ADRealGradient
C2::precomputeQpResidual()
{
    return _M * (_grad_mu[_qp]);

}

