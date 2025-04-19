#pragma once

#include "ADKernelValue.h"

class M1 : public ADKernelValue
{
public:
  static InputParameters validParams();
  M1(const InputParameters & parameters);

protected:
  virtual ADReal precomputeQpResidual() override;
};