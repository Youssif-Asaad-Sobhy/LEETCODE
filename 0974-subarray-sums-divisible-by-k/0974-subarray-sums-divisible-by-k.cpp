class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0,cnt=0;
        map<int,int>appear;
        for(auto it:nums)
        {
            sum+=it;
            sum=((sum%k)+k)%k;
            if(sum%k==0)cnt++;
            if(appear.find(sum%k)!=appear.end())cnt+=appear[sum%k];
            appear[sum%k]++;
        }
        return cnt;
    }
};