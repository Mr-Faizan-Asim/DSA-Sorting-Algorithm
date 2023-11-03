#include <iostream>
using namespace std;

template <typename item>
void insertionSort(item data[], size_t n)
{
    int j;
    item temp;
    for (int i = 1; i < n; i++)
    {
        temp = data[i];
        for (j = i; j > 0 and data[j - 1] > temp; j--)
        {
            data[j] = data[j - 1];
        }
        data[j] = temp;
    }

}

template <typename item>
void selectionSort(item data[], size_t n)
{
    int smallest;
    item temp;
    for (int i = 0; i < n - 1; i++)
    {
        smallest = i;
        for (int j = i + 1; j < n; j++)
        {

            if (data[smallest] > data[j])
            {
                smallest = j;
            }
        }
        temp = data[i];
        data[i] = data[smallest];
        data[smallest] = temp;
    }
}
// Bubble Sort
template <typename item>
void BubbleSort(item data[], size_t n)
{
    size_t i, j;
    item temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}
// Merger
void merger(int arr[], int start,int mid,int en)
{
    const int con = en - start + 1;
        int mer[100];
        int ob1 = start;
        int ob2 = mid + 1;
        int x = 0;
        while (ob1 <= mid && ob2 <= en)
        {
            if (arr[ob1] <= arr[ob2])
            {
                mer[x] = arr[ob1];
                ob1++;
                x++;
            }
            else
            {
                mer[x] = arr[ob2];
                ob2++;
                x++;
            }
        }
        while(ob1 <= mid)
        {
            mer[x] = arr[ob1];
            x++;
            ob1++;
        }
        while (ob2 <= en)
        {
            mer[x] = arr[ob2];
            x++;
            ob2++;
        }
        for (int i = 0, j = start; i < en - start + 1; i++, j++)
        {
            arr[j] = mer[i];
        }
    
}
// Merge Sort 
void mergeSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merger(arr, start, mid, end);
}

int partition(int arr[], int low,int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            //swap
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }
    i++;
    //swap with pivot i++;
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, pi + 1, high);
    }
}

// Driver code
int main()
{
    int arr[6] = { 12, 11, 13, 5, 6, 7 };
    quickSort(arr, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i]<<",";
    }

}