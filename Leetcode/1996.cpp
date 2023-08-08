class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        int res=0,mx=0,temp=0,pre=-1;
        for(int i=a.size()-1;~i;i--) {
            if(a[i][0]!=pre) {
                pre=a[i][0];
                mx=max(mx,temp);
                temp=0;
            }
            if(a[i][1]<mx) ++res;
            temp=max(temp,a[i][1]);
        }
        return res;
    }
};