#include <iostream>

using namespace std;

int main()
{
    int arry[100001] = {0};
    int n = 0, inNum = 0;
    cin >> n;
    for(int i=0; i< n; i++)
    {
        cin >> inNum;
        arry[i] = inNum;
    }

    int ThisSum = arry[0];
    int maxSum = arry[0];
    int last = arry[0];
    int first = arry[0];
    int preIndex = 0;
    int postIndex = 0;


    if(n !=1 )
    {

        for(int i = 1; i < n; i++)
        {
            if(ThisSum >= 0)
            {
                ThisSum += arry[i];
                postIndex++;
            }
            else
            {
                ThisSum = arry[i];
                preIndex = i;
                postIndex = i;
            }
            if(ThisSum > maxSum)
            {
                maxSum = ThisSum;
                last = arry[postIndex];
                first = arry[preIndex];
            }

        }
        if(maxSum < 0)
            {
                last = arry[n-1];
                first = arry[0];
            }

    }
    else if(n == 0)
    {
        return -1;
    }

    cout << maxSum << " " << first << " " << last << endl;
    return 0;
}


