#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <random>
using namespace std;

class node {
 public:
  int data;
  node* leftChild;
  node* rightChild;
  node* parent;
  node(int t) {
    data = t;
    parent = nullptr;
    leftChild = nullptr;
    rightChild = nullptr;
  }
  void printNode() {
    cout << data << endl;
    /*cout << "(" << data << ", ";
    if (parent != nullptr) {
      cout << parent->data << ", ";
    } else {
      cout << "null" << ", ";
    }
    if (leftChild != nullptr) {
      cout << leftChild->data << ", ";
    } else {
      cout << "null" <<	", ";
    }
    if (rightChild != nullptr) {
      cout << rightChild->data;
    } else {
      cout << "null";
    }
    cout << ")" << endl;*/
  }
  
};
class BST {
public:
  node* root;
  node* finder;
  int comparisonCounter;
  BST() {
    root = nullptr;
    comparisonCounter = 0;
  }
   bool find(int d) {
    node *curr;
    curr = this->root;
    bool flag = false;
    while(curr != nullptr) {
      comparisonCounter++;
      if(curr->data > d) {
	curr = curr->leftChild;
      }
      else if(curr->data < d) {
	curr = curr->rightChild;
      }
      else {
	flag = true;
	finder = curr;
	return true;
      }
    }
    if (flag == true) {
      finder = curr;
    } else {
      finder = nullptr;
    }
    return flag;
  }

  void insert(int t) {
    if (t > 0) {
      if (root == nullptr) {
	root = new node(t);
	return;
      }
      bool r = true;
      node* traverse = root;
      while (r == true) {
	comparisonCounter++;
	if (t > traverse->data) {
	  if (traverse->rightChild == nullptr) {
	    traverse->rightChild = new node(t);
	    traverse->rightChild->parent = traverse;
	    r = false;
	  }
	  traverse = traverse->rightChild;
	}
	else if (t < traverse->data) {
	  if (traverse->leftChild == nullptr) {
	    traverse->leftChild = new node(t);
	    traverse->leftChild->parent = traverse;
	    r = false;
	  }
	  traverse = traverse->leftChild;
	} else {
	  r = false;
	  cout << "can't insert duplicates!: " << t << endl;
	}
      }
    }
  }
  node* getPredicessor(node* c) { //assume curr has 2 children... ALSO, this is successor not predicessor lol
    node* curr = c;
    curr = curr->rightChild;
    while (curr->leftChild != nullptr) {
      curr = curr->leftChild;
    }
    return curr;
  }
  /*node* getSuccessor(node* curr) {

  }*/
  void remove(int t) {
    this->find(t);
    if (finder != nullptr) {
      if (finder->leftChild == nullptr && finder->rightChild == nullptr) {
	if (finder->parent->leftChild == finder) {
	  finder->parent->leftChild = nullptr;
	} else {
	  finder->parent->rightChild = nullptr;
	}
	if (finder == this->root) {
	  this->root = nullptr;
	}
	finder->parent = nullptr;
	delete finder;
	finder = nullptr;
      }
      else if (finder->leftChild == nullptr && finder->rightChild != nullptr) {
	if (finder != root) { 
	if (finder->parent->leftChild == finder) {
          finder->parent->leftChild = finder->rightChild;
        } else {
          finder->parent->rightChild = finder->rightChild;
        }
	finder->rightChild->parent = finder->parent;

	finder->rightChild = nullptr;
	finder->parent = nullptr;
	delete finder;
	finder = nullptr;
	} else {
	  root = finder->rightChild;
	  finder->rightChild->parent = nullptr;

	  finder->rightChild = nullptr;
	  delete finder;
	}
      }
      else if (finder->leftChild != nullptr && finder->rightChild == nullptr) {
	if (finder != root) {
	if (finder->parent->leftChild == finder) {
          finder->parent->leftChild = finder->leftChild;
        } else {
          finder->parent->rightChild = finder->leftChild;
        }
        finder->leftChild->parent = finder->parent;

        finder->leftChild = nullptr;
        finder->parent = nullptr;
	delete finder;
	finder = nullptr;
	} else {
	  root = finder->leftChild;
	  finder->leftChild->parent = nullptr;

	  finder->leftChild = nullptr;
	    delete finder;
	}
      } else {
	//get predicessor to replace
	node* toReplace = nullptr;
	toReplace = getPredicessor(finder);
	cout << "Predicessor " << toReplace->data << endl;
	//remove predicessor from its current place on tree
	if (toReplace->parent->leftChild == toReplace) {
	  toReplace->parent->leftChild = toReplace->rightChild;//these should be rightChild not leftChild with successor?
	} else {
	  toReplace->parent->rightChild = toReplace->rightChild;
	}
	//now put toReplace where finder is
	if (finder->parent != nullptr) {
	if (finder->parent->leftChild == finder) {
	  finder->parent->leftChild = toReplace;
	} else {
	  finder->parent->rightChild = toReplace;
	}
	}
	toReplace->parent = finder->parent;
	toReplace->leftChild = finder->leftChild;
	toReplace->rightChild = finder->rightChild;
	if (finder->leftChild != nullptr && finder->leftChild != toReplace) {
	  finder->leftChild->parent = toReplace;
	}
	if (finder->rightChild != nullptr) {
	  finder->rightChild->parent = toReplace;
	}
	if (finder == root) {
	  root = toReplace;
	}

	
	finder->parent = nullptr;
	finder->leftChild = nullptr;
	finder->rightChild = nullptr;
	delete finder;
	finder = nullptr;
	
      }
    }
  }
  void printTree(node* curr, int spaces) {
    if (curr->leftChild != nullptr) {
      printTree(curr->leftChild, spaces + 10);
    }
    int i;
    for (i = 0; i < spaces; i++) {
      cout << " ";
    }
    curr->printNode();
    if (curr->rightChild != nullptr) {
      printTree(curr->rightChild, spaces + 10);
    }
  }
  void insertVector(vector<int>* t) {
    int	i = 0;
    for (int i = 0; i < t->size(); i++) {
      insert(t->at(i));
      this->printTree(this->root, 0);
      cout << "____" << endl;
    }
  }
  void removeVector(vector<int>* t) {
    int i = 0;
    for (int i = 0; i < t->size(); i++) {
      remove(t->at(i));
      this->printTree(this->root, 0);
      cout << "____" << endl;
    }
  }
  void shuffle(vector<int> *swap, int s) {
<<<<<<< HEAD
    int r1;
    int r2;
    int t;
    random_device rd;
    mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, swap->size());
    for (int i = 0; i < s; i++) {
      srand((unsigned) time(NULL));
      r1 = dis(gen) % (swap->size());
      r2 = dis(gen) % (swap->size());
      cout << "rand: " << rand() << endl;
      t = swap->at(r1);
      swap->at(r1) = swap->at(r2);
      swap->at(r2) = t;

      for (int j = 0; j < swap->size(); j++) {
	cout << swap->at(j) << ", ";
      }
      cout << endl;
      cout << "next shuffle: " << endl;
=======
    srand((unsigned) time(NULL));
    for (int i = 0; i < s; i++) {
      int r1 = rand() % (swap->size()-1);
 
    }
  }
  void shake(int S, int R, vector<int>* v) {
    int i = 0;
    random_device rd;
    mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, v->size());
    for (i = 0; i < S; i++) {
        srand((unsigned) time(NULL));
        int random = dis(gen) % v->size();
	
	cout << "rand: " << dis(gen) << endl;
        int numOver = (dis(gen) % (R - 1)) + 1;
	numOver = (numOver * 2) - R;
        int toMove = v->at(random);
        v->erase(v->begin() + random);
	int newLoc = random + numOver;
	if (newLoc > v->size() - 1) {
	  newLoc = v->size() - 1;
	}
	if (newLoc < 0) {
	  newLoc = 0;
	}
        v->insert(v->begin() + newLoc, toMove);
    }
  }
  int getHeight(node* curr) {
    int heightLeft = -1;
    int heightRight = -1;
    int height = -1;
    if (curr->leftChild != nullptr) {
      heightLeft = getHeight(curr->leftChild);
    }
    if (curr->rightChild != nullptr) {
	heightRight = getHeight(curr->rightChild);
    }

      if (heightLeft > heightRight) {
	height = heightLeft;
      } else {
	height = heightRight;
      }
      
      return (height + 1);
  }
  double averageDepth() {
    vector<node*> now {this->root};
    vector<node*> next;
    int i = 0;
    double currentDepth = 0;
    double sum = 0;
    double totalNodes = 0;
    while (now.size() > 0) {
      for (i = 0; i < now.size(); i++) {
	sum = sum + currentDepth;
	totalNodes++;
	if (now.at(i)->leftChild != nullptr) {
	  next.push_back(now.at(i)->leftChild);
	}
	if (now.at(i)->rightChild != nullptr) {
	next.push_back(now.at(i)->rightChild);
      }
      }
      //now clear now and set next into now
      now.clear();
      for (i = 0; i < next.size(); i++) {
	now.push_back(next.at(i));
      }
      next.clear();
      currentDepth++;
    }
    return (sum/totalNodes);
  }
  void reset() {
    comparisonCounter = 0;
  }
  int getCount() {
    return comparisonCounter;
  }
  };
