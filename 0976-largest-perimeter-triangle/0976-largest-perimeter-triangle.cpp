class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n&&ans==0;i++)
        {
            for(int j=i+1;j<n&&ans==0;j++)
            {
                for(int k=j+1;k<n&&ans==0;k++)
                {
                    if(valid(nums[i],nums[j],nums[k]))
                    {
                        ans=max(ans,nums[i]+nums[j]+nums[k]);
                    }
                    else break;
                }
            }
        }
        return ans;
    }
    bool valid(int &x,int &y,int &z)
    {return x+y>z&&x+z>y&&y+z>x;}
};