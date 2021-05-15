#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int t=n-2;
        int a=n*n*n;
        cout<<a*(a-1)/2-(3*t*t*t+15*t*t+24*t+12)<<endl;
    }
    return 0;
}