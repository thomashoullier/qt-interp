# QT Interpolation toy
`qt-interp` is a QT toy program that demonstrates interpolating points
in the 2D plane in an interactive fashion.

The goal for this program is to be a exercise and a starting point for similar
toys. Please note that this is one of my first program in C++ and certainly in
Qt6. Do not rely on the present work to build serious projects nor learn about
correct C++ or Qt programming.

In action:
![demo movie](doc/demo.mp4)

## Interpolation implementation
The interpolation is performed as detailed in [1]. It is a Lagrangian
interpolation in barycentric formulation. This is not the focus of
this repository, but this paper is worth a read.

## Performance
While I tried not to make a mess, and believe the structure is sound
and no excessive operations are carried out, there may be some
unnecessary data copying as well as awkward data marshalling.

The program runs smoothly on my (small) desktop.

## Build and environment
To build this project, make sure you have Qt6 development libraries installed
and `cmake`. Change to a `build` directory at the root of the project and run:

```shell
cd build
cmake ..
cmake --build .
```

`qt-interp` builds and runs fine with `cmake-3.22.2`, `gcc-10.2.1`,
`qt-6.3.0_1`, on my Void Linux desktop with kernel `5.15_1`.

## Further improvements
* Dynamically add or remove points.
* Zoom the chart area.
* Display a formula using the basis of monomials. This would require
  something along the lines of [2].

## References
1. J.-P. Berrut and L. N. Trefethen, “Barycentric Lagrange Interpolation,” SIAM
   Review 46, 501–517 (2004). https://doi.org/10.1137/s0036144502417715
2. https://math.stackexchange.com/questions/88256/computation-of-coefficients-of-lagrange-polynomials

## Links
I took a lot of inspiration from the QT documentation examples, along
with the usual copying and pasting from StackOverflow.

* https://doc.qt.io/qt-6/qtcharts-areachart-example.html
* https://doc.qt.io/qt-6/qtcharts-scatterinteractions-example.html
* https://doc.qt.io/qt-6/qtwidgets-graphicsview-elasticnodes-example.html
* https://doc.qt.io/qt-6/qtwidgets-graphicsview-diagramscene-example.html
* https://forum.qt.io/topic/109935/draggable-line-segment/3
 
