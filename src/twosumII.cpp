/**
 * 排序数组取两数和为指定数
 */

#include <stdio.h>
#include <iostream>
#include <vector>

class Solution
{
public:
  static std::vector<int> twoSum(std::vector<int> &nums, int target)
  {
    int left = 0, right = nums.size() - 1;
    //数组已排序，左右夹逼 ==》 变大只能左指针右移，变小只能右指针左移
    while (left < right)
    {
      int sum = nums[left] + nums[right];
      if (sum < target)
      {
        left++;
      }
      else if (sum > target)
      {
        right--;
      }
      else
      {
        return {left, right};
      }
    }
    return {-1, -1};
  }
};

int main(int argc, char *argv[])
{

  std::cout << "两数之和" << std::endl;
  std::vector<int> nums = {2, 3, 4};
  std::vector<int> result = Solution::twoSum(nums, 6);

  for (int it : result)
  {
    std::cout << it << " ";
  }
  return 0;
}