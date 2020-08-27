## Ternary search (tersearch.cpp) O(log N)

**`tersearch(l, r, f)`** searches the smallest value of `[l,r)` that maximizes the unimodal (increases until some value `m` and then decreases) function `f`.

```cpp
cout << tersearch(0,  999, [](lli a){ return      -abs(a-10)         ; }) << endl;//10
cout << tersearch(0, 9999, [](lli a){ return min(1-abs(a-35), (lli)0); }) << endl;//34;

```
