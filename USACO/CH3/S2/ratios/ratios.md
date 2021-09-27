Given $a_{1..3}$, $b_{1..3}$, $c_{1..3}$, $y_{1..3}$, find $(a, b, c)$ that satisfies 

$$
\begin{bmatrix}
a_1 & a_2 & a_3\\
b_1 & b_2 & b_3\\
c_1 & c_2 & c_3
\end{bmatrix}
\begin{bmatrix}
a \\
b \\
c
\end{bmatrix} = k
\begin{bmatrix}
y_1 \\
y_2 \\
y_3
\end{bmatrix}
$$

where all variables are non-negative integers.

### Answer

Say we know $a$ and $b$, and want to find $c$, $k$.

$$
\begin{cases}
a a_1 + b b_1 + c c_1 = k y_1\\
a a_2 + b b_2 + c c_2 = k y_2\\
a a_3 + b b_3 + c c_3 = k y_3\\
\end{cases}
\iff
\begin{cases}
c c_1 - k y_1 = -a a_1 - b b_1\\
c c_2 - k y_2 = -a a_2 - b b_2\\
c c_3 - k y_3 = -a a_3 - b b_3\\
\end{cases}
$$

Using only two equations,

$$
\begin{cases}
c c_1 - k y_1 = - a a_1 - b b_1\\
c c_2 - k y_2 = - a a_2 - b b_2\\
\end{cases}
\iff
\begin{cases}
c c_1 c_2 - k y_1 c_2 = - a a_1 c_2 - b b_1 c_2\\
c c_1 c_2 - k y_2 c_1 = - a a_2 c_1 - b b_2 c_1\\
\end{cases}
\iff
$$

$$
\iff
\begin{cases}
-\\
k y_1 c_2 - k y_2 c_1 = a a_1 c_2 + b b_1 c_2 - a a_2 c_1 - b b_2 c_1 \\
\end{cases}
\iff
$$

$$
\iff
\begin{cases}
-\\
k (y_1 c_2 - y_2 c_1) = a (a_1 c_2 - a_2 c_1) + b (b_1 c_2 - b_2 c_1)\\
\end{cases}
\implies
$$

$$
\implies
k  = \displaystyle\frac{a (a_1 c_2 - a_2 c_1) + b (b_1 c_2 - b_2 c_1)}{y_1 c_2 - y_2 c_1}
$$

To find $c$, just use the first equation:

$$
a a_1 + b b_1 + c c_1 = k y_1 \iff
c c_1 = k y_1 - a a_1 - b b_1 \iff
$$

$$
\iff c = \displaystyle\frac{k y_1 - a a_1 - b b_1}{c_1}
$$
