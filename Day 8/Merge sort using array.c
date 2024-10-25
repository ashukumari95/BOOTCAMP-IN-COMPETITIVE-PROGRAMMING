#include <stdio.h>

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right)
{
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Create temp arrays
  int L[n1], R[n2];

  // Copy data to temp arrays L[] and R[]
  for (i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  // Merge the temp arrays back into arr[l..r]
  i = 0;    // Initial index of first subarray
  j = 0;    // Initial index of second subarray
  k = left; // Initial index of merged subarray
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

  // Copy the remaining elements of L[], if any
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copy the remaining elements of R[], if any
  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// Function to implement Merge Sort
void mergeSort(int arr[], int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;

    // Sort first and second halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
  }
}

// Function to display the array
void displayArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main()
{
  int arr[100], n, choice, i;

  do
  {
    printf("\n1. Enter array\n2. Perform Merge Sort\n3. Display array\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter the number of elements in the array: ");
      scanf("%d", &n);
      printf("Enter %d elements: ", n);
      for (i = 0; i < n; i++)
      {
        scanf("%d", &arr[i]);
      }
      break;
    case 2:
      mergeSort(arr, 0, n - 1);
      printf("Array sorted using Merge Sort.\n");
      break;
    case 3:
      printf("Array elements: ");
      displayArray(arr, n);
      break;
    case 4:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice! Please try again.\n");
    }
  } while (choice != 4);

      return 0;
}