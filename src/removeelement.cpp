#include <stdio.h>
#include <vector>
#include <iostream>

// using namespace std;

class Solution
{
public:
  static int removeElement(std::vector<int> &nums, int target)
  {
    int slow = 0;
    for (int fast = 0; fast < nums.size(); ++fast)
    {
      if (nums[fast] != target)
      {
        nums[slow++] = nums[fast];
      }
    }
    return slow;
  }
};

int main(int argc, char *argv[])
{

  std::vector nums = {0, 1, 2, 3, 4, 5};
  int target = 1;
  int length = Solution::removeElement(nums, target);
  std::cout << "resoult length " << length << std::endl;
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
  std::cout << "nums ";
  for (int i = 0; i < length; i++)
  {
    std::cout << nums[i] << " ";
  }

  return 0;
}