#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <queue>

using namespace std;

class PriorityQueue
{
private:
    priority_queue<int> elements;

public:
    void insertion(int valeur);
    int extraction();
    int sommet();
    bool vide();
};

#endif
