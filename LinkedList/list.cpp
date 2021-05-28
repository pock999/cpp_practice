// use struct
# include <iostream>

typedef struct node {
  int val;
  struct node *next;
} ListNode;

ListNode *start;

// initial
void init() {
  // free before malloc
  free(start);
  start = NULL;
  // malloc
  start = (ListNode *)malloc(sizeof(ListNode));
  start->next = NULL;
}

// append node
void appendNode(int n) {
  using namespace std;
  ListNode *newNode, *current;

  // create new node and give it value
  newNode = (ListNode *)malloc(sizeof(ListNode));
  newNode->val = n;
  newNode->next = NULL;

  // get the last node and make "next" of the node pointing the new node
  current = start;
  while(current->next != NULL) {
    current = current->next;
  }

  current->next = newNode;

  cout << "push " << n << " in list" << endl;
}

// iterator link list and print every node value
void printList() {
  using namespace std;
  ListNode *current;

  cout << "printList --- start ---" << endl;
  current = start;
  while(current->next != NULL) {
    current = current->next;
    cout << current->val << "->";
  }
  cout << "null" << endl;
  cout << "printList ---  end  ---" << endl;
}

int main() {

  init();
  appendNode(1);
  appendNode(5);
  appendNode(3);

  printList();

  return 0;
}