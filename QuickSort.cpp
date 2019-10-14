#include <iostream> // cout, <<, endl
#include <cstdlib>  // rand() and srand()
#include <ctime>    // use time() to set seed for srand()
#include <chrono>   // C++ library used to measure execution time
using namespace std::chrono;

/* Swap -helper function */
void Swap(int &A, int &B)
{
    int temp = A;
    A = B;
    B = temp;
}

/* Partition */
int Partition(int *A, int low, int high)
{
    int pivot = A[high]; // select pivot to be the last element
    int start = low;
    for (int i = low; i < high; i++)
    {
        if (A[i] <= pivot)
        {
            Swap(A[i], A[start]);
            start++;
        }
    }
    Swap(A[start], A[high]);
    return start;
}

/* Quicksort */
void QuickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int q = Partition(A, low, high);
        QuickSort(A, 0, q - 1);    // Call Quicksort recursively on left subarray
        QuickSort(A, q + 1, high); // Call Quicksort recursively on righ subarray
    }
}

/* Display -helper function */
void display(int A[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}

int main()
{

    int arr[] = {10, 80, 3, 19, 14, 7, 5, 12};
    int n = sizeof(arr) / sizeof(arr[0]); //size of array in bits/size of element bits = size of array
    QuickSort(arr, 0, n - 1);
    display(arr, n);

    int mediumArray[100];
    std::srand(time(0)); // use current time as seed generator
    for (int i = 0; i <= 100; i++)
    {
        mediumArray[i] = rand() % 100; //use modulo operator to get integers in range from 1 to 100
    }
    int s = sizeof(mediumArray) / sizeof(mediumArray[0]);
    QuickSort(mediumArray, 0, s - 1);
    display(mediumArray, s);

    int megaArray[1000] = {};
    int largeArray[1000];
    std::srand(time(0)); // use current time as seed generator
    for (int i = 0; i <= 1000; i++)
    {
        largeArray[i] = rand() % 1000; //use modulo operator to get integers in range from 1 to 1000
    }
    int z = sizeof(largeArray) / sizeof(largeArray[0]);

    auto start = high_resolution_clock::now(); //entry point to begin measurement t=0
    QuickSort(largeArray, 0, z - 1);
    auto stop = high_resolution_clock::now(); //exit point to measure elapsed time t
    auto duration = duration_cast<microseconds>(stop - start);

    display(largeArray, z);

    std::cout << "\nTime Taken: " << duration.count() << " microseconds. " << std::endl;

    return 0;
}