#include <iostream>
using namespace std;
namespace ariel
{
struct node
{
  int key;
  node *left;
  node *right;
};

class Tree
{
private:
  node *Troot;
  void removethetree(node *root);
  node *newNode(int data);
  node *find(node *, int);
  node *min(node *);
  node *insert(node *, int);
  node *remove(node *, int);
  int size(node *);
  bool pre_order(node *, int);
  int parent(node *, int);
  void print(node *);

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
