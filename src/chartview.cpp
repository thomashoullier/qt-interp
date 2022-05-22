#include "chartview.h"

QT_USE_NAMESPACE

ChartView::ChartView() : QChartView(new QChart())
{
  setRenderHint(QPainter::Antialiasing);

  // Define the points.
  points = new QScatterSeries();
  *points << QPointF(-0.7, -0.3) << QPointF(-0.3, 0.1) << QPointF(0, 0.4)
          << QPointF(0.3, -0.1) << QPointF(0.7, -0.2);
  chart()->addSeries(points);

  // Define graph general properties and display.
  chart()->legend()->hide();
  chart()->createDefaultAxes();
  chart()->axes(Qt::Horizontal).first()->setRange(-1, 1);
  chart()->axes(Qt::Vertical).first()->setRange(-0.5, 0.5);

  // TODO: * Use a QXYSeries instead of the more complicated ScatterSeries?
  // * Display the point coordinates while dragging.
  connect(points, &QScatterSeries::pressed, this,
          &ChartView::handlePressedPoint);

  // Get chart axes.
  xaxis = static_cast<const QValueAxis*>(chart()->axes(Qt::Horizontal).first());
  yaxis = static_cast<const QValueAxis*>(chart()->axes(Qt::Vertical).first());
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

void ChartView::handleHoveredPoint(const QPointF &point)
{
  QString xstr = QString::number(point.x());
  QString ystr = QString::number(point.y());
  point_coords->setText(xstr + " ; " + ystr );
}

void ChartView::handlePressedPoint(const QPointF &point)
{
  dragp = true;
  pressed_point = &point;
}

void ChartView::mouseMoveEvent(QMouseEvent *event)
{
  if (dragp == true) {
    auto mousePos = event->pos();
    QPointF mouseOnChart = chart()->mapToValue(mousePos);
    if (pointInChartp(mouseOnChart)) {
      points->replace(*pressed_point, mouseOnChart);
    }
  }
  QChartView::mouseMoveEvent(event);
}

void ChartView::mouseReleaseEvent(QMouseEvent *event)
{
  dragp = false;
  QChartView::mouseReleaseEvent(event);
}

bool ChartView::pointInChartp(const QPointF &point)
{
  auto xmin = xaxis->min();
  auto xmax = xaxis->max();
  auto ymin = yaxis->min();
  auto ymax = yaxis->max();
  bool inchartp = (point.x() <= xmax && point.x() >= xmin &&
                   point.y() <= ymax && point.y() >= ymin);
  return inchartp;
}
