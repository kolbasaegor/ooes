#include <stdio.h>

void bubbleSort(int arr[], int n){
  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < n - 1 -i; j++){
      if(arr[j] > arr[j+1]){
      int tmp = arr[j];
      arr[j] = arr[j+1];
      arr[j+1] = tmp;
      }
    }
  }
}

int main(){
  int n;
  int array[n];
  printf("Size = ");
  scanf("%d", &n);
  printf("Enter array\n");
  for(int i = 0; i < n;i++)
    scanf("%d", &array[i]);

  bubbleSort(array, n);

  for(int i = 0; i<n; i++)
    printf("%d ", array[i]);
  printf("\n");
  return 0;
}
