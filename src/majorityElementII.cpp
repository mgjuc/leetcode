/**
 * 统计超过超过1/3的票型
 * Majority Element  
 * 摩尔投票法
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution{
public:
  std::vector<int> majorityElement(std::vector<int>& nums){
    //超过1/3的票形最多只有两个
    //求最多的两个票形
    int vote1 =0, vote2 =0;
    int count1=0, count2 =0;

    for(auto it : nums){
      if(it == vote1){
        count1++;
      }else if(it == vote2){
        count2++;
      }else if(count1 == 0){
        count1 = 1;
        vote1 = it;
      }else if(count2 == 0){
        count2 = 1;
        vote2 = it;
      }else{
        count1--;
        count2--;
      }
    }

    std::vector<int> result;
    for(auto it : std::vector<int>{vote1, vote2}){
      if(std::count(nums.begin(), nums.end(), it) > nums.size()/3){
        result.push_back(it);
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]){
  std::vector<int> nums = {1,2,3,4,5,8,8,8,8,8,5,5,5,5};
  Solution s;
  for(auto it : nums){
    std::cout<< it;
  }
  std::cout<< std::endl;
  std::vector<int> result = s.majorityElement(nums);
  for(auto i: result){
    std::cout<< i <<" ";
  }

  return 0;
}