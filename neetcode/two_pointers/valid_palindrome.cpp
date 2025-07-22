#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

class Solution {
public:
  void cleanString(std::string &s) {
    s.erase(std::remove_if(s.begin(), s.end(),
           [](unsigned char c) {
             return !std::isalnum(c) || std::isspace(c);
           }),
        s.end());
    }

    bool isPalindrome(std::string s) {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower); // convert string to lowercase 
        int ptrOne = 0;
        int ptrTwo = s.length() - 1;

        while (ptrOne < ptrTwo) {
            if (!std::isalnum(s.at(ptrOne))) {
                ptrOne++;
            } else if (!std::isalnum(s.at(ptrTwo))) {
                ptrTwo--;
            } else if (s.at(ptrOne) == s.at(ptrTwo)) {
                ptrOne++;
                ptrTwo--;
            } else {
                return false;
            }
        }

        return true;
    }
};

int main() {
    std::string s1 = "Was it a car or a cat I saw";
    std::string s2 = "deez nutz";

    Solution solution;
    bool resOne = solution.isPalindrome(s1);
    bool resTwo = solution.isPalindrome(s2);

    std::cout << resOne << "\n" << resTwo << "\n";
}
