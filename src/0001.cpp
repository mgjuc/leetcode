//2013年8月12日(星期一) 晚上8:16
#include "stdio.h"
int main()
{
  int a = 1, b;
  for (b = 1; b <= 10; b++)
  {
    if (a >= 8)
      break;
    if (a % 2 == 1)
    {
      a += 5;
      printf("%d %d %d\n", b, a, a % 2);
      continue;
    }
    a -= 3;
    printf("%d %d %d\n", b, a, a % 2);
  }
  printf("%d\n", b);
  return 0;
}
/*第一个a为什么是6?*/

/*
  2024/02/19 09:21
  因为a % 2 是取余，第一个a = 1，所以 1 % 2 = 1
*/