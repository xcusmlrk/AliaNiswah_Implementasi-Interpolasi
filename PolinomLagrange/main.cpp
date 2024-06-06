#include <iostream>
#include <vector>

// Fungsi untuk menghitung nilai interpolasi polinom Lagrange
double lagrangeInterpolation(const std::vector<double>& x, const std::vector<double>& y, double xInterp) {
    double result = 0.0;
    int n = x.size();

    for (int i = 0; i < n; ++i) {
        double term = y[i];
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                term *= (xInterp - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}

int main() {
    // Data input dari pengguna
    int numPoints;
    std::cout<<"~~~~~~~~~~~~~~~~~~";
    std::cout<<"| Program Interpolasi Lagrange|";
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~";
    std::cout << "\nMasukkan jumlah titik data: ";
    std::cin >> numPoints;

    std::vector<double> x(numPoints), y(numPoints);

    std::cout << "Masukkan nilai x dan y:\n";
    for (int i = 0; i < numPoints; ++i) {
        std::cout << "x[" << i << "]: ";
        std::cin >> x[i];
        std::cout << "y[" << i << "]: ";
        std::cin >> y[i];
    }

    // Nilai x yang ingin diinterpolasi
    double xInterp;
    std::cout << "Masukkan nilai x yang ingin diinterpolasi: ";
    std::cin >> xInterp;

    // Menghitung nilai interpolasi
    double yInterp = lagrangeInterpolation(x, y, xInterp);

    std::cout << "Nilai interpolasi pada x = " << xInterp << " adalah y = " << yInterp << std::endl;

    return 0;
}
