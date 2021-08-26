#include <stdio.h>


void swapchik(int *num1, int *num2){
  int tmp = *num1;
  *num1 = *num2;
  *num2 = tmp;
}



int main(){
  int a,b;
  printf("Enter two integer numbers\n");
  scanf("%d %d", &a, &b);

  swapchik(&a, &b);
  printf("%d %d\n", a, b);

  return 0;
}
