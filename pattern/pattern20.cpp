#include <iostream>
using namespace std;

class Solution
{

public:
    void printPattern(int n)
    {
        int t = 1;
        for (int i = 0; i < 2 * n-1; i++)
        {
            for (int j = 0; j < 2 * n; j++)
            {
                if ((j <= i || j > 2 * n - i - 2) && i<=2 * n - i - 2) {cout << "*"; t = 0; }
                else if (((2 * n - 1) / 2 < i)){
                    if(j > i || j < ((2 * n - 1) / 2) - t){ 
                        cout<<"X";
                    }
                    else cout<<" ";
                } 
                else {cout << " "; t = 0; }
            }
            t--;
            cout << endl;
        }
    }
};

int main()
{
    Solution a;
     a.printPattern(3);
    return 0;
}