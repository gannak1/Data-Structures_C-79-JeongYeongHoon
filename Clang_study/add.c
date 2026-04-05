#include <stdio.h>

int main()
{
  int arr[6] = {12, 513, 4613, 457, 4138745, 8};
  int len = sizeof(arr)/sizeof(int);
  qsort_helper(arr,0,len-1,len);
  for (int i=0;i<sizeof(arr) / sizeof(int);i++) {
    printf("%d\n",arr[i]);
  }
  return 0;
}

int qsort(int *arr, int left, int right,int len){
  int pivot = arr[right];
  int temp;
  int j = left;
  int i;
  for(i=left+1;i < right+1; i++) {
    if (arr[i] < pivot) {
      temp = arr[j];
      arr[j] = arr[i];
      arr[i] = temp;
      ++j;
    }
  }
  temp = arr[right];
  arr[right] = arr[j];
  arr[j] = temp;
  return j;
}

void qsort_helper(int *arr,int left,int right,int len) {
  if (left >=right) {
    return;
  }
  int pivot = qsort(arr,left,right,len);
  qsort_helper(arr,left,pivot-1,len);
  qsort_helper(arr,pivot+1,right,len);
}