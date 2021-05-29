// use class
# include <iostream>

using namespace std;

class TreeNode {
  public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {
      left = NULL;
      right = NULL;
    }
    void setValue(int n);
};

void TreeNode::setValue(int n) {
  this->val = n;
}

class Tree {
  public:
    TreeNode *root;
    Tree() {
      root = NULL;
    }
    void appendNode(int n);
    void preorderTraversal(TreeNode *rootp);
    void inorderTraversal(TreeNode *rootp);
    void postorderTraversal(TreeNode *rootp);
};

void Tree::appendNode(int n) {
  TreeNode *newNode;
  
  // create new node and give it value
  newNode = new TreeNode();
  newNode->setValue(n);

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

void Tree::preorderTraversal(TreeNode *rootp) {
  TreeNode *current, *previos;
  current = rootp;
  previos = NULL;
  if(current != NULL) {
    cout << current->val << " ";
    preorderTraversal(current->left);
    preorderTraversal(current->right);
  }
}

void Tree::inorderTraversal(TreeNode *rootp) {
  TreeNode *current, *previos;
  current = rootp;
  previos = NULL;
  if(current != NULL) {
    inorderTraversal(current->left);
    cout << current->val << " ";
    inorderTraversal(current->right);
  }
}

void Tree::postorderTraversal(TreeNode *rootp) {
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
  Tree tree;
  cout << "insert in: " << endl;
  tree.appendNode(5);
  tree.appendNode(3);
  tree.appendNode(2);
  tree.appendNode(7);
  tree.appendNode(6);
  tree.appendNode(3);
  cout << endl;

  cout << "=== preorderTraversal start ===" << endl;
  tree.preorderTraversal(tree.root);
  cout << "=== preorderTraversal  end  ===\n" << endl;

  cout << "=== inorderTraversal start ===" << endl;
  tree.inorderTraversal(tree.root);
  cout << "=== inorderTraversal  end  ===\n" << endl;

  cout << "=== postorderTraversal start ===" << endl;
  tree.postorderTraversal(tree.root);
  cout << "=== postorderTraversal  end  ===" << endl;

  return 0;
}