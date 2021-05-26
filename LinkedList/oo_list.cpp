// use class
# include <iostream>

using namespace std;

class ListNode {
  public:
    int val;
    ListNode *next;
    ListNode() {
      next = NULL;
    }
    void setValue(int n);
};

void ListNode::setValue(int n) {
  this->val = n;
}

class LinkedList {
  public:
    ListNode *start;
    LinkedList() {
      start = new ListNode();
    }
    void appendNode(int n);
    void printList();
};

// append node
void LinkedList::appendNode(int n){

  ListNode *newNode, *current;

  // create new node and give it value
  newNode = new ListNode();
  newNode->val = n;

  // get the last node and make "next" of the node pointing the new node
  current = this->start;
  while(current->next != NULL) {
    current = current->next;
  }

  current->next = newNode;
  cout << "push " << n << " in list" << endl;
}

// iterator link list and print every node value
void LinkedList::printList() {
  ListNode *current;
  current = this->start;

  while(current->next != NULL) {
    current = current->next;
    cout << "node value: " << current->val << endl;
  }
  cout << "printList ---  end  ---" << endl;

}

int main() {
  LinkedList list;

  list.appendNode(1);
  list.appendNode(4);
  list.appendNode(3);

  list.printList();

  return 0;
}