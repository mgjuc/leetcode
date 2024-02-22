/**
 * Majority Element
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution{
public:
  //排序，出现超过一半的数，就是中间那个数
  int majorityElement(std::vector<int>& nums){
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    return nums[n/2];
  }

  //由于超过n/2，可以用相抵消的思想，凡是和最多元素不相等的，就抵消
  int majorityElement1(std::vector<int>& nums){
    int count = 0, element = 0;
    for(auto i: nums){
      if(i == element){
        count++;
      }else if(count == 0){ //减到0后换个数重新统计
        count = 1;
        element = i;
      }else{
        count--;
      }
    }
    return element;
  }
};



int main(int argc, char* argv[]){
  std::vector<int> nums = {1,2,3,4,5,6,7,8,5,5,5,5,5,5};
  Solution s;
  for(auto it : nums){
    std::cout<< it;
  }
  std::cout<< std::endl;
  std::cout<< "Majority Element = " << s.majorityElement(nums) << std::endl;
  std::cout<< "Majority Element = " << s.majorityElement1(nums) << std::endl;
  return 0;
}