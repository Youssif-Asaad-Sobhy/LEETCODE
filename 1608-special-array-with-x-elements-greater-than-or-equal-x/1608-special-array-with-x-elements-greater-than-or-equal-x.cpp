class Solution {
public:
    int specialArray(vector<int>& nums) {
        int pos,l=1,r=1000,md;
        sort(nums.begin(),nums.end());
        while(l<=r)
        {
            md=(l+r)/2;
            pos=lower_bound(nums.begin(),nums.end(),md)-nums.begin();
            pos=nums.size()-pos;
            if(md>pos)r=md-1;
            else if(md==pos)return md;
            else l=md+1;
        }
        return -1;
    }
};