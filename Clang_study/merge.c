
int *arrcpy(int *arr,int len) {
    int *temp = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
    {
        temp[i] = arr[i];
    }
    return temp;
}

void merge(int *arr, int left, int right, int mid,int len)
{
  int i, j, k;
  int temp[right-left];
  i = left;
  j = mid + 1;
  for (k = left; k < right+1; k++)
  {
    if (mid < i) {
      temp[k-left] = arr[j];
      ++j;
    }else if (j > right) {
      temp[k-left]= arr[i];
      ++i;
    }
    else if (arr[i] > arr[j])
    {
      temp[k-left] = arr[j];
      ++j;
    }
    else
    {
      temp[k-left] = arr[i];
      ++i;
    }
  }
  for(k=left;k<right+1;k++) {
    arr[k] = temp[k-left];
  }
}

void merge_init(int *arr, int left, int right,int len)
{
  if (left >= right)
  {
    return;
  }
  int mid = (left + right) / 2;
  merge_init(arr, left, mid,len);
  merge_init(arr, mid + 1, right,len);
  merge(arr, left, right, mid,len);
}

int start(int *arr,int len)
{
  merge_init(arr, 0, len-1,len);
}
