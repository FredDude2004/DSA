#include <iostream>
#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.size() == 0) { return false; }
        bool found = false;

        int lo = 0;
        int hi = matrix.size() - 1;
        int mid = lo + (hi - lo) / 2;
        int row;

        do {
            row = mid;
            if (matrix[mid][0] == target) {
                found = true;
                break;
            } else if (matrix[mid][0] < target && matrix[mid][matrix[mid].size() - 1] < target) {
                lo = mid + 1;
                mid = lo + (hi - lo) / 2;
            } else if (matrix[mid][0] > target && matrix[mid][matrix[mid].size() - 1] > target){
                hi = mid - 1;
                mid = lo + (hi - lo) / 2;
            } else {
                break;
            }
        } while (lo <= hi);

        lo = 0;
        hi = matrix[row].size() - 1;
        mid = lo + (hi - lo) / 2;

        do {
            if (matrix[row][mid] == target) {
                found = true;
                break;
            } else if (matrix[row][mid] < target) {
                lo = mid + 1;
                mid = lo + (hi - lo) / 2;
            } else {
                hi = mid - 1;
                mid = lo + (hi - lo) / 2;
            }
        } while (lo <= hi && !found);

        return found;
    }
};

void printSolution(bool expected, bool result) {
    if (expected) {
        std::cout << "Expected: true ";
    } else {
        std::cout << "Expected: false ";
    }

    if (result) {
        std::cout << " Result: true\n";
    } else {
        std::cout << " Result: false\n";
    }
}

int main() {
    Solution solution;

    std::vector<std::vector<int>> in = {{1,2,4,8}, {10,11,12,13}, {14,20,30,40}};
    std::vector<std::vector<int>> inTwo = {{1,3,5,7}, {10,11,16,20}, {23,30,34,50}};
    int targetOne = 10;
    int targetTwo = 15;
    int targetThree = 11;

    bool resOne = solution.searchMatrix(in, targetOne);
    bool resTwo = solution.searchMatrix(in, targetTwo);
    bool resThree = solution.searchMatrix(inTwo, targetThree);

    printSolution(true, resOne);
    printSolution(false, resTwo);
    printSolution(true, resThree);
}

/*
    Input: matrix = [[1,2,4,8],[10,11,12,13],[14,20,30,40]], target = 10
    Output: true

    Input: matrix = [[1,2,4,8],[10,11,12,13],[14,20,30,40]], target = 15
    Output: false

    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 11
    Output: true
*/
