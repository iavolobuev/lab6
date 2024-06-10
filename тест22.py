# 6 лабораторная , 2 задача

import numpy as np

def func(x):
    return x[0] + 2 * x[1] + 4 * np.sqrt(1 + x[0]**2 + x[1]**2)

def gradient(x):
    grad = np.zeros_like(x)
    sqrt_term = np.sqrt(1 + x[0]**2 + x[1]**2)
    grad[0] = 1 + (4 * x[0]) / sqrt_term
    grad[1] = 2 + (4 * x[1]) / sqrt_term
    return grad

def gradient_descent(start, learning_rate, max_iterations, tolerance):
    x = np.array(start, dtype=float)
    for _ in range(max_iterations):
        grad = gradient(x)
        x_new = x - learning_rate * grad
        if np.linalg.norm(x_new - x) < tolerance:
            break
        x = x_new
    return x

# Начальная точка, скорость обучения, максимальное количество итераций, точность
start = [1.0, 1.0]
learning_rate = 0.01
max_iterations = 10000
tolerance = 1e-6

# Поиск оптимума методом наискорейшего спуска
optimal_x = gradient_descent(start, learning_rate, max_iterations, tolerance)
optimal_value = func(optimal_x)

print(f"Оптимальная точка: {optimal_x}")
print(f"Значение функции в оптимальной точке: {optimal_value}")
