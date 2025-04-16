#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <unordered_map>
#include <vector>

using namespace std;

typedef std::int16_t berkay16;

class Device {};

class DeviceManager {
   private:
    std::unordered_map<std::string, std::vector<Device *>> m_Devices;

   public:
    const std::unordered_map<std::string, std::vector<Device *>> &getDevices() const {
        return m_Devices;
    }
};

int main(int argc, char const *argv[]) {
    std::vector<std::string> items;
    items.push_back("Apple");
    items.push_back("Orange");

    for (std::vector<std::string>::iterator it = items.begin(); it != items.end(); it++) {
        std::cout << *it << std::endl;
    }

    using DeviceMAP = std::unordered_map<std::string, std::vector<Device *>>;
    typedef std::unordered_map<std::string, std::vector<Device *>> typedefDeviceMap;

    DeviceManager dm;
    std::unordered_map<std::string, std::vector<Device *>> devices = dm.getDevices();
    DeviceMAP shortenDeviceMap = dm.getDevices();

    cout << sizeof(berkay16) << endl;

    return 0;
}