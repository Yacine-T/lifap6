/*
 * @file    LetterPointTable.hpp
 * @author  Raoufdine SAID, Yacine TAZDIT
 * @date    19/02/2020
 */

#include "LetterPointTable.hpp"

int LetterPointTable::getPointOf(char c_) const
{
    if (c_ < 'A' || c_ > 'Z')
    {
        std::cerr << "'" << c_ << "' n'est pas une lettre valide" << std::endl;

        exit(EXIT_FAILURE);
    }

    return (content[c_ - 'A']);
}

void LetterPointTable::test_regression()
{
    LetterPointTable const t({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
                              15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25});

    //  Teste que le constructeur à bien pris les données
    for (int i = 0; i < t.content.size(); ++i)
        assert(i == t.content[i]);

    //  Teste que c'est la bonne valeur
    for (char c = 'A'; c <= 'Z'; ++c)
        assert(t.getPointOf(c) == (c - 'A'));
}
