/*
 * @file LetterBag.hpp
 * @author Yacine TAZDAIT, Raoufdine SAID
 * @date 19/03/2020
 *
 **/

#include "LetterBag.hpp"

#include <cassert>

bool LetterBag::takeLetter(char& l_)
{
    if (content.empty())
        return (false);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> d(0, content.size() - 1);
    int const id = d(gen);

    l_ = content[id];

    content[id] = content.back();

    content.pop_back();

    return (true);
}

void LetterBag::test_regression()
{
    LetterBag   bag1({'a'});
    char        c = 0;

    assert(bag1.nbContent() == 1);
    assert(bag1.takeLetter(c) && c == 'a');
    assert(bag1.nbContent() == 0);
    assert(bag1.takeLetter(c) == false);
}
