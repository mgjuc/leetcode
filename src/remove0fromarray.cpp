#include <stdio.h>
#include <vector>
#include <iostream>

// using namespace std;

// Move Zeroes
// 双指针
// Time Complexity: O(n), Space Complexity: O(1)
class Solution {
public:
    static void moveZeroes(std::vector<int>& nums) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast) {
            if (nums[fast] != 0) {
                std::swap(nums[slow++], nums[fast]);
            }
        }
    }
};

int main(int argc, char *argv[])
{

  std::vector<int> nums = {0, 1, 2, 3, 4, 5};
  int target = 1;
  Solution::moveZeroes(nums);
  std::cout << "nums ";
  for (auto &v : nums)
  {
    std::cout << v << " ";
  }
  std::cout << "nums ";
  for (auto iter = nums.begin(); iter != nums.end(); iter++)
  {
    std::cout << *iter << " ";
  }
  return 0;
}