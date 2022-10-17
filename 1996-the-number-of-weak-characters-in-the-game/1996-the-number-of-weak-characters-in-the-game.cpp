class Solution {
public:
    static bool cmp(vector<int>&x,vector<int>&y)
    {
        if(x[0]<y[0])return 1;
        if(x[0]>y[0])return 0;
        if(x[1]>y[1])return 1;
        if(x[1]<=y[1])return 0;
        return 0;
    }
    int numberOfWeakCharacters(vector<vector<int>>& v) {
        int cnt=0;
        sort(v.begin(),v.end(),cmp);
        int x=v.size()-1;
        int f,mxs=0;
        f=v[x][0];
        for(int i=v.size()-1;i>=0;i--)
        {
            if(mxs>v[i][1])
                cnt++;
            mxs=max(v[i][1],mxs);
        }
        return cnt;
    }
};