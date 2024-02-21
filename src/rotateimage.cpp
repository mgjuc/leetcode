/**
 * Rotate Image 数据距阵顺时针旋转90度
 * 2024/02/21 10:28
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
  static void rotate(std::vector<std::vector<int>> &matrix)
  {
    const int size = matrix.size();
    // 上下翻转
    for (int i = 0; i < size / 2; i++)  //size/2 处理一半，否则翻两次变回去了
    {
      for (int j = 0; j < size; j++)
      {
        std::swap(matrix[i][j], matrix[size - i - 1][j]);
      }
    }
    // 主对角线翻转
    for (int i = 0; i < size; i++)
    {
      for (int j = i + 1; j < size; j++)
      {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};

void printMatrix(const std::vector<std::vector<int>> &matrix)
{
  for (auto i : matrix)
  {
    for (auto j : i)
    {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
}

int main(int argc, char *argv[])
{
  std::vector<std::vector<int>> matrix = {{1, 2}, {3, 4}};
  std::cout << "距阵数据:" << std::endl;
  printMatrix(matrix);
  std::cout << "正确结果为:" << std::endl;
  std::cout << "3 1" << std::endl;
  std::cout << "4 2" << std::endl;
  std::cout << "计算结果:" << std::endl;
  Solution::rotate(matrix);
  printMatrix(matrix);
  return 0;
}
