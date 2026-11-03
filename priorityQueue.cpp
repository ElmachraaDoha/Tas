#include "priorityQueue.h"
#include <stdexcept>

void PriorityQueue::insertion(int valeur)
{
    elements.push(valeur);
}

int PriorityQueue::extraction()
{
    if(elements.empty())
    {
        throw runtime_error("Priority Queue vide");
    }

    int valeur = elements.top();

    elements.pop();

    return valeur;
}

int PriorityQueue::sommet()
{
    if(elements.empty())
    {
        throw runtime_error("Priority Queue vide");
    }

    return elements.top();
}

bool PriorityQueue::vide()
{
    return elements.empty();
}
