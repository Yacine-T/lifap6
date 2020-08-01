/*
 * @file LetterBag.hpp
 * @author Yacine TAZDAIT, Raoufdine SAID
 * @date 22/03/2020
 *
 **/

#include "KicksInformation.hpp"

KicksInformation::KicksInformation(const std::string& word_,
                                   const Vec2i& coord_, e_direction d_)
:   word(word_), coord(coord_), d(d_)
{   }

KicksInformation KicksInformation::format() const
{
    auto itPlus = this->word.begin();

    //  Trouver le plus
    while (itPlus != this->word.end() && *itPlus != '+')
        ++itPlus;

    if (itPlus == this->word.end())
        return (*this);

    KicksInformation res = *this;
    int const delta = itPlus - this->word.begin();

    //  Recalcul des coordonnées
    if (res.d == e_direction::horizontal)
        res.coord.x -= delta - 1;
    else    //  vertical
        res.coord.y -= delta - 1;

    res.word.clear();

    //  Remise dans l'ordre des lettres et suppression du +
    for (auto i = delta - 1; i >= 0; --i)
        res.word.push_back(this->word[i]);

    for (auto it = itPlus + 1; it<this->word.end(); ++it)
        res.word.push_back(*it);

    return (res);
}
