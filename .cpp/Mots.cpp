#include "Mots.h"

#include <iostream>
#include <fstream>
#include <iomanip> // pour setw
#include <cstring>
using namespace std;

/**
 * @brief Initialise les champs de la structure MotDuJeu en allouant de l'espace mémoire pour le mot
 * et le mot choisi par le robot, et en initialisant le nombre de lettres à 0
 *
 * @param m
 */
void InitMots(MotDuJeu &m)
{
    m.mot = new char[MAX_CHAR];
    m.motRobotChoisi = new char[MAX_CHAR];
    m.nbLettres = 0;
    for (unsigned int i = 0; i < MAX_CHAR; i++)
    {
        m.mot[i] = 0;
    }
}

/**
 * @brief vérifie si le mot passé en paramètre est présent dans un dictionnaire de mots stocké dans un fichier texte.
 * @param[in] motATester
 * @return true si le mot est présent, false sinon
 */
bool comparerMot(char motATester[])
{
    ifstream dictionnaire("ods4.txt"); // on ouvre le fichier
    if (!dictionnaire)
    {
        cout << "le dictionnaire n'a pu etre ouvert" << endl;
        return false;
    }

    bool verif = false;
    char motDico[MAX_CHAR];
    dictionnaire >> setw(MAX_CHAR) >> motDico; // on essaye de lire le premier mot
    while (dictionnaire)
    {
        if (strcmp(motDico, motATester) == 0)
        {
            verif = true;
            break;
        }
        else
            dictionnaire >> setw(MAX_CHAR) >> motDico;
    }
    dictionnaire.close();
    return verif;
}

/**
 * @brief affiche le mot en cours de jeu (c'est-à-dire le mot avec les lettres déjà proposées).
 *
 * @param m
 * @param j
 */
void affichageMot(MotDuJeu &m, Joueur &j)
{
    cout << ", (";
    for (unsigned int j = 0; j < m.nbLettres; j++)
    {
        cout << m.mot[j];
    }
    cout << ") > ";
}