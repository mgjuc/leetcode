/**
 * 距阵十字消消乐
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

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

// Set Matrix Zeroes
// 时间复杂度O(m*n)，空间复杂度O(1)
class Solution
{
public:
  static void setZeroes(std::vector<std::vector<int>> &matrix)
  {
    const size_t rowsize = matrix.size();
    const size_t columnsize = matrix[0].size();
    bool row_has_zero = false; // 第一行是否存在 0
    bool col_has_zero = false; // 第一列是否存在 0
    // 第一行是否存在0
    for (size_t i = 0; i < columnsize; i++)
    {
      if (matrix[0][i] == 0)
      {
        row_has_zero = true;
        break;
      }
    }
    // 第一列是否存在0
    for (size_t i = 0; i < rowsize; i++)
    {
      if (matrix[i][0] == 0)
      {
        col_has_zero = true;
        break;
      }
    }
    // 从第1行列开始，找0并标记到首行首列；
    for (size_t i = 1; i < rowsize; i++)
    {
      for (size_t j = 1; j < columnsize; j++)
      {
        //首行列本来就是0，或已经被标记
        if(matrix[0][j] == 0 || matrix[i][0] == 0) continue;
        //内部有0，标记到首行列
        if (matrix[i][j] == 0)
        {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }

#ifdef DEBUG
    std::cout << "标记后" << std::endl;
    printMatrix(matrix);
#endif

    // 据标记内部清零
    for (size_t i = 1; i < rowsize; i++)
    {
      for (size_t j = 1; j < columnsize; j++)
      {
        // 首行首列标记==》可能是读内部标记的0，也可能本来就是0
        if (matrix[i][0] == 0 || matrix[0][j] == 0)
        {
          matrix[i][j] = 0;
        }
      }
    }
    // 首行清零
    if (row_has_zero)
    {
      for (size_t i = 0; i < columnsize; i++)
      {
        matrix[0][i] = 0;
      }
    }
    // 首列清零
    if (col_has_zero)
    {
      for (size_t i = 0; i < rowsize; i++)
      {
        matrix[i][0] = 0;
      }
    }
  }
};

int main(int argc, char *argv[])
{
  std::vector<std::vector<int>> matrix = {{1, 2, 3, 4, 5, 6}, {1, 2, 3, 0, 5, 6}, {0, 2, 3, 4, 5, 6}, {1, 2, 3, 4, 5, 6}, {1, 2, 3, 4, 5, 6}};
  std::cout << "输入距阵" << std::endl;
  printMatrix(matrix);
  Solution::setZeroes(matrix);
  std::cout << "处理后" << std::endl;
  printMatrix(matrix);
  return 0;
}