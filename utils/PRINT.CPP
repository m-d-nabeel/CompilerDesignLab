// #include <algorithm>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void print(int &x) { cout << setw(5) << x << endl; }

void print(vector<int> &v) {
  for (auto x : v) {
    cout << setw(5) << x;
  }
  cout << setw(5) << endl;
}
void print(vector<string> &v) {
  for (auto x : v) {
    cout << setw(10) << x;
  }
  cout << endl;
}

void print(vector<vector<int>> &v) {
  for (auto x : v) {
    for (auto y : x) {
      cout << setw(5) << y;
    }
    cout << setw(5) << endl;
  }
}

void print(vector<vector<string>> &v) {
  for (auto x : v) {
    for (auto y : x) {
      cout << setw(10) << y;
    }
    cout << setw(10) << endl;
  }
}

void print(vector<vector<pair<int, int>>> &v) {
  for (auto x : v) {
    for (auto y : x) {
      cout << setw(5) << "(" << y.first << ", " << y.second << ")";
    }
    cout << setw(5) << endl;
  }
}

void print(vector<vector<int>> &v1, vector<int> &v2) {
  for (size_t i = 0; i < v1.size(); i++) {
    for (auto y : v1[i]) {
      cout << setw(5) << y;
    }
    cout << setw(5) << " => " << char(v2[i]);
    cout << setw(5) << endl;
  }
}

void print(map<string, vector<string>> matrix) {
  for (auto x : matrix) {
    cout << setw(10) << x.first << " => ";
    for (auto y : x.second) {
      cout << setw(10) << y;
    }
    cout << endl;
  }
}

void print(vector<pair<string, vector<string>>> matrix) {
  // auto remove_chars = [](string &str, char ch) {
  //   str.erase(std::remove(str.begin(), str.end(), ch), str.end());
  //   return str;
  // };
  for (const auto &row : matrix) {
    string first = row.first;
    cout << setw(10) << first + " => ";
    // cout << setw(10) << remove_chars(first, '.') + " => ";
    for (size_t i = 0; i < row.second.size(); ++i) {
      string secondTemp = row.second[i];
      cout << setw(10) << row.second[i];
      // cout << setw(10) << remove_chars(secondTemp, ',');
    }
    cout << endl;
  }
}

void print(std::unordered_map<char, std::vector<char>> matrix) {
  for (auto x : matrix) {
    cout << setw(2) << x.first << " => ";
    for (auto y : x.second) {
      cout << setw(2) << y;
    }
    cout << endl;
  }
}

void print(std::unordered_map<char, std::vector<string>> matrix) {
  for (auto x : matrix) {
    cout << setw(2) << x.first << " => ";
    for (auto y : x.second) {
      cout << setw(4) << y;
    }
    cout << endl;
  }
}

void print(std::map<char, std::vector<string>> matrix) {
  for (auto x : matrix) {
    cout << setw(2) << x.first << " -> ";
    for (size_t i = 0; i < x.second.size(); i++) {
      cout << setw(4) << x.second[i];
      if (i + 1 < x.second.size())
        cout << setw(4) << "|";
    }
    cout << endl;
  }
}