// use class
# include <iostream>

using namespace std;

class StackNode {
  public:
    int val;
    StackNode *above;
    StackNode *under;
    int currentHeight;
    StackNode() {
      above = NULL;
      under = NULL;
    }
    void setValue(int n);
    void setCurrentHeight(int n);
};

void StackNode::setValue(int n) {
  this->val = n;
}

void StackNode::setCurrentHeight(int n) {
  this->currentHeight = n;
}

class Stack {
  public:
    StackNode *top;
    StackNode *bottom;
    int limitHeight;
    Stack(int n) {
      top = new StackNode();
      bottom= new StackNode();
      limitHeight = n;
    }
    void push(int n);
    int pop();
};

void Stack::push(int n) {
  // check top->node currentHeight
  if(this->top->under == NULL || this->top->under->currentHeight < this->limitHeight) {
    StackNode *newNode, *current;

    newNode = new StackNode();
    newNode->val = n;
    newNode->above = NULL;
    newNode->under = NULL;

    // get the last node and make "above" of the node pointing the new node
    current = this->bottom;
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
    this->top->under = newNode;
    cout << n << " ";
  } else {
    cout << "\nover limitHeight of stack" << endl;
  }
}

int Stack::pop() {
  StackNode *current;

  // from top
  current = this->top->under;

  // if stack is empty
  if(current == NULL) {
    cout << "this stack is empty" << endl;
    return 0;
  }

  int pop = current->val;
  top->under->above = NULL;
  top->under = current->under;

  // free ram
  delete current;
  return pop;
}

int main() {
  Stack stack(5);

  stack.push(5);
  stack.push(4);
  stack.push(3);
  stack.push(2);
  stack.push(1);
  stack.push(1);
  stack.push(1);


  cout << "pop " << stack.pop() << endl;
  cout << "pop " << stack.pop() << endl;
  cout << "pop " << stack.pop() << endl;
  cout << "pop " << stack.pop() << endl;
  cout << "pop " << stack.pop() << endl;
  cout << "pop " << stack.pop() << endl;
  cout << "pop " << stack.pop() << endl;


  return 0;
}