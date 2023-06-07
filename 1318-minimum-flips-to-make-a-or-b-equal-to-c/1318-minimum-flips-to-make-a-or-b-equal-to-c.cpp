class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        for(int i=0;i<31;i++)
        {
            int j=(1<<i);
            if(c&j)
            {
                if((a&j)||(b&j))continue;
                else ans++;
            }
            else
            {
                ans+=((a&j)>0)+((b&j)>0);
            }
        }
        return ans;
    }
};