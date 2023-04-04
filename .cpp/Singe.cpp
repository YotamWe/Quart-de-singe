#include "Jeu.h"

#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;

int main(int argc, char **argv)
{
    Joueur j;
    MotDuJeu m;
    if (argc >= 2)
    {
        Jeu(argv[1], j, m);
    }
    else
        cout << "Veuillez rentrer le nombre et le type de joueurs ( ex : HRHR)" << endl;
}
