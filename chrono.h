#ifndef CHRONO_H
#define CHRONO_H

#include <chrono>

class Chrono
{
private:
    std::chrono::high_resolution_clock::time_point debut;

public:
    void demarrer();
    double arreter();
};

#endif
