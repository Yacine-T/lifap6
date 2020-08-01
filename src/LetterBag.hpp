/**
 * @file LetterBag.hpp
 * @author Yacine TAZDAIT, Raoufdine SAID
 * @date 19/02/2020
 *
 **/

#ifndef LETTERBAG_H
#define LETTERBAG_H

#include <vector>
#include <random>
#include <string>
#include <iostream>
#include <cassert>

/**
 * @param l_    Lettre
 * @param n_    Nombre de fois
 * 
 * Renvoie une chaine contenant n fois la lettre l_
 */
inline std::string mk_ltr(char l_, int n_)
{
    assert(n_ > 0);

    std::string s;

    while (n_--)
        s.push_back(l_);

    return (s);
}

/** Letter Bag class. */
class LetterBag
{
public:

    /** Constructeur par défaut : Initialise le sac avec les lettres du sujet du
     *  projet (scrabble Français). */
    LetterBag()
    :   LetterBag(
            mk_ltr('A', 9) + mk_ltr('B', 2) + mk_ltr('C', 2) + mk_ltr('D', 3) +
            mk_ltr('E', 15)+ mk_ltr('F', 2) + mk_ltr('G', 2) + mk_ltr('H', 2) +
            mk_ltr('I', 8) + mk_ltr('J', 1) + mk_ltr('K', 1) + mk_ltr('L', 5) +
            mk_ltr('M', 3) + mk_ltr('N', 6) + mk_ltr('O', 6) + mk_ltr('P', 2) +
            mk_ltr('Q', 3) + mk_ltr('R', 6) + mk_ltr('S', 6) + mk_ltr('T', 6) +
            mk_ltr('U', 6) + mk_ltr('V', 2) + mk_ltr('W', 1) + mk_ltr('X', 1) +
            mk_ltr('Y', 1) + mk_ltr('Z', 1) + mk_ltr(' ', 2)
        )
    {   }

    /**
     * @param lst_ Liste à ajouter dans le sac
     * 
     * Constructeur : Prend en paramètre la liste de lettre.
     */
    LetterBag(std::string const& lst_)
    {
        for (auto c : lst_)
            content.push_back(c);
    }

    /** Renvoie nombre de lettre dans le sac. */
    size_t  nbContent() const
    {   return (content.size());}

    /** Renvoie true si est vide. */
    bool    isEmpty() const
    {   return (nbContent() == 0);}

    /**
     * @param l_    Lettre à ajouter
     * 
     * Ajouter une lettre.
     */
    void    putLetter(char l_)
    {   this->content.push_back(l_);}

    /**
     * @param[out] l_   Lettre
     * 
     * Renvoie au hasard une lettre du sac et la retire du sac.
     */
    bool takeLetter(char& l_);

    /** Teste de regression. */
    static void test_regression();

private:
    std::vector<char> content;  ///< Contenu du sac.
};

#endif // LETTERBAG_H
