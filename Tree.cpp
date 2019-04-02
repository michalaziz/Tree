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
    Tree::removethetree(Troot);
}
void Tree::removethetree(node *root)
{
    if (root != NULL)
    {
        Tree::removethetree(root->left);
        Tree::removethetree(root->right);
        delete root;
    }
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

// node *Tree::remove(node *root, int key)
// {
//     // base case
//     if (root == NULL)
//         return root;

//     // If the key to be deleted is smaller than the root's key,
//     // then it lies in left subtree
//     if (key < root->key & root->left != NULL)
//         root->left = Tree::remove(root->left, key);

//     // If the key to be deleted is greater than the root's key,
//     // then it lies in right subtree
//     else if (key > root->key & root->right != NULL)
//         root->right = Tree::remove(root->right, key);

//     // if key is same as root's key, then This is the node
//     // to be deleted
//     else
//     {
//         if (root->right == NULL & root->left == NULL)
//         {
//             delete (root);
//             return NULL;
//         }
//         // node with only one child or no child
//         if (root->left == NULL & root->right != NULL)
//         {
//             node *temp = root->right;
//             delete (root);
//             return temp;
//         }
//         else if (root->right == NULL & root->left != NULL)
//         {
//             node *temp = root->left;
//             delete (root);
//             return temp;
//         }

//         // node with two children: Get the inorder successor (smallest
//         // in the right subtree)
//         node *temp = min(root->right);

//         // Copy the inorder successor's content to this node
//         root->key = temp->key;

//         // Delete the inorder successor
//         root->right = Tree::remove(root->right, temp->key);
//     }
//     return root;
// }

// void Tree::remove(int x)
// {
//     if ((contains(x) == false) || (Troot == NULL))
//     {
//         throw ::invalid_argument("Is Not GOOD");
//         return;
//     }
//     else
//     {
//         cout<<"got else";
//         Tree::remove(Troot, x);
//     }
// }
node *Tree::remove(node *root, int i)
{
    if (root == NULL)
        return root;

    if (i < root->key && root->left!=NULL)
        root->left = remove(root->left, i);


    else if (i > root->key && root->right!=NULL)
        root->right = remove(root->right, i);

    else
    {
        if (root->left == NULL && root->left==NULL)
        {
            node *temp = root->right;
            delete (root);
            return NULL;
        }
        if(root->left == NULL&root->right != NULL)
        {
            node *temp = root->right;
            delete(root);
            return temp;
        }
        else if (root->right == NULL && root->left!=NULL)
        {
            node *temp = root->left;
            delete (root);
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
   node *removeNode = find(Troot, i);

        if (removeNode == NULL)
        {
                throw std::invalid_argument("The data is not in the tree!!");
        }

        node *temp = remove(Troot,i);

        if (removeNode == Troot)
        {
                Troot = temp;
        }
        if (temp == NULL)
        {
                Troot = NULL;
}
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

node *Tree::find(node *root, int i)
{
    if (root == NULL || root->key == i)
        return root;
    if (root->key < i)
        return find(root->right, i);
    return find(root->left, i);
}

bool Tree::contains(int i)
{
    if (find(Troot, i) == NULL)
    {
        return false;
    }
    else
        return true;
}

int Tree::root()
{
    return Troot->key;
}

int Tree::parent(int i)
{
    node *temp = find(Troot, i);
    if (temp->key == Troot->key || temp == NULL)
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
    node *temp = find(Troot, i);
    if (temp == NULL)
    {
        throw ::invalid_argument("Error:no left");
        return -1;
    }
    if (temp->key == i)
        temp = temp->left;
    return temp->key;
}

int Tree::right(int i)
{
    node *temp = find(Troot, i);
    if (temp == NULL)
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