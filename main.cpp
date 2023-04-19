#include "BSTD.cpp"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
int main() {
  BST* d = new BST();
  vector<int> insert {7, 5, 4, 3, 2, 6, 1, 9, 8};
  vector<int> remove {3, 4, 8, 5, 7, 6, 1};
  //<<<<<<< Updated upstream
  /*int i;
>>>>>>> a4fe9984414bb09227225ee344f9e7b8fc1f0ec2
  int j;
  for (i = 0; i < 10; i++) {
      d->shake(8, 4, &insert);
      for (j = 0; j < insert.size(); j++) {
	cout << insert.at(j) << " ";
      }
      cout << endl;
  }
  */
  vector<int> swap {4, 6, 4, 8, 2, 4, 9, 0, 1, 4, 3};
  srand((unsigned) time(NULL));
  int no_of_swaps = rand() % 100;

  vector<int> shake_vector {5, 6, 3, 7, 5, 24, 16, 74, 53, 67, 49};
  d->insertVector(&insert);
  //d->removeVector(&remove);
  d->printTree(d->root, 0);
  int h = d->getHeight(d->root);
  double a = d->averageDepth();
  cout << "Height: " << h << endl;
  cout << "Average Depth: " << a << endl;
  cout << "Before Shuffling" << endl;
  for(int i = 0; i <swap.size(); i++) {
    cout << swap[i] << " ";
  }
  cout << endl;
  
  d->shuffle(&swap, no_of_swaps);
  cout << "After Shuffling" <<endl;
  for(int i = 0; i <swap.size(); i++) {
    cout << swap[i] << " ";
  }
  cout << endl;

  cout << "inserting numbers into the binary search tree" << endl; 
  vector<int> bst_numbers = {45, 64, 27, 89, 72, 31, 29, 64, 4, 8, 13};
  for(int i = 0; i < bst_numbers.size(); i++) {
    d->insert(bst_numbers[i]);
  }
  cout << "new binary search tree" << endl;
  d->printTree(d->root, 0);

  cout << "removing numbers 4, 45, 72 from the binary search tree" << endl;
  d->remove(4);
  d->remove(45);
  d->remove(72);

  cout << "after removing 4, 45, 72" << endl;
  d->printTree(d->root, 0);

  cout << "Before Shaking" << endl;
  for(int i = 0; i < shake_vector.size(); i++) {
    cout << shake_vector[i] << " ";
  }
  cout << endl;

  int S = rand() % 100;
  int R = rand();
  d->shake(S, R, &shake_vector);
  cout << "After Shaking" << endl; 
  for(int i = 0; i < shake_vector.size(); i++) {
    cout << shake_vector[i] << " ";
  }
  cout << endl;
  return 0;
};
