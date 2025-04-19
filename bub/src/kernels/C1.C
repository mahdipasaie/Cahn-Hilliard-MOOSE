#include "C1.h"

registerMooseObject("bubApp", C1);

InputParameters
C1::validParams()
{
  InputParameters params = ADTimeKernelValue::validParams();
  params.addClassDescription("Implements the time derivative term for Concentration < dc/dt, q >.");
  return params;
}

C1::C1(const InputParameters & parameters)
  : ADTimeKernelValue(parameters)
{
}

ADReal
C1::precomputeQpResidual()
{
  return _u_dot[_qp];
}
