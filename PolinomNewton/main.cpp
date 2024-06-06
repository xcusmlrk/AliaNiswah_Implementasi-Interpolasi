#include <iostream>
#include <vector>

// Fungsi untuk menghitung koefisien Newton
std::vector<double> newtonCoefficients(const std::vector<double>& x, const std::vector<double>& y) {
    int n = x.size();
    std::vector<std::vector<double>> dividedDifferences(n, std::vector<double>(n));
    std::vector<double> coefficients(n);

    // Inisialisasi divided differences dengan nilai y
    for (int i = 0; i < n; ++i) {
        dividedDifferences[i][0] = y[i];
    }

    // Hitung divided differences
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
            dividedDifferences[i][j] = (dividedDifferences[i + 1][j - 1] - dividedDifferences[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    // Ekstrak koefisien
    for (int i = 0; i < n; ++i) {
        coefficients[i] = dividedDifferences[0][i];
    }

    return coefficients;
}

// Fungsi untuk menghitung nilai interpolasi menggunakan polinom Newton
double newtonInterpolation(const std::vector<double>& x, const std::vector<double>& coefficients, double xInterp) {
    double result = coefficients[0];
    double term = 1.0;

    for (int i = 1; i < coefficients.size(); ++i) {
        term *= (xInterp - x[i - 1]);
        result += coefficients[i] * term;
    }

    return result;
}

int main() {
    // Data input dari pengguna
    int numPoints;
    std::cout<<"~~~~~~~~~~~~~~~~~~";
    std::cout<<"| Program Interpolasi Newton |";
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

    // Hitung koefisien Newton
    std::vector<double> coefficients = newtonCoefficients(x, y);

    // Nilai x yang ingin diinterpolasi
    double xInterp;
    std::cout << "Masukkan nilai x yang ingin diinterpolasi: ";
    std::cin >> xInterp;

    // Menghitung nilai interpolasi
    double yInterp = newtonInterpolation(x, coefficients, xInterp);

    std::cout << "Nilai interpolasi pada x = " << xInterp << " adalah y = " << yInterp << std::endl;

    return 0;
}
