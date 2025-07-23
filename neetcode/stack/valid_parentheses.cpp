#include <iostream>
#include <string>
#include <stack>

class Solution {
public:
    bool areMatching(char c, char d) {
        bool matching;
        char leftParens[] = {'(', '[', '{'};
        char rightParens[] = {')', ']', '}'};

        if (c == leftParens[0] && d == rightParens[0]) {
            matching = true;
        } else if (c == leftParens[1] && d == rightParens[1]) {
            matching = true;
        } else if (c == leftParens[2] && d == rightParens[2]) {
            matching = true;
        } else {
            matching = false;
        }

        return matching;
    }

    bool isLeftParen(char c) {
        char leftParens[] = {'(', '[', '{'};
        bool isLeftParen = false;
        for (int i = 0; i < sizeof(leftParens); ++i) {
            if (c == leftParens[i]) {
                isLeftParen = true;
            }
        }

        return isLeftParen;
    }

    bool isValid(std::string s) {
        if (!isLeftParen(s[0]) || s.size() == 1) {
            return false;
        }

        bool valid = true;
        std::stack<char> tracker;

        for (int i = 0; i < s.length(); ++i) {
            if (isLeftParen(s[i])) {
                tracker.push(s[i]);
            } else if (!tracker.empty()){
                char parenOne = tracker.top();
                char parenTwo = s[i];

                if (!isLeftParen(parenOne)) {
                    valid = false;
                }
                if (!areMatching(parenOne, parenTwo)) {
                    valid = false;
                }

                tracker.pop();
            } else {
                valid = false;
            }
        }

        if (tracker.size() != 0) {
            valid = false;
        }

        return valid;
    }
};

void printBool(bool expected, int n) {
    if (expected) {
        std::cout << "Expected: true\n";
    } else {
        std::cout << "Expected: false\n";
    }

    if (n) {
        std::cout << "Result: true\n\n";
    } else {
        std::cout << "Result: false\n\n";
    }
}

int main() {
    Solution solution;
    std::string strOne = "[]";
    std::string strTwo = "([{}])";
    std::string strThree = "[(])";
    std::string strFour = "[";
    std::string strFive = "((";
    std::string strSix = "[])";

    printBool(true, solution.isValid(strOne));
    printBool(true, solution.isValid(strTwo));
    printBool(false, solution.isValid(strThree));
    printBool(false, solution.isValid(strFour));
    printBool(false, solution.isValid(strFive));
    printBool(false, solution.isValid(strSix));
}

/*
Example 1:
Input: s = "[]"
Output: true

Example 2:

Input: s = "([{}])"

Output: true

Example 3:

Input: s = "[(])"

Output: false
*/
