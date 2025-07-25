#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int result = -1;
        int lo = 0, hi = nums.size() - 1;
        int mid = lo + (hi - lo) / 2;

        do {
            if (nums[mid] == target) {
                result = mid;
                break;
            } else if (nums[mid] < target) {
                lo = mid + 1;
                mid = lo + (hi - lo) / 2;
            } else {
                hi = mid - 1;
                mid = lo + (hi - lo) / 2;
            }
        } while (lo <= hi);


        return result;
    }
};

void printSolution(int expected, int result) {
    std::cout << "Expected: " << expected << " Result: " << result << "\n";
}

int main() {
    Solution solution;

    std::vector<int> vecOne  = {-1, 0, 2, 4, 6, 8};
    std::vector<int> vecTwo = {-1, 0, 2, 4, 6, 8};

    int targetOne = 4;
    int targetTwo = 3;
    int expecOne = 3;
    int expecTwo = -1;

    int resOne = solution.search(vecOne, targetOne);
    int resTwo = solution.search(vecTwo, targetTwo);

    printSolution(expecOne, resOne);
    printSolution(expecTwo, resTwo);
}

/*
Input: nums = [-1,0,2,4,6,8], target = 4
Output: 3

Input: nums = [-1,0,2,4,6,8], target = 3
Output: -1
*/
