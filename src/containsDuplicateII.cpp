/**
 * 判断整型数组里是否有元数重复
 * Contains Duplicate
 */

// 方法1：用set，取数放进去，放时判断是否存在

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

class Solution
{
public:
  bool contiansDuplicate(const std::vector<int> &nums, int k)
  {
    std::unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
      if (m.find(nums[i]) != m.end())
      {
        if (std::abs(i - m[nums[i]]) <= k)
        {
          return true;
        }
      }
      m[nums[i]] = i;
    }
    return false;
  }
};

int main(int argc, char *argv[])
{
  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 1, 7, 8, 9};
  int k = 4;
  Solution s;
  std::cout << s.contiansDuplicate(nums, k) << std::endl;

  return 0;
}
