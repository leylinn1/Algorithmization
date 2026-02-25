#include <iostream>
#include <cmath>

double simpson_rule(double (*f)(double), double a, double b, int n) {
    if (n % 2 == 1) n++; // Делаем n четным
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i += 2)
        sum += 4 * f(a + i * h);

    for (int i = 2; i < n - 1; i += 2)
        sum += 2 * f(a + i * h);

    return (h / 3) * sum;
}

double function(double x) {
    return 5*cos(x) + 2; // Интегрируемая функция разность функций
}

int main() {
    double result = simpson_rule(function, 1, 2, 10);
    std::cout << "Приближенное значение интеграла: " << result << std::endl;
    return 0;
}   