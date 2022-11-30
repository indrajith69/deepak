 #include <stdio.h>
  
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
  
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
        largest = left;
  
    if (right < n && arr[right] > arr[largest])
        largest = right;
  
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void Buildmaxheap(int arr[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i); 
    }
}  

void heapSort(int arr[], int n) {
    int i;
  
    Buildmaxheap(arr, n);

    for (i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
  
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
        printf("\n");
}
  
void main() {
    int n,i, arr[50];

    printf("enter the number of elements to store in the array:");
    scanf("%d", &n);
    printf("enter the elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("The array is \n");
    printArray(arr, n);

    heapSort(arr, n);
  
    printf("Sorted array is \n");
    printArray(arr, n);
}
