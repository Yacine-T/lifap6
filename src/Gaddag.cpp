/*
 * @file LetterBag.hpp
 * @author Yacine TAZDAIT, Raoufdine SAID
 * @date 01/03/2020
 *
 **/

#include "Gaddag.hpp"

Gaddag::Gaddag(const std::string& file_)
{
    std::ifstream ifs(file_);

    if (!ifs.is_open())
    {
        std::cerr << "Error : we couldn't open this file '"
            << file_ << "'" << std::endl;

        exit(EXIT_FAILURE);
    }

    readStream(ifs);

    ifs.close();
}

void Gaddag::insert(const std::string& word_)
{
    GaddagNode* node = &root;

    for (auto c : word_)
        node = node->newChild(c);

    node->setTerminal(true);
}

GaddagNode* Gaddag::find(const std::string& word_)
{
    GaddagNode* node = &root;

    for (auto c : word_)
    {
        node = node->getChild(c);

        if (node == nullptr)
            return (nullptr);
    }

    return (node);
}

GaddagNode const* Gaddag::find(const std::string& word_) const
{
    GaddagNode const* node = &root;

    for (auto c : word_)
    {
        node = node->getChild(c);

        if (node == nullptr)
            return (nullptr);
    }

    return (node);
}

void Gaddag::insertPlus(const std::string& word_)
{
    if (word_.empty())
        return;

    std::string wordPlus = "+" + word_;

    insert(wordPlus);

    for (int i = 1; i < wordPlus.size(); ++i)
    {
        char const tmp_c = wordPlus[i];

        for (int j = i; j > 0; --j)
            wordPlus[j] = wordPlus[j - 1];

        wordPlus[0] = tmp_c;

        insert(wordPlus);
    }
}

std::istream& Gaddag::readStream(std::istream& is_)
{
    while (is_)
    {
        std::string word;

        is_ >> word;
        insertPlus(word);
    }

    return (is_);
}
