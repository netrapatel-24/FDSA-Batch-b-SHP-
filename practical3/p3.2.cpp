#include <iostream>
using namespace std;

void sort(int arr[], int n)
{
    int l = 0;
    int m = 0;
    int h = n - 1;

    while (m <= h)
    {
        if (arr[m] == 0)
        {
            int temp = arr[l];
            arr[l] = arr[m];
            arr[m] = temp;

            l++;
            m++;
        }
        else if (arr[m] == 1)
        {
            m++;
        }
        else
        {
            int temp = arr[m];
            arr[m] = arr[h];
            arr[h] = temp;

            h--;
        }
    }
}

void show(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {2, 0, 1, 2, 1, 0, 2, 1, 0};
    int n = 9;

    sort(arr, n);

    cout << "Sorted colours: ";
    show(arr, n);

    return 0;
}

