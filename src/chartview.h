#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QtCharts/QChartGlobal>
#include <QtCharts/QChartView>
#include <QtCharts/QScatterSeries>
#include <QLabel>
#include <QString>
#include <QMouseEvent>
#include <iostream>

QT_USE_NAMESPACE

class ChartView : public QChartView
{
  Q_OBJECT

public:
  ChartView();
  ~ChartView();
  void connectPointLabel (QLabel *point_label);

private Q_SLOTS:
  void handleHoveredPoint(const QPointF &point);
  void handlePressedPoint(const QPointF &point);
  void mouseMoveEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);

private:
  QScatterSeries *points;
  QLabel *point_coords;
  const QPointF *pressed_point; // Reference to the point being dragged.
  bool dragp = false; // Are we currently in a dragging action?
};

#endif // CHARTVIEW_H
