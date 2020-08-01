/*
 * @file    Player.hpp
 * @author  Yacine TAZDAIT, Raoufdine SAID
 * @date    22/03/2020
 *
 **/

#include "Player.hpp"

using namespace std;

bool Player::play(const KicksInformation& kiks_)
{
    string      lettersUsed;
    int const   delta_score = this->scoreOfKick(kiks_, lettersUsed);

    if (delta_score <= 0)
        return (false);

    //  Simuler un dépot des lettres sur le board
    for (char letter : lettersUsed)
    {
        if (!this->getLetterOfPlayer().remove(letter))
        {
            if (!this->getLetterOfPlayer().remove(' '))
            {
                this->setLetterOfPlayer(letterOfPlayer);

                return (false);
            }
        }
    }

    KicksInformation const formatedKick = kiks_.format();
    int const   step_x = (kiks_.d == e_direction::horizontal ? 1 : 0),
                step_y = (kiks_.d == e_direction::vertical ? 1 : 0);

    Vec2i       v = formatedKick.coord;
    unsigned    i = 0;

    while (v.x < this->getBoard()->getWidth() &&
           v.y < this->getBoard()->getHeigth() && i < formatedKick.word.size())
    {
        this->getBoard()->at(v).letter = formatedKick.word[i];

        v.x += step_x;
        v.y += step_y;
        ++i;
    }

    score += delta_score;

    return (true);
}

int Player::scoreOfKick(const KicksInformation& kci, string& lettersUsed_) const
{
    KicksInformation const  kcif = kci.format();
    Vec2i                   pos = kcif.coord;
    int                     score = 0;
    int                     bonus_word = 1;
    int                     score_total_perpendicular = 0;

    lettersUsed_.clear();

    for (auto const l : kcif.word)
    {
        //  On va ajouter cette lettre
        if (this->getBoard()->at(pos).letter == 0)
        {
            int perpendicular_score = 0;

            lettersUsed_.push_back(l);

            score += this->getBoard()->at(pos).bonus.letter_factor *
                                                    this->getPointOfLetter(l);
            bonus_word *= this->getBoard()->at(pos).bonus.word_factor;

            if (kcif.d == e_direction::horizontal)
            {
                for (int y = pos.y - 1;
                           y >= 0 && this->getBoard()->at(y, pos.x).letter; y--)
                {
                    perpendicular_score += this->getPointOfLetter(
                                        this->getBoard()->at(y, pos.x).letter);
                }

                for (int y = pos.y + 1;
                        y < this->getBoard()->getHeigth() &&
                                    this->getBoard()->at(y, pos.x).letter; y++)
                {
                    perpendicular_score += this->getPointOfLetter(
                                        this->getBoard()->at(y, pos.x).letter);
                }
            }

            if (kcif.d == e_direction::vertical)
            {
                for (int x = pos.x - 1;
                        x >= 0 && this->getBoard()->at(pos.y, x).letter; x--)
                {
                    perpendicular_score += this->getPointOfLetter(
                                        this->getBoard()->at(pos.y, x).letter);
                }

                for (int x = pos.x + 1; x < this->getBoard()->getWidth() && 
                                    this->getBoard()->at(pos.y, x).letter; x++)
                {
                    perpendicular_score += this->getPointOfLetter(
                                        this->getBoard()->at(pos.y, x).letter);
                }
            }

            if (perpendicular_score != 0)
            {
                perpendicular_score +=
                    this->getBoard()->at(pos).bonus.letter_factor *
                                                    this->getPointOfLetter(l);
                perpendicular_score *=
                                    this->getBoard()->at(pos).bonus.word_factor;
            }

            score_total_perpendicular += perpendicular_score;
        }
        else // if (this->getBoard()->at(pos).letter != 0)
            score += this->getPointOfLetter(l);

        if (kcif.d == e_direction::horizontal)
            ++pos.x;
        else
            ++pos.y;
    }

    if (lettersUsed_.empty())
        return (0);

    //  Si le plateau est vide le mot doit obligatoirement passer par le centre
    if (this->getBoard()->isEmpty())
    {
        //  Si passe par le centre on renvoie le score
        if (kcif.d == e_direction::vertical &&
            kcif.coord.x == this->getBoard()->getWidth() / 2 &&
            kcif.coord.y <= this->getBoard()->getHeigth() / 2 &&
            kcif.coord.y + kcif.word.size() > this->getBoard()->getHeigth() / 2)
        {
            return (score * bonus_word);
        }

        if (kcif.d == e_direction::horizontal &&
            kcif.coord.y == this->getBoard()->getHeigth() / 2 &&
            kcif.coord.x <= this->getBoard()->getWidth() / 2 &&
            kcif.coord.x + kcif.word.size() > this->getBoard()->getWidth() / 2)
        {
            return (score * bonus_word);
        }

        return (0);
    }

    //  Si le plateau n'est pas vide et
    //  que le mot n'utilise pas de lettre préexistante et
    //  qu'il ne créer pas de nouveau (autre) alors on renvoie 0
    if (!this->getBoard()->isEmpty() &&
        kcif.word.size() == lettersUsed_.size() &&
        score_total_perpendicular == 0)
    {
        return (0);
    }

    return (score * bonus_word + score_total_perpendicular);
}
