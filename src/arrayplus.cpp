/**
 * 数组加法计算
 */

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
  static void plus(std::vector<int> &nums, int digit)
  {
    int c = digit; // 进位

    for (auto it = nums.rbegin(); it != nums.rend(); it++)
    {
      *it += c;
      c = *it / 10;
      *it %= 10;
    }
    if (c > 0)
    {
      nums.insert(nums.begin(), c);
    }
  }
};

int main(int argc, char *argv[])
{
  std::vector<int> nums = {1, 2, 9, 9, 9};
  Solution::plus(nums, 1000001);
  for (auto i : nums)
  {
    std::cout << i;
  }
  return 0;
}