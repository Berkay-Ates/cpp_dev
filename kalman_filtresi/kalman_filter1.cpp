#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

constexpr double true_temperature = 25.0;
constexpr int num_measurements = 50;
constexpr double measurement_noise_stddev = 2.0;
constexpr double R =
    measurement_noise_stddev * measurement_noise_stddev;  // olcum gurultusu kovaryansi

int main(int argc, char const *argv[]) {
    std::default_random_engine generator;
    std::normal_distribution<double> noise_dist(0.0, measurement_noise_stddev);

    // kalman filtresi baslangic degeri
    double x_est = 20.0;  // ilk tahmin (ornegin kotu bir baslangic)
    double p = 10.0;      // ilk tahminin belirsizligi

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Gercek sicaklik: " << true_temperature << " C" << std::endl;

    for (int i = 0; i < num_measurements; i++) {
        // gurultulu olcum uret
        double noise = noise_dist(generator);
        double z = true_temperature + noise;

        // kalman kazanci
        double K = p / (p + R);

        // tahmini duzelt
        x_est = x_est + K * (z - x_est);

        // belirsizligi azalt
        p = (1 - K) * p;

        std::cout << "Olcum " << (i + 1) << ": " << z << "C -> Tahmin: " << x_est << "C Kazanc: -> "
                  << K << std::endl;
    }

    return 0;
}