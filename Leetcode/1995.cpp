class Solution {
public:
    int countQuadruplets(vector<int>&v) {
        int res=0;
        for(int i=0;i<v.size();i++)
            for(int j=i+1;j<v.size();j++)
                for(int k=j+1;k<v.size();k++)
                    for(int l=k+1;l<v.size();l++)
                        if(v[i]+v[j]+v[k]==v[l])
                            ++res;
        return res;
    }
};