/**
 * 判断整型数组里是否有元数重复
 * Contains Duplicate
 */

// 方法1：用set，取数放进去，放时判断是否存在

// 方法2：排序，找前后两个相同的数

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
  bool containsDuplicate(std::vector<int> &nums)
  {
    std::sort(nums.begin(), nums.end());
    for (auto it = nums.begin(); it != nums.end() - 1; it++)
    {
      if (*it == *(it + 1))
        return true;
    }
    return false;
  }
};

int main(int argc, char *argv[])
{
  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9};
  Solution s;
  std::cout << s.containsDuplicate(nums) << std::endl;
  return 0;
}