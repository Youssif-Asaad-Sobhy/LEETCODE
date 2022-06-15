class Solution {
public:
    vector<vector<int>>arr;
    bool valid(int i,int j,vector<vector<int>>& t)
    {
        return i>=0&&j>=0&&i<t.size()&&j<i+1;
    }
    int mnmm(int i,int j,vector<vector<int>>& t)
    {
        if(!valid(i,j,t))
            return 0;
        if(arr[i][j]!=INT_MIN)
            return arr[i][j];
        int t0,t1;
        t0=t[i][j]+mnmm(i+1,j,t);
        t1=t[i][j]+mnmm(i+1,j+1,t);
        arr[i][j]=min(t0,t1);
        return arr[i][j];
    }
    int minimumTotal(vector<vector<int>>& t) {
        arr=vector<vector<int>>(t.size(),(vector<int>(t.size(),INT_MIN)));
        return mnmm(0,0,t);
    }
};