#include "M1.h"

registerMooseObject("bubApp", M1);

InputParameters
M1::validParams()
{
  InputParameters params = ADKernelValue::validParams();
  params.addClassDescription("Implements < mu , v >");
  return params;
}

M1::M1(const InputParameters & parameters)
  : ADKernelValue(parameters)
{
}

ADReal
M1::precomputeQpResidual()
{
  return _u[_qp]; 
}
