#include<iostream>
using namespace std;
int main()
{
    int arr[] = {2, 5, 4, 3, 2, 2, 6, 4, 1};
    int n = 9;

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        int c = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                c = 1;
                break;
            }
        }

        if (c == 1)
            continue;


        for (int i; i < n; i++)
        {
            if (arr[i] == arr[i+1])
            {
                count++;
            }
        }

        cout << arr[i] << " - " << count << endl;
    }

    return 0;
}
