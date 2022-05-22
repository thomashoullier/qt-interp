#include "lagrange_interp.h"

void LagrangeInterp::updateNodes(const std::vector<Point> nodes_to_interp)
{
  nodes = nodes_to_interp;
  updateWeights();
}

void LagrangeInterp::updateWeights()
{// TODO: * Super ugly, we must be able to iterate more compactly.
  interp_validp = true;
  std::vector<double> new_weights;

  for (uint j=0 ; j < nodes.size() ; j++) {
    double prod = 1;
    double xj = nodes.at(j).x;
    for (uint k=0 ; k < nodes.size() ; k++) {
      if (k != j) {
        double diff = xj - nodes.at(k).x;
        if (diff == 0) {
          interp_validp = false; return;
        }
        else {
          prod *= diff;
        }
      }
    }
    new_weights.push_back(1 / prod);
  }
  weights = new_weights;
}

bool LagrangeInterp::isValid()
{
  return interp_validp;
}

std::vector<double> LagrangeInterp::evalInterp(const std::vector<double> x)
{
  // If no valid interpolation can be made, output the previously computed one.
  if (not interp_validp) {
    return prev_y;
  }
  else {
    std::vector<double> y;
    for (uint k=0 ; k < x.size() ; k++) {
      double numerator = 0;
      double denom = 0;
      for (uint j=0 ; j < weights.size() ; j++) {
        double xdiff = x.at(k) - nodes.at(j).x;
        numerator += weights.at(j) * nodes.at(j).y / xdiff;
        denom += weights.at(j) / xdiff;
      }
      y.push_back(numerator / denom);
    }
    prev_y = y;
    return y;
  }
}
