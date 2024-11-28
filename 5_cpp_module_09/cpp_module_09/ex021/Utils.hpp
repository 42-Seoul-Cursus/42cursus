#pragma once

#include <deque>
#include <vector>

int strToInt(const std::string &str);

std::deque<int> vectorToDeque(const std::vector<int> &vec);

std::vector<int> oneIndexedToZeroIndexed(const std::vector<int> &oneIndexed);

std::deque<int> generateJooncobsthalSequence(int n);
std::vector<int> generateInsertionOrder(int n);