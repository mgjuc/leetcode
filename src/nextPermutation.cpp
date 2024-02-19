/**
 * 下一个更大的排列数，主要是提炼思路
 * 有标准库实现std::next_permutation(nums.begin(), nums.end());
 * https://leetcode.cn/problems/next-permutation/solutions/479151/xia-yi-ge-pai-lie-by-leetcode-solution/
 * 最佳题解：https://leetcode.cn/problems/next-permutation/solutions/2547378/jiao-ni-yi-bu-yi-bu-xie-chu-zui-jian-dai-saaz/
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
  static void nextPermutation(std::vector<int> &nums)
  {
    //标准库实现
    // std::next_permutation(nums.begin(), nums.end());
    int i = nums.size() - 2;
    // nums[i] >= nums[i + 1] =》第一个左边比右边小的数，否则这些数是降序排列A>B>C>D，找不到比它更大的数，无法交换
    while (i >= 0 && nums[i] >= nums[i + 1])
    {
      i--;
    }
    if (i >= 0)
    {
      int j = nums.size() - 1;
      // A<B>C>D>E =》因为右边是降序的，找右边比A大第一个数X，再交换位A和X位置，比如结果是B>C>A>E，它还是降序
      while (j >= 0 && nums[i] >= nums[j])
      {
        j--;
      }
      std::swap(nums[i], nums[j]);
    }
    // 直接逆序
    std::reverse(nums.begin() + i + 1, nums.end());
  }
};

int main(int argc, char *argv[])
{
  std::vector<int> nums = {4, 5, 2, 6, 3, 1};
  Solution::nextPermutation(nums);
  for (auto i : nums)
  {
    std::cout << i << " ";
  }
  return 0;
}