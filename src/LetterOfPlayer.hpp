/**
 * @file    LetterOfPlayer.h
 * @author  SAID Raoufdine
 * 
 * @date    29 février 2020, 15:59
 */

#ifndef LETTEROFPLAYER_H
#define LETTEROFPLAYER_H

#include <string>
#include <cassert>
#include <algorithm>
#include <vector>

/** Lettres du joueur. */
class LetterOfPlayer
{
public:

    /** Constructeur par défaut. */
    LetterOfPlayer()
    {   data.reserve(7);}

    /**
     * @param other_    Un autre objet de même classe
     * 
     * Constructeur par copie.
     */
    LetterOfPlayer(LetterOfPlayer const& other_)
    :   data(other_.data)
    {   }

    /**
     * @param str_  Chaine
     * 
     * Constructeur depuis une chaine.
     */
    LetterOfPlayer(std::string const& str_)
    :   data(str_)
    {   assert(str_.size() <= 7);}

    /** Nombre d'élements. */
    size_t  nbContent() const
    {   return (data.size());}

    /** Renvoie true si est vide. */
    bool isEmpty() const
    {   return (nbContent() == 0);}

    /**
     * @param id_   Indice
     * 
     * Accées à une lettre, ne l'enlève pas.
     */
    char check(size_t id_) const
    {
        assert(id_ < nbContent());

        return (data[id_]);
    }

    /** Obtenir la liste de toutes les lettres. */
    std::string const& getListOfLetters() const
    {   return (data);}

    /** Accées operateur []. */
    bool operator[](size_t id_) const
    {   return (check(id_));}

    /** Enlever une lettre. */
    bool remove(char l_);

    /** Ajouter une lettre si possible, renvoie true si ok. */
    bool add(char l_);

    /** Iterateur sur le début. */
    std::string::iterator begin()
    {   return (data.begin());}

    /** Iterateur sur le début. */
    std::string::const_iterator begin() const
    {   return (data.begin());}

    /** Iterateur sur la fin. */
    std::string::iterator end()
    {   return (data.end());}

    /** Iterateur sur la fin. */
    std::string::const_iterator end() const
    {   return (data.end());}

    /** Teste de regression. */
    static void test_regression();

private:

    std::string   data;   ///< Lettre du joueur
};

#endif /* LETTEROFPLAYER_H */
