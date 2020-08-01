/*
 * @file    LetterBag.hpp
 * @author  Yacine TAZDAIT, Raoufdine SAID
 * @date    03/03/2020
 *
 **/

#include "AIScrabble.hpp"

using namespace std;

bool AIScrabble::play()
{
    //  Prendre les lettres dans le sac
    this->takeLettersFromBag();

    //  jouer
    KicksInformation const  kick = this->bestPossibleKick();

    //  Si on a pas réussi à jouer
    if (!Player::play(kick))
    {
        //  Echanger des lettres
        string const    listLetters =
                                this->getLetterOfPlayer().getListOfLetters();
        this->exchangeLetter();

        return (false);
    }

    return (true);
}

void AIScrabble::exchangeLetter()
{
    string const listLetters = this->getLetterOfPlayer().getListOfLetters();
    int const rand_int = std::min((int)listLetters.size(), rand() % 8);

    for (int j = 0; j < rand_int; ++j)
    {
        this->getLetterOfPlayer().remove(listLetters[j]);
        this->getLetterBag()->putLetter(listLetters[j]);
    }
}

vector<KicksInformation> AIScrabble::listAllPossibleKicks() const
{
    vector<KicksInformation>    result;
    vector<Vec2i>               startCoords = listAllNonEmptyTileCoord();

    //  Si pas de coordonnée initiale, on place au centre du plateau
    if (startCoords.empty())
    {
        startCoords.push_back(Vec2i(this->getBoard()->getWidth() / 2,
                                    this->getBoard()->getHeigth() / 2));
    }

    //  on cherche
    for (Vec2i const& coord : startCoords)
    {
        //  Solutions perpendiculaire ou superposer
        vector<KicksInformation> const  horizRes =
                        this->listPossibleKicks(coord, e_direction::horizontal);
        vector<KicksInformation> const  vertRes =
                        this->listPossibleKicks(coord, e_direction::vertical);

        for (auto const& k : horizRes)
            result.push_back(k);

        for (auto const& k : vertRes)
            result.push_back(k);

        //  Solutions parallèle, vertical à gauche de la coordonnée actuelle
        if (coord.x > 0 && !this->getBoard()->at(coord.y, coord.x - 1).letter)
        {
            vector<KicksInformation> const  vertAdjRes =
                        this->listPossibleKicks(Vec2i(coord.x - 1, coord.y),
                                                e_direction::vertical);

            for (auto const& k : vertAdjRes)
                result.push_back(k);
        }

        //  Solutions parallèle, vertical à droite de la coordonnée actuelle
        if (coord.x < this->getBoard()->getWidth() - 1 &&
            !this->getBoard()->at(coord.y, coord.x + 1).letter)
        {
            vector<KicksInformation> const  vertAdjRes =
                        this->listPossibleKicks(Vec2i(coord.x + 1, coord.y),
                                                e_direction::vertical);

            for (auto const& k : vertAdjRes)
                result.push_back(k);
        }

        //  Solution parallèle, horizontal en haut de la coordonnée actuelle
        if (coord.y > 0 && !this->getBoard()->at(coord.y - 1, coord.x).letter)
        {
            vector<KicksInformation> const  vertAdjRes =
                        this->listPossibleKicks(Vec2i(coord.x, coord.y - 1),
                                                e_direction::horizontal);

            for (auto const& k : vertAdjRes)
                result.push_back(k);
        }

        //  Solution parallèle, horizontal en bas de la coordonnée actuelle
        if (coord.y < this->getBoard()->getHeigth() - 1 &&
            !this->getBoard()->at(coord.y + 1, coord.x).letter)
        {
            vector<KicksInformation> const  vertAdjRes =
                        this->listPossibleKicks(Vec2i(coord.x, coord.y + 1),
                                                e_direction::vertical);

            for (auto const& k : vertAdjRes)
                result.push_back(k);
        }
    }

    return (result);
}

vector<Vec2i> AIScrabble::listAllNonEmptyTileCoord() const
{
    vector<Vec2i> res;

    for (int y = 0; y < this->getBoard()->getHeigth(); ++y)
    {
        for (int x = 0; x < this->getBoard()->getWidth(); ++x)
        {
            if (this->getBoard()->at(y, x).letter)
                res.push_back(Vec2i(x, y));
        }
    }

    return (res);
}

KicksInformation AIScrabble::bestPossibleKick() const
{
    vector<KicksInformation> const  allPossibleKicks = listAllPossibleKicks();

    if (allPossibleKicks.empty())
        return (KicksInformation("", Vec2i(), e_direction::horizontal));

    KicksInformation bestKick;
    int best_score = 0;

    for (auto it = allPossibleKicks.begin(); it < allPossibleKicks.end(); ++it)
    {
        KicksInformation kick = (*it).format();
        int score = scoreOfKick(kick);

        if (score > best_score)
        {
            best_score = score;
            bestKick = kick;
        }
    }

    return (bestKick);
}

static vector<string> joker_extend(string prefix_, string leftLetters_)
{
    if (leftLetters_.empty())
        return (vector<string>({prefix_}));

    char const  letter = leftLetters_.back();

    leftLetters_.pop_back();

    //  Si c'est pas un joker
    if (letter != ' ')
    {
        prefix_.push_back(letter);

        return (joker_extend(prefix_, leftLetters_));
    }

    vector<string>  result;

    //  C'est un joker
    for (char c = 'A'; c <= 'Z'; ++c)
    {
        prefix_.push_back(c);
        vector<string> const    tmpResult = joker_extend(prefix_, leftLetters_);

        for (string s : tmpResult)
            result.push_back(s);

        prefix_.pop_back();
    }

    return (result);
}

vector<KicksInformation> AIScrabble::listPossibleKicks(Vec2i const& start_,
                                                   e_direction direction_) const
{
    int const   step_x = (direction_ == e_direction::horizontal ? -1 : 0),
                step_y = (direction_ == e_direction::vertical ? -1 : 0);
    vector<string> const  allPossibleHandsLetters = joker_extend("",
                               this->getLetterOfPlayer().getListOfLetters());
    vector<KicksInformation>    result;

    for (string letters : allPossibleHandsLetters)
    {
        vector<string> const possiblity = this->listPossibleKicks(
                                    &this->getGaddag()->getRoot(), start_,
                                    letters, "", start_, step_x, step_y, false);

        for (auto const& p : possiblity)
            result.push_back(KicksInformation(p, start_, direction_));
    }

    return (result);
}

vector<string> AIScrabble::listPossibleKicks(const GaddagNode* node_,
                                             const Vec2i& start_,
                                             const std::string& letters_,
                                             const std::string& currentWord_,
                                             const Vec2i& current_,
                                             int step_x_, int step_y_,
                                             bool plus_used_) const
{
    //  On arrete si on est sortie du plateau
    if (current_.x < 0 || current_.x >= this->getBoard()->getWidth() ||
        current_.y < 0 || current_.y >= this->getBoard()->getHeigth())
    {   return (vector<string>());}

    vector<string>  res;

    //  Si il y'a une lettre sur le spot, on l'utilise
    if (this->getBoard()->at(current_).letter)
    {
        char const  current_letter = this->getBoard()->at(current_).letter;

        //  Si il n'y a pas de fils associée à cette lettre
        if (node_->getChild(current_letter) == nullptr)
            return (vector<string>());

        string newWord = currentWord_;

        newWord.push_back(current_letter);

        return (this->listPossibleKicks(node_->getChild(current_letter),
                            start_, letters_, newWord,
                            Vec2i(current_.x + step_x_, current_.y + step_y_),
                            step_x_, step_y_, plus_used_));
    }

    //  Si le noeud actuelle est terminal on ajoute le mot
    if (node_->isTerminal())
        res.push_back(currentWord_);

    //  Si il y'a un plus sur le noeud actuelle et que le plus n'a pas été
    //  utiliser
    if (!plus_used_ && node_->getChild('+'))
    {
        GaddagNode const* childNode = node_->getChild('+');
        string  newWord = currentWord_;

        newWord.push_back('+');

        vector<string> const partRes = this->listPossibleKicks(
                                childNode, start_, letters_, newWord,
                                Vec2i(start_.x - step_x_, start_.y - step_y_),
                                -step_x_, -step_y_, true);

        for (auto const& w : partRes)
            res.push_back(w);
    }

    //  On prend toutes les possibilités à partir des lettres qui nous reste
    vector<char> lastLetters;   // Ou on est passer

    for (int i = 0; i < letters_.size(); ++i)
    {
        char const  letter = letters_[i];   //  La nouvelle lettre à ajouter
        GaddagNode const* childNode = node_->getChild(letter);

        //  Si on est déja passer par le noeud
        if (std::find(lastLetters.begin(),
                      lastLetters.end(), letter) != lastLetters.end())
        {
            continue;
        }

        lastLetters.push_back(letter);

        e_direction const   direction =
                    step_x_ ? e_direction::horizontal : e_direction::vertical;
        bool const  can_place_this_letter =
                    this->canPlaceLetterAt(direction, current_, letter);

        //  Si il y'a un fils associée à cette lettre et qu'on peut la placer
        if (childNode && can_place_this_letter)
        {
            //  Lettres restantes
            string  leftLetter = letters_;
            string  newWord = currentWord_;

            leftLetter.erase(leftLetter.begin() + i);
            newWord.push_back(letter);

            vector<string> const partRes = this->listPossibleKicks(
                            childNode, start_, leftLetter, newWord,
                            Vec2i(current_.x + step_x_, current_.y + step_y_),
                            step_x_, step_y_, plus_used_);

            for (auto const& w : partRes)
                res.push_back(w);
        }
    }

    return (res);
}

bool AIScrabble::canPlaceLetterAt(e_direction direction_,
                                  const Vec2i& coord_, char l_) const
{
    //  Si il y'a déja une lettre sur le spot c'est mort
    if (this->getBoard()->at(coord_).letter)
        return (false);

    //  Tester le mot en vertical
    if (direction_ == e_direction::horizontal)
    {
        int y0 = coord_.y - 1,
            y1 = coord_.y + 1;

        while (y0 >= 0 && this->getBoard()->at(y0, coord_.x).letter)
            --y0;

        while (y1 < this->getBoard()->getHeigth() &&
               this->getBoard()->at(y1, coord_.x).letter)
        {
            ++y1;
        }

        if (y0 == coord_.y - 1 && y1 == coord_.y + 1)
            return (true);

        //  Tester que le mot partant de y0 + 1 à y1 - 1 est terminal
        string  perpendicWorld = "+";

        for (int y = y0 + 1; y < y1; ++y)
        {
            if (y == coord_.y)
                perpendicWorld.push_back(l_);
            else
            {
                perpendicWorld.push_back(
                                    this->getBoard()->at(y, coord_.x).letter);
            }
        }

        GaddagNode const* node = this->getGaddag()->find(perpendicWorld);

        return (node && node->isTerminal());
    }

    //  Tester Horizontal
    int x0 = coord_.x - 1,
        x1 = coord_.x + 1;

    while (x0 >= 0 && this->getBoard()->at(coord_.y, x0).letter)
        --x0;

    while (x1 < this->getBoard()->getWidth() &&
           this->getBoard()->at(coord_.y, x1).letter)
    {   ++x1;}

    if (x0 == coord_.x - 1 && x1 == coord_.x + 1)
        return (true);

    //  Tester que le mot partant de x0 + 1 à x1 - 1 est terminal
    string  perpendicWorld = "+";

    for (int x = x0 + 1; x < x1; ++x)
    {
        if (x == coord_.x)
            perpendicWorld.push_back(l_);
        else
            perpendicWorld.push_back(this->getBoard()->at(coord_.y, x).letter);
    }

    GaddagNode const* node = this->getGaddag()->find(perpendicWorld);

    return (node && node->isTerminal());
}
