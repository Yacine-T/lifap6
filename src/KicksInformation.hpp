/**
 * @file    KicksInformation.hpp
 * @author  Yacine TAZDAIT, Raoufdine SAID
 * @date    22/03/2020
 *
 **/

#ifndef KICKSINFORMATION_H
#define KICKSINFORMATION_H

#include <vector>
#include <string>
#include <iostream>

#include "Vec2i.hpp"

/** Ensemble des directions possibles sur un plateau de scrabble */
enum class e_direction : int
{
    horizontal, ///< Horizontal
    vertical    ///< Vertical
};

inline std::ostream& operator<<(std::ostream& os_, e_direction const& d_)
{
    return (os_ << (d_ == e_direction::horizontal ? "horizontal" : "vertical"));
}

/** Informations d'un coup au scrabble */
struct KicksInformation
{
    std::string word;   ///< Mot
    Vec2i       coord;  ///< Coordonnées du mot
    e_direction d;      ///< Direction

    /**
     * @param word_     Mot du coup
     * @param coord_    Coordonnée initiale du mot
     * @param d_        Direction ou placer le mot
     * 
     * Constructeur avec tous en paramètres.
     */
    KicksInformation(std::string const& word_, Vec2i const& coord_, 
                     e_direction d_);

    /** Constructeur par défaut. */
    KicksInformation()
    {   }

    /** Renvoie une version formater de l'objet actuelle (format canonique). */
    KicksInformation format() const;
};

#endif /* KICKSINFORMATION_H */
