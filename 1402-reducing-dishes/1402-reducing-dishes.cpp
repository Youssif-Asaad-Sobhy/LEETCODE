class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end());
        int ans=0;
        for(int i=0;i<sat.size();i++)
        {
            int cnt=0,k=1;
            for(int j=i;j<sat.size();j++,k++)
            {
                cnt+=sat[j]*k;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};