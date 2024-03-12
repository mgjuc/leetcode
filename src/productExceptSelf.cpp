/**
 * 返回数组除了自身外其余元素的积的数组
 * 不能用除法，当有元素为0时除法无效
 * 思路是：获取每个元素的前缀和后缀乘积集
 */

#include <stdio.h>
#include <iostream>
#include <vector>

class Solution
{
public:
  std::vector<int> productExceptSelf(const std::vector<int> &nums)
  {
    std::vector<int> left(nums.size()), right(nums.size()), result(nums.size());
    left[0] = 1;
    right[nums.size() - 1] = 1;

    for (int i = 1; i < nums.size(); i++)
    {
      left[i] = left[i - 1] * nums[i - 1];
    }
    for (int i = nums.size() - 2; i >= 0; i--)
    {
      right[i] = right[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < nums.size(); i++)
    {
      result[i] = left[i] * right[i];
    }
    return result;
  }

  //省去了right数组
  std::vector<int> productExceptSelf1(const std::vector<int> &nums)
  {
    std::vector<int> left(nums.size());
    left[0] = 1;
    int right = 1;

    for (int i = 1; i < nums.size(); i++)
    {
      left[i] = left[i - 1] * nums[i - 1];
    }
    for (int i = nums.size() - 2; i >= 0; i--)
    {
      right = right * nums[i+1];
      left[i] = left[i] * right;
    }

    return left;
  }
};

void printVector(const std::vector<int> &nums)
{
  for (auto it : nums)
  {
    std::cout << it << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[])
{
  std::vector<int> nums = {1, 2, 3, 4};
  std::vector<int> result;
  Solution s;
  printVector(nums);
  result = s.productExceptSelf1(nums);
  std::cout << "ansole is: 24 12 8 6" << std::endl;
  printVector(result);
  return 0;
}