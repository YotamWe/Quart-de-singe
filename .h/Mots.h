#ifndef _MOTS_
#define _MOTS_


#include "structJeu.h"


/**
 * @brief Initialise les champs de la structure MotDuJeu en allouant de l'espace mémoire pour le mot
 * et le mot choisi par le robot, et en initialisant le nombre de lettres à 0
 *
 * @param m
 */
void InitMots(MotDuJeu &m);

/**
 * @brief vérifie si le mot passé en paramètre est présent dans un dictionnaire de mots stocké dans un fichier texte.
 * @param[in] motATester
 * @return true si le mot est présent, false sinon
 */
bool comparerMot(char motATester[]);

/**
 * @brief affiche le mot en cours de jeu (c'est-à-dire le mot avec les lettres déjà proposées).
 *
 * @param m
 * @param j
 */
void affichageMot(MotDuJeu &m, Joueur &j);

#endif