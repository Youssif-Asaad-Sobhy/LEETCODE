class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx=0;
        int cur=0;
        for(auto it:gain)cur+=it,mx=max(mx,cur);
        return mx;
    }
};