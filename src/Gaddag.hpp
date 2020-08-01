/**
 * @file LetterBag.hpp
 * @author Yacine TAZDAIT, Raoufdine SAID
 * @date 01/03/2020
 *
 **/

#ifndef GADDAG_HPP
#define GADDAG_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "GaddagNode.hpp"

/** Un Gaddag. */
class Gaddag
{
public:

    /**
     * Constructeur par défaut.
     */
    Gaddag()
    {   }

    /**
     * @param is_   Flux d'entrée
     * 
     * Constructeur avec flux d'entrée en paramètre.
     */
    Gaddag(std::istream& is_)
    {   readStream(is_);}

    /**
     * @param file_ Nom de fichier
     * 
     * Constructeur avec nom de fichier en paramètre.
     */
    Gaddag(std::string const& file_);

    /** Racine du gaddag. */
    GaddagNode const&   getRoot() const
    {   return (root);}

    /**
     * @param word_ Mot à ajouter
     * 
     * Insert un nouveau mot dans le gaddag.
     */
    void insert(std::string const& word_);

    /**
     * @param word_ Mot
     * 
     * Renvoie le noeud corréspondant à la dernière lettre du mot en parcourant
     * le gaddag.
     */
    GaddagNode* find(std::string const& word_);

    /**
     * @param word_ Mot
     * 
     * Renvoie le noeud corréspondant à la dernière lettre du mot en parcourant
     * le gaddag.
     */
    GaddagNode const* find(std::string const& word_) const;

    /**
     * @param word_ Mot
     * 
     * Combinaison de tous les mots avec le plus 
     */
    void insertPlus(std::string const& word_);

private:

    /** Construit le gaddag à partir d'un flux d'entrée. */
    std::istream& readStream(std::istream& is_);

private:

    GaddagNode root;
};

#endif /* GADDAG_HPP */
