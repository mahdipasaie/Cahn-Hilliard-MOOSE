#pragma once

#include "ADKernelValue.h"

class M2 : public ADKernelValue
{
public:
  static InputParameters validParams();
  M2(const InputParameters & parameters);

protected:
  virtual ADReal precomputeQpResidual() override;

private:
  const ADVariableValue & _c;
};