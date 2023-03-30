#include <iostream>

using namespace std;

class Node {
private:
  int val; 
  Node *left;
  Node *right;
  Node *parent;
  
public:
  int getVal() {
    return val;
  }
  Node* getLeft() {
    return *left;
  }
  Node* getRight() {
    return *right;
  }
  Node* getParent() {
    return *parent;
  }
  Node(const int& d, Node *p = nullptr,  Node* l = nullptr, Node* r = nullptr) {
    val = d;
    parent = p;
    left = l;
    right = r;
};
class BST {
private:
  Node *root;
  int size;

public:
  BST() {
    root = nullptr;
    size = 0;
  }
  
  bool find(int d) {
    Node *curr;
    curr = this->root;
    bool flag = false;
    while(curr->left == nullptr && curr->right == nullptr) {
      if(curr->val > d) {
	curr = curr->left;
      }
      else if(curr->val < d) {
	curr = curr->right;
      }
      else {
	flag = true;;
      }
    }
    return flag;
  }
};

  int main() {
    
  
