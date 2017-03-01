#include <iostream>

using namespace std;

int main()
{
    int arry[1000];
    int n = 0, inNum = 0;
    cin >> n;
    for(int i=0; i< n; i++)
    {
        cin >> inNum;
        arry[i] = inNum;
    }

    int maxSum = 0, thisSum = 0;

    for(int i=0; i< n; i++)
    {
        thisSum = thisSum + arry[i];
        if(thisSum > maxSum)
            maxSum = thisSum;
        else if(thisSum < 0)
            thisSum = 0;
    }


    cout << maxSum << endl;
    return 0;
}
