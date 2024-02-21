/**
 * leetcode 135
 * 孩子站成一排，跟据每个人评分发糖，评分比两边高的人必须比边上的人发得多，且每人致少一个，怎样发的最少？
 *
 * TODO:有这想法，如果这个排序是可变的呢？
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> //std::accumulate 累加

class Solution
{
public:
  static int candy(const std::vector<int> &ratings)
  {
    std::vector<int> candies(ratings.size(), -1);

    // 根据左右值计算最少糖果
    for (int i = 0; i < ratings.size(); i++)
    {
      candies[i] = getcandy(candies, ratings, i);
    }
    return std::accumulate(candies.begin(), candies.end(), 0);
  }

private:
  // 根据左右值计算最少糖果
  static int getcandy(std::vector<int>& candies, const std::vector<int> &ratings, int index)
  {
    //已经计算过
    if(index >=0 && index <= ratings.size() -1 && candies[index] > 0){
      return candies[index];
    }
    int left = 1, right = 1;
    //算左边最值
    if (index > 0 && ratings[index] > ratings[index - 1])
    {
      left = getcandy(candies, ratings, index - 1) + 1;
    }
    //算右边最值
    if (index < ratings.size() - 1 && ratings[index] > ratings[index + 1])
    {
      right = getcandy(candies, ratings, index + 1) + 1;
    }
    int max = std::max(left, right);
    //保存已计算的最值
    candies[index] = max;
    return max;
  }
};

int main(int argc, char *argv[])
{
  std::vector<int> ratings = {1, 2, 2};
  std::cout << "正确答案4" << std::endl;
  std::cout << Solution::candy(ratings) << std::endl;

  std::vector<int> ratings1 = {1,0,2};
  std::cout << "正确答案5" << std::endl;
  std::cout << Solution::candy(ratings1) << std::endl;
  return 0;
}