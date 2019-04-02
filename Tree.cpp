#include <iostream>
#include "Tree.hpp"
using namespace std;
using namespace ariel;

Tree::Tree()
{
    Troot = NULL;
}
Tree::~Tree()
{
    Troot = NULL;
}
Tree::Tree(node *t)
{
    Troot->key = t->key;
    Troot->left = t->left;
    Troot->right = t->right;
    Troot->parent = t->parent;
}

node *Tree::newNode(int data)
{
    node *temp = new node;
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    return temp;
}

node *Tree::insert(node *temp, int i)
{
    if (temp == NULL) //the tree is empty
    {
        return newNode(i);
    }
    else if (temp->key == i)
    {
        throw invalid_argument("error: the number is allready exist");
    }
    if (i < temp->key)
    {
        node *l = insert(temp->left, i);
        temp->left = l;
        l->parent = temp;
    }
    else if (i > temp->key)
    {
        node *r = insert(temp->right, i);
        temp->right = r;
        r->parent = temp;
    }
    return temp;
}

void Tree::insert(int i)
{
    Troot = insert(Troot, i);
}

node *Tree::min(node *t)
{
    node *temp = t;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

node *Tree::remove(node *root, int i)
{
    if (root == NULL)
        return root;
    if (i < root->key)
        root->left = remove(root->left, i);
    else if (i > root->key)
        root->right = remove(root->right, i);

    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        node *temp = min(root->right);
        root->key = temp->key;
        root->right = remove(root->right, temp->key);
    }
    return root;
}
void Tree::remove(int i)
{
    remove(Troot, i);
}

int Tree::size(node *t)
{
    if (t == NULL)
        return 0;
    else
    {
        return (size(t->left) + 1 + size(t->right));
    }
}
int Tree::size()
{
    return size(Troot);
}

bool Tree::pre_order(node *x, int i)
{
    if (x != NULL)
    {
        if (x->key == i)
            return true;
        pre_order(x->left, i);
        pre_order(x->right, i);
    }
    return false;
}

node *Tree::find(int i, node t)
{
    node *z = Troot;
    node *y = NULL;
    while (z->key)
    {
        y = z;
        if (i == z->key)
            return z;
        if (i < z->key)
            z = z->left;
        else
            z = z->right;
    }
    return y;
}

bool Tree::contains(int i)
{
    return pre_order(Troot, i);
}

int Tree::root()
{
    return Troot->key;
}

int Tree::parent(int i)
{
    node *temp = find(i, *Troot);
    if (temp->key ==Troot->key || temp==NULL )
    {
        throw ::invalid_argument("Error:no parent");
        return -1;
    }
    else
    {
        temp = temp->parent;
        return temp->key;
    }
}

int Tree::left(int i)
{
    node *temp = find(i, *Troot);
    if(temp==NULL)
    {
        throw ::invalid_argument("Error:no left");
        return -1;
    }
    if(temp->key==i)
    temp = temp->left;
    return temp->key;
}

int Tree::right(int i)
{
    node *temp = find(i, *Troot);
     if(temp==NULL)
    {
        throw ::invalid_argument("Error:no right");
        return -1;
    }
    temp = temp->right;
    return temp->key;
}

void Tree::print(node *temp)
{
    if (temp != NULL)
    {
        cout << temp->key << " ";
        print(temp->left);
        print(temp->right);
    }
}

void Tree::print()
{
    print(Troot);
}