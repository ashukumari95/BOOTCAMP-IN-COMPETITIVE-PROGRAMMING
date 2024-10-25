#include <stdio.h>

// Function to perform Binary Search
int binarySearch(int arr[], int n, int key)
{
  int low = 0;
  int high = n - 1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2; // Calculate mid index

    // Check if the key is present at mid
    if (arr[mid] == key)
    {
      return mid; // Return the index if found
    }

    // If the key is greater, ignore the left half
    if (arr[mid] < key)
    {
      low = mid + 1;
    }
    // If the key is smaller, ignore the right half
    else
    {
      high = mid - 1;
    }
  }
  return -1; // Return -1 if the element is not found
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
  int arr[100], n, key, choice, result;

  do
  {
    printf("\n1. Enter array (sorted)\n2. Perform Binary Search\n3. Display array\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter the number of elements in the array: ");
      scanf("%d", &n);
      printf("Enter %d sorted elements: ", n);
      for (int i = 0; i < n; i++)
      {
        scanf("%d", &arr[i]);
      }
      break;
    case 2:
      printf("Enter the value to search: ");
      scanf("%d", &key);
      result = binarySearch(arr, n, key);
      if (result != -1)
      {
        printf("Element found at index: %d\n", result);
      }
      else
      {
        printf("Element not found in the array.\n");
      }
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
