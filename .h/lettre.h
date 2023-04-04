#ifndef _LETTRE_
#define _LETTRE_

#include "affichageJeu.h"


/**
 * @brief renvoie l'indice du joueur qui doit jouer.
 *
 * @param j
 * @return l'indice du joueur précédent ou l'indice du dernier joueur si RDJ est égal à 0
 */
unsigned int RDJ(Joueur &j);

/**
 * @brief Traite les entrées de l'utilisateur lorsque le joueur courant saisit un '?' ou un '!'.
 *
 * @param entree : caractère saisi par l'utilisateur (doit être soit '?', soit '!').
 * @param m Un pointeur sur la structure MotDuJeu contenant les informations sur le mot en cours de jeu.
 * @param j Un pointeur sur la structure Joueur contenant les informations sur les joueurs.
 */
void traitementEntreeSpeciale(char entree, MotDuJeu &m, Joueur &j);


/**
 * @brief Cherche une lettre adéquat pour le robot.
 * Si le mot n'a pas encore de lettre, le robot choisit une lettre au hasard parmi l'alphabet.
 * @param m
 * @return char
 */
char chercherLettre(MotDuJeu &m);

/**
 * @brief Ajoute un caractère au mot en cours de jeu.
 * Appelle la fonction qui met à jour le score du joueur et l'indice du joueur qui doit jouer.
 * @param m Un pointeur sur la structure MotDuJeu à mettre à jour.
 * @param j Un pointeur sur la structure Joueur à mettre à jour.
 * @param caractere : caractère à ajouter au mot en cours de jeu.
 */
void ajouterLettre(MotDuJeu &m, Joueur &j, char caractere);

#endif