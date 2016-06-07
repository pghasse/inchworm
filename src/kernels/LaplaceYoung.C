#include "LaplaceYoung.h"


template<>
InputParameters validParams<LaplaceYoung>()
{
  InputParameters p = validParams<Kernel>();
  return p;
}

LaplaceYoung::LaplaceYoung(const InputParameters & parameters) :
    Kernel(parameters)
{
}

Real
LaplaceYoung::computeQpResidual()
{
  return _grad_u[_qp] * _grad_test[_i][_qp];
}

Real
LaplceYoung::computeQpJacobian()
{
  return _grad_phi[_j][_qp] * _grad_test[_i][_qp];
}
