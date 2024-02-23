#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
  /*   std::vector<int> rotateArray(std::vector<int> &nums, int k)
    {
      std::vector<int> right(k, 0);
  #ifdef __cpp_lib_containers_ranges
      right.append_range();
  #else
      right.insert(right.begin(), nums.end() - k, nums.end());
      printArray(right);
  #endif
      right.insert(right.begin() + k, nums.begin(), nums.end() - k);
      right.erase(right.end() - k, right.end());
      nums = right;

      return nums;
    } */

  int* rotate(int nums[], int k, int n)
  {
    k %= n;
    reverse(nums, 0, n - k);
    reverse(nums, n - k, n);
    reverse(nums, 0, n);
    std::cout<<"nums address "<< nums <<std::endl;
    return nums;
  }
  int* test(int arr[]){
    return arr;
  }

private:
  static void reverse(int nums[], int begin, int end)
  {
    int left = begin;
    int right = end - 1;
    while (left < right)
    {
      // swap
      int tmp = nums[left];
      nums[left] = nums[right];
      nums[right] = tmp;
      ++left;
      --right;
    }
  }
};

int main(int argc, char *argv[])
{
  if (argc >= 2)
  {
    std::cout << argc << " " << argv[1] << std::endl; // 如果没有argv[1]会直接退出
  }
  Solution s;
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int* a = new int[5]{1,2,3,4,5};
  delete a;
  std::cout<<"arr address "<< arr <<std::endl;
  int n = sizeof(arr) / sizeof(arr[0]);
  s.rotate(arr, 4, n);
  for (int i = 0; i < n; i++)
  {
    std::cout << arr[i];
  }
  return 0;
}