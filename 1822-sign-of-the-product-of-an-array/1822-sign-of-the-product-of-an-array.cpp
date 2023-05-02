class Solution {
public:
    int arraySign(vector<int>& nums) {
        int pos=0,neg=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                pos++;
            else if(nums[i]<0)
                neg++;
            else return 0;
        }
        return neg%2==0?1:-1;
    }
};