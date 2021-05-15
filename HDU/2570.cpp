#include<bits/stdc++.h>
using namespace std;
int main()
{
    int C;
    cin>>C;
    while(C--)
    {
        int n,V,W,max=0,Pi_sum=0;
        double W_temp=0.0;
        cin>>n>>V>>W;
        int Pi[n];
        for(int i=0;i<n;i++)
            cin>>Pi[i];
        sort(Pi,Pi+n);
        for(int i=0;i<n;i++)
        {
            if((double)(Pi_sum+Pi[i])/(i+1)<=W)
            {
                Pi_sum+=Pi[i];
                W_temp=(double)Pi_sum/(i+1);
                max++;
            }
            else
                break;
        }
        cout<<setiosflags(ios::fixed)<<setprecision(2);
        cout<<max*V<<" "<<W_temp*0.01<<endl;
    }
    return 0;
}