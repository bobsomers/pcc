# pcc: Piecewise Clothoid Curves

This library implements curves that are composed of piecewise clothoids. The
curve passes through each control point and the curve segments between control
points are clothoids. With tangent or curvature constraints on the control
points, segments can also be lines or circular arcs.

The curve's control points can be iteratively refined into an approximation of
the actual curve using a sequence of line segments.

The library is intended to be standalone and easy to integrate into other
projects. The visualizer has a number of self-contained dependencies, primarily
[nanogui](https://github.com/wjakob/nanogui).

## Build

```
$ git clone --recursive https://github.com/bobsomers/pcc.git
$ cd pcc
$ make deps
```

To build the library only:

```
$ make lib
```

To build library and visualizer:

```
$ make all
```

To run the visualizer:

```
$ make run
```
