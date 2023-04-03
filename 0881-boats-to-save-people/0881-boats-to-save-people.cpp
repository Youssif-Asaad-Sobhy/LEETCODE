class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(),p.end());
        int ans=p.size();
        int l=0,r=p.size()-1;
        while(l<r)
        {
            if(p[l]+p[r]>limit)
                r--;
            else l++,r--,ans--;
        }
        return ans;
    }
};