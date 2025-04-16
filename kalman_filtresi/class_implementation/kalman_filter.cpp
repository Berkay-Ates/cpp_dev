#pragma once

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

class KalmanFilter1D {
   private:
    double x;  // Tahmin
    double P;  // Belirsizlik
    double Q;  // Sistem Gurultusu kovaryansi
    double R;  // Olcum Gurultusu Kovaryansi

   public:
    KalmanFilter1D(double Q = 0, double R = 4.0) : Q(Q), R(R), x(0.0), P(1.0) {}

    void init(double x0, double P0) {
        x = x0;
        P = P0;
    }

    void predict() {
        // sabit sistem oldugu icin X degismiyor
        P += Q;
    }

    void update(double z) {
        double K = P / (P + R);
        x = x + K * (z - x);
        K = (1 - K) * P;
    }
    double getEstimate() const { return x; }
    double getUncertanty() const { return P; }
};
