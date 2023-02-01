class Solution {
public:
    
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        vector<vector<int>>dp(t.length()+1,vector<int>(t.length()+1,-1));
        return solve(s,t,0,0,dp);
    }
    int solve(string&s,string&t,int i,int j,vector<vector<int>>&dp){
        if(i>=s.length() || j>=t.length()){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int t1 = 0;
        if(s[i]==t[j]){
            t1 += 1 + solve(s,t,i+1,j+1,dp);
        }
        else{
            t1 += solve(s,t,i+1,j,dp);
            int t2 = solve(s,t,i,j+1,dp);
            t1 = max(t1,t2);
        }
        return dp[i][j] = t1;
    }
};