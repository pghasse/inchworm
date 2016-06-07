#ifndef LAPLACEYOUNG_H
#define LAPLACEYOUNG_H

#include "Kernel.h"

class LaplaceYoung;

template<>
InputParameters validParams<LaplaceYoung>();

class Diffusion : public Kernel
{
public:
  LaplaceYoung(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();

  virtual Real computeQpJacobian();
};


#endif /* LAPLACEYOUNG_H */
