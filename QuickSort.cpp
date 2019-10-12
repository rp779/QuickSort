#include<iostream> // cout, <<, endl
#include<cstdlib> // rand() and srand()
#include<ctime> // use time() to set seed for srand()

/* Swap */
void Swap(int &A, int &B){
    int temp = A;
    A = B;
    B = temp;
}

/* Partition */
int Partition(int *A, int low, int high)
{
    int pivot = A[high]; // select pivot to be the last element
    int start = low;     
    for(int i = low; i < high; i++)
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
void QuickSort(int A[], int low, int high){
    if(low < high){
        int q = Partition(A, low, high);
        QuickSort(A, 0, q - 1);   // Call Quicksort recursively on left subarray
        QuickSort(A, q + 1, high);// Call Quicksort recursively on righ subarray
    }
}

int main(){

    int arr[] = {10, 80, 3, 19, 14, 7, 5, 12};
    int n = sizeof(arr)/sizeof(arr[0]); //size of array in bits/size of element bits = size of array
    QuickSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    } 

    std::cout << std::endl;

    int myArray [100];
    std::srand(time(0)); // use current time as seed generator
    for(int i = 0; i <= 100; i++){
        myArray[i] = rand() % 100; //use modulo operator to get integers in range from 1 to 100
    }
    int s = sizeof(myArray)/sizeof(myArray[0]);
    QuickSort(myArray, 0, s - 1);
    for(int i = 0; i < s; i++){
        std::cout << myArray[i] << " ";
    } 

    std::cout << std::endl;

    int myBigArray [1000];
    std::srand(time(0)); // use current time as seed generator
    for(int i = 0; i <= 1000; i++){
        myBigArray[i] = rand() % 1000; //use modulo operator to get integers in range from 1 to 1000
    }
    int z = sizeof(myBigArray)/sizeof(myBigArray[0]);
    QuickSort(myBigArray, 0, z - 1);
    for(int i = 0; i < z; i++){
        std::cout << myBigArray[i] << " ";
    } 

    return 0;
}