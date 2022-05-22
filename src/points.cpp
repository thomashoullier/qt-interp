#include "chartview.h"

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
      // Manage the interpolation
      updatePolyPoints();
    }
  }
  QChartView::mouseMoveEvent(event);
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

void ChartView::mouseReleaseEvent(QMouseEvent *event)
{
  dragp = false;
  QChartView::mouseReleaseEvent(event);
}
