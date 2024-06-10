6 лабораторная , 1 задача

#include <iostream>
#include <cmath>
#include <vector>
#include <functional>

using namespace std;

double func(const vector<double>& x) {
    return x[0] + 5 * x[1] + exp(x[0] * x[0] + x[1] * x[1]);
}

vector<double> gradient(const vector<double>& x) {
    vector<double> grad(2);
    grad[0] = 1 + 2 * x[0] * exp(x[0] * x[0] + x[1] * x[1]);
    grad[1] = 5 + 2 * x[1] * exp(x[0] * x[0] + x[1] * x[1]);
    return grad;
}

vector<double> coordinate_descent(const vector<double>& start, double learning_rate, int max_iterations, double tolerance) {
    vector<double> x = start;
    for (int iter = 0; iter < max_iterations; ++iter) {
        vector<double> x_new = x;
        for (int i = 0; i < x.size(); ++i) {
            vector<double> step = x;
            step[i] -= learning_rate * gradient(x)[i];
            if (abs(step[i] - x[i]) < tolerance) {
                return x;
            }
            x[i] = step[i];
        }
    }
    return x;
}

int main() {
    vector<double> start = {1.0, 1.0}; // начальная точка
    double learning_rate = 0.01; // скорость обучения
    int max_iterations = 10000; // максимальное количество итераций
    double tolerance = 1e-6; // точность

    vector<double> result = coordinate_descent(start, learning_rate, max_iterations, tolerance);

    cout << "Оптимальная точка: ";
    for (double val : result) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Значение функции в оптимальной точке: " << func(result) << endl;

    return 0;
}

