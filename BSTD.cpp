#include <iostream>
#include <stdio.h>
using namespace std;

class node() {
 public:
  int data;
  node* leftChild;
  node* rightChild;
  node(int t) {
    data = t;
    leftChild = nullptr;
    rightChild = nullptr;
  }
  
};
class BST() {
  node* root;
  BST() {
    root = nullptr;
  }
  void insert(int t) {
    if (t > 0) {
      if (root == nullptr) {
	root = new node(t);
      }
      bool r = true;
      node* traverse = root;
      while (r === true) {
	if (t > traverse->data) {
	  if (traverse->rightChild == nullptr) {
	    traverse->rightChild = new node(t);
	    r = false;
	  }
	  traverse = traverse->rightChild;
	}
	else if (t < traverse->data) {
	  if (traverse->leftChild == nullptr) {
	    traverse->leftChild = new node(t);
	    r = false;
	  }
	  traverse = traverse->leftChild;
	} else {
	  r = false;
	  cout << "can't insert duplicates!" << endl;
	}
      }
    } 
  }
}
