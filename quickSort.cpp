#include <iostream>
#include <fstream>

using namespace std;

int comparisons = 0; 

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high; j++)
    {
        comparisons++;
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    comparisons++; 
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n, pivotPos;
    string pathFile;

    cout << "Enter file path: ";
    cin >> pathFile;

    ifstream inputFile(pathFile);
    inputFile >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        inputFile >> arr[i];
    }
    inputFile.close();

    cout << "Select the position of the pivot element: first, middle, or last: ";
    cin >> pivotPos;

    int low = 0, high = n - 1;

    if (pivotPos == 1)
    {
        quickSort(arr, low, high);
    }
    else if (pivotPos == 2)
    {
        quickSort(arr, low + (high - low) / 2, high);
    }
    else if (pivotPos == 3)
    {
        quickSort(arr, low, high - (high - low) / 2);
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nNumber of comparisons: " << comparisons << endl;
    cout << "Number of elements: " << n;

    delete[] arr;
    return 0;
}