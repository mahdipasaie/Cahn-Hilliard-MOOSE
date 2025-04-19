#include "M2.h"

registerMooseObject("bubApp", M2);

InputParameters
M2::validParams()
{
  InputParameters params = ADKernelValue::validParams();
  params.addClassDescription("Kernel to compute  < - df/dc , v > ");
  params.addRequiredCoupledVar("c", "c");

  return params;
}

M2::M2(const InputParameters & parameters)
  : ADKernelValue(parameters),
  _c(adCoupledValue("c"))
  

{ 
}


ADReal
M2::precomputeQpResidual()
{
    const ADReal c = _c[_qp];
    return -200.0 * c * (1.0 - c) * (1.0 - 2.0 * c);
}
