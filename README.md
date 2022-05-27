# Integral Solver for c++

## How to use

This program is header only.
You can just use all of integral solver scheme by just including.

```c++
    #include "IntegralSolver.hpp"
```

Let integral you want to solve be like this below
$$\int^b_a f(x)dx$$

You have to split section [a,b] into N sections and store value of f(x) like this below

```c++
    double dx = (b-a)/N;
    std::vector<double> fvec;
    for(int i = 0;i<=N;++i)
        fvec.push(f(a+i*dx));
```

Finally, you can solve integral problem like this

```c++
    double ans = IntegralSolver::Simpson(fvec,dx);
```

Be careful about the fact that in some scheme, you have a constraint about (N+1)

When it comes to Simpson, (N+1) have to be an odd

When it comes to Simpson38, (N+1) have to be a multiple of 3 + 1

When it comes to Boole, (N+1), (N+1) must be a multiple of 4 + 1
