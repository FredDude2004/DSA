#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
  bool isAnagram(std::string s, std::string t) {
    std::unordered_map<char, int> wordOne;
    std::unordered_map<char, int> wordTwo;

    for (char c : s) {
      wordOne[c]++;
    }

    for (char c : t) {
      wordTwo[c]++;
    }

    if (wordOne == wordTwo) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  Solution solution;
  bool result = solution.isAnagram("racecar", "carrace");
  if (result) {
    std::cout << "True\n";
  } else {
    std::cout << "False\n";
  }
}
