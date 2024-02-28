#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <set>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

#include "PRINT.H"
#include "STRING_UTILS.H"

using namespace std;

void construct_dfa_matrix(string state_init, map<string, vector<string>> &nfa,
                          vector<pair<string, vector<string>>> &dfa,
                          unordered_set<string> &visited_states);

bool is_final_stage(int current_state, vector<int> &final_state) {
  for (int state : final_state) {
    if (state == current_state) {
      return true;
    }
  }
  return false;
}

void get_final_state(vector<int> &final_state, string &line) {
  string numstr = "";
  line.push_back(' ');
  for (char ch : line) {
    if (ch == ' ') {
      if (!numstr.empty()) {
        final_state.push_back(stoi(numstr));
        numstr.clear();
      }
      continue;
    }
    numstr.push_back(ch);
  }
}

vector<string> get_transitions(string &line) {
  vector<string> nfa_matrix_row;
  line.push_back(' ');
  bool skip = false, get_output = false;
  string temp = "";
  for (auto ch : line) {
    if (ch == ' ') {
      if (!temp.empty()) {
        nfa_matrix_row.push_back(temp);
        temp.clear();
      }
      continue;
    }
    temp.push_back(ch);
  }
  return nfa_matrix_row;
}

int main() {
  ifstream file("../data/lab4_nfa_to_dfa.txt", ios::in);
  string line;
  int i = 0, initial_state = 0;
  vector<int> final_state;
  map<string, vector<string>> nfa_matrix;
  vector<pair<string, vector<string>>> dfa_matrix;
  unordered_set<string> visited_states;
  if (!file.is_open()) {
    cerr << "File opening failed\n";
    return 1;
  }
  while (getline(file, line)) {
    if (i == 0) {
      try {
        initial_state = stoi(line);
      } catch (const exception &e) {
        cerr << e.what() << "\nInvalid Initial State";
        return 0;
      }
    } else if (i == 1) {
      try {
        get_final_state(final_state, line);
      } catch (const exception &e) {
        cerr << e.what() << "\nInvalid Final State(s)";
        return 0;
      }
    } else {
      nfa_matrix[to_string(i - 2)] = get_transitions(line);
    }
    ++i;
  }
  cout << "Initial State : ";
  print(initial_state);
  cout << "Final State   : ";
  print(final_state);
  cout << "nfa_matrix        :\n";
  print(nfa_matrix);
  file.close();

  cout << "Constructing DFA Matrix\n";
  construct_dfa_matrix("0", nfa_matrix, dfa_matrix, visited_states);
  cout << "DFA Matrix Constructed\n";

  cout << "dfa_matrix        :\n";
  print(dfa_matrix);

  // USER USE CASE
  string user_input = "";
  while (true) {
    cout << "Input Text    : ";
    cin >> ws;
    getline(cin, user_input);
  }
  return 0;
}

void construct_dfa_matrix(string source_state, map<string, vector<string>> &nfa,
                          vector<pair<string, vector<string>>> &dfa,
                          unordered_set<string> &visited_states) {

  if (visited_states.find(source_state) != visited_states.end()) {
    return;
  }

  visited_states.insert(source_state);

  vector<string> dfa_row;
  vector<string> new_states;
  vector<set<string>> unique_states;

  if (contains('-', source_state)) {
    vector<string> multiple_sources = split('-', source_state);
    for (const string &s : multiple_sources) {

      if (nfa.find(s) == nfa.end()) {
        cerr << "Error: Source state not found in NFA map\n";
        return;
      }

      vector<string> dest_state = nfa[s];
      if (unique_states.empty()) {
        unique_states.resize(dest_state.size());
      }

      for (int i = 0; i < dest_state.size(); i++) {
        if (dest_state[i] != "-1") {
          vector<string> temp2 = split(',', dest_state[i]);
          for (const string &s2 : temp2) {
            unique_states[i].insert(s2);
          }
        }
      }
    }
  } else {

    if (nfa.find(source_state) == nfa.end()) {
      cerr << "Error: Source state not found in NFA map\n";
      return;
    }

    vector<string> dest_state = nfa[source_state];

    if (unique_states.empty()) {
      unique_states.resize(dest_state.size());
    }

    for (int i = 0; i < dest_state.size(); i++) {
      if (dest_state[i] != "-1") {
        vector<string> temp2 = split(',', dest_state[i]);
        for (const string &s2 : temp2) {
          unique_states[i].insert(s2);
        }
      }
    }
  }

  for (const set<string> &s : unique_states) {
    vector<string> combined_state = vector<string>(s.begin(), s.end());
    new_states.push_back(join('-', combined_state));
    dfa_row.push_back(join(',', combined_state));
  }

  dfa.push_back(make_pair(source_state, dfa_row));
  nfa[source_state] = dfa_row;
  for (const string &s : new_states) {
    construct_dfa_matrix(s, nfa, dfa, visited_states);
  }
}