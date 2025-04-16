#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

// bir veya daha fazla parametre alir. Nesneyi ozellestirilmis degerlerle baslatmak icin kullanilir

// cpp de en fazla kullanilan constructor turudur. Ozellikle donanim surucusu, kenel modulleri veya
// HAL siniflarinda spesifik register addreslerini veya konfigurasyonlari vermek icin kullanilir.

class Task {
    int id;

   public:
    Task(int id_) : id(id_) {}
};

int main(int argc, char const *argv[]) { return 0; }