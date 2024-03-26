#include <cstdlib>
#include <fmt/base.h>
#include <fmt/core.h>
#include <fmt/format.h>
#include <fstream>
using namespace std;

int main() {
  fstream file("data/lab5_first_follow.txt", ios::in);
  if (!file.is_open()) {
    return EXIT_FAILURE;
  }
  string line;
  while (getline(file, line)) {
    fmt::println("{}", line);
  }
}