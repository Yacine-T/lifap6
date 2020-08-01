/*
 * @file LetterBag.hpp
 * @author Yacine TAZDAIT, Raoufdine SAID
 * @date 01/03/2020
 *
 **/

#include "GaddagNode.hpp"

GaddagNode::GaddagNode()
: is_terminal(false)
{
    for (auto& p : childs)
        p = nullptr;
}

GaddagNode::~GaddagNode()
{
    for (auto& e : childs)
    {
        if (e)
            delete e;
    }
}

GaddagNode* GaddagNode::getChild(char l_)
{
    assert((l_ >= 'A' && l_ <= 'Z') || l_ == '+');

    if (l_ >= 'A' && l_ <= 'Z')
        return (this->childs[l_ - 'A']);

    if (l_ == '+')
        return (this->childs[26]);

    return (nullptr);
}

const GaddagNode* GaddagNode::getChild(char l_) const
{
    assert((l_ >= 'A' && l_ <= 'Z') || l_ == '+');

    if (l_ >= 'A' && l_ <= 'Z')
        return (this->childs[l_ - 'A']);

    if (l_ == '+')
        return (this->childs[26]);

    return (nullptr);
}

GaddagNode* GaddagNode::newChild(char l_)
{
    assert((l_ >= 'A' && l_ <= 'Z') || l_ == '+');

    GaddagNode* node = getChild(l_);

    if (node != nullptr)
        return (node);

    node = new GaddagNode();

    if (l_ >= 'A' && l_ <= 'Z')
        this->childs[l_ - 'A'] = node;

    if (l_ == '+')
        this->childs[26] = node;

    return (node);
}
