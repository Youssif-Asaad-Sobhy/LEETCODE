class Solution {
public:
    int dp[40];
    int tribonacci(int n) {
        if(n<=2)return min(n,1);
        if(dp[n])return dp[n];
        return dp[n]=tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};