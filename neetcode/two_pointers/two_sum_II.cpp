#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        std::vector<int> solution;
        int left = 0;
        int right = numbers.size() - 1;

        while (1) {
            if (numbers[left] + numbers[right] == target) {
                solution.push_back(left + 1);
                solution.push_back(right + 1);
                break;
            } else if ((numbers[left] + numbers[right]) < target) {
                left++;
            } else {
                right--;
            }
        }

        return solution;
    }
};

void printVector(std::vector<int> numbers) {
    std::cout << "[";
    for (int i = 0; i < numbers.size(); ++i) {
        if (i == numbers.size() - 1) {
            std::cout << numbers[i];
        } else {
            std::cout << numbers[i] <<  ",";
        }
    }
    std::cout << "]\n";
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4};
    int target = 3;
    
    Solution solution;
    std::vector<int> result = solution.twoSum(numbers, target);
    std::cout << "Expected: [1,2]\n" << "Result: ";
    printVector(result);
}

/*
Input: numbers = [1,2,3,4], target = 3

Output: [1,2]
*/
