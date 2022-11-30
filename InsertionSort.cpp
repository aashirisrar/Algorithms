#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {5, 4, 3, 1, 2};

    int sizeOfArr = 5;

    // Insertion Sort
    for (int i = 1; i < sizeOfArr; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }

    // Print Array
    for (int i = 0; i < sizeOfArr; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}