#include <iostream>
using namespace std;
namespace ariel
{
struct node
{
    int key;
    node *left;
    node *right;
    node *parent;
};

class Tree
{
  private:
    node *Troot;
void removethetree(node *root);
  public:
    Tree();
    ~Tree();
    Tree(node *);
    node * newNode(int data);
    node*insert(node*,int);
    void insert(int);
    node*find(node*,int);
    node*min(node*);
    node*remove(node*,int);
    void remove(int);
    int size(node *);
    int size();
    bool pre_order(node *,int);
    bool contains(int);
    int root();
    int parent(int);
    int left(int);
    int right(int);
    void print (node*);
    void print();
   
};

} // namespace ariel
