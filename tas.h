#ifndef TAS_H
#define TAS_H

#include <vector>

using namespace std;

class Tas
{
private:
    vector<int> elements;

public:
    void insertion(int valeur);
    int extraction();
    void afficher();
};

#endif
