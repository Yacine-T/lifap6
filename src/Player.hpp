/**
 * @file    Player.hpp
 * @author  Yacine TAZDAIT, Raoufdine SAID
 * @date    22/03/2020
 *
 **/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

#include "LetterOfPlayer.hpp"
#include "Gaddag.hpp"
#include "LetterPointTable.hpp"
#include "board.hpp"
#include "LetterBag.hpp"
#include "KicksInformation.hpp"

/** Joueur. */
class Player
{
public:

    /**
     * @param gdg_  Le gaddag
     * @param lbg_  Sac de lettres
     * @param ltp_  Tableau du nombre de point par lettre
     * @param brd_  Le plateau
     * 
     * Constructeur avec gaddag, tableau de nombre de point par lettre et
     * plateau en paramètre.
     */
    Player(Gaddag const *gdg_, LetterBag* letterBag_,
           LetterPointTable const *ltp_, Board* brd_)
    :   gaddag(gdg_), letterBag(letterBag_), letterPointTable(ltp_),
        board(brd_), score(0)
    {   }

    /** Obtenir le gaddag. */
    Gaddag const* getGaddag() const
    {   return (this->gaddag);}

    /**
     * @param c_    Lettre à obtenir les points
     * 
     * Obtenir le nombre de point pour une lettre.
     */
    int getPointOfLetter(char c_) const
    {   return (letterPointTable->getPointOf(c_));}

    /** Obtenir le plateau. */
    Board* getBoard()
    {   return (board);}

    /** Obtenir le plateau. */
    Board const* getBoard() const
    {   return (board);}

    /** Renvoie les lettres en pocession du joueur. */
    LetterOfPlayer const& getLetterOfPlayer() const
    {   return (letterOfPlayer);}

    /** Renvoie les lettres en pocession du joueur. */
    LetterOfPlayer& getLetterOfPlayer()
    {   return (letterOfPlayer);}

    /**
     * @param lop_  Nouvelles lettres pour le joueur
     * 
     * Changer les lettres en pocession du joueur.
     */
    void setLetterOfPlayer(LetterOfPlayer const& lop_)
    {   this->letterOfPlayer = lop_;}

    /** Prendre des lettres depuis le sac. */
    void    takeLettersFromBag()
    {
        char    letter;

        while (this->letterOfPlayer.nbContent() < 7 &&
            this->letterBag->takeLetter(letter))
        {
            this->letterOfPlayer.add(letter);
        }
    }

    /**
     * @param kci_          Coup
     * @param lettersUsed_  Liste des lettres utiliser
     * 
     * Renvoie le score rapporter par un coup ainsi que la liste des lettres
     * utiliser.
     */
    int scoreOfKick(KicksInformation const& kci_,
                    std::string& lettersUsed_) const;

    /**
     * @param kci_   Coup
     * 
     * Renvoie le score rapporter par un coup ainsi que la liste des lettres
     * utiliser.
     */
    int scoreOfKick(KicksInformation const& kci_) const
    {
        std::string s;

        return (scoreOfKick(kci_, s));
    }

    /** Jouer un coup.   */
    bool    play(KicksInformation const& kiks_);

    /** Obtenir le score.   */
    int getScore() const
    {   return (score);}

    /** Obtenir le sac de lettre.   */
    LetterBag*  getLetterBag()
    {   return (letterBag);}

    /** Obtenir le sac de lettre.   */
    LetterBag const*  getLetterBag() const
    {   return (letterBag);}

private:

    Gaddag const*           gaddag;             ///< Le gaddag
    LetterBag*              letterBag;          ///< Sac de lettre
    LetterPointTable const* letterPointTable;   ///< Lettre du joueur
    Board*                  board;              ///< Le plateau
    LetterOfPlayer          letterOfPlayer;     ///< Lettre du joueur
    int                     score;              ///< Score
};

#endif /* PLAYER_HPP */
