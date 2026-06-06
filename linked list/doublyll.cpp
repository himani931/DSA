#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;

  Node(int data)
  {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
  }

  Node(int data, Node *next, Node *prev)
  {
    this->data = data;
    this->next = next;
    this->prev = prev;
  }
};

Node *convertRR2LL(vector<int> &arr)
{
  Node *head = new Node(arr[0]);
  Node *prev = head;
  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp;
  }
  return head;
}

void print(Node *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
}

// Deletion

Node *delHead(Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return NULL;
  }
  Node *temp = head;
  head = head->next;
  head->prev = NULL;
  temp->next = NULL;
  free(temp);

  return head;
}

Node *deltail(Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return NULL;
  }
  Node *tail = head;
  while (tail->next != NULL)
  {
    tail = tail->next;
  }
  Node *temp = tail->prev;
  temp->next = NULL;
  tail->prev = NULL;

  free(tail);

  return head;
}

Node *delk(Node *head, int k)
{
  if (head == NULL)
  {
    return NULL;
  }
  int cnt = 0;
  Node *temp = head;
  while (temp != NULL)
  {
    cnt++;
    if (cnt == k)
      break;
    temp = temp->next;
  }
  Node *back = temp->prev;
  Node *front = temp->next;

  if (back == NULL && front == NULL)
  {
    return NULL;
  }
  else if (front == NULL)
  {
    deltail(head);
  }
  else if (back == NULL)
  {
    delHead(head);
  }
  else
  {
    back->next = front;
    front->prev = back;
    temp->next = NULL;
    temp->prev = NULL;
    free(temp);
    return head;
  }
}

void delNode(Node *temp)
{
  Node *back = temp->prev;
  Node *front = temp->next;

  if (front == NULL)
  {
    back->next = NULL;
    temp->prev = NULL;
    free(temp);
    return;
  }
  back->next = front;
  front->prev = back;

  temp->prev = NULL;
  temp->next = NULL;
  free(temp);
}

// insertion
Node *insertbefHead(Node *head, int val)
{
  Node *newHead = new Node(val, head, nullptr);
  head->prev = newHead;
  return newHead;
}

Node *insertbefTail(Node *head, int val)
{
  if (head->next == NULL)
  {
    return insertbefHead(head, val);
  }
  Node *tail = head;
  while (tail->next != NULL)
  {
    tail = tail->next;
  }
  Node *temp = tail->prev;
  Node *newNode = new Node(val, tail, temp);
  temp->next = newNode;
  tail->prev = newNode;

  return head;
}

Node *insertBrfK(Node *head, int k, int val)
{
  if (k == 1)
  {
    insertbefHead(head, val);
  }
  Node *temp = head;
  int cnt = 0;
  while (temp != NULL)
  {
    cnt++;
    if (cnt == k)
      break;
    temp = temp->next;
  }
  Node *back = temp->prev;
  Node *newNode = new Node(val, temp, back);
  back->next = newNode;
  temp->prev = newNode;
  return head;
}

void insertBefNode(Node *node, int val)
{
  Node *back = node->prev;
  Node *newNode = new Node(val, node, back);
  back->next = newNode;
  node->prev = newNode;
}

int main()
{
  vector<int> arr = {12, 5, 8, 7};
  Node *head = convertRR2LL(arr);
  // print(head);

  // head = delk(head, 1);
  // delNode(head->next);
  // head = insertBrfK(head, 4, 100);
  insertBefNode(head->next, 100);
  print(head);
  return 0;
}