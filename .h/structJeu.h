#ifndef _STRUCTJEU_
#define _STRUCTJEU_

const int MAX_CHAR = 26;
#define INT_MAX 2147483647

/**
 * @brief Représente un joueur du jeu du quart de singe.
 *
 * Un joueur est caractérisé par son nombre, son type (humain ou robot), son score et son tour de jeu.
 */
struct Joueur
{
    /**
     * @brief Nombre de joueurs.
     *
     * Cette valeur est déterminée lors de l'initialisation du jeu.
     */
    int nbJoueur;

    /**
     * @brief Score de chaque joueur.
     *
     * Cette valeur est mise à jour au cours de la partie en fonction des mots trouvés.
     */
    float *quartDeSinge;

    /**
     * @brief Type de chaque joueur.
     *
     * Cette valeur peut être 'H' pour Humain ou 'R' pour Robot. Elle est déterminée lors de l'initialisation du jeu.
     */
    char typeJ[MAX_CHAR];

    /**
     * @brief Indice du joueur qui doit jouer.
     *
     * Cette valeur est mise à jour au cours de la partie et permet de déterminer quel joueur doit jouer à chaque tour.
     */
    unsigned int RDJ;
};

/**
 * @brief Représente le mot en cours de jeu et son état de découverte.
 *
 * Le mot en cours de jeu est représenté par un tableau de caractères et son état de découverte par le nombre de lettres découvertes.
 * Si le joueur est un robot, le mot choisi par le robot est également stocké.
 */
struct MotDuJeu
{
    /**
     * @brief Mot en cours de jeu.
     *
     * Cette valeur est mise à jour au cours de la partie en fonction des lettres proposées par les joueurs.
     */
    char *mot;

    /**
     * @brief Nombre de lettres du mot découvertes.
     *
     * Cette valeur est mise à jour au cours de la partie en fonction des lettres proposées par les joueurs.
     */
    unsigned int nbLettres;

    /**
     * @brief Mot choisi par le robot.
     *
     * Cette valeur est déterminée lorsque le joueur est un robot et est utilisée lorsque le joueur humain demande à voir le mot choisi par le robot.
     */
    char *motRobotChoisi;
};

#endif