#include <iostream>
using namespace std;

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i, j, minIndex, temp;

    for (i = 0; i<n-1; i++)
    {
        minIndex = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        temp = arr[minIndex];               
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
    cout << "Sorted array: \n";
    for (int i=0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
