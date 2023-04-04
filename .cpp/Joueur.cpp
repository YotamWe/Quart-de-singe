#include "Joueur.h"
#include <iostream>

using namespace std;

/**
 * @brief Demande à l'utilisateur de saisir un caractère et l'ajoute au mot en cours de jeu.
 * @param m Un pointeur sur la structure MotDuJeu à mettre à jour.
 * @param j Un pointeur sur la structure Joueur à mettre à jour.
 */
void Humain(MotDuJeu &m, Joueur &j)
{
    char caractere;
    cin >> caractere;
    cin.ignore(INT_MAX, '\n'); // On ignore tout ce qui se trouve après le caractère saisi dans le buffer d'entrée
    ajouterLettre(m, j, caractere);
}

/**
 * @brief Propose une lettre et l'ajoute au mot en cours de jeu.
 * @param m Un pointeur sur la structure MotDuJeu à mettre à jour.
 * @param j Un pointeur sur la structure Joueur à mettre à jour.
 */
void Robot(MotDuJeu& m, Joueur& j)
{
    char caractere;

    // On appelle la fonction chercherLettre pour trouver une lettre à proposer
    cout << chercherLettre(m) << endl;
    // On ajoute la lettre proposée au mot en cours de jeu en appelant la fonction ajouterLettre
    ajouterLettre(m, j, chercherLettre(m));
}

/**
 * @brief Affiche le joueur qui doit jouer.
 *
 * @param j Un pointeur sur la structure Joueur contenant les informations sur les joueurs.
 */
void TourJoueur(Joueur& j)
{
    // On affiche le numéro du joueur qui doit jouer et son type (H pour humain, R pour robot)
    cout << j.RDJ + 1 << j.typeJ[j.RDJ];
}