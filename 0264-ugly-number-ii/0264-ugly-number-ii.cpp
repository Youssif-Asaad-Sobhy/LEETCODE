class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long>dp;
        int j=0,ans;
        dp.insert(1);
        for(auto it:dp)
        {
            dp.insert(it*2);
            if(dp.size()>=1800)break;
            dp.insert(it*3);
            if(dp.size()>=1800)break;
            dp.insert(it*5);
            if(dp.size()>=1800)break;
        }
        j=0;
        for(auto it:dp)
        {
            j++;
            cout<<j<<endl;
            if(j==n)return it;
        }
        return 0;
    }
};