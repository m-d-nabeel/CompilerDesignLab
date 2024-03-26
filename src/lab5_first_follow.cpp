#include <cstdlib>
#include <fmt/base.h>
#include <fmt/color.h>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../utils/PRINT.H"
using namespace std;

void make_grammar_map(unordered_map<char, vector<string>> &grammar_map,
                      const string &line);

int main() {
  fstream file("data/lab5_first_follow.txt", ios::in);
  if (!file.is_open()) {
    return EXIT_FAILURE;
  }
  string line;
  unordered_map<char, vector<string>> grammar_map;
  unordered_set<char> non_terminals;
  while (getline(file, line)) {
    fmt::print(fmt::emphasis::bold | fg(fmt::color::red),
               "Non-terminal: {} -> Production: {}\n", line[0], line.substr(5));
    make_grammar_map(grammar_map, line);
  }
  print(grammar_map);
}

void make_grammar_map(unordered_map<char, vector<string>> &grammar_map,
                      const string &line) {
  char non_terminal = line[0];
  vector<string> productions;
  for (size_t i = 1; i < line.size(); i++) {
    if (line[i] == ' ') {
      continue;
    }
  }
  grammar_map[non_terminal] = productions;
}