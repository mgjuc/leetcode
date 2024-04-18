/**
 * 数组向右边出，从左边进，循环
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

int result[9];

class Solution
{
public:
  std::vector<int> rotateArray(std::vector<int> &nums, int k)
  {
    std::vector<int> right(k, 0);
    // 在指定地址插入
#ifdef __cpp_lib_containers_ranges
    right.append_range();
#else
    right.insert(right.begin(), nums.end() - k, nums.end());
    // printArray(right);
#endif
    right.insert(right.begin() + k, nums.begin(), nums.end() - k);
    right.erase(right.end() - k, right.end());
    nums = right;

    return nums;
  }

  int *rotate(int nums[], int k, int n)
  {
    // int size = sizeof(nums)/sizeof(nums[0]); error：sizeof是在编译阶段展开的一个宏，函数参数在运行阶段以压栈方式传递了一个地址
    /**
     * 三次翻转
     * 123456789
     * 54321 9876   987654321
     * 678912345    6789 12345
     * */
    reverse(nums, 0, n - k);
    reverse(nums, n - k, n);
    reverse(nums, 0, n);
    std::cout << "nums address " << nums << std::endl;
    return nums;
  }
  int *test(int arr[])
  {
    return arr;
  }

  int *rotate1(int **nums, int k, int n)
  {
    // error 始终是1，实际算的是指针长度
    //  int size = sizeof(*nums)/sizeof(nums[0]);
    //  int result[n];
    for (int i = 0; i < n; i++)
    {
      // int v = *((*nums) + i);
      int v = (*nums)[i];
      /**
       * 利用取余实现循环
       */
      int index = (i + k) % n;
      result[index] = v;
    }
    std::cout << "nums address " << *nums << std::endl;
    // memcpy(nums, result, n);
    *nums = result; // nums只是一个临时变量，保存了一个地址；改变了这个临时变量保存的地址，并不会影响外部数组地址
    std::cout << "nums address " << *nums << std::endl;
    return *nums;
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
  int *a = new int[5]{1, 2, 3, 4, 5};
  delete a;
  std::cout << "arr address " << arr << std::endl;
  std::cout << "result address " << result << std::endl;
  int n = sizeof(arr) / sizeof(arr[0]);
  s.rotate(arr, 4, n);
  // a = arr;
  // std::cout << "a " << a << std::endl;
  // int *n1 = s.rotate1(&a, 4, n);
  std::cout << "arr address " << arr << std::endl;
  for (int i = 0; i < n; i++)
  {
    std::cout << arr[i];
  }
  // std::cout << std::endl
  //           << "n1 " << n1 << std::endl;
  // std::cout << "a " << a << std::endl;
  // for (int i = 0; i < n; i++)
  // {
  //   std::cout << *(n1 + i);
  // }
  // std::cout << std::endl
  //           << "array " << std::endl;
  // for (int i = 0; i < n; i++)
  // {
  //   std::cout << *(arr + i);
  // }
  return 0;
}