#include <iostream>
#include "Tree.hpp"
using namespace std;
using namespace ariel;

Tree::Tree()
{
    Troot=NULL;
}
Tree::~Tree()
{
    Troot=NULL;
}
Tree::Tree(node*t)
{
    Troot->key=t->key;
    Troot->left=t->left;
    Troot->right=t->right;
    Troot->parent=t->parent;
}

void Tree::insert(int i)
{

}

void Tree::remove(int i)
{

}

int Tree::size()
{
    return 7;
}

bool Tree::contains(int i)
{
    return 0;
}

int Tree::root()
{
    return 0;
}

int Tree::parent(int i)
{
    return 0;
}

int Tree::left(int i)
{
    return 0;
}

int Tree::right(int i)
{
    return 0;
}

void Tree::print()
{

}