#include "chartview.h"

QT_USE_NAMESPACE

ChartView::ChartView() : QChartView(new QChart())
{
  setRenderHint(QPainter::Antialiasing);

  // Define the draggable points.
  points = new QScatterSeries();
  *points << QPointF(-0.7, -0.3) << QPointF(-0.3, 0.1) << QPointF(0, 0.4)
          << QPointF(0.3, -0.1) << QPointF(0.7, -0.2);
  chart()->addSeries(points);

  poly_points = new QSplineSeries();
  chart()->addSeries(poly_points);

  // Define graph general properties and display.
  chart()->legend()->hide();
  chart()->createDefaultAxes();
  chart()->axes(Qt::Horizontal).first()->setRange(-1, 1);
  chart()->axes(Qt::Vertical).first()->setRange(-0.5, 0.5);

  // TODO: * Use a QXYSeries instead of the more complicated ScatterSeries?
  // * Display the point coordinates while dragging.
  // * Splines may be a bad idea. We get oscillations. Switch to LineSeries.

  connect(points, &QScatterSeries::pressed, this,
          &ChartView::handlePressedPoint);

  // Get chart axes.
  xaxis = static_cast<const QValueAxis*>(chart()->axes(Qt::Horizontal).first());
  yaxis = static_cast<const QValueAxis*>(chart()->axes(Qt::Vertical).first());

  // Define the interpolated points series.
  fillPolyPoints(100);
  poly_coeffs.push_back(0.1);
  poly_coeffs.push_back(-0.1);
  poly_coeffs.push_back(0.2);
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
