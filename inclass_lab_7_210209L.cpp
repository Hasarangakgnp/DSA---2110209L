#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) {
        traverseInOrder(root->left);
        cout << root->key << " ";
        traverseInOrder(root->right);
    }
}

// Insert a node
struct node *insertNode(struct node *root, int key) {
  if (root == NULL) {
    struct node *newnode = new node;
    newnode->key = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
  }
  else if (key < root->key) {
    root->left = insertNode(root->left, key);
  }
  else if (key > root->key) {
    root->right = insertNode(root->right, key);
  }
  return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {

  if(root == NULL){
    return root;
  }
  else if(key<root->key){
    root->left = deleteNode(root->left,key);
  }else if(key>root->key){
    root->right = deleteNode(root->right,key);
  }else{
    if(root->left == NULL && root->right==NULL ){
        root == NULL;
    }else if(root->left==NULL){
        root = root->right;
    }else if(root->right==NULL){
        root = root->left;
    }else{
        while(root->right->left != NULL){
            root->right = root->right->left;
        }
        int minimum = root->right->key;
        root->key = minimum;
        root->right = deleteNode(root->right,minimum);
    }
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }

  traverseInOrder(root);

  return 0;
}
