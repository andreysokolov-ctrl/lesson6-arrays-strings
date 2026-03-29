#include <iostream>
using namespace std;

int main() {
    const int N = 30; 
    double a, b;

    cout << "Введите начало отрезка (a): ";
    cin >> a;
    cout << "Введите конец отрезка  (b): ";
    cin >> b;

    if (a >= b) {
        cout << "Ошибка: a должно быть меньше b." << endl;
        return 1;
    }


    double step = (b - a) / (N - 1);

    double F[N];

    for (int i = 0; i < N; i++) {
        double x = a + i * step;
        F[i] = exp(-x) * sin(6.0 * x);
    }

    double lastPositive = 0.0;
    bool found = false;

    for (int i = N - 1; i >= 0; i--) {
        if (F[i] > 0.0) {
            lastPositive = F[i];
            found = true;
            break;  // нашли — дальше не идём
        }
    }


    if (!found) {
        cout << "Ошибка: в массиве нет положительных значений." << endl;
        return 1;
    }
    double invLast = 1.0 / lastPositive;

    for (int i = 0; i < N; i++) {
        F[i] *= invLast;
    }

    cout << "\n i |        x        |       F[i]" << endl;
    cout << "---|-----------------|------------------" << endl;

    for (int i = 0; i < N; i++) {
        double x = a + i * step;
        cout << " " << i << " | " << x << " | " << F[i] << endl;
    }

    return 0;
}
