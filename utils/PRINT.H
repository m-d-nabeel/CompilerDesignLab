#pragma once

#include <map>
#include <string>
#include <unordered_map>
#include <vector>

void print(int &x);
void print(std::vector<int> &v);
void print(std::vector<std::string> &v);
void print(std::vector<std::vector<int>> &v);
void print(std::vector<std::vector<std::string>> &v);
void print(std::vector<std::vector<std::pair<int, int>>> &v);
void print(std::vector<std::vector<int>> &v1, std::vector<int> &v2);
void print(std::map<std::string, std::vector<std::string>> matrix);
void print(std::unordered_map<char, std::vector<char>> matrix);
void print(std::unordered_map<char, std::vector<std::string>> matrix);
void print(std::map<char, std::vector<std::string>> matrix);

void print(
    std::vector<std::pair<std::string, std::vector<std::string>>> matrix);

#include "PRINT.CPP"