#pragma once

#include "Vec2i.hpp"
#include "spot.hpp"

#include <iostream>

/* Scrabble board */

struct Board {
  //default initialization of a scrabble board
  Board() ;

  //i/o to files
  void save(std::ostream& out) ;
  void load(std::istream& in) ;

  /** Largeur du plateau. */
  int getWidth() const
  { return 15;}

  /** Hauteur du plateau. */
  int getHeigth() const
  { return 15;}

  //access to the spots by coordinates
  Spot operator()(unsigned char l, unsigned char c) const;
  Spot& operator()(unsigned char l, unsigned char c);
  
  Spot operator()(Vec2i const& v_) const
  { return (*this)(v_.y, v_.x);}

  Spot& operator()(Vec2i const& v_)
  { return (*this)(v_.y, v_.x);}

  Spot at(int y_, int x_) const
  { return (*this)(y_, x_);}
  
  Spot& at(int y_, int x_)
  { return (*this)(y_, x_);}
  
  Spot at(Vec2i const& v_) const
  { return (*this)(v_);}
  
  Spot& at(Vec2i const& v_)
  { return (*this)(v_);}

  /** Renvoie true si le plateau est vide. */
  bool isEmpty() const
  {
    return this->at(this->getHeigth() / 2, this->getWidth() / 2).letter == 0;
  }

  //spots are public, and can therefore also be accessed b index
  Spot spots[225] ;  
} ;

//board display on the console
std::ostream& operator<<(std::ostream& out, const Board& b) ;
