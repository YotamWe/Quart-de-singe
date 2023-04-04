#ifndef _JEU_
#define _JEU_


#include "Mots.h"
#include "Joueur.h"

/**
 * @brief initialise les champs de la structure MotDuJeu et de la structure Joueur.
 * Copie le type de joueur (humain ou robot) dans le champ typeJ de la structure Joueur,
 * initialise le nombre de joueurs à la longueur de typeJoueur,
 * initialise le nombre de lettres à 0 et alloue de l'espace mémoire pour le tableau quartDeSinge de la structure Joueur.
 * @param[out] p : la pile à initialiser
 * @param[in] typeJoueur : type de joueur (humain ou robot)
 */
void InitJeu(MotDuJeu &m, Joueur &j, char typeJoueur[]);

/**
 * @brief fonction principale du jeu.
 * Gère la boucle de jeu en appelant les fonctions précédemment décrites au fur et à mesure de l'avancée du jeu.
 * S'arrête lorsque l'un des joueurs a trouvé le mot ou lorsque tous les mots du dictionnaire ont été proposés.
 *
 * @param typeJoueur
 * @param j
 * @param m
 */
void Jeu(char typeJoueur[], Joueur &j, MotDuJeu &m);

#endif /*_JEU_*/
