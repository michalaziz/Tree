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

  public:
    Tree();
    ~Tree();
    Tree(node *);
    void insert(int);
    void remove(int);
    int size();
    bool contains(int);
    int root();
    int parent(int);
    int left(int);
    int right(int);
    void print();
};

} // namespace ariel
