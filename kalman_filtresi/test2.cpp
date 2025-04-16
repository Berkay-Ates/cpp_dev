#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

constexpr double true_temperature = 25.0;
constexpr int num_measurements = 50;
constexpr double measurement_noise_stddev = 2.0;

int main() {
    std::default_random_engine generator;
    std::normal_distribution<double> noise_dist(0.0, measurement_noise_stddev);

    std::vector<double> measurements;
    double cumulative_sum = 0.0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Gerçek sicaklik: " << true_temperature << " C\n\n";

    for (int i = 0; i < num_measurements; ++i) {
        double noise = noise_dist(generator);
        double measured_temp = true_temperature + noise;
        cumulative_sum += measured_temp;
        measurements.push_back(measured_temp);

        double running_average = cumulative_sum / (i + 1);

        std::cout << "Olcum " << (i + 1) << ": " << measured_temp
                  << " C  → Ortalama Tahmin: " << running_average << " C\n";
    }

    return 0;
}
