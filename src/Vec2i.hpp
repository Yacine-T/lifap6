/**
 * @file    LetterBag.hpp
 * @author  Yacine TAZDAIT, Raoufdine SAID
 * @date    03/03/2020
 *
 **/

#ifndef VEC2I_HPP
#define VEC2I_HPP

#include "spot.hpp"

/** Vecteur 2D d'entier. */
struct Vec2i
{
    /** Constructeur par défaut, initialise les coordonnées à 0. */
    Vec2i()
    : Vec2i(0, 0)
    {   }

    /** Constructeur avec coordonnée en paramètre. */
    Vec2i(int x_, int y_)
    : x(x_), y(y_)
    {   }

    int x,  ///< Coordonnée X du Vec2i
        y;  ///< Coordonnée Y du Vec2i
};

inline std::ostream& operator <<(std::ostream& out, Vec2i const& v_)
{
    return (out << v_.x << ", " << v_.y);
}

#endif /* VEC2I_HPP */
