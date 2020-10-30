#include <stdio.h>
#include <string.h>
#include <time.h>

void swapInt(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}
void swapCharacter(char *xp, char *yp)
{
  char temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d", arr[i]);
  }
  printf("\n");
}

/* Insertion Sort */
void insertionSort(int arr[], int n)
{
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void insertionSortChar(char str[], int n)
{
  int i, j;
  char key;
  for (i = 1; i < n; i++)
  {
    key = str[i];
    j = i - 1;
    while (j >= 0 && str[j] > key)
    {
      str[j + 1] = str[j];
      j = j - 1;
    }
    str[j + 1] = key;
  }
}

/* Selection Sort */
void selectionSort(int arr[], int n)
{
  int i, j, min;

  for (i = 0; i < n - 1; i++)
  {
    // Find the minimum element in unsorted array
    min = i;
    for (j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min])
      {

        min = j;
      }
    }
    swapInt(&arr[min], &arr[i]);
  }
}
void selectionSortChar(char str[], int n)
{
  int i, j;
  char min;
  for (i = 0; i < n - 1; i++)
  {
    // Find the minimum element in unsorted array
    min = i;
    for (j = i + 1; j < n; j++)
    {
      if (str[j] < str[min])
      {

        min = j;
      }
    }
    swapCharacter(&str[min], &str[i]);
  }
}

/* Merge Sort */
void merge(int arr[], int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}
void mergeSortChar(char arr[], int l, int r)
{
  if (l < r)
  {

    int m = l + (r - l) / 2;

    mergeSortChar(arr, l, m);
    mergeSortChar(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

/* Bubble Sort */
void bubbleSort(int arr[], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swapInt(&arr[j], &arr[j + 1]);
      }
    }
  }
}
void bubbleSortChar(char str[], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (str[j] > str[j + 1])
      {
        swapCharacter(&str[j], &str[j + 1]);
      }
    }
  }
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swapInt(&arr[i], &arr[j]);
    }
  }
  swapInt(&arr[i + 1], &arr[high]);
  return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}
char partitionChar(char arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swapCharacter(&arr[i], &arr[j]);
    }
  }
  swapCharacter(&arr[i + 1], &arr[high]);
  return (i + 1);
}
void quickSortChar(char arr[], int low, int high)
{
  if (low < high)
  {
    int pIndex = partitionChar(arr, low, high);

    quickSortChar(arr, low, pIndex - 1);
    quickSortChar(arr, pIndex + 1, high);
  }
}

void heapify(int arr[], int n, int i)
{
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest])
    largest = l;

  if (r < n && arr[r] > arr[largest])
    largest = r;

  if (largest != i)
  {
    swapInt(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n)
{
  int i, j;
  for (i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }

  for (j = n - 1; j > 0; j--)
  {
    swapInt(&arr[0], &arr[j]);
    heapify(arr, j, 0);
  }
}

void heapifyChar(char arr[], int n, int i)
{
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest])
    largest = l;

  if (r < n && arr[r] > arr[largest])
    largest = r;

  if (largest != i)
  {
    swapCharacter(&arr[i], &arr[largest]);
    heapifyChar(arr, n, largest);
  }
}

void heapSortChar(char arr[], int n)
{
  int i, j;
  for (i = n / 2 - 1; i >= 0; i--)
  {
    heapifyChar(arr, n, i);
  }

  for (j = n - 1; j > 0; j--)
  {
    swapCharacter(&arr[0], &arr[j]);
    heapifyChar(arr, j, 0);
  }
}

int main(int argc, char const *argv[])
{
  /* Bubble Sort */
  int num1[] = {2, 0, 1, 9, 5, 5, 6, 4, 6, 1};
  int lengthOfNum1 = sizeof(num1) / sizeof(num1[0]);
  char name1[] = "mahmut can cingi";
  int lengthOfName1 = strlen(name1);
  clock_t begin = clock();
  bubbleSort(num1, lengthOfNum1);
  printArray(num1, lengthOfNum1);
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Bubble sort integers time: %f\n", time_spent);
  begin = clock();
  bubbleSortChar(name1, lengthOfName1);
  printf("Sorted letters: %s\n", name1);
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Bubble sort string time: %f\n", time_spent);
  /* Bubble Sort */

  /* Selection Sort */
  int num2[] = {2, 0, 1, 9, 5, 5, 6, 4, 6, 1};
  int lengthOfNum2 = sizeof(num2) / sizeof(num2[0]);
  char name2[] = "mahmut can cingi";
  int lengthOfName2 = strlen(name2);
  begin = clock();
  selectionSort(num2, lengthOfNum2);
  printArray(num2, lengthOfNum2);
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Selection sort integers time: %f\n", time_spent);
  begin = clock();
  selectionSortChar(name2, lengthOfName2);
  printf("Sorted letters: %s\n", name2);
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Selection sort string time: %f\n", time_spent);
  /* Selection Sort */

  /* Insertion Sort */
  int num3[] = {2, 0, 1, 9, 5, 5, 6, 4, 6, 1};
  int lengthOfNum3 = sizeof(num3) / sizeof(num3[0]);
  char name3[] = "mahmut can cingi";
  int lengthOfName3 = strlen(name3);
  begin = clock();
  insertionSort(num3, lengthOfNum3);
  printArray(num3, lengthOfNum3);
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Insertion sort integers time: %f\n", time_spent);
  begin = clock();
  insertionSortChar(name3, lengthOfName3);
  printf("Sorted letters: %s\n", name3);
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Insertion sort string time: %f\n", time_spent);
  /* Insertion Sort */

  /* Merge Sort */
  int num4[] = {2, 0, 1, 9, 5, 5, 6, 4, 6, 1};
  int lengthOfNum4 = sizeof(num4) / sizeof(num4[0]);
  char name4[] = "mahmut can cingi";
  int lengthOfName4 = strlen(name4);
  begin = clock();
  mergeSort(num4, 0, lengthOfNum4);
  printArray(num4, lengthOfNum4);
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Merge sort integers time: %f\n", time_spent);
  begin = clock();
  mergeSortChar(name4, 0, lengthOfName4);
  printf("Sorted letters: %s\n", name4);
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Merge sort string time: %f\n", time_spent);
  /* Merge Sort */

  /* Quick Sort */
  int num5[] = {2, 0, 1, 9, 5, 5, 6, 4, 6, 1};
  int lengthOfNum5 = sizeof(num5) / sizeof(num5[0]);
  char name5[] = "mahmut can cingi";
  int lengthOfName5 = strlen(name5);
  begin = clock();
  quickSort(num5, 0, lengthOfNum5 - 1);
  printArray(num5, lengthOfNum5);
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Quick sort integers time: %f\n", time_spent);
  begin = clock();
  quickSortChar(name5, 0, lengthOfName5 - 1);
  printf("Sorted letters: %s\n", name5);
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Quick sort string time: %f\n", time_spent);
  /* Quick Sort */

  /* Heap Sort */
  int num6[] = {2, 0, 1, 9, 5, 5, 6, 4, 6, 1};
  int lengthOfNum6 = sizeof(num6) / sizeof(num6[0]);
  char name6[] = "mahmut can cingi";
  int lengthOfName6 = strlen(name6);
  begin = clock();
  heapSort(num6, lengthOfNum6);
  printArray(num6, lengthOfNum6);
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Heap sort integers time: %f\n", time_spent);
  begin = clock();
  heapSortChar(name6, lengthOfName6);
  printf("Sorted letters: %s\n", name6);
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Heap sort string time: %f\n", time_spent);
  /* Heap Sort */
  return 0;
}