#include "BSTD.cpp"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int main() {
  BST* d = new BST();
  vector<int> insert {7, 5, 4, 3, 2, 6, 1, 9, 8};
  vector<int> remove {3, 4, 8, 5, 7, 6, 1};
<<<<<<< Updated upstream
  int i;
  int j;
  for (i = 0; i < 10; i++) {
      d->shake(8, 4, &insert);
      for (j = 0; j < insert.size(); j++) {
	cout << insert.at(j) << " ";
      }
      cout << endl;
  }

  vector<int> swap {4, 6, 4, 8, 2, 4, 9, 0, 1, 4, 3};
  srand((unsigned) time(NULL));
  int no_of_swaps = rand() % 10;
  /*
>>>>>>> Stashed changes
  d->insertVector(&insert);
  //d->removeVector(&remove);
  d->printTree(d->root);
  int h = d->getHeight(d->root);
  double a = d->averageDepth();
  cout << "Height: " << h << endl;
  cout << "Average Depth: " << a << endl;
<<<<<<< Updated upstream
  */

  cout << "Before Shuffling" << endl;
  for(int i = 0; i <swap.size(); i++) {
    cout << swap[i] << " ";
  }
  cout << endl;
  
  d->shuffle(&swap);
  cout << "After Shuffling" <<endl;
  for(int i = 0; i <swap.size(); i++) {
    cout << swap[i] << " ";
  }
  cout << endl;
  
  
>>>>>>> Stashed changes
  return 0;
};
