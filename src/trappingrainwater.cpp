/**
 *  Trapping Rain Water 求存水量
 *  2024/02/20 17:51
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
  static int trap(const std::vector<int> &A)
  {
    const int n = A.size();
    int *left_highest = new int[n]();
    int *right_highest = new int[n]();

    //求每块左边最高
    for (int i = 1; i < n; i++)
    {
      //把最大值传递下去
      left_highest[i] = std::max(left_highest[i - 1], A[i - 1]);
    }
    //求每块右边最高，有传递性
    for (int i = n - 2; i >= 0; i--)
    {
      right_highest[i] = std::max(right_highest[i + 1], A[i + 1]);
    }
    //求总存水量
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      int high = std::min(left_highest[i], right_highest[i]);
      if (high > A[i])
      {
        sum += high - A[i];
      }
    }

    return sum;
  }
};

int main(int argc, char *argv[])
{
  std::vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  std::cout<< "正确答案为6" << std::endl;
  std::cout << Solution::trap(nums) << std::endl;
  return 0;
}
