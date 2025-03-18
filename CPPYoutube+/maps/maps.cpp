#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <map>
#include <thread>
#include <unordered_map>
#include <vector>

struct CityRecord {
    std::string Name;
    uint64_t Population;
    double Latitute, Longitude;

    bool operator<(const CityRecord other) const { return Population < other.Population; }
};

namespace std {
template <>
struct hash<CityRecord> {
    size_t operator()(const CityRecord &key) { return hash<std::string>()(key.Name); }
};
}  // namespace std

int main(int argc, char const *argv[]) {
    // std::vector<CityRecord> cities;
    // cities.emplace_back("Melborne", 3000, 2.4, 9.4);
    // cities.emplace_back("Lol-Town", 3000, 2.4, 9.4);
    // cities.emplace_back("Berlin", 3000, 2.4, 9.4);
    // cities.emplace_back("Paris", 3000, 2.4, 9.4);
    // cities.emplace_back("London", 3000, 2.4, 9.4);

    // for (const auto &city : cities) {
    //     if (city.Name == "Berlin") {
    //         city.Population;
    //         break;
    //     }
    // }

    // std::map<std::string, CityRecord> cityMap;

    // cityMap["Melborne"] = CityRecord{"Melborne", 3000, 2.4, 9.4};
    // cityMap["Lol-Town"] = CityRecord{"Lol-Town", 3000, 2.4, 9.4};
    // cityMap["Berlin"] = CityRecord{"Berlin", 3000, 2.4, 9.4};
    // cityMap["Paris"] = CityRecord{"Paris", 3000, 2.4, 9.4};
    // cityMap["London"] = CityRecord{"London", 3000, 2.4, 9.4};

    // CityRecord &berlinData = cityMap["Berlin"];
    // berlinData.Population;

    std::unordered_map<CityRecord, uint32_t> foundMap;

    std::unordered_map<std::string, CityRecord> cityMap;
    cityMap["melborne"] = CityRecord{"Melborne", 3000, 2.4, 9.4};
    cityMap["Lol-Town"] = CityRecord{"Lol-Town", 4000, 2.4, 9.4};
    cityMap["Berlin"] = CityRecord{"Berlin", 5000, 2.4, 9.4};
    cityMap["Paris"] = CityRecord{"Paris", 6000, 2.4, 9.4};
    cityMap["London"] = CityRecord{"London", 7000, 2.4, 9.4};

    std::map<CityRecord, uint32_t> cityFounded;
    cityFounded[CityRecord{"Melborne", 3000, 2.4, 9.4}];
    cityFounded[CityRecord{"Lol-Town", 4000, 2.4, 9.4}];
    cityFounded[CityRecord{"Berlin", 5000, 2.4, 9.4}];
    cityFounded[CityRecord{"Paris", 6000, 2.4, 9.4}];
    cityFounded[CityRecord{"London", 7000, 2.4, 9.4}];

    CityRecord &berlinData = cityMap["Berlin"];
    berlinData.Population;

    cityMap.erase("Paris");

    const auto &cities = cityMap;
    if (cities.find("Berlin") != cities.end()) {
        const CityRecord &berlinData = cities.at("Berlin");
        // berlinData.Name = "Berlin";
        // berlinData.Population = 5;
    }

    for (auto &[key, city] : cityMap) {
        std::cout << key << "__" << city.Name << std::endl;

        cityFounded[city] = 0;
    }

    std::cout << " =========== " << std::endl;

    for (auto &[city, founded] : cityFounded) {
        std::cout << city.Name << " " << city.Population << " " << founded << std::endl;
    }

    return 0;
}