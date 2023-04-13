#include "BSTD.cpp"
#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
  BST* d = new BST();
  vector<int> insert {7, 5, 4, 3, 2, 6, 1, 9, 8};
  vector<int> remove {3, 4, 8, 5, 7, 6, 1};
  d->insertVector(&insert);
  //d->removeVector(&remove);
  d->printTree(d->root);
  int h = d->getHeight(d->root);
  double a = d->averageDepth();
  cout << "Height: " << h << endl;
  cout << "Average Depth: " << a << endl;
  return 0;
};
