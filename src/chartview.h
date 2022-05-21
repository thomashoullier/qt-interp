#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QtCharts/QChartGlobal>
#include <QtCharts/QChartView>
#include <QtCharts/QScatterSeries>
#include <QLabel>
#include <QString>
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

 private:
    QScatterSeries *points;
    QLabel *point_coords;
};

#endif // CHARTVIEW_H
