// use struct
# include <iostream>

using namespace std;

typedef struct node {
  int val;
  struct node *left;
  struct node *right;
} TreeNode;

TreeNode *root;

// initial
void init() {
  // free before malloc
  free(root);
  root = NULL;
}

void appendNode(int n) {

  TreeNode *newNode;
  // create new node and give it value
  newNode = (TreeNode *)malloc(sizeof(TreeNode));
  newNode->val = n;
  newNode->left = NULL;
  newNode->right = NULL;


  TreeNode *current, *previos;
  current = root;
  previos = NULL;

  while(current != NULL) {
    previos = current;
    if (newNode->val < current->val){
      current = current->left;
    }
    else{
      current = current->right;
    }
  }

  if (previos == NULL){
    root = newNode;
    cout << n << "-";
  } else if (newNode->val < previos->val){
    previos->left = newNode;
    cout << n << "-";
  } else if(newNode->val > previos->val) {
    previos->right = newNode;
    cout << n << "-";
  } else {
    cout << "(" << n << " has already exists)" << endl;
  }
}

// 前序
void preorderTraversal() {

}

// 中序
void inorderTraversal() {

}

// 後序
void postorderTraversal() {

}

int main() {
  init();

  cout << "insert in: " << endl;
  appendNode(5);
  appendNode(3);
  appendNode(2);
  appendNode(7);
  appendNode(6);
  appendNode(3);
  cout << endl;

  return 0;
}

