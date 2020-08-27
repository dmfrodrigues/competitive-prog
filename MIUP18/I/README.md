# MIUP18 Problem I: Goin’ south

This problem is very easy. All we need to do is to store `(t,x,y)` for each observation, and count how many observations were made at the same `(t,x,y)` coordinates.

For that, we can use a `map<vector<lli>, lli>`.
