#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QChartView>
#include <QScatterSeries>
#include <QSplineSeries>
#include <QLabel>
#include <QString>
#include <QMouseEvent>
#include <QValueAxis>

// #include <iostream>
#include <vector>
#include <ranges>

#include "utils.h"
#include "lagrange_interp.h"

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
  QScatterSeries *points; // Draggable nodes.
  QLabel *point_coords; // Coordinates display of nodes, connected to
  //                       external widget.
  const QPointF *pressed_point; // Reference to the point being dragged.
  bool dragp = false; // Are we currently in a dragging action?
  const QValueAxis *xaxis, *yaxis; // Store axes for easy access.
  QSplineSeries *poly_points; // Series holding the display interpolation points
  LagrangeInterp interpolator; // Interpolator instance.

  void updateLabel(const QPointF &point); // Update the connected
  //                                         label with the coordinates of point
  bool pointInChartp(const QPointF &point); // Is point in the visible chart?
  // Fill poly_points with a sampling of points in current chart area.
  void fillPolyPoints(int numPoints);
  void updatePolyPoints(); // Recompute poly_points according to current state.

  // External interface.
  // Convert series into a vector of Points.
  std::vector<Point> seriesToPoints(QXYSeries *series);
  // Convert series into a vector of x coordinates.
  std::vector<double> seriesToX(QXYSeries *series);
};

#endif // CHARTVIEW_H
