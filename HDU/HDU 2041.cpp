#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,M;
    cin>>N;
    int step[41]={0,0,1,2};
    for(int i=4;i<41;i++)
        step[i]=step[i-1]+step[i-2];
    while(N--)
    {
        cin>>M;
        cout<<step[M]<<endl;
    }
    return 0;
}