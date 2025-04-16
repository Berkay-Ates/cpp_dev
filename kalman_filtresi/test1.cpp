#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

// sabit sicaklik
constexpr double true_temperature = 25.0;

// olcum sayisi
constexpr int num_measurements = 50;

// olcum hatasinin standart sapmasi (gurultu seviyesi)
constexpr double measurement_noise_std_dev = 2.0;
int main(int argc, char const *argv[]) {
    // rastgele sayi uretici ve normal dagilim
    std::default_random_engine generator;
    std::normal_distribution<double> noise_dist(0.0, measurement_noise_std_dev);

    std::vector<double> measurements;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Gercek Sicaklik:" << true_temperature << std::endl;

    for (int i = 0; i < num_measurements; i++) {
        double noise = noise_dist(generator);
        double measured_temp = true_temperature + noise;
        measurements.push_back(measured_temp);

        std::cout << "Olcum: " << (i + 1) << " " << measured_temp << " hata: " << noise
                  << std::endl;
    }

    return 0;
}
