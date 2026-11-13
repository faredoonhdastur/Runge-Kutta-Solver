# Runge-Kutta-Solver
The goal of this piece of software is to replicate the Runge-Kutta method, but use appropriate libraries aimed at parallel processing to decrease runtime. Furthermore, I am currently implementing an ML-based algorithm to compute a lower bound on the step size, before making the process computationally expensive/undoable.

## Preview of code that uses parallel processing
Note that for this feature I use `omp.h`, given this is a C++ project. The preprocessor directive is hence linked to a Homebrew file, as I have built the code on MacOS, and hence found it convenient to use such a method to get this library. Depending on the setup (such as Linux), it may be simpler than having to go through Homebrew.

## ML-Based algorithm for step size
Currently developing an ML-based method to choose a step size that gives accurate numerical solutions at low computational cost. For training, we consider the exact solution of the ODE, denoted by $y$, or a sufficiently accurate reference solution. We treat the numerical solution as a finite sequence of real numbers $y_i$ and define the errors $\varepsilon_i=|y(x_i)-y_i|$ at the grid points. We then minimize the computational cost subject to $\varepsilon_i\leq\tau$ for every $i$, where $\tau$ is the chosen error tolerance. The penalty term used to handle these constraints is discussed in `step_size_penalty.pdf`.

This ML approach can be extended to higher-dimensional systems of ODEs and complex-valued problems, using an appropriate norm to measure the error between the exact and numerical solutions.
