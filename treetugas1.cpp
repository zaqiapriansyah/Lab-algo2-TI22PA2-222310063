#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

Node *newNode(int x) {
  Node *node = new Node();
  node->data = x;
  node->left = node->right = NULL;
  return node;
}

void preorderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }
  cout << root->data << " ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void inorderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }
  inorderTraversal(root->left);
  cout << root->data << " ";
  inorderTraversal(root->right);
}

void postorderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout << root->data << " ";
}

int main() {
  Node *root = newNode(12);
  root->left = newNode(16);
  root->right = newNode(20);
  root->left->left = newNode(24);
  root->left->right = newNode(32);

  cout << "Pre-order traversal: ";
  preorderTraversal(root);
  cout << endl;

  cout << "In-order traversal: ";
  inorderTraversal(root);
  cout << endl;

  cout << "Post-order traversal: ";
  postorderTraversal(root);
  cout << endl;

  return 0;
}