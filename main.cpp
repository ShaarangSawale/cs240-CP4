#include "BSTD.cpp"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
int main() {
  BST* d = new BST();
  vector<int> full {7, 5, 4, 3, 2, 6, 1, 9, 8};
  vector<int> complete {1, 12, 9, 5, 6, 10};
  vector<int> balanced {1, 12, 9, 5, 6, 10};
  vector<int> perfect;

  d->insertVector(&full);
  cout << "After inserting values in a vector" << endl;
  d->printTree(d->root, 0);
  cout << "Height: " << d->getHeight(d->root) << endl;
  cout << "Average Depth: " << d->averageDepth() << endl;
  cout << "Number of Comparisons: " << d->getCount() << endl;
  d->removeVector(&complete);
  cout << "After removing values in a vector" << endl;
  d->printTree(d->root, 0);
  cout << "Height: " << d->getHeight(d->root) << endl;
  cout << "Average Depth: " << d->averageDepth() << endl;
  cout << "Number of Comparisons: " << d->getCount() << endl;

  srand((unsigned) time(NULL));
  int no_of_swaps = rand() % 100;
  cout << "Before Shuffling" << endl;
  d->printVector();
  d->shuffle(no_of_swaps);
  cout << "After Shuffling" <<endl;
  d->printVector(); 

  cout << "Before Shaking" << endl;
  d->printVector();
  int S = rand() % 100;
  int R = rand();
  d->shake(S, R);
  cout << "After Shaking" << endl;
  d->printVector();
  
  return 0;
};
