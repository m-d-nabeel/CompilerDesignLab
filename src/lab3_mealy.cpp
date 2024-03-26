#include "../utils/PRINT.H"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool is_final_stage(int current_state, vector<int> &final_state) {
  for (int state : final_state) {
    if (state == current_state) {
      return true;
    }
  }
  return false;
}

int use_mealy_machine(string user_input, int initial_state,
                      vector<int> &final_state,
                      vector<vector<pair<int, int>>> &matrix) {

  if (user_input.size() == 0) {
    cerr << "User Input Not Provided." << endl;
    return EXIT_FAILURE;
  }

  int non_terminals = matrix[0].size();
  int total_states = matrix.size();
  int current_state = initial_state;

  for (char inp : user_input) {

    int input = inp - '0';
    if (input >= non_terminals || input < 0) {
      cerr << "Invalid Input" << endl;
      return EXIT_FAILURE;
    }

    if (current_state >= total_states) {
      cerr << "Invalid Input" << endl;
      return EXIT_FAILURE;
    }
    pair<int, int> transition = matrix[current_state][input];

    if (transition.first == -1) {
      cerr << "\nInvalid Transition." << endl;
      return EXIT_FAILURE;
    }
    cout << char(transition.second) << " ";
    cout << "Current State : " << current_state << endl;
    current_state = transition.first;
  }

  if (!is_final_stage(current_state, final_state)) {
    cerr << "\nMachine Not In Final Stage." << endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

void get_final_state(vector<int> &final_state, string &line) {
  string numstr = "";
  line.push_back(' ');
  for (char ch : line) {
    if (ch == ' ' && numstr.size() > 0) {
      final_state.push_back(stoi(numstr));
      numstr.clear();
    }
    numstr.push_back(ch);
  }
}

vector<pair<int, int>> get_transitions(string &line) {
  vector<pair<int, int>> vp;
  line.push_back(' ');
  bool skip = false, get_output = false;
  string temp = "";
  for (auto ch : line) {
    if (ch == ' ') {
      continue;
    }
    if (skip) {
      skip = false;
      continue;
    }
    if (get_output) {
      vp.push_back(make_pair(stoi(temp), ch));
      temp.clear();
      get_output = false;
      continue;
    }
    if (ch == '-') {
      vp.push_back(make_pair(-1, -1));
      skip = true;
      continue;
    }
    if (ch == ',') {
      get_output = true;
      continue;
    }

    temp.push_back(ch);
  }
  return vp;
}

int main() {
  ifstream file("data/lab3_mealy.txt", ios::in);
  if (!file.is_open()) {
    cerr << "File opening failed\n";
    return 1;
  }
  string line;
  int i = 0, initial_state = 0;
  vector<int> final_state;
  vector<vector<pair<int, int>>> matrix;
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
      matrix.push_back(get_transitions(line));
    }
    ++i;
  }
  std::cout << "Initial State : ";
  print(initial_state);
  std::cout << "Final State   : ";
  print(final_state);
  std::cout << "Matrix        :\n";
  print(matrix);
  file.close();

  // USER USE CASE

  string user_input = "";
  while (true) {
    std::cout << "Input Text    : ";
    cin >> ws;
    getline(cin, user_input);
    // std::cout << "Text Rgstrd   : " << user_input << endl;
    int exit_status =
        use_mealy_machine(user_input, initial_state, final_state, matrix);
    if (exit_status == EXIT_FAILURE) {
      cerr << "EXIT_FAILURE" << endl;
    }
    cout << "\n\n";
  }

  return 0;
}
