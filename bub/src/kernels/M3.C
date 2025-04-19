#include "M3.h"

registerMooseObject("bubApp", M3);

InputParameters
M3::validParams()
{
  InputParameters params = ADKernelGrad::validParams();
  params.addClassDescription("Kernel for < -λ ∇c ,  ∇v > ");
  params.addRequiredCoupledVar("c", "c");
  params.addParam<Real>("lambda", 1e-2, "Gradient energy coefficient λ");
  return params;
}

M3::M3(const InputParameters & parameters)
  : ADKernelGrad(parameters),
    _grad_c(adCoupledGradient("c")),
    _lambda(getParam<Real>("lambda"))
{
}

ADRealGradient
M3::precomputeQpResidual()
{
  return -_lambda * _grad_c[_qp] ;
}