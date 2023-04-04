#ifndef _AFFICHAGEJEU_
#define _AFFICHAGEJEU_

#include "Mots.h"

/**
 * @brief Affiche l'indice et le type (humain ou robot) du joueur qui doit saisir le mot
 */
void demande(Joueur& j);

/**
 * @brief Vérifie si le mot proposé par le joueur ne commence pas par les lettres attendues.
 * Si c'est le cas, met à jour le score du joueur précédent et retourne sa position dans le tableau des joueurs.
 *
 * @param tester : mot proposé par le joueur.
 * @param j Le tableau des joueurs.
 * @return la position du joueur qui prend un quart de singe.
 */
unsigned int verifLettresEtMot(char tester[], Joueur& j);

/**
 * @brief Affiche si le mot cherché existe dans le dictionnaire et affiche le joueur qui prend un quart de singe.
 * Retourne le rang du joueur qui doit prendre un quart de singe.
 *
 * @param[in] verif : Booléen indiquant si le mot cherché existe dans le dictionnaire.
 * @param[in] motCherchee : Mot cherché.
 * @return le rang du joueur qui doit prendre un quart de singe.
 */
unsigned int motTrouver(bool verif, char motCherchee[], Joueur& j);

/**
 * @brief Affiche un message indiquant que le joueur en cours d'exécution a abandonné la manche et prend un quart de singe.
 */
void abandon(Joueur& j);

/**
 * @brief Mise à jour du nombre de quart de singe possédé par chaque joueur et affichage du score.
 * @param m Structure MotDuJeu contenant les informations sur le mot en cours de jeu.
 * @param j Structure Joueur contenant les informations sur les joueurs et leurs scores.
 * @param[in] rangQDS : Rang du joueur qui vient de prendre un quart de singe.
 */
void comptageQds(MotDuJeu& m, Joueur& j, unsigned int rangQDS);

/**
 * @brief réinitialise les champs de la structure MotDuJeu et met à jour l'indice du joueur qui doit jouer.
 *
 * @param m
 * @param j
 * @param[in] rangQDS : indice du joueur qui doit jouer lors de la prochaine partie.
 */
void NouvellePartie(MotDuJeu& m, Joueur& j, unsigned int rangQDS);

#endif