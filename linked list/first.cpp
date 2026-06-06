#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
};

void insertAtHead(Node *&head, int d)
{
  Node *temp = new Node(d);
  temp->next = head;
  head = temp;
}

void insertAtEND(Node *&tail, int d)
{
  Node *temp = new Node(d);
  tail->next = temp;
  tail = temp;
}
// traverse a ll

void print(Node *&head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
  Node *node1 = new Node(10);
  cout << node1->data << endl;
  cout << node1->next << endl;

  Node *head = node1;
  Node *tail = node1;
  // print(head);
  // insertAtHead(head, 20);
  // print(head);

  // insertAtHead(head, 30);
  // print(head);

  print(head);
  insertAtEND(tail, 20);
  print(head);

  insertAtEND(tail, 30);
  print(head);
  return 0;
}