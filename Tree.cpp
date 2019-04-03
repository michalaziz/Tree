#include <iostream>
#include "Tree.hpp"
using namespace std;
using namespace ariel;

//deafult ctor
Tree::Tree()
{
    Troot = NULL;
}

//dtor
Tree::~Tree()
{
    Tree::removethetree(Troot);
}

//delete ol the nodes in the tree
void Tree::removethetree(node *root)
{
    if (root != NULL)
    {
        Tree::removethetree(root->left);
        Tree::removethetree(root->right);
        delete root;
    }
}

//ctor
Tree::Tree(node *t)
{
    Troot->key = t->key;
    Troot->left = t->left;
    Troot->right = t->right;
}

//reset a new node
node *Tree::newNode(int key)
{
    node *temp = new node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

//shell function of insert
node *Tree::insert(node *temp, int i)
{
    if (temp == NULL) //the tree is empty
        return newNode(i);

    if (i < temp->key)
        temp->left = insert(temp->left, i);
    else if (i > temp->key)
        temp->right = insert(temp->right, i);
    return temp;
}
// insert a new node to the tree
void Tree::insert(int i)
{
    if (contains(i) == true) //trying to insert a nmber that allredy exist
    {
        throw std::invalid_argument("allready exist");
    }
    Troot = insert(Troot, i);
}

//find the node with the minimum key in the tree
node *Tree::min(node *t)
{
    if (t == NULL)
        return NULL;
    else if (t->left == NULL)
        return t;
    else
        return min(t->left);
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
    {
        return root;
    }
    if (root->key > i)
    {
        root->left = remove(root->left, i);
        return root;
    }
    else if (root->key < i)
    {
        root->right = remove(root->right, i);
        return root;
    }
    if (root->left == NULL)
    {
        node *temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL)
    {
        node *temp = root->left;
        delete root;
        return temp;
    }
    else
    {
        node *sParent = root->right;
        node *s = root->right;
        while (s->left != NULL)
        {
            sParent = s;
            s = s->left;
        }
        sParent->left = s->right;
        root->key=s->key;
        delete s;
        return root;
    }
}









//     if (root == NULL)
//     return root;

// if (i < root->key && root->left != NULL)
//     root->left = remove(root->left, i);

// else if (i > root->key && root->right != NULL)
//     root->right = remove(root->right, i);

// else
// {
//     if (root->left == NULL && root->left == NULL)
//     {
//         node *temp = root->right;
//         delete (root);
//         return NULL;
//     }
//     if (root->left == NULL & root->right != NULL)
//     {
//         node *temp = root->right;
//         delete (root);
//         return temp;
//     }
//     else if (root->right == NULL && root->left != NULL)
//     {
//         node *temp = root->left;
//         delete (root);
//         return temp;
//     }
//     node *temp = min(root->right);
//     root->key = temp->key;
//     root->right = remove(root->right, temp->key);
// }
// return root;
// }







//     if (root == NULL)
//     {
//         return root;
//     }
//     if (root->key > i)
//     {
//         root->left = remove(root->left, i);
//         return root;
//     }
//     else if (root->key < i)
//     {
//         root->right = remove(root->right, i);
//         return root;
//     }
//     if (root->left == NULL)
//     {
//         node *temp = root->right;
//         delete root;
//         return temp;
//     }
//     else if (root->right == NULL)
//     {
//         node *temp = root->left;
//         delete root;
//         return temp;
//     }
//     else
//     {
//         node *sParent = root->right;
//         node *s = root->right;
//         while (s->left != NULL)
//         {
//             sParent = s;
//             s = s->left;
//         }
//         sParent->left = s->right;
//         root->key=s->key;
//         delete s;
//         return root;
//     }
// }
///////////////////////////////////////
//         temp = min(root->right);
//         root->key = (temp->key);
//         root->right = remove(root->right, temp->key);
//     }
//     return root;
// }


void Tree::remove(int i)
{
    node *removeNode = find(Troot, i);

    if (removeNode == NULL)
    {
        throw std::invalid_argument("not exist");
    }

    node *temp = remove(Troot, i);

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

int Tree::parent(node *root, int i)
{
    if (i < root->key)
        if (root->left->key == i)
            return root->key;
        else
            return parent(root->left, i);
    else if (root->right->key == i)
        return root->key;
    else
        return parent(root->right, i);

    // while (root->key != i)
    // {
    //     if (root->left->key == i || root->right->key == i)
    //         return root->key;
    //     if (i < root->left->key)
    //         root = root->left;
    //     else if (i > root->left->key)
    //         root = root->left;
    //     if (i > root->right->key)
    //         root = root->right;
    //     else if (i < root->right->key)
    //         root = root->right;
    // }
    // return root->key;
}

int Tree::parent(int i)
{
    if (contains(i) == false || Troot->key == i || Troot == NULL)
    {
        throw std::invalid_argument("error finding parent");
    }
    return parent(Troot, i);
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

int Tree::left(int i)
{
    node *temp = find(Troot, i);
    if (temp == NULL || temp->left == NULL)
    {
        throw ::invalid_argument("Error:no left");
    }
    temp = temp->left;
    return temp->key;
}

int Tree::right(int i)
{
    node *temp = find(Troot, i);
    if (temp == NULL || temp->right == NULL)
    {
        throw ::invalid_argument("Error:no right");
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