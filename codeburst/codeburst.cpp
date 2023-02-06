#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

//https://codeburst.io/100-coding-interview-questions-for-programmers-b1cf74885fb7

// Problem: 1
// Name: Bubble Sort

bool isSorted(vector<int>& vec) {
  for (int x = 0; x < vec.size() - 1; x++) {
    if (vec[x] > vec[x + 1]) return false;
  }
  return true;
}

void swap(int a, int b, vector<int>& vec) {
  int c = vec[a];
  vec[a] = vec[b];
  vec[b] = c;
}

void bubbleSort(vector<int>& vec) {
  while (!isSorted(vec)) {
    for (int x = 0; x < vec.size() - 1; x++) {
      if (vec[x] > vec[x + 1]) swap(x, x + 1, vec);
    }
  }
}

void printVector(vector<int>& vec) {
  for (int i : vec) cout << i << ' ';
  cout << endl;
}

void printVector(vector<double>& vec) {
  for (double i : vec) cout << i << ' ';
  cout << endl;
}

void testProblem1() {
  vector<int> vec{ 10,1,4,2,8,5,9 };
  printVector(vec);
  bubbleSort(vec);
  printVector(vec);
}

// Problem: 2
// Name: Merge Sort

void mergeSort(vector<int>& vec) {
  if (vec.size() <= 1) return; // 1 / 0 elements, already sorted

  vector<int> first(vec.begin(), vec.begin() + vec.size() / 2);
  vector<int> last(vec.begin() + vec.size() / 2, vec.end());

  mergeSort(first);
  mergeSort(last);

  int vecPos = 0, firstPos = 0, lastPos = 0;

  while (firstPos < first.size() && lastPos < last.size()) {
    if (first[firstPos] < last[lastPos]) {
      vec[vecPos] = first[firstPos];
      firstPos++;
    } else {
      vec[vecPos] = last[lastPos];
      lastPos++;
    }
    vecPos++;
  }

  while (firstPos < first.size()) {
    vec[vecPos] = first[firstPos];
    firstPos++; vecPos++;
  }

  while (lastPos < last.size()) {
    vec[vecPos] = last[lastPos];
    lastPos++; vecPos++;
  }
}

void testProblem2() {
  vector<int> vec{ 10,1,4,2,8,5,9 };
  printVector(vec);
  mergeSort(vec);
  printVector(vec);
}

// Problem: 3
// Name: Character Count

int countChar(char c, string str) {
  const char* arr = str.c_str();
  int counter = 0;
  for (int x = 0; x < str.size(); x++)
    if (arr[x] == c) counter++;
  return counter;
}

void testProblem3() {
  string str = "i think therefore i am";
  char c = 't';
  cout << "String: " << str << endl;
  cout << "Occurrences of " << c << ": " << countChar(c, str) << endl;
}

// Problem: 4
// Name: First Unique Character

char firstUniqueChar(string str) {
  vector<int> charCounter(CHAR_MAX);
  for (char c : str) charCounter[c]++;
  for (char c : str)
    if (charCounter[c] == 1)
      return c;
  return -1;
}

void testProblem4() {
  string str = "i think therefore i am";
  cout << "String" << str << endl;
  cout << "Unique: " << firstUniqueChar(str) << endl;
}

// Problem: 5
// Name: String to Int

int strToInt(string str) {
  int num = 0;
  for (char c : str)
    num = num * 10 + (c - '0');

  return num;
}

void testProblem5() {
  string str = "1234567890";
  cout << "String: " << str << endl;
  cout << "Int: " << strToInt(str) << endl;
}

// Problem: 6
// Name: Bucket Sort

void bucketSort(vector<double>& vec) {
  double origin = 0, unit = 0.1;
  vector<vector<double>> buckets(10);

  for (double i : vec)
    buckets[(int)(i / unit)].push_back(i);

  int pos = 0;
  for (auto b : buckets) {
    sort(b.begin(), b.end());
    for (double i : b)
      vec[pos++] = i;
  }
}

void testProblem6() {
  vector<double> vec{ 0.13,0.23,0.94,0.53,0.25,0.03,0.85 };
  printVector(vec);
  bucketSort(vec);
  printVector(vec);
}

// Problem: 7
// Name: Counting Sort

void countingSort(vector<int>& vec) {
  vector<int> count(10);
  for (int i : vec) count[i]++;
  int pos = 0;
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < count[i]; j++)
      vec[pos++] = i;
}

void testProblem7() {
  vector<int> vec{ 1,3,3,6,2,6,1,1,9,9,3,2,5,3,0 };
  printVector(vec);
  countingSort(vec);
  printVector(vec);
}

// Problem: 8
// Name: Remove Duplicates

void removeDuplicates(vector<int>& vec) {
  set<int> history;
  vector<int>::iterator pos = vec.begin();
  for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
    if (history.find(*it) == history.end()) {
      history.insert(*it);
      *pos = *it;
      pos++;
    }
  }

  while (pos != vec.end())
    *(pos++) = 0;
}

void testProblem8() {
  vector<int> vec{ 1,3,3,6,2,6,1,1,9,9,3,2,5,3,0,4,1 };
  printVector(vec);
  removeDuplicates(vec);
  printVector(vec);
}

// Problem: 9
// Name: Reverse Array

void reverseArray(vector<int>& vec) {
  int half = vec.size() / 2;
  for (int x = 0; x < half; x++) {
    swap(x, vec.size() - x - 1, vec);
  }
}

void testProblem9() {
  vector<int> vec{ 0,1,2,3,4,5,6,7,8,9 };
  printVector(vec);
  reverseArray(vec);
  printVector(vec);
}

// Problem: 10
// Name: Remove Duplicates Without Library

void removeDuplicates2(vector<int>& vec) {
  int pos = 1;
  bool flag;
  for (int i = 1; i < vec.size(); i++) {

    flag = true; // check if elem is dupe
    for (int j = 0; j < i; j++) {
      if (vec[i] == vec[j]) {
        flag = false;
        break;
      }
    }

    if (flag) vec[pos++] = vec[i];
  }

  while (pos < vec.size()) vec[pos++] = 0;
}

void testProblem10() {
  vector<int> vec{ 1,3,3,6,2,6,1,1,9,9,3,2,5,3,0,4,1 };
  printVector(vec);
  removeDuplicates2(vec);
  printVector(vec);
}

// Problem: 11
// Name: Radix Sort

void radixSort(vector<int>& vec) {
  vector<vector<int>> buckets(10);
  int radix = 10, digit = 1, pos;
  bool flag = true;

  while (flag) {
    flag = false;
    for (int i : vec) {
      if (i / digit >= radix) flag = true;
      buckets[(i / digit) % radix].push_back(i);
    }

    pos = 0;
    for (int i = 0; i < radix; i++) {
      for (int j : buckets[i]) {
        vec[pos++] = j;
      }

      buckets[i].clear();
    }

    digit *= radix;
  }

}

void testProblem11() {
  vector<int> vec{ 11,32,64,35,85,76,38,82,10,93,82,13,75 };
  printVector(vec);
  radixSort(vec);
  printVector(vec);
}

// Problem: 12
// Name: Inplace Swap

void inplaceSwap(int& a, int& b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}

void testProblem12() {
  int a = 10;
  int b = 20;

  cout << a << " " << b << endl;
  inplaceSwap(a, b);
  cout << a << " " << b << endl;
}

// Problem: 13
// Name: Overlapped Rectangles

bool isOverlapped(int x1, int x2, int y1, int y2, int x3, int x4, int y3, int y4) {
  return (x1 > x4) || (x2 > x3) &&
    (y1 > y4) || (y2 > y3);
}

void testProblem13() {
  int a1 = 100, b1 = 400, c1 = 0, d1 = 200;
  int a2 = 100, b2 = 300, c2 = 250, d2 = 300;
  cout << a1 << " " << b1 << " " << c1 << " " << d1 << " | " << a2 << " " << b2 << " " << c2 << " " << d2 << " ; " << isOverlapped(a1, b1, c1, d1, a2, b2, c2, d2) << endl;
  c2 = 150; d2 = 250;
  cout << a1 << " " << b1 << " " << c1 << " " << d1 << " | " << a2 << " " << b2 << " " << c2 << " " << d2 << " ; " << isOverlapped(a1, b1, c1, d1, a2, b2, c2, d2) << endl;
}

// Problem: 14
// Name: Vending Machine

void vendingMachine() {
  vector<pair<string, int>> inventory{
    {"chips", 5},
    {"pretzels", 3},
    {"water", 10},
    {"gummy bears", 7}
  };

  int choice;

  do {
    cout << "Available Items: " << endl;
    for (int i = 0; i < inventory.size(); i++)
      cout << i << ": " << inventory[i].first << " x" << inventory[i].second << endl;
    cout << endl << "What would you like? (-1 to exit) ";
    cin >> choice;

    if (choice >= 0 && choice < inventory.size()) {
      if (inventory[choice].second <= 0) {
        cout << "Out of stock!" << endl;
        continue;
      }
      cout << endl << "Here is one " << inventory[choice].first << "!" << endl << endl;
      inventory[choice].second--;
    }
  } while (choice != -1);

  cout << "Thank you for using this vending machine" << endl;
}

void testProblem14() {
  vendingMachine();
}

// Problem: 15
// Name: Missing Numbers

void missingNumbers(vector<int>& vec, int limit) {
  set<int> numbers;
  for (int i : vec) numbers.insert(i);
  for (int i = 0; i < limit; i++) {
    if (numbers.find(i) == numbers.end()) {
      cout << "Missing Number: " << i << endl;
    }
  }
}

void testProblem15() {
  vector<int> vec{ 3,2,6,4,8,0,4,2,9,6 };
  printVector(vec);
  missingNumbers(vec, 10);
}

// Problem: 16 + 17
// Name: Duplicate Numbers

void duplicateNumber(vector<int>& vec, int limit) {
  set<int> numbers;
  for (int i : vec) {
    if (numbers.find(i) != numbers.end())
      cout << "Duplicate Number: " << i << endl;
    numbers.insert(i);
  }
}

void testProblem16() {
  vector<int> vec{ 1,2,3,4,5,6,7,8,9,10,5 };
  printVector(vec);
  duplicateNumber(vec, 10);
}

// Problem: 18
// Stable sorts keep the intial order of elements when their values are equal.
// Unstable sorts do not do this

// Problem: 19
// Iterative Quicksort

void iterQuicksort(vector<int>& vec) {
  queue<pair<int, int>> worker;
  pair<int, int> task;
  int pivot, low, high;
  worker.emplace(0, vec.size() - 1);

  while (worker.size() != 0) {
    task = worker.front(); worker.pop();
    if (task.first >= task.second) continue; // 1 or less element, already sorted

    pivot = vec[task.first];
    low = task.first; high = task.second;

    for (int i = task.first + 1; i <= high; i++) {
      if (vec[i] < pivot) {
        swap(vec[low++], vec[i]);
      } else {
        swap(vec[high--], vec[i]);
        i--;
      }
    }

    worker.emplace(task.first, low - 1);
    worker.emplace(high + 1, task.second);
  }
}

void testProblem19() {
  vector<int> vec{ 11,32,64,35,85,76,38,82,10,93,82,13,75 };
  printVector(vec);
  iterQuicksort(vec);
  printVector(vec);
}


// Problem: 20
// Numeric Extremes

void extremes(vector<int>& vec) {
  int a = vec[0];
  int b = vec[0];

  for (int i : vec) {
    a = min(i, a);
    b = max(i, b);
  }

  cout << "Min: " << a << endl;
  cout << "Max: " << b << endl;
}

void testProblem20() {
  vector<int> vec{ 11,32,64,35,85,76,38,82,10,93,82,13,75 };
  printVector(vec);
  extremes(vec);
}

// Problem: 21
// Name: LinkedList Inplace Reverse

template <typename T>
class node {
public:
  node() {}
  node* child = NULL;
  T value;
};

template <typename T>
node<T>* vecToLinkedList(vector<T>& vec) {
  node<T>* root = new node<T>(), * pos = root, * tmp;
  for (auto i : vec) {
    tmp = new node<T>();
    tmp->value = i;
    pos->child = tmp;
    pos = pos->child;
  }

  return root->child;
}

void printLinkedList(node<int>* root) {
  while (root != NULL) {
    cout << root->value << " ";
    root = root->child;
  }
  cout << endl;
}

node<int>* reverseLinkedList(node<int>* root) {
  node<int>* a = root, * b = root->child, * c;
  root->child = NULL;
  while (b != NULL) {
    c = b->child;
    b->child = a;
    a = b; b = c;
  }

  return a;
}

void testProblem21() {
  vector<int> vec{ 1,2,3,4,5,6,7 };
  node<int>* root = vecToLinkedList(vec);
  printLinkedList(root);
  root = reverseLinkedList(root);
  printLinkedList(root);
}

// Problem: 22
// Name: LinkedList insert

node<int>* insert(int num, int pos, node<int>* root) {
  node<int>* a = root, * tmp = new node<int>(); tmp->value = num;
  if (pos == 0) {
    tmp->child = root;
    return tmp;
  }

  for (int x = 0; x < pos - 2; x++) a = a->child;
  tmp->child = a->child;
  a->child = tmp;

  return root;
}

void testProblem22() {
  vector<int> vec{ 1,2,3,4,5,6,7 };
  node<int>* root = vecToLinkedList(vec);
  printLinkedList(root);
  root = insert(10, 0, root);
  root = insert(20, 1, root);
  root = insert(30, 5, root);
  printLinkedList(root);
}

//Problem: 23
// Name: Sorted LinkedList

node<int>* sortLinkedList(node<int>* root) {
  return root; //TODO
}

void testProblem23() {
  vector<int> vec{ 1,5,2,7,6,4,3};
  node<int>* root = vecToLinkedList(vec);
  printLinkedList(root);
  root = sortLinkedList(root);
  printLinkedList(root);
}

int main() {
  testProblem23();
}
