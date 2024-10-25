#include <stdio.h>

// Function to perform Linear Search
int linearSearch(int arr[], int n, int key)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == key)
    {
      return i; // Return the index if the element is found
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
    printf("\n1. Enter array\n2. Perform Linear Search\n3. Display array\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter the number of elements in the array: ");
      scanf("%d", &n);
      printf("Enter %d elements: ", n);
      for (int i = 0; i < n; i++)
      {
        scanf("%d", &arr[i]);
      }
      break;
    case 2:
      printf("Enter the value to search: ");
      scanf("%d", &key);
      result = linearSearch(arr, n, key);
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