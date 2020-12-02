#include <stdio.h>

int main()
{
  int i = 0;
  while(1)
  {
    if(i > 100)
      break;       // завершить цикл
    printf("%d ", i);
    ++i;
  }
  return 0;
}
