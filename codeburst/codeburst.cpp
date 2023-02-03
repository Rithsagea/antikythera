#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

//https://codeburst.io/100-coding-interview-questions-for-programmers-b1cf74885fb7

// Problem: 1
// Name: Bubble Sort

bool isSorted(vector<int> &vec) {
  for(int x = 0; x < vec.size() - 1; x++) {
    if(vec[x] > vec[x + 1]) return false;
  }
  return true;
}

void swap(int a, int b, vector<int> &vec) {
  int c = vec[a];
  vec[a] = vec[b];
  vec[b] = c;
}

void bubbleSort(vector<int> &vec) {
  while(!isSorted(vec)) {
    for(int x = 0; x < vec.size() - 1; x++) {
      if(vec[x] > vec[x + 1]) swap(x, x + 1, vec);
    }
  }
}

void printVector(vector<int> &vec) {
  for(int i : vec) cout << i << ' ';
  cout << endl;
}

void printVector(vector<double> &vec) {
  for(double i : vec) cout << i << ' ';
  cout << endl;
}

void testProblem1() {
  vector<int> vec{10,1,4,2,8,5,9};
  printVector(vec);
  bubbleSort(vec);
  printVector(vec);
}

// Problem: 2
// Name: Merge Sort

void mergeSort(vector<int> &vec) {
  if(vec.size() <= 1) return; // 1 / 0 elements, already sorted

  vector<int> first(vec.begin(), vec.begin() + vec.size() / 2);
  vector<int> last(vec.begin() + vec.size() / 2, vec.end());

  mergeSort(first);
  mergeSort(last);

  int vecPos = 0, firstPos = 0, lastPos = 0;

  while(firstPos < first.size() && lastPos < last.size()) {
    if(first[firstPos] < last[lastPos]) {
      vec[vecPos] = first[firstPos];
      firstPos++;
    } else {
      vec[vecPos] = last[lastPos];
      lastPos++;
    }
    vecPos++;
  }

  while(firstPos < first.size()) {
    vec[vecPos] = first[firstPos];
    firstPos++; vecPos++;
  }

  while(lastPos < last.size()) {
    vec[vecPos] = last[lastPos];
    lastPos++; vecPos++;
  }
}

void testProblem2() {
  vector<int> vec{10,1,4,2,8,5,9};
  printVector(vec);
  mergeSort(vec);
  printVector(vec);
}

// Problem: 3
// Name: Character Count

int countChar(char c, string str) {
  const char * arr = str.c_str();
  int counter = 0;
  for(int x = 0; x < str.size(); x++)
    if(arr[x] == c) counter++;
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
  for(char c : str) charCounter[c]++;
  for(char c : str)
    if(charCounter[c] == 1)
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
  for(char c : str)
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

void bucketSort(vector<double> &vec) {
  double origin = 0, unit = 0.1;
  vector<vector<double>> buckets(10);
  
  for(double i : vec)
    buckets[(int) (i / unit)].push_back(i);
  
  int pos = 0;
  for(auto b : buckets) {
    sort(b.begin(), b.end());
    for(double i : b)
      vec[pos++] = i;
  }
}

void testProblem6() {
  vector<double> vec{0.13,0.23,0.94,0.53,0.25,0.03,0.85};
  printVector(vec);
  bucketSort(vec);
  printVector(vec);
}

// Problem: 7
// Name: Counting Sort

void countingSort(vector<int> &vec) {
  vector<int> count(10);
  for(int i : vec) count[i]++;
  int pos = 0;
  for(int i = 0; i < 10; i++)
    for(int j = 0; j < count[i]; j++)
      vec[pos++] = i;
}

void testProblem7() {
  vector<int> vec{1,3,3,6,2,6,1,1,9,9,3,2,5,3,0};
  printVector(vec);
  countingSort(vec);
  printVector(vec);
}

// Problem: 8
// Name: Remove Duplicates

void removeDuplicates(vector<int> &vec) {
  set<int> history;
  vector<int>::iterator pos = vec.begin();
  for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
    if(history.find(*it) == history.end()) {
      history.insert(*it);
      *pos = *it;
      pos++;
    }
  }

  while(pos != vec.end())
    *(pos++) = 0;
}

void testProblem8() {
  vector<int> vec{1,3,3,6,2,6,1,1,9,9,3,2,5,3,0,4,1};
  printVector(vec);
  removeDuplicates(vec);
  printVector(vec);
}

// Problem: 9
// Name: Reverse Array

void reverseArray(vector<int> &vec) {
  int half = vec.size() / 2;
  for(int x = 0; x < half; x++) {
    swap(x, vec.size() - x - 1, vec);
  }
}

void testProblem9() {
  vector<int> vec{0,1,2,3,4,5,6,7,8,9};
  printVector(vec);
  reverseArray(vec);
  printVector(vec);
}

// Problem: 10
// Name: Remove Duplicates Without Library

void removeDuplicates2(vector<int> &vec) {
  int pos = 1;
  bool flag;
  for(int i = 1; i < vec.size(); i++) {
    
    flag = true; // check if elem is dupe
    for(int j = 0; j < i; j++) {
      if(vec[i] == vec[j]) {
        flag = false;
        break;
      }
    }

    if(flag) vec[pos++] = vec[i];
  }

  while(pos < vec.size()) vec[pos++] = 0;
}

void testProblem10() {
  vector<int> vec{1,3,3,6,2,6,1,1,9,9,3,2,5,3,0,4,1};
  printVector(vec);
  removeDuplicates2(vec);
  printVector(vec);
}

int main() {
  testProblem10();
}