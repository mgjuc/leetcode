/**
 * Remove Duplicates from Sorted Array II，允许2个重复
 * 
 */

#include <iostream>
#include <string>
#include <vector>

// Remove Duplicates from Sorted Array II
// Time Complexity: O(n)，Space Complexity: O(1)
class Solution
{
public:
  static int removeDuplicates(std::vector<int> &nums)
  {
    const int N = 2;
    if (nums.size() <= N)
      return nums.size();

    int slow = N;
    for (int fast = N; fast < nums.size(); fast++)
    {
      if (nums[fast] != nums[slow - N])
        nums[slow++] = nums[fast];
    }

    return slow;
  }
};

//方法二
// Remove Duplicates from Sorted Array II
// Time Complexity: O(n), Space Complexity: O(1)
class Solution1
{
public:
  static int removeDuplicates(std::vector<int> & nums)
  {
    int n = nums.size();
    int index = 0;
    for (int i = 0; i < n; ++i)
    {
      std::cout<< nums[i - 1] << " " << nums[i] << " " << nums[i + 1] << std::endl;
      if (i > 0 && i < n - 1 && nums[i] == nums[i - 1] && nums[i] == nums[i + 1])
        continue;
      std::cout<< "nums[" << index << "]=nums[" << i << "]" << std::endl; 
      nums[index++] = nums[i];
    }
    return index;
  }
};

int main()
{

  std::cout << "Remove Duplicates from Sorted Array II，允许2个重复" << std::endl;
  std::vector<int> A{1, 1, 1, 2, 2, 3};

  std::cout << Solution1::removeDuplicates(A) << std::endl;
  return 0;
}