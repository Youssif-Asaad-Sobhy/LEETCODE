class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0,cnt=0;
        map<int,int>appear;
        for(auto it:nums)
        {
            sum+=it;
            if(sum%k==0)appear[0]++;
            else if(sum%k<0)appear[(sum%k)+k]++;
            else appear[sum%k]++;
        }
        for(int i=0;i<k;i++)
        {
            if(appear.find(i)!=appear.end())
                cnt+=((appear[i]-1)*appear[i]/2);
        }
        return cnt+appear[0];
    }
};