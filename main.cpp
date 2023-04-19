#include "BSTD.cpp"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
int main() {
  BST* f = new BST();
  vector<int> full = {20, 10, 30, 5, 15, 12, 17};
  vector<int> full_remove = {10, 30, 15, 12, 13, 57};
  vector<int> complete = {5, 3, 11, 2, 4, 7, 15, 1};
  vector<int> complete_remove = {5, 3, 2, 7, 74, 32};
  vector<int> balanced = {50, 30, 66, 27, 41, 90, 39};
  vector<int> balanced_remove = {30, 66, 41, 30, 56, 80};
  vector<int> perfect = {40, 25, 101, 17, 32, 73, 205};
  vector<int> perfect_remove = {17, 25, 101, 74, 85};

  srand((unsigned) time(NULL));
  int no_of_swaps = rand() % 100;
  cout << "Before Shuffling" << endl;
  f->printVector();
  f->shuffle(no_of_swaps);
  cout << "After Shuffling" <<endl;
  f->printVector();
  cout << endl;
  
  cout << "Before Shaking" << endl;
  f->printVector();
  int S = rand() % 100;
  int R = rand();
  f->shake(S, R);
  cout << "After Shaking" << endl;
  f->printVector();
  cout << endl;
  
  f->insertVector(&full);
  cout << "Inserting values (full)" << endl;
  f->printTree(f->root, 0);
  cout << "Height: " << f->getHeight(f->root) << endl;
  cout << "Average Depth: " << f->averageDepth() << endl;
  cout << "Number of Comparisons: " << f->getCount() << endl;
  f->removeVector(&full_remove);
  cout << "After removing values in a vector" << endl;
  f->printTree(f->root, 0);
  cout << "Height: " << f->getHeight(f->root) << endl;
  cout << "Average Depth: " << f->averageDepth() << endl;
  cout << "Number of Comparisons: " << f->getCount() << endl;
  //d->removeVector(&full);
  cout << endl;

  
  BST *c = new BST();
  c->insertVector(&complete);
  cout << "Inserting values (complete)" << endl;
  c->printTree(c->root, 0);
  cout << "Height: " << c->getHeight(c->root) << endl;
  cout << "Average Depth: " << c->averageDepth() << endl;
  cout << "Number of Comparisons: " << c->getCount() << endl;
  c->removeVector(&complete_remove);
  cout << "After removing values in a vector" << endl;
  c->printTree(c->root, 0);
  cout << "Height: " << c->getHeight(c->root) << endl;
  cout << "Average Depth: " << c->averageDepth() << endl;
  cout << "Number of Comparisons: " << c->getCount() << endl;
  //d->removeVector(&complete);
  cout << endl;
  
  BST *b = new BST();
  b->insertVector(&balanced);
  cout << "Inserting values (balanced)" << endl;
  b->printTree(b->root, 0);
  cout << "Height: " << b->getHeight(b->root) << endl;
  cout << "Average Depth: " << b->averageDepth() << endl;
  cout << "Number of Comparisons: " << b->getCount() << endl;
  b->removeVector(&balanced_remove);
  cout << "After removing values in a vector" << endl;
  b->printTree(b->root, 0);
  cout << "Height: " << b->getHeight(b->root) << endl;
  cout << "Average Depth: " << b->averageDepth() << endl;
  cout << "Number of Comparisons: " << b->getCount() << endl;
  //d->removeVector(&balanced);
  cout << endl;
  
  BST *p = new BST();
  p->insertVector(&perfect);
  cout << "Inserting values (perfect)" << endl;
  p->printTree(p->root, 0);
  cout << "Height: " << p->getHeight(p->root) << endl;
  cout << "Average Depth: " << p->averageDepth() << endl;
  cout << "Number of Comparisons: " << p->getCount() << endl;
  p->removeVector(&perfect_remove);
  cout << "After removing values in a vector" << endl;
  p->printTree(p->root, 0);
  cout << "Height: " << p->getHeight(p->root) << endl;
  cout << "Average Depth: " << p->averageDepth() << endl;
  cout << "Number of Comparisons: " << p->getCount() << endl;
  //d->removeVector(&perfect);

  
  return 0;
};
