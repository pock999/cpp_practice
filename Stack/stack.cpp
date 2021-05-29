// use struct
# include <iostream>

using namespace std;

typedef struct node {
  int val;
  struct node *above;
  struct node *under;
  int currentHeight;
} StackNode;

StackNode *bottom;
StackNode *top;
int limitHeight = 5;

// initial
void init() {
  // free before malloc
  free(bottom);
  bottom = NULL;

  free(top);
  top = NULL;

  // malloc
  bottom = (StackNode *)malloc(sizeof(StackNode));
  bottom->above = NULL;
  bottom->under = NULL;
  bottom->currentHeight = 0;

  top = (StackNode *)malloc(sizeof(StackNode));
  top->above = NULL;
  top->under = NULL;
  top->currentHeight = 0;
}

void pushStack(int n) {
  // check top->node currentHeight
  if(top->under == NULL || top->under->currentHeight < limitHeight) {
    StackNode *newNode, *current;

    // create new node and give it value
    newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->val = n;
    newNode->above = NULL;
    newNode->under = NULL;

    // get the last node and make "above" of the node pointing the new node
    current = bottom;
    int curHeight = current->currentHeight;
    while(current->above != NULL) {
      current = current->above;
      curHeight = current->currentHeight;
    }

    newNode->currentHeight = curHeight+1;

    // if stack is empty, then the new node under be appointed "NULL".
    if(curHeight == 0) {
      newNode->under = NULL;
    } else {
      newNode->under = current;
    }
    
    current->above = newNode;
    top->under = newNode;
    cout << n << " ";
  } else {
    cout << "\nover limitHeight of stack" << endl;
  }
}

int popStack() {
  StackNode *current;

  // from top
  current = top->under;

  // if stack is empty
  if(current == NULL) {
    cout << "this stack is empty" << endl;
    return 0;
  }
  int pop = current->val;
  top->under->above = NULL;
  top->under = current->under;

  // free ram
  free(current);
  return pop;
}

int main() {
  init();
  
  cout << "push in: " << endl;
  pushStack(1);
  pushStack(2);
  pushStack(3);
  pushStack(4);
  pushStack(6);
  pushStack(7);
  cout << endl;

  cout << "pop " << popStack() << endl;
  cout << "pop " << popStack() << endl;
  cout << "pop " << popStack() << endl;
  cout << "pop " << popStack() << endl;
  cout << "pop " << popStack() << endl;
  cout << "pop " << popStack() << endl;
  cout << "pop " << popStack() << endl;

  return 0;
}