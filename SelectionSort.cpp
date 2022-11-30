#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {5, 4, 3, 1, 2};

    int sizeOfArr = 5;

    int index = 0;

    bool run = false;

    // Selection Sort
    for (int i = 0; i < sizeOfArr - 1; i++)
    {
        int minValue = arr[i];
        run = false;

        for (int j = i + 1; j < sizeOfArr; j++)
        {
            if (arr[j] < minValue)
            {
                minValue = arr[j];
                index = j;
                run = true;
            }
        }
        if (run)
        {
            int temp = arr[i];
            arr[i] = minValue;
            arr[index] = temp;
        }
    }

    // Print Array
    for (int i = 0; i < sizeOfArr; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}