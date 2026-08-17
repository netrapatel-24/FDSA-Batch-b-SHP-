#include <iostream>
using namespace std;

void bs(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void ss(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int low = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[low])
            {
                low = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[low];
        arr[low] = temp;
    }
}

void is(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
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
    int m[] = {75, 45, 90, 60, 30, 85};
    int n = 6;


    int b[6];
    int s[6];
    int in[6];

    for (int i = 0; i < n; i++)
    {
        b[i] = m[i];
        s[i] = m[i];
        in[i] = m[i];
    }


    bs(b, n);
    cout << "Bubble Sort: ";
    show(b, n);

    ss(s, n);
    cout << "Selection Sort: ";
    show(s, n);

    is(in, n);
    cout << "Insertion Sort: ";
    show(in, n);

    return 0;
}
