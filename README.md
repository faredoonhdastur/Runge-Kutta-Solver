# Runge-Kutta-Solver
The goal of this piece of software is to replicate the Runge-Kutta method, but use appropriate libraries aimed at parallel processing to decrease runtime. Furthermore, I am currently implementing an ML-based algorithm to compute a lower bound on the step size, before making the process computationally expensive/undoable.

## Preview of code that uses parallel processing
Note that for this feature I use `omp.h`, given this is a C++ project. The preprocessor directive is hence linked to a Homebrew file, as I have built the code on MacOS, and hence found it convenient to use such a method to get this library. Depending on the setup (such as Linux), it may be simpler than having to go through Homebrew.

## ML-Based algorithm for step size
Currently developing ML-based method to acquire accurate yet computationally inexpensive step size. We can reason through this by considering the analytic solution of the ODE, which we may call $y$ and the approximated solution which we may treat as a sequence $`a : \{1,2,\ldots,k\} \to \mathbb{R}`$ 
