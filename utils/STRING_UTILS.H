#pragma once
#include <string>
#include <vector>

std::string trim_left(const std::string &str);
std::string trim_right(const std::string &str);
std::string trim(const std::string &str);
std::vector<std::string> split(char delim, const std::string &str);
std::string join(char delim, const std::vector<std::string> &vec);
bool contains(char ch, const std::string &str);
std::string reverse(const std::string &str);

#include "STRING_UTILS.CPP"