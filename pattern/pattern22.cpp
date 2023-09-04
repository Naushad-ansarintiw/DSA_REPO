#include <iostream>
using namespace std;
int main()
{
    int n, t = 0, p = 1, h = 1;
    cin >> n;
    int dup;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            if (i <= 2 * n - 2 - i)
            {
                if (j > i && j <= 2 * n - 2 - i)
                {
                    cout << dup <<" ";
                }
                else if (j <= i)
                {
                    dup = n - t;
                    cout << dup <<" ";
                    t++;
                }
                else if (j > 2 * n - 2 - i)
                {
                    cout << ++dup << " ";
                }
            }
            else
            {
                if (j > i - 2*h && j <= i)
                {
                    cout << dup << " ";
                }
                else if (j <= i - 2*h)
                {
                    dup = n - t;
                    cout << dup << " ";
                    t++;
                }
                else if (j > i)
                {
                    cout << ++dup <<" ";
                    p++;
                } 
                if(j == 2*n-2) h++;
            }
        }
           p = 1;
           t = 0;
             dup = n;
             cout<<endl;
    }

    return 0;
}