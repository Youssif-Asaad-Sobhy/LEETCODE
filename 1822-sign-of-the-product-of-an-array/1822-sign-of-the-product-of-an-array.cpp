class Solution {
public:
    int arraySign(vector<int>& nums) {
        int pos=0,neg=0,zero=0;
        for(auto it:nums)
        {
            if(it>0)
                pos++;
            else if(it==0)
                return 0;
            else neg++;
        }
        return neg%2==0?1:-1;
    }
};