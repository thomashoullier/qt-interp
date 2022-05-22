#include "chartview.h"

QT_USE_NAMESPACE

ChartView::ChartView() : QChartView(new QChart())
{
  setRenderHint(QPainter::Antialiasing);

  // Define the draggable points and interpolation series.
  points = new QScatterSeries();
  *points << QPointF(-0.7, -0.3) << QPointF(-0.3, 0.1) << QPointF(0, 0.4)
          << QPointF(0.3, -0.1) << QPointF(0.7, -0.2);
  poly_points = new QSplineSeries();
  chart()->addSeries(poly_points);
  chart()->addSeries(points);

  // Define graph general properties and display.
  chart()->legend()->hide();
  chart()->createDefaultAxes();
  chart()->axes(Qt::Horizontal).first()->setRange(-1, 1);
  chart()->axes(Qt::Vertical).first()->setRange(-0.5, 0.5);

  // TODO: * Use a QXYSeries instead of the more complicated ScatterSeries?
  // * Display the point coordinates while dragging.
  // * Splines may be a bad idea. We get oscillations. Switch to LineSeries.
  // * The poly_points series is in front, which hampers selection of nodes.
  // * Create an init method for the interpolator.

  connect(points, &QScatterSeries::pressed, this,
          &ChartView::handlePressedPoint);

  // Get chart axes.
  xaxis = static_cast<const QValueAxis*>(chart()->axes(Qt::Horizontal).first());
  yaxis = static_cast<const QValueAxis*>(chart()->axes(Qt::Vertical).first());

  // Define the interpolated points series.
  fillPolyPoints(100);

  // Initialize the interpolation.
  interpolator.updateNodes(seriesToPoints(points));
  interpolator.evalInterp(seriesToX(poly_points));
  updatePolyPoints();
}

ChartView::~ChartView()
{
}

void ChartView::connectPointLabel (QLabel *point_label)
{
  point_coords = point_label;
  connect(points, &QScatterSeries::hovered, this,
          &ChartView::handleHoveredPoint);
}

std::vector<Point> ChartView::seriesToPoints(QXYSeries *series)
{
  std::vector<Point> nodes;
  auto pvec {series->points()};
  for (auto &p: pvec) {
    nodes.push_back(Point(p.x(), p.y()));
  }
  return nodes;
}

std::vector<double> ChartView::seriesToX(QXYSeries *series)
{
  std::vector<double> x;
  auto pvec {series->points()};
  for (auto &p: pvec) {
    x.push_back(p.x());
  }
  return x;
}
