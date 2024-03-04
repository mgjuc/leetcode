/**
 * 判断整型数组里是否有元数重复
 * 1、存在两个下标 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值小于等于 t
 * ==》nums[i]-t < nums[j] < nums[i] + t
 * 2、满足 i 和 j 的差的绝对值也小于等于k
 * Contains Duplicate
 */

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>


void printSet(std::set<long> s){
  for(auto i : s){
    std::cout<< i<< " ";
  }
  std::cout<<std::endl;
}

class Solution
{
public:
  bool contiansDuplicate(std::vector<int> &nums, int indexDiff, int valueDiff)
  {
    std::set<long> s;
    for (int i = 0; i < nums.size(); i++)
    {
      //lower_bound ==》returns an iterator to the first element not less than the given key
      auto pos = s.lower_bound(long(nums[i] - valueDiff));
      if (pos != s.end() && *pos <= long(nums[i] + valueDiff))
      {
        return true;
      }
      s.insert(nums[i]);
      if (s.size() > indexDiff)
      {
        s.erase(nums[i - indexDiff]);
      }
      printSet(s);
    }
    return false;
  }
};

int main(int argc, char *argv[])
{

  std::vector<int> nums = {1, 1, 2, 3, 1};
  int indexDiff = 3, valueDiff = 0;
  Solution s;
  bool ok = s.contiansDuplicate(nums, indexDiff, valueDiff);
  std::cout << "Is contians duplicate: " << (ok? "true": "false") << std::endl;
  return 0;
}