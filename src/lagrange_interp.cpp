// TODO:
// * Get x and y coordinates from points. (in another file)
//   Try getting them as const references recast from QXYSeries.
//   We may need to put Point in a dedicated file shared by chartview
//   and lagrange_interp.
// * Compute weights from nodes, signal an error when nodes share the same
//   abscissa. Maybe manage this by a flag inside LagrangeInterp, which
//   simply spews out the previous result? Or maybe manage this from the
//   Chart and do not try to eval.
// * Evaluation using precomputed weights, at arbitrary x positions.

#include "lagrange_interp.h"

LagrangeInterp::LagrangeInterp()
{

}

int LagrangeInterp::updateNodes(const std::vector<Point> nodes)
{

  updateWeights();
}

void LagrangeInterp::updateWeights()
{

}

std::vector<double> LagrangeInterp::evalInterp(const std::vector<double> x)
{

}
