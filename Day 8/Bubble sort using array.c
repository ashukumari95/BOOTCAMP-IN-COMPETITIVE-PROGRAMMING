#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n)
{
  int i, j, temp;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        // Swap arr[j] and arr[j+1]
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// Function to display the array
void displayArray(int arr[], int n)
{
  int i;
  for (i = 0; i < n; i++)
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
    printf("\n1. Enter array\n2. Perform Bubble Sort\n3. Display array\n4. Exit\n");
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
      bubbleSort(arr, n);
      printf("Array sorted using Bubble Sort.\n");
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