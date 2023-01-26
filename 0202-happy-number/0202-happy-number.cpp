class Solution {
public:
    bool isHappy(int n) {
        map<int,bool>mp;
        while(n!=1)
        {
            int x=0;
            while(n)
            {
                x+=((n%10)*(n%10));
                n/=10;
            }
            n=x;
            if(mp.find(n)!=mp.end())return 0;
            mp[n]=1;
        }
        return 1;
    }
};