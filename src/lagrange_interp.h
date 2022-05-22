#ifndef LAGRANGE_INTERP_H
#define LAGRANGE_INTERP_H

/* This is a Barycentric Lagrangian polynomial interpolator class
   implemented according to:
   J.-P. Berrut and L. N. Trefethen, “Barycentric Lagrange
   Interpolation,” SIAM Review 46, 501–517 (2004).
   https://doi.org/10.1137/s0036144502417715 */

#include "utils.h"
#include <vector>

class LagrangeInterp
{
 public:
  LagrangeInterp();
  int updateNodes(const std::vector<Point> nodes); // Return 1 in
  //                                                  case of x values conflict
  std::vector<double> evalInterp(const std::vector<double> x);

 private:
  std::vector<Point> nodes; // Data nodes that generate the interpolation.
  std::vector<double> weights; // Precomputed data weights.

  void updateWeights(); // Precompute Lagrange weights.
};

#endif // LAGRANGE_INTERP_H
