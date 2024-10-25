#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Partition function used by Quick Sort
int partition(int arr[], int low, int high)
{
  int pivot = arr[high]; // Pivot
  int i = (low - 1);     // Index of smaller element

  for (int j = low; j <= high - 1; j++)
  {
    // If the current element is smaller than the pivot
    if (arr[j] < pivot)
    {
      i++; // Increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    // Find pivot element such that elements smaller than pivot
    // are on the left of pivot and elements greater are on the right
    int pi = partition(arr, low, high);

    // Recursively sort the elements before and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
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
    printf("\n1. Enter array\n2. Perform Quick Sort\n3. Display array\n4. Exit\n");
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
      quickSort(arr, 0, n - 1);
      printf("Array sorted using Quick Sort.\n");
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