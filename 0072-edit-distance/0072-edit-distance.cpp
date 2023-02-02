class Solution {
public:
    string s,ss;
    int n,m;
    vector<vector<int>>dp;
    int solve(int i,int j)
    {
        if(j==m&&i==n)return 0;
        int &ret=dp[i][j];
        if(~ret)return ret;
        int remove,replace,add,skip;
        remove=replace=skip=add=INT_MAX;
        if(i<n&&j<m)
        {
            if(s[i]==ss[j])
                skip=solve(i+1,j+1);
            remove=solve(i+1,j)+1;
            replace=solve(i+1,j+1)+1;
            add=solve(i,j+1)+1;
        }
        else if(i==n)
            add=solve(i,j+1)+1;
        else if(j==m)
            remove=solve(i+1,j)+1;
        return ret=min({remove,add,replace,skip});
    }
    int minDistance(string word1, string word2) {
        s=word1;
        ss=word2;
        n=s.size(),m=ss.size();
        dp=vector<vector<int>>(n+5,vector<int>(m+5,-1));
        return solve(0,0);
    }
};