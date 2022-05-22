#include "chartview.h"

void ChartView::fillPolyPoints(int numPoints)
{
  auto xSpacing = (xaxis->max() - xaxis->min()) / (numPoints - 1);

  for (int i = 0 ; i<numPoints ; i++) {
    poly_points->append(xaxis->min() + xSpacing * i, 0);
  }
}

void ChartView::updatePolyPoints()
{
  interpolator.updateNodes(seriesToPoints(points));
  std::vector<double> y = interpolator.evalInterp(seriesToX(poly_points));
  auto pvec {poly_points->points()};
  uint i = 0;
  for (auto &p: pvec) {
    p.ry() = y.at(i);
    i++;
  }
  poly_points->replace(pvec);
}
