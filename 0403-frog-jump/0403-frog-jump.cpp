class Solution {
public:
    int dp[2000][2000];
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1)return 0;
        memset(dp,-1,sizeof dp);
        return solve(0,1,1,stones);
    }
    int GetNext(int value,vector<int>& s)
    {
        auto it=lower_bound(s.begin(),s.end(),value);
        if(it==s.end())return 2002;
        return (*it==value?it-s.begin():2002);
    }
    bool solve(int prev,int i,int k,vector<int>& s)
    {
        if(i==s.size()-1)return 1;
        else if(i>=s.size())return 0;
        int &ret=dp[prev][i];
        if(~ret)return ret;
        bool tr=0;
        if(k-1>0)
        {
            int next=GetNext(s[i]+k-1,s);
            tr|=solve(i,next,k-1,s);
        }
        int next=GetNext(s[i]+k,s);
        tr|=solve(i,next,k,s);
        next=GetNext(s[i]+k+1,s);
        tr|=solve(i,next,k+1,s);
        return ret=tr;
    }
};