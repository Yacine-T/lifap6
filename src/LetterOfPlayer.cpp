/*
 * @file    LetterOfPlayer.cpp
 * @author  Raoufdine SAID, Yacine TAZDIT
 * 
 * @date    29 février 2020, 15:59
 */

#include "LetterOfPlayer.hpp"

bool LetterOfPlayer::remove(char l_)
{
    auto it = std::find(this->data.begin(), this->data.end(), l_);

    if (it != this->data.end())
    {
        std::swap(this->data.back(), *it);
        this->data.pop_back();

        return (true);
    }

    return (false);
}

bool LetterOfPlayer::add(char l_)
{
    if (nbContent() >= 7)
        return (false);

    data.push_back(l_);

    return (true);
}

void LetterOfPlayer::test_regression()
{
    LetterOfPlayer lp;

    assert(lp.isEmpty());
    assert(lp.nbContent() == 0);

    for (char c = 'A'; c < 'A' + 7; ++c)
        assert(lp.add(c));

    assert(lp.add('Z') == false);

    char const c = 'A';
    int        id = 0;

    for (auto it = lp.begin(); it != lp.end(); ++it, ++id)
    {
        assert((c + id) == *it);
        assert((c + id) == lp.check(id));
    }
}
