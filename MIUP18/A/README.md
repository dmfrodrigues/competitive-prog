# MIUP18 Problem A: Clocks

Use strategy of **difference array**.

Difference array works by saving the difference between consecutive elements rather than the values of the actual elements. That means when we want, for instance, to sum `s` over the range `[l,r)`, we execute the following operations on the diff array:

```cpp
diff[l] += s;
if(r < diff.size()) diff[r] -= s;
```

The real values encoded by a difference array can be retrieved by:

```cpp
int c = 0;
VI v(diff.size());
FOR(i,0,v.size()) v[i] = c = c+diff[i];
```

Now, for each column `c`, we create a new difference array, check what operations change values in column `c`, update `diff` accordingly and then iterate over `diff` to count the positions of the clocks.
