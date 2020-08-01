/**
 * @file    LetterPointTable.hpp
 * @author  Raoufdine SAID, Yacine TAZDIT
 * @date    19/02/2020
 */

#ifndef LETTERPOINTTABLE_HPP
#define LETTERPOINTTABLE_HPP

#include <cstdlib>

#include <vector>
#include <array>
#include <iostream>
#include <cassert>

/** Table of Letter Point class. */
class LetterPointTable
{
public:

    /** Default constructor : use French mode. */
    LetterPointTable()
    : LetterPointTable({1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 10, 1, 2, 1, 1, 3, 2, 1,
                       1, 1, 1, 4, 10, 10, 10, 10})
    {   }

    /** Constructor : take points by letter. */
    LetterPointTable(std::array<char, 26> const& v_)
    {
        for (int i = 0; i < v_.size(); ++i)
            content[i] = v_[i];
    }

    /** return points of letter. */
    int getPointOf(char c_) const;

    /** Teste de regression. */
    static void test_regression();

private:

    std::array<int, 26> content; ///< Array whom content points by letter
};

#endif /* LETTERPOINTTABLE_HPP */
