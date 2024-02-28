#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

std::string trim_left(const std::string &str) {
  auto it = std::find_if_not(str.begin(), str.end(),
                             [](char ch) { return ch == ' '; });
  return std::string(it, str.end());
}

std::string trim_right(const std::string &str) {
  auto it = std::find_if_not(str.rbegin(), str.rend(),
                             [](char ch) { return ch == ' '; });
  return std::string(str.begin(), it.base());
}

std::string trim(const std::string &str) { return trim_left(trim_right(str)); }

std::vector<std::string> split(char delim, const std::string &str) {
  std::vector<std::string> vec;
  std::string substr;
  for (char ch : str) {
    if (ch == delim) {
      if (!substr.empty()) {
        vec.push_back(std::move(substr));
        substr.clear();
      }
    } else {
      substr.push_back(ch);
    }
  }
  if (!substr.empty()) {
    vec.push_back(std::move(substr));
  }
  return vec;
}

std::string join(char delim, const std::vector<std::string> &vec) {
  std::ostringstream oss;
  if (!vec.empty()) {
    oss << vec.front();
    for (auto it = vec.begin() + 1; it != vec.end(); ++it) {
      oss << delim << *it;
    }
  }
  return oss.str();
}

bool contains(char ch, const std::string &str) {
  return std::find(str.begin(), str.end(), ch) != str.end();
}

std::string reverse(const std::string &str) {
  return std::string(str.rbegin(), str.rend());
}
