#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

#include "kalman_filter.cpp"

constexpr double TRUE_TEMP = 25.0;
constexpr double R = 4.0;  // olcum gurultusunun kovaryansi
constexpr double Q = 0.0;  // sabit sistem
constexpr int N = 50;

int main(int argc, char const *argv[]) {
    std::default_random_engine gen;
    std::normal_distribution<double> noise_dist(0.0, std::sqrt(R));

    KalmanFilter1D kf(Q, R);
    kf.init(20.0, 10.0);

    std::cout << std::fixed << std::setprecision(2) << std::endl;

    std::cout << "Gercek sicaklik: " << TRUE_TEMP << std::endl;

    for (int i = 0; i < N; i++) {
        double noisy = TRUE_TEMP + noise_dist(gen);

        kf.predict();
        kf.update(noisy);

        std::cout << "Ölçüm " << (i + 1) << ": " << noisy << " C -> Tahmin: " << kf.getEstimate()
                  << " C (Belirsizlik: " << kf.getUncertanty() << ")\n";
    }

    return 0;
}