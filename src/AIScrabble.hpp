/**
 * @file    LetterBag.hpp
 * @author  Yacine TAZDAIT, Raoufdine SAID
 * @date    03/03/2020
 *
 **/

#ifndef AISCRABBLE_HPP
#define AISCRABBLE_HPP

#include <vector>
#include <string>

#include "board.hpp"
#include "Gaddag.hpp"
#include "LetterOfPlayer.hpp"
#include "Vec2i.hpp"
#include "LetterPointTable.hpp"
#include "KicksInformation.hpp"
#include "Player.hpp"

/** Une IA de Scrabble. */
class AIScrabble : public Player
{
public:

    /**
     * @param gdg_  Le gaddag
     * @param ltp_  Table des point par lettre
     * @param brd_  Plateau
     * 
     * Constructeur par défaut.
     */
    AIScrabble(Gaddag const *gdg_, LetterBag* letterBag_,
               LetterPointTable const *ltp_, Board* brd_)
    :   Player(gdg_, letterBag_, ltp_, brd_)
    {   }

    /** Jouer.  */
    bool    play();

private:

    /** Echanger les lettres en mains avec d'autres du sac. */
    void exchangeLetter();

    /** Renvoie la liste de toutes les possibilités pour le coup suivant. */
    std::vector<KicksInformation> listAllPossibleKicks() const;

    /** Renvoie la meilleur possibilité pour le coup suivant. */
    KicksInformation bestPossibleKick() const;

    /** Liste de toutes les tuiles non vides. */
    std::vector<Vec2i> listAllNonEmptyTileCoord() const;

    /**
     * @param start_        Position de la lettre de départ
     * @param direction_    Direction (horizontal ou vertical)
     * 
     * Liste de toutes les possibilités à partir d'une lettre et vers une
     * direction.
     */
    std::vector<KicksInformation> listPossibleKicks(Vec2i const& start_,
                                                  e_direction direction_) const;

    /**
     * @param node_         Noeud actuelle sur le gaddag
     * @param start_        Position de la lettre de départ sur le plateau
     * @param letters_      lettres du joueurs qui ne sont pas encore utiliser
     * @param currentWord_  Le mot en cours de formation
     * @param current_      La position actuelle sur le plateau
     * @param step_x_       Pas horizontal
     * @param step_y_       Pas vertical
     * @param plus_used_    Le plus à t'il était utilisé?
     * 
     * Fonction récursive de liste de posibilité.
     */
    std::vector<std::string> listPossibleKicks(GaddagNode const* node_,
                                               Vec2i const& start_,
                                               std::string const& letters_,
                                               std::string const& currentWord_,
                                               Vec2i const& current_,
                                               int step_x_, int step_y_,
                                               bool plus_used_) const;

    /**
     * @param start_    Position de la lettre de départ pour la recherche
     * @param coord_    Position ou on veut savoir si on peut ajouter la lettre
     * @param l_        Lettre à verifier la possibilité d'ajout sur le plateau
     * 
     * Renvoie true si on peut placer la lettre sur la coordonnée sur le
     * plateau.
     */
    bool canPlaceLetterAt(e_direction direction_,
                          Vec2i const& coord_, char l_) const;
};

#endif /* AISCRABBLE_HPP */
