class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=0,r=1e9,md,ans,tmp,cnt;
        while(l<=r)
        {
            md=(r+l)/2;
            tmp=cnt=0;
            for(int i=0;i<weights.size();)
            {
                tmp++;
                cnt=0;
                int j=i;
                if(weights[i]>md)
                {
                    tmp=days+1;
                    break;
                }
                for(j;j<weights.size();j++)
                {
                    cnt+=weights[j];
                    if(cnt>md)break;
                }
                i=j;
            }
            if(tmp>days)l=md+1;
            else if(tmp<=days)r=md-1,ans=md;
        }
        return ans;
    }
};