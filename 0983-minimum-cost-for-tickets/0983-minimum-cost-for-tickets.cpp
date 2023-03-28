class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,-1);
        return solve(0,0,dp,days,costs);
    }
    int solve(int i,int ld,vector<int>&dp,vector<int>&days,vector<int>&costs)
    {
        if(i==days.size())return 0;
        if(days[i]<=ld)return solve(i+1,ld,dp,days,costs);
        int&ret=dp[i];
        if(~ret)return ret;
        return ret=min({
            solve(i+1,days[i],dp,days,costs)+costs[0]
            ,solve(i+1,days[i]+6,dp,days,costs)+costs[1]
            ,solve(i+1,days[i]+29,dp,days,costs)+costs[2]});
        
    }
};