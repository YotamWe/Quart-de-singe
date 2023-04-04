#ifndef _JOUEUR_
#define _JOUEUR_


#include "lettre.h"

/**
 * @brief Demande à l'utilisateur de saisir un caractère et l'ajoute au mot en cours de jeu.
 * @param m Un pointeur sur la structure MotDuJeu à mettre à jour.
 * @param j Un pointeur sur la structure Joueur à mettre à jour.
 */
void Humain(MotDuJeu &m, Joueur &j);

/**
 * @brief Propose une lettre et l'ajoute au mot en cours de jeu.
 * @param m Un pointeur sur la structure MotDuJeu à mettre à jour.
 * @param j Un pointeur sur la structure Joueur à mettre à jour.
 */
void Robot(MotDuJeu &m, Joueur &j);

/**
 * @brief Affiche le joueur qui doit jouer.
 *
 * @param j Un pointeur sur la structure Joueur contenant les informations sur les joueurs.
 */
void TourJoueur(Joueur &j);

#endif