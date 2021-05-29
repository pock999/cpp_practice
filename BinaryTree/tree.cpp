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

  // TODO: My Unskilled place
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
void preorderTraversal(TreeNode *rootp) {
  TreeNode *current, *previos;
  current = rootp;
  previos = NULL;
  if(current != NULL) {
    cout << current->val << " ";
    preorderTraversal(current->left);
    preorderTraversal(current->right);
  }
}

// 中序
void inorderTraversal(TreeNode *rootp) {
  TreeNode *current, *previos;
  current = rootp;
  previos = NULL;
  if(current != NULL) {
    inorderTraversal(current->left);
    cout << current->val << " ";
    inorderTraversal(current->right);
  }
}

// 後序
void postorderTraversal(TreeNode *rootp) {
  TreeNode *current, *previos;
  current = rootp;
  previos = NULL;
  if(current != NULL) {
    postorderTraversal(current->left);
    postorderTraversal(current->right);
    cout << current->val << " ";
  }
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

  cout << "=== preorderTraversal start ===" << endl;
  preorderTraversal(root);
  cout << "=== preorderTraversal  end  ===\n" << endl;

  cout << "=== inorderTraversal start ===" << endl;
  inorderTraversal(root);
  cout << "=== inorderTraversal  end  ===\n" << endl;

  cout << "=== postorderTraversal start ===" << endl;
  postorderTraversal(root);
  cout << "=== postorderTraversal  end  ===" << endl;

  return 0;
}

