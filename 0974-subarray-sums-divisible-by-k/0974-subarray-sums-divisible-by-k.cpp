class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0,cnt=0;
        map<int,int>appear;
        for(auto it:nums)
        {
            sum+=it;
            appear[((sum % k) + k) % k]++;
        }
        for(int i=0;i<k;i++)
        {
            if(appear.find(i)!=appear.end())
                cnt+=((appear[i]-1)*appear[i]/2);
        }
        return cnt+appear[0];
    }
};