/**
 * 排序数组取两数和为指定数
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

// 3Sum
// 先排序，然后双指针左右夹逼，注意跳过重复的数
// Time Complexity: O(n^2)
// Space Complexity: from O(logn) to O(n), depending on the
// implementation of the sorting algorithm
class Solution
{
public:
  static std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
  {
    // 排序
    std::sort(begin(nums), end(nums));
    std::vector<std::vector<int>> result;
    //for循环里用夹逼求符合条件的剩余两数
    for (int i = 0; i < nums.size(); ++i)
      if (i == 0 || nums[i] != nums[i - 1])
      {
        for (auto &lst : twoSumII(nums, i + 1, 0 - nums[i]))
        {
          lst.insert(lst.begin(), nums[i]);
          result.push_back(lst);
        }
      }
    return result;
  }

  //求和为指定值的两数
  //这里用的排序夹逼，也可以用hashset保存已处理数下标，见0001/0001.cpp
  static std::vector<std::vector<int>> twoSumII(std::vector<int> &nums, int start, int target)
  {
    std::vector<std::vector<int>> result;
    int low = start, high = nums.size() - 1;
    while (low < high)
    {
      int sum = nums[low] + nums[high];
      if (sum < target)
      {
        ++low;
      }
      else if (sum > target)
      {
        --high;
      }
      else
      {
        result.push_back({nums[low++], nums[high--]});
        while (low < high && nums[low] == nums[low - 1])
          ++low;
        while (low < high && nums[high] == nums[high + 1])
          --high;
      }
    }
    return result;
  }
};

int main(int argc, char *argv[])
{

  std::cout << "三数之和" << std::endl;
  std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
  auto result = Solution::threeSum(nums);

  for (auto it : result)
  {
    for (auto v : it)
    {
      std::cout << v << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}