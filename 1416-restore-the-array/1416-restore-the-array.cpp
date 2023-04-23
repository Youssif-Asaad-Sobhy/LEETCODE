class Solution {
public:
    int mod=1e9+7,k;
    string s;
    vector<int>dp;
    int solve(int i)
    {
        if(i==s.size())return 1;
        if(s[i]=='0')return 0;
        int &ret=dp[i];
        if(~ret)return ret;
        long long a=0,cnt=0;
        for(i;i<s.size();i++)
        {
            a*=10;
            a+=s[i]-'0';
            if(a>=1&&a<=k)cnt=(cnt+solve(i+1))%mod;
            else break;
        }
        return ret=cnt;
    }
    int numberOfArrays(string ss, int kk) {
        dp=vector<int>(ss.size(),-1);
        k=kk;
        s=ss;
        return solve(0);
    }
};