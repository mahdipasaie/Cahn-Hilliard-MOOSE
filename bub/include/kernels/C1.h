#pragma once
#include "ADTimeKernelValue.h"

class C1 : public ADTimeKernelValue
{
public:
  static InputParameters validParams();

  C1(const InputParameters & parameters);

protected:
  virtual ADReal precomputeQpResidual() override;
  private:

};