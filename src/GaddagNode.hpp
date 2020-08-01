/**
 * @file LetterBag.hpp
 * @author Yacine TAZDAIT, Raoufdine SAID
 * @date 01/03/2020
 *
 **/

#ifndef GADDAGNODE_HPP
#define GADDAGNODE_HPP

#include <algorithm>
#include <iostream>
#include <array>
#include <cassert>

/** Noeud d'un Gaddag. */
class GaddagNode
{
public:

    /** Constructeur par défaut. */
    GaddagNode();

    /** Destructeur */
    virtual ~GaddagNode();

    /**
     * Si le noeud est terminal alors la fonction renvoie true sinon false
     */
    bool isTerminal() const
    {   return (is_terminal);}

    /**
     * @param l_    lettre
     * 
     * Renvoie le noeud fils corréspondant à la lettre, renvoie nullptr si il
     * n'y a pas de noeud fils associer.
     */
    GaddagNode* getChild(char l_);

    /**
     * @param l_    lettre
     * 
     * Renvoie le noeud fils corréspondant à la lettre, renvoie nullptr si il
     * n'y a pas de noeud fils associer.
     */
    GaddagNode const* getChild(char l_) const;

    /**
     * @param l_    lettre
     * 
     * Ajouter un noeud fils corréspondant à une lettre
     */
    GaddagNode * newChild(char l_);

    /** Spécifie si un noeud est terminal ou pas. */
    void setTerminal(bool is_terminal_)
    {   is_terminal = is_terminal_;}

private:
    bool                        is_terminal;///< Le noeud est terminal
    std::array<GaddagNode*, 27> childs;     ///< fils 27 ème +
};

#endif /* GADDAGNODE_HPP */
