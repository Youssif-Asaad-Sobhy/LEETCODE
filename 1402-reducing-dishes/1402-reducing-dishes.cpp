class Solution {
public:
    vector<vector<int>>dp;
    int maxSatisfaction(vector<int>& sat) {
        dp=vector<vector<int>>(sat.size()+5,vector<int>(sat.size()+5,-1));
        sort(sat.begin(),sat.end());
        return solve(0,1,sat);
    }
    int solve(int i,int j,vector<int>&sat)
    {
        if(i==sat.size())return 0;
        int&ret=dp[i][j];
        if(~ret)return ret;
        int take=solve(i+1,j+1,sat)+sat[i]*j;
        int leave=solve(i+1,j,sat);
        return ret=max(take,leave);
    }
};