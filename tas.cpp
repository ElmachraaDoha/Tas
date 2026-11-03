#include <iostream>
#include "tas.h"

void Tas::insertion(int valeur)
{
    // Add value at the end of the vector
    elements.push_back(valeur);

    // Get the index of the new element
    int i = elements.size() - 1;

    //find parent
    int ind_par = (i - 1)/2;

    //move new element if its bigger than parent
    while( i>0 && elements[i] > elements[ind_par] )
    {
        //exchange the child and the parent
           int temp          = elements[i] ;
           elements[i]       = elements[ind_par];
           elements[ind_par] = temp ;

        //update i
            i = ind_par;

        //recalculate the parent index
            ind_par = (i - 1)/2;
    }

}
int Tas::extraction()
{
    if(elements.empty())
    {
        throw runtime_error("TAS vide");
    }

    int root = elements[0];

    elements[0] = elements.back();

    elements.pop_back();

    int i = 0;

    while(i < elements.size())
    {
        int fg = 2 * i + 1;
        int fd = 2 * i + 2;

        int Max = i;

        if(fg < elements.size() && elements[fg] > elements[Max])
        {
            Max = fg;
        }

        if(fd < elements.size() && elements[fd] > elements[Max])
        {
            Max = fd;
        }

        if(Max == i)
        {
            break;
        }

        int temp = elements[i];
        elements[i] = elements[Max];
        elements[Max] = temp;

        i = Max;
    }

    return root;
}

void Tas::afficher()
{
    for(int i = 0; i < elements.size(); i++)
    {
        cout << elements[i] << " ";
    }

    cout << endl;
}

