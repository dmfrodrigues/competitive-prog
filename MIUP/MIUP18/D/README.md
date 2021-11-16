# MIUP18 Problem D: The Falling Drops

Since full turns return the tap to the original position, `omega=ω%360`.

Instead of assuming the disk is rotating counterclockwise at speed `omega`, we will assume the tap is rotating clockwise at speed `omega`; that means the tap has a speed of `-omega`. Rotating `-omega` in one second can be considered the same as rotating `(360-omega)%360` in one second. So we can assume the tap has a positive speed of `v=(360-omega)%360`.

The position of the tap after `t` seconds is `p=z+v*t`. To find if position `p` is gray, we create a vector `g` of size `360` and paint it gray in the gray angles; then to find if position `p` is gray, we can ask that to `g` in *O(1)*.

Now we only have to iterate over all values of t, from 0 to 100000 inclusive.
