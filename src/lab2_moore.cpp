
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include "../utils/PRINT.H"

using namespace std;

bool is_final_stage(int current_state, vector<int> &final_state) {
  for (int state : final_state) {
    if (state == current_state) {
      return true;
    }
  }
  return false;
}

int use_moore_machine(string user_input, int initial_state,
                      vector<int> &final_state, vector<vector<int>> &matrix,
                      vector<int> &output_data) {

  cout << char(output_data[initial_state]);

  if (user_input.size() == 0) {
    cerr << "\nUser Input Not Provided." << endl;
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
    int transition = matrix[current_state][input];

    if (transition == -1) {
      cerr << "\nInvalid Transition." << endl;
      return EXIT_FAILURE;
    }
    cout << char(output_data[transition]);
    // cout << char(transition) << " ";
    // cout << "Current State : " << current_state << endl;
    current_state = transition;
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

vector<int> get_transitions(string &line) {
  vector<int> temp_vec;
  string temp = "";
  for (auto ch : line) {
    if (ch == ' ') {
      if (temp.size() > 0) {
        temp_vec.push_back(stoi(temp));
        temp.clear();
      }
      continue;
    }
    temp.push_back(ch);
  }
  return temp_vec;
}

int main() {
  ifstream file("data/lab2_moore.txt", ios::in);
  if (!file.is_open()) {
    cerr << "File opening failed\n";
    return 1;
  }
  string line;
  int i = 0, initial_state = 0;
  vector<int> final_state;
  vector<vector<int>> matrix;
  vector<int> output_data;
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
      try {
        output_data.push_back(line[line.size() - 1]);
        matrix.push_back(get_transitions(line));
      } catch (const exception &e) {
        cerr << e.what() << "\nInvalid Input Format.";
        return 0;
      }
    }
    ++i;
  }
  std::cout << "Initial State : ";
  print(initial_state);
  std::cout << "Final State   : ";
  print(final_state);
  std::cout << "Matrix        :\n";
  print(matrix, output_data);
  file.close();

  // USER USE CASE

  string user_input = "";
  while (true) {
    std::cout << "Input Text    : ";
    getline(cin, user_input);
    int exit_status = use_moore_machine(user_input, initial_state, final_state,
                                        matrix, output_data);
    if (exit_status == EXIT_FAILURE) {
      cerr << "\nEXIT_FAILURE" << endl;
    }
    cout << "\n\n";
  }

  return 0;
}
