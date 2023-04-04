#include <iostream>
#include <fstream>
#include <iomanip> // pour setw
#include <cstring>
using namespace std;

#include "affichageJeu.h"

/**
 * @brief Affiche l'indice et le type (humain ou robot) du joueur qui doit saisir le mot
 */
void demande(Joueur &j)
{
    if (j.RDJ == 0)
    {
        cout << j.nbJoueur << j.typeJ[j.nbJoueur - 1];
    }
    else
        cout << j.RDJ << j.typeJ[j.RDJ - 1];
    cout << ", saisir le mot > ";
}

/**
 * @brief Vérifie si le mot proposé par le joueur ne commence pas par les lettres attendues.
 * Si c'est le cas, met à jour le score du joueur précédent et retourne sa position dans le tableau des joueurs.
 *
 * @param tester : mot proposé par le joueur.
 * @param j : Le tableau des joueurs.
 * @return la position du joueur qui prend un quart de singe.
 */
unsigned int verifLettresEtMot(char tester[], Joueur &j)
{
    cout << "le mot " << tester << " ne commence pas par les lettres attendues, le joueur ";
    if (j.RDJ == 0)
    {
        cout << j.nbJoueur << j.typeJ[j.nbJoueur - 1] << " prend un quart de singe" << endl;
        return j.nbJoueur - 1;
    }
    else
    {
        cout << j.RDJ << j.typeJ[j.RDJ - 1] << " prend un quart de singe" << endl;
        return j.RDJ - 1;
    }
}

/**
 * @brief Affiche si le mot cherché existe dans le dictionnaire et affiche le joueur qui prend un quart de singe.
 * Retourne le rang du joueur qui doit prendre un quart de singe.
 *
 * @param[in] verif : Booléen indiquant si le mot cherché existe dans le dictionnaire.
 * @param[in] motCherchee : Mot cherché.
 * @return le rang du joueur qui doit prendre un quart de singe.
 */
unsigned int motTrouver(bool verif, char motCherchee[], Joueur &j)
{
    if (verif)
    {
        cout << "le mot " << motCherchee << " existe, le joueur " << j.RDJ + 1 << j.typeJ[j.RDJ] << " prend un quart de singe" << endl;
        return j.RDJ;
    }
    else
    {
        cout << "Le mot " << motCherchee << " n'existe pas, ";
        if (j.RDJ == 0)
        {
            cout << j.nbJoueur << j.typeJ[j.nbJoueur - 1] << " prend un quart de singe" << endl;
            return j.nbJoueur - 1;
        }
        else
        {
            cout << j.RDJ << j.typeJ[j.RDJ - 1] << " prend un quart de singe" << endl;
            return j.RDJ - 1;
        }
    }
}

/**
 * @brief Affiche un message indiquant que le joueur en cours d'exécution a abandonné la manche et prend un quart de singe.
 */
void abandon(Joueur &j)
{
    cout << "le joueur " << j.RDJ + 1 << j.typeJ[j.RDJ] << " abandonne la manche et prend un quart de singe" << endl;
}

/**
 * @brief réinitialise les champs de la structure MotDuJeu et met à jour l'indice du joueur qui doit jouer.
 *
 * @param m : Structure MotDuJeu contenant les informations sur le mot en cours de jeu.
 * @param j : Structure Joueur contenant les informations sur les joueurs et leurs scores.
 * @param[in] rangQDS : indice du joueur qui doit jouer lors de la prochaine partie.
 */
void NouvellePartie(MotDuJeu &m, Joueur &j, unsigned int rangQDS)
{
    delete[] m.mot;
    delete[] m.motRobotChoisi;
    InitMots(m);
    j.RDJ = rangQDS;
}

/**
 * @brief Mise à jour du nombre de quart de singe possédé par chaque joueur et affichage du score.
 * @param m : Structure MotDuJeu contenant les informations sur le mot en cours de jeu.
 * @param j : Structure Joueur contenant les informations sur les joueurs et leurs scores.
 * @param[in] rangQDS : Rang du joueur qui vient de prendre un quart de singe.
 */
void comptageQds(MotDuJeu &m, Joueur &j, unsigned int rangQDS) // rangQDS = position de la personne qui prend un quart de singe
{
    // Mise à jour du nombre de quart de singe possédé par le joueur qui vient de prendre un quart de singe
    j.quartDeSinge[rangQDS] += 0.25;
    // Affichage du score de chaque joueur
    for (unsigned int k = 0; k < j.nbJoueur; k++)
    {
        cout << k + 1 << j.typeJ[k] << " : " << j.quartDeSinge[k];
        if (k < j.nbJoueur - 1)
        {
            cout << "; ";
        }
    }
    cout << endl;
    // Si un joueur possède 4 quart de singe, la partie est terminée et le programme s'arrête
    for (unsigned int k = 0; k < j.nbJoueur; k++)
    {
        if (j.quartDeSinge[k] >= 1.)
        {
            cout << "La partie est finie" << endl;
            exit(0);
        }
    }
    // Réinitialisation des champs de la structure MotDuJeu et mise à jour de l'indice du joueur qui doit jouer
    NouvellePartie(m, j, rangQDS);
}
