#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
  bool hasDuplicate(std::vector<int> &nums) {
    bool contains_duplicate = false;
    std::unordered_set<int> seen;
    for (int i = 0; i < nums.size(); ++i) {
      if (seen.count(nums[i])) {
        contains_duplicate = true;
      } else {
        seen.insert(nums[i]);
      }
    }

    return contains_duplicate;
  }
};

int main() {
  std::vector<int> nums = {1, 2, 3, 3};
  Solution solution;
  bool result = solution.hasDuplicate(nums);
  if (result) {
    std::cout << "true\n";
  } else {
    std::cout << "false\n";
  }

  return 0;
}
