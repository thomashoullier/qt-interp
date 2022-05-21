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
  //std::cout << point.x() << " ; " << point.y() << std::endl;
  QString xstr = QString::number(point.x());
  QString ystr = QString::number(point.y());
  point_coords->setText(xstr + " ; " + ystr );
}
