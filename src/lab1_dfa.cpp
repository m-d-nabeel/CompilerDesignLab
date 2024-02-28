#include <bits/stdc++.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

int finalStates(vector<int> &v, int c) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == c) return 1;
  }
  return 0;
}

vector<int> stringToVector(string &line) {
  int i = 0;
  vector<int> v;
  while (i < line.size()) {
    if (line[i] == '-') {
      int x = -1;
      v.push_back(x);
      i++;
    } else if (line[i] != '-' && line[i] != ' ') {
      v.push_back(line[i] - '0');
    }
    i++;
  }
  return v;
}

int isAccepted(string &s) {
  fstream file("../data/lab1_dfa.txt", ios::in);
  int n = s.size();
  vector<vector<int>> v;
  string line;

  while (getline(file, line)) {
    vector<int> temp;
    temp = stringToVector(line);
    v.push_back(temp);
  }
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      cout << v[i][j];
    }
    cout << endl;
  }

  vector<int> finalState = v[1];
  int i = 0;
  int currentState = 0;
  int sz = v[2].size();
  int p = v.size();

  while (currentState != -1 && i < n) {
    if (s[i] - 'a' >= sz)
      return 0;
    else {
      currentState = v[currentState + 2][s[i] - 'a'];
      i++;
    }
  }

  if (finalStates(finalState, currentState))
    return 1;
  else
    return 0;
}

int main() {

  fstream file("../data/lab1_dfa.txt");
  if(!file.is_open()){
    cerr<<"File opening failed"<<endl;
    return EXIT_FAILURE;
  }
  string s;
  cout << "Enter the string :";
  cin >> ws;
  getline(cin, s);

  cout << "Input String : " << s << endl;
  if (isAccepted(s))
    cout << "Accepted";
  else
    cout << "Not Accepted";

  return 0;
}
