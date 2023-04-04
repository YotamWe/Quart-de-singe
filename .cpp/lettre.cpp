#include "lettre.h"


#include <iostream>
#include <fstream>
#include <iomanip> // pour setw
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;




/**
 * @brief renvoie l'indice du joueur qui doit jouer.
 *
 * @param j
 * @return l'indice du joueur précédent ou l'indice du dernier joueur si RDJ est égal à 0
 */
unsigned int RDJ(Joueur &j)
{
    if (j.RDJ == 0)
    {
        return j.nbJoueur - 1;
    }
    else
        return j.RDJ - 1;
}

/**
 * @brief Traite les entrées de l'utilisateur lorsque le joueur courant saisit un '?' ou un '!'.
 *
 * @param entree : caractère saisi par l'utilisateur (doit être soit '?', soit '!').
 * @param m : Un pointeur sur la structure MotDuJeu contenant les informations sur le mot en cours de jeu.
 * @param j : Un pointeur sur la structure Joueur contenant les informations sur les joueurs.
 */
void traitementEntreeSpeciale(char entree, MotDuJeu &m, Joueur &j)
{
    switch (entree)
    {
    case '?':
        char test[MAX_CHAR];
        demande(j);
        switch (j.typeJ[RDJ(j)])
        {
        case 'H':
            cin >> test;
            break;
        case 'R':
            cout << m.motRobotChoisi << endl;
            strcpy(test, m.motRobotChoisi);
            break;
        }
        for (unsigned int j = 0; j < strlen(test); j++)
        {
            test[j] = toupper(test[j]);
        }

        for (unsigned int i = 0; i < m.nbLettres; i++)
        {
            if (test[i] != m.mot[i])
            {
                comptageQds(m, j, verifLettresEtMot(test, j));
                return;
            }
        }
        comptageQds(m, j, motTrouver(comparerMot(test), test, j));
        break;

    case '!':
        abandon(j);
        comptageQds(m, j, j.RDJ);
        break;
    }
}


/**
 * @brief Cherche une lettre adéquat pour le robot.
 * Si le mot n'a pas encore de lettre, le robot choisit une lettre au hasard parmi l'alphabet.
 * @param m
 * @return char
 */
char chercherLettre(MotDuJeu &m)
{
    if (m.nbLettres == 0)
    {
        srand(time(NULL));
        char lettreAlea = 'A' + rand() % 26;
        return lettreAlea;
    }
    else
    {
        ifstream dictionnaire("ods4.txt"); // on ouvre le fichier
        if (!dictionnaire)
        {
            cout << "le dictionnaire n'a pu etre ouvert" << endl;
            return false;
        }
        char motDico[MAX_CHAR];
        char motT[MAX_CHAR] = "\0";
        bool verif;
        while (dictionnaire)
        {
            dictionnaire >> setw(MAX_CHAR) >> motDico; // on essaye de lire le premier mot
            verif = true;

            for (unsigned int i = 0; i < m.nbLettres; i++)
            {
                if (motDico[i] != m.mot[i])
                {
                    verif = false;
                    break;
                }
            }
            if (verif && (m.nbLettres + 1 < strlen(motDico)))
            {
                for (int i = 0; i < m.nbLettres + 1; i++)
                {
                    motT[i] = motDico[i];
                }
                if (!comparerMot(motT) || (comparerMot(motT) && strlen(motT) <= 2))
                {
                    strcpy(m.motRobotChoisi, motDico);
                    dictionnaire.close();
                    return motDico[m.nbLettres];
                }
            }
        }
        if (!verif)
        {
            return '?';
        }
    }
}

/**
 * @brief Ajoute un caractère au mot en cours de jeu.
 * Appelle la fonction qui met à jour le score du joueur et l'indice du joueur qui doit jouer.
 * @param m : Un pointeur sur la structure MotDuJeu à mettre à jour.
 * @param j : Un pointeur sur la structure Joueur à mettre à jour.
 * @param caractere : caractère à ajouter au mot en cours de jeu.
 */
void ajouterLettre(MotDuJeu &m, Joueur &j, char caractere)
{
    // Si le caractère saisi est un '?' ou un '!', on appelle la fonction traitementEntree
    if (caractere == '?' || caractere == '!')
    {
        traitementEntreeSpeciale(caractere, m, j);
    }
    // Sinon, on ajoute le caractère au mot en cours de jeu et on incrémente le nombre de lettres du mot
    else
    {
        caractere = toupper(caractere); // on convertit le caractère en majuscule
        m.mot[m.nbLettres] = caractere;
        m.nbLettres++;
        // Si le mot en cours de jeu a au moins 3 lettres, on vérifie s'il existe en comparant avec le dictionnaire
        if (m.nbLettres > 2)
        {
            if (comparerMot(m.mot))
            {
                // Si le mot existe, on met à jour le score du joueur et on décrémente l'indice du joueur qui doit jouer
                comptageQds(m, j, motTrouver(comparerMot(m.mot), m.mot, j));
                j.RDJ--;
            }
        }
        j.RDJ++; // On incrémente l'indice du joueur qui doit jouer
    }
}
