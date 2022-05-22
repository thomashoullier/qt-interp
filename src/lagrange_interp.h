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
  bool isValid(); // Can we proceed with evaluation?
  void updateNodes(const std::vector<Point> nodes);
  std::vector<double> evalInterp(const std::vector<double> x);

 private:
  std::vector<Point> nodes; // Data nodes that generate the interpolation.
  std::vector<double> weights; // Precomputed data weights.
  bool interp_validp = true; // Is there a valid interpolation to evaluate?
  std::vector<double> prev_y; // Previously evaluated y values, returned in
  //                             case of current non-valid interpolation.

  void updateWeights(); // Precompute Lagrange weights.
};

#endif // LAGRANGE_INTERP_H
