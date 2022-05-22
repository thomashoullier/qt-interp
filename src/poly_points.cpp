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
  auto pvec {poly_points->points()};
  for (auto &p: pvec) {
    p.ry() = compYpoly(p.x());
  }
  poly_points->replace(pvec);
}

double ChartView::compYpoly(double x)
{ // We use Horner's scheme.
  double y = 0;
  auto reverse_view = std::ranges::reverse_view{poly_coeffs};
  for (const auto& c : reverse_view) {
    y = y * x + c;
  }
  return y;
}
