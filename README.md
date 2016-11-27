# pcc: Piecewise Clothoid Curves

This library implements curves that are composed of piecewise clothoids. The
curve passes through each control point and the curve segments between control
points are clothoids. With tangent or curvature constraints on the control
points, segments can also be lines or circular arcs.

The curve's control points can be iteratively refined into an approximation of
the actual curve using a sequence of line segments.
