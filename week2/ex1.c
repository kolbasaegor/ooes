#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
  int a = INT_MAX;
  float b = FLT_MAX;
  double c = DBL_MAX;

  printf("Integer:\nSize: %ld\nMax value: %d\n\n", sizeof(a), a);
  printf("Float:\nSize: %ld\nMax value: %f\n\n", sizeof(b), b);
  printf("Double:\nSize: %ld\nMax value: %f\n", sizeof(c), c);

  return 0;
}
