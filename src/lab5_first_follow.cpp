#include <cstdlib>
#include <fmt/base.h>
#include <fmt/color.h>
#include <fstream>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>

#include "../utils/PRINT.H"
#include "../utils/STRING_UTILS.H"

using namespace std;

void make_grammar_matrix(map<char, vector<string>> &grammar_map, string &line);

int main() {
  fstream file("data/lab5_first_follow.txt", ios::in);
  if (!file.is_open()) {
    return EXIT_FAILURE;
  }
  string line;
  map<char, vector<string>> grammar_map;
  unordered_set<char> non_terminals;
  while (getline(file, line)) {
    fmt::print(fmt::emphasis::italic | fg(fmt::color::olive_drab),
               "Non-terminal: {} -> Production: {}\n", line[0], line.substr(5));
    make_grammar_matrix(grammar_map, line);
  }
  file.close();
  print(grammar_map);
}

void make_grammar_matrix(map<char, vector<string>> &grammar_map, string &line) {
  line.push_back(' ');
  char non_terminal = line[0];
  vector<string> productions;
  string production = "";
  for (size_t i = 1; i < line.size(); i++) {
    if (line[i] == ' ') {
      if (!production.empty()) {
        grammar_map[non_terminal].push_back(trim(production));
        production.clear();
      }
      continue;
    }
    if (line[i] == '|') {
      if (!production.empty()) {
        grammar_map[non_terminal].push_back(trim(production));
        production.clear();
      }
      continue;
    }
    if (i + 1 < line.size() && line[i] == '-' && line[i + 1] == '>') {
      i++;
      continue;
    }
    production.push_back(line[i]);
  }
}