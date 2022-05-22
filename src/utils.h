#ifndef UTILS_H
#define UTILS_H

// This is a decoupling interface between QT and the interpolator class.
struct Point
{
  double x, y;
  Point(double a, double b) { this->x = a; this->y = b; }
};

#endif // UTILS_H
