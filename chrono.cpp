#include "chrono.h"

void Chrono::demarrer()
{
    debut = std::chrono::high_resolution_clock::now();
}

double Chrono::arreter()
{
    auto fin = std::chrono::high_resolution_clock::now();

    double temps = std::chrono::duration<double, std::milli>(fin - debut).count();

    return temps;
}
