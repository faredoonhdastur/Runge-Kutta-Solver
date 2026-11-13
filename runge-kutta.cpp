#include <cstdio>
#include <chrono>
#include <functional>
#include <iostream>
#include "/opt/homebrew/opt/libomp/include/omp.h"

using namespace std;

const int MAX_ITERATIONS = 20*100000;
const double h = 0.05/100000;

class ODE {
    public:
        double x;
        double y;

        function<double(double, double)> f;
        
        // Update x with fixed step
        double update_x(double x) {
            return x + h;
        }

        // Update approximation output via Runge-Kutta procedure
        double update_y(double x, double y) {
            double k1 = f(x,y);
            double k2 = f(x + h/2, y + (h/2)*k1);
            double k3 = f(x + h/2, y + (h/2)*k2);
            double k4 = f(x + h, y + h*k3);
            return y + h/6 * (k1 + 2*k2 + 2*k3 + k4);
        }
};


// Main program to run Euler's method
int main() {  
    ODE ode;
  
    // define function
    ode.f = [](double x, double y){ return y * log(x); };

    // initial conditions
    ode.x = 1.0;
    ode.y = 2.0;

    // RK4 steps depend on the previous iteration, so loop must run serially
    pthread_set_qos_class_self_np(QOS_CLASS_USER_INITIATED, 0);
    auto startTime = chrono::steady_clock::now();

    for (int i = 0; i < MAX_ITERATIONS; i++) {
        ode.y = ode.update_y(ode.x, ode.y);
        ode.x = ode.update_x(ode.x);
        printf("x=%lf \t y=%lf \n", ode.x, ode.y);
    }

    auto endTime = chrono::steady_clock::now();
    double seconds = chrono::duration<double>(endTime - startTime).count();
    cout << "Time: " << seconds << " seconds\n";
    return 0;
}
