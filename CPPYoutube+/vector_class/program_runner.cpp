#include <iostream>
#include <chrono>
#include <cstdlib> // system() için

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    // Çalıştırılacak program (örnek: "notepad.exe")
    system("a.exe");

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Program çalıştırma süresi: " << duration.count() << " saniye" << std::endl;
    return 0;
}
