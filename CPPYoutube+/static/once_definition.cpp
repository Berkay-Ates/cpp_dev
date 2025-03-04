#include <iostream>

void sayac()
{
    static int count = 0; // İlk çağrıda oluşturulur, diğer çağrılarda aynı değişken kullanılır.
    count++;
    std::cout << "Sayac: " << count << std::endl;
}

int main()
{
    sayac();
    sayac();
    sayac();
    return 0;
}
