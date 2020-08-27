# MIUP18 Problem G: Luigi’s Pizzeria

May `N` be the size of the scores vector `s`, and `S` the the sum of all scores.

Suppose the best section does not contain slices `0` and `N-1`. In that case, the solution is the maximum subarray `max_sub` of `s`.

Suppose now that the best section contains both slices `0` and `N-1`. In that case, the minimum subarray `min_sub` of `s` does not contain slices `0` and `N-1`. Having found `min_sub`, we know `min_sub+max_sub=S`, so `max_sub=S-min_sub`.
