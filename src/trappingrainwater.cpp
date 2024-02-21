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
  // 计算每个方块的左右最高值，再计算存水量
  static int trap(const std::vector<int> &A)
  {
    const int n = A.size();
    int *left_highest = new int[n]();
    int *right_highest = new int[n]();

    // 求每块左边最高
    for (int i = 1; i < n; i++)
    {
      // 把最大值传递下去
      left_highest[i] = std::max(left_highest[i - 1], A[i - 1]);
    }
    // 求每块右边最高，有传递性
    for (int i = n - 2; i >= 0; i--)
    {
      right_highest[i] = std::max(right_highest[i + 1], A[i + 1]);
    }
    // 求总存水量
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
  
  // 先找出最高方块，再分左右求存水量。左边只要求左最高，右边只要求右最高
  static int trap1(const std::vector<int> A)
  {
    int sum = 0, highest_index = 0;
    const int n = A.size();
    for (int i = 0; i < n; i++)
    {
      if (A[i] > A[highest_index])
      {
        highest_index = i;
      }
    }
    // 从右往左还要一直找到最左才能确定左最高；从左往右可利用传递性
    //  for(int i=highest_index, hight =0; i>=0; i--)
    for (int i = 0, left_highest = 0; i < highest_index; i++)
    {
      if (A[i] > left_highest)
      {
        left_highest = A[i];
      }
      else
      {
        sum += left_highest - A[i];
      }
    }

    for (int i = n - 1, right_highest = 0; i > highest_index; i--)
    {
      if (A[i] > right_highest)
      {
        right_highest = A[i];
      }
      else
      {
        sum += right_highest - A[i];
      }
    }

    return sum;
  }
};

int main(int argc, char *argv[])
{
  std::vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  std::cout << "正确答案为6" << std::endl;
  std::cout << Solution::trap1(nums) << std::endl;
  return 0;
}
