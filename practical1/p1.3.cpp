#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[100];

    cout << "Enter a sentence: ";
    cin.getline(s, 100);

    int maxl = 0, cl = 0;
    int start = 0, maxstart = 0;

    for (int i = 0; i <= strlen(s); i++)
    {
        if (s[i] != ' ' && s[i] != '\0')
        {
            cl++;
        }
        else
        {
            if (cl > maxl)
            {
                maxl = cl;
                maxstart = start;
            }

            cl = 0;
            start = i + 1;
        }
    }

    cout << "Longest word: ";
    for (int i = maxstart; i < maxstart + maxl; i++)
    {
        cout << s[i];
    }

    cout << endl;
    cout << "Character count: " << maxl;

    return 0;
}
