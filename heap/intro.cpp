#include <iostream>
#include <vector>
using namespace std;

class heap
{
public:
  int arr[100];
  int size;

  heap()
  {
    arr[0] = -1;
    size = 0;
  }

  void insert(int val)
  {
    size++;
    int idx = size;
    arr[idx] = val;
    while (idx > 1)
    {
      int parent = idx / 2;

      if (arr[parent] < arr[idx])
      {
        swap(arr[parent], arr[idx]);
        idx = parent;
      }
      else
        return;
    }
  }

  void deletefromHeap()
  {
    if (size == 0)
    {
      cout << "Nothing to delete" << endl;
      return;
    }

    arr[1] = arr[size];
    size--;

    int i = 1;
    while (i < size)
    {
      int leftChild = 2 * i;
      int rightChild = 2 * i + 1;
      int largest = i;

      if (leftChild <= size && arr[leftChild] > arr[largest])
        largest = leftChild;

      if (rightChild <= size && arr[rightChild] > arr[largest])
        largest = rightChild;

      if (largest == i)
        return;

      swap(arr[i], arr[largest]);
      i = largest;
    }
  }

  void print()
  {
    for (int i = 1; i <= size; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

void heapify(int arr[], int n, int i)
{
  int large = i;
  int leftchild = 2 * i;
  int rightchild = 2 * i + 1;

  if (leftchild <= n && arr[large] < arr[leftchild])
  {
    large = leftchild;
  }

  if (rightchild <= n && arr[rightchild] > arr[large])
    large = rightchild;

  if (large == i)
    return;

  swap(arr[i], arr[large]);
  heapify(arr, n, large);
}

// min heap

void minheapify(vector<int> &arr, int n, int i)
{
  int small = i;
  int leftchild = 2 * i + 1;
  int rightchild = 2 * i + 2;

  if (leftchild < n && arr[leftchild] < arr[small])
  {
    small = leftchild;
  }

  if (rightchild < n && arr[rightchild] < arr[small])
  {
    small = rightchild;
  }

  if (small == i)
    return;

  swap(arr[i], arr[small]);

  minheapify(arr, n, small);
}

vector<int> buildMinHeap(vector<int> &arr)
{
  int n = arr.size();

  for (int i = n / 2 - 1; i >= 0; i--)
  {
    minheapify(arr, n, i);
  }

  return arr;
}

// heap sort

void heapSort(int arr[], int n)
{
  int size = n;
  while (size > 1)
  {
    swap(arr[size], arr[1]);
    size--;
    heapify(arr, size, 1);
  }
}

int main()
{

  heap h;
  h.insert(60);
  h.insert(70);
  h.insert(50);
  h.insert(55);
  h.insert(40);
  h.insert(15);
  h.insert(82);

  cout << "Heap : ";

  h.print();

  h.deletefromHeap();

  cout << "After deletion : ";
  h.print();

  int arr[6] = {-1, 54, 53, 55, 52, 50};
  int n = 5;

  for (int i = n / 2; i > 0; i--)
  {
    heapify(arr, n, i);
  }

  cout << "Printing arr : ";
  for (int i = 1; i <= n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  heapSort(arr, n);

  cout << "Printing sorted arr : ";
  for (int i = 1; i <= n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  vector<int> arr1 = {10, 5, 20, 2, 4};

  buildMinHeap(arr1);

  cout << "Min Heap: ";
  for (int x : arr1)
  {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}