#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

#include "tas.h"
#include "priorityQueue.h"
#include "chrono.h"

using namespace std;

int main()
{
    int tailles[] = {1000, 10000, 50000, 100000, 500000, 1000000};

    int repetitions = 10;

    mt19937 generateur(12345);
    uniform_int_distribution<int> distribution(1, 1000000);

    cout << fixed << setprecision(4);

    cout << "========== COMPARAISON TAS MAX ==========" << endl;

    for(int k = 0; k < 6; k++)
    {
        int n = tailles[k];

        // Generate values
        vector<int> valeurs(n);

        for(int i = 0; i < n; i++)
        {
            valeurs[i] = distribution(generateur);
        }

        double insertionTas = 0;
        double extractionTas = 0;
        double insertionPQ = 0;
        double extractionPQ = 0;

        // Repeat tests 10 times
        for(int r = 0; r < repetitions; r++)
        {
            Chrono c;

            // =================================
            // TAS MANUEL AVEC VECTOR
            // =================================

            Tas t;

            // Insertion
            c.demarrer();

            for(int i = 0; i < n; i++)
            {
                t.insertion(valeurs[i]);
            }

            insertionTas += c.arreter();

            // Extraction
            c.demarrer();

            for(int i = 0; i < n; i++)
            {
                t.extraction();
            }

            extractionTas += c.arreter();


            // =================================
            // PRIORITY QUEUE
            // =================================

            PriorityQueue pq;

            // Insertion
            c.demarrer();

            for(int i = 0; i < n; i++)
            {
                pq.insertion(valeurs[i]);
            }

            insertionPQ += c.arreter();

            // Extraction
            c.demarrer();

            for(int i = 0; i < n; i++)
            {
                pq.extraction();
            }

            extractionPQ += c.arreter();
        }

        // Calculate average
        insertionTas /= repetitions;
        extractionTas /= repetitions;
        insertionPQ /= repetitions;
        extractionPQ /= repetitions;

        // Display results
        cout << "\nNombre d'elements : " << n << endl;

        cout << "\nTAS avec vector :" << endl;
        cout << "Temps insertion  : " << insertionTas << " ms" << endl;
        cout << "Temps extraction : " << extractionTas << " ms" << endl;

        cout << "\nPriority Queue :" << endl;
        cout << "Temps insertion  : " << insertionPQ << " ms" << endl;
        cout << "Temps extraction : " << extractionPQ << " ms" << endl;

        cout << "\n----------------------------------------" << endl;
    }

    return 0;
}
