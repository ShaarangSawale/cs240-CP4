//David Lovejoy and Shaarang Sawale
#include "BSTD.cpp"
#include <iostream>
#include <stdio.h>
#include <cstdlib>

vector <int> comparisons;
vector <int> heights;
vector <int> depths;
void testTree(BST* f, int size,  bool useShuffle) {
  cout << "size: " << size << endl;
  f->insertRandom(size);
  f->insertVector(&(f->BST_Vector));
  cout << "root: " << f->root << endl;
  cout << "Height: " << f->getHeight(f->root) << endl;
  cout << "Average Depth: " << f->averageDepth() << endl;
  cout << "Number of Comparisons: " << f->getCount() << endl;
  comparisons.push_back(f->getCount());
  heights.push_back(f->getHeight(f->root));
  depths.push_back(f->averageDepth());
  f->reset();

  int i = 0;
  bool flag = true;
  for (i= 0; i < size; i++) {
    if (f->find(f->BST_Vector.at(i)) == false) {
      flag = false;
    }
  }
  if (flag == false) {
    cout << "ERROR couldn't find elements in the BST" << endl;
  } else {
    cout << "found all elements in the BST" << endl;
  }

  f->shake(size/4, 10000);
  f->shuffle(size/2);
  flag = true;
    for (i = 0; i < size/4; i++) {
      f->remove(f->root, f->BST_Vector.at(i));
      if (f->find(f->BST_Vector.at(i)) == true) {
	flag = false;
      }
    }
  if (flag == false) {
    cout << "ERROR, found removed element" << endl;
  } else {
    cout << "test passed, couldn't find any removed elements" << endl;
  }
    
  cout << "After removing values in a vector" << endl;
  cout << "root again: " << f->root << endl;
  cout << "Height: " << f->getHeight(f->root) << endl;
  cout << "Average Depth: " << f->averageDepth() << endl;
  cout << "Number of Comparisons: " << f->getCount() << endl;
    comparisons.push_back(f->getCount());
  heights.push_back(f->getHeight(f->root));
  depths.push_back(f->averageDepth());

}
  
int main() {
  BST* f = new BST();
  srand((unsigned) time(NULL));
  int no_of_swaps = (rand() % 1000) + 2000;
  cout << "Before Shuffling" << endl;
  f->printVector();
  f->shuffle(no_of_swaps);
  cout << "After Shuffling" <<endl;
  f->printVector();
  cout << endl;
  
  cout << "Before Shaking" << endl;
  f->printVector();
  int S = rand() % 1000;
  int R = rand();
  f->shake(S, R);
  cout << "After Shaking" << endl;
  f->printVector();
  cout << endl;

  cout << "Tree One" << endl;
  testTree(f, 1000, false);
  f->deleteTree(f->root);
  f->root = nullptr;
  f->BST_Vector.clear();
  f->reset();
  cout << "Tree Two" << endl;
  testTree(f, 5000, false);
  f->deleteTree(f->root);
  f->root = nullptr;
  f->BST_Vector.clear();
  f->reset();
  cout << "Tree Three" << endl;
  testTree(f, 10000, false);
  f->deleteTree(f->root);
  f->root = nullptr;
  f->BST_Vector.clear();
  f->reset();

  int i;
  for (i = 0; i < comparisons.size(); i++) {
    cout << comparisons.at(i) <<  " " << heights.at(i) << " " << depths.at(i) << endl;
    if (i % 2 != 0) {
      cout << endl;
    } 
  }
  /* cout << "Inserting values (empty)" << endl;
  f->printTree(f->root, 0);
  cout << "here!" << endl;
  cout << "Height: " << f->getHeight(f->root) << endl;
  cout << "Average Depth: " << f->averageDepth() << endl;
  cout << "Number of Comparisons: " << f->getCount() << endl;
  f->reset();
  f->removeVector(&full_remove);
  cout << "After removing values in a vector" << endl;
  f->printTree(f->root, 0);
  cout << "Height: " << f->getHeight(f->root) << endl;
  cout << "Average Depth: " << f->averageDepth() << endl;
  cout << "Number of Comparisons: " << f->getCount() << endl;
  f->removeVector(&full);
  f->reset();
  
   cout << "random BST 1/1: " << endl;
  f->insertVector(&(f->BST_Vector));
  f->printTree(f->root, 0);
  cout << "Height: " << f->getHeight(f->root) << endl;
  cout << "Average Depth: " << f->averageDepth() << endl;
  cout << "Number of Comparisons: " << f->getCount() << endl;
  f->removeVector(&perfect_remove);
  cout << "After removing values in a vector" << endl;
  f->printTree(f->root, 0);
  cout << "Height: " << f->getHeight(f->root) << endl;
  cout << "Average Depth: " << f->averageDepth() << endl;
  cout << "Number of Comparisons: " << f->getCount() << endl;
  f->removeVector(&(f->BST_Vector));
  f->shuffle(no_of_swaps, 1000);
  
  cout << "random BST 2/1: " << endl;
  f->insertVector(&(f->BST_Vector));
  f->printTree(f->root, 0);
  cout << "Height: " << f->getHeight(f->root) << endl;
  cout << "Average Depth: " << f->averageDepth() << endl;
  cout << "Number of Comparisons: " << f->getCount() << endl;
  f->removeVector(&perfect_remove);
  cout << "After removing values in a vector" << endl;
  f->printTree(f->root, 0);
  cout << "Height: " << f->getHeight(f->root) << endl;
  cout << "Average Depth: " << f->averageDepth() << endl;
  cout << "Number of Comparisons: " << f->getCount() << endl;
  f->removeVector(&(f->BST_Vector));
  f->shake(no_of_swaps);
  
  cout << "random BST 3/1: " << endl;
  f->insertVector(&(f->BST_Vector));
  f->printTree(f->root, 0);
  cout << "Height: " << f->getHeight(f->root) << endl;
  cout << "Average Depth: " << f->averageDepth() << endl;
  cout << "Number of Comparisons: " << f->getCount() << endl;
  f->removeVector(&perfect_remove);
  cout << "After removing values in a vector" << endl;
  f->printTree(f->root, 0);
  cout << "Height: " << f->getHeight(f->root) << endl;
  cout << "Average Depth: " << f->averageDepth() << endl;
  cout << "Number of Comparisons: " << f->getCount() << endl;
  f->BST_Vector.clear();
  /*
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
  f->removeVector(&full);
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
  
  //now testing trees of size 1000, 5000, 10000
  cout << "random BST 1/2: " << endl;
  f->insertRandom(1000);
  f->insertVector(&(f->BST_Vector));
  f->printTree(f->root, 0);
  cout << "Height: " << f->getHeight(f->root) << endl;
  cout << "Average Depth: " << f->averageDepth() << endl;
  cout << "Number of Comparisons: " << f->getCount() << endl;
  f->removeVector(&perfect_remove);
  cout << "After removing values in a vector" << endl;
  f->printTree(f->root, 0);
  cout << "Height: " << f->getHeight(f->root) << endl;
  cout << "Average Depth: " << f->averageDepth() << endl;
  cout << "Number of Comparisons: " << f->getCount() << endl;
  //f->removeVector(&(f->BST_Vector));
  f->deleteTree(f->root);
  f->root = nullptr;
  f->BST_Vector.clear();
  f->shuffle(no_of_swaps);
  
  cout << "random BST 2/2: " << endl;
  f->insertRandom(5000);
  f->insertVector(&(f->BST_Vector));
  f->printTree(f->root, 0);
  cout << "Height: " << f->getHeight(f->root) << endl;
  cout << "Average Depth: " << f->averageDepth() << endl;
  cout << "Number of Comparisons: " << f->getCount() << endl;
  f->removeVector(&perfect_remove);
  cout << "After removing values in a vector" << endl;
  f->printTree(f->root, 0);
  cout << "Height: " << f->getHeight(f->root) << endl;
  cout << "Average Depth: " << f->averageDepth() << endl;
  cout << "Number of Comparisons: " << f->getCount() << endl;

  f->deleteTree(f->root);
  f->root = nullptr;
  f->BST_Vector.clear();
  
 
  cout << "random BST 3/2: " << endl;
  f->insertRandom(10000);
  f->insertVector(&(f->BST_Vector));
  f->printTree(f->root, 0);
  cout << "Height: " << f->getHeight(f->root) << endl;
  cout << "Average Depth: " << f->averageDepth() << endl;
  cout << "Number of Comparisons: " << f->getCount() << endl;
  f->removeVector(&perfect_remove);
  cout << "After removing values in a vector" << endl;
  f->printTree(f->root, 0);
  cout << "Height: " << f->getHeight(f->root) << endl;
  cout << "Average Depth: " << f->averageDepth() << endl;
  cout << "Number of Comparisons: " << f->getCount() << endl;

  f->deleteTree(f->root);
  f->root = nullptr;
  f->BST_Vector.clear();*/

  
  return 0;
};
