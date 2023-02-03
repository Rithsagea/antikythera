#include <iostream>
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

void _bucketSortHelper(vector<double> &vec, double origin, double unit) {
  vector<vector<double>> bucket(10);
  for(int i : vec) {
    bucket[(int) ((i - origin) / unit)].push_back(i);
  }
}

void bucketSort(vector<double> &vec) {
  _bucketSortHelper(vec, 0, 0.1);
}

int main() {
  testProblem5();
}