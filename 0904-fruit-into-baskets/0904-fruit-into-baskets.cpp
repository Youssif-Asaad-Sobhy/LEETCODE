class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int mx=0,cnt=0,total=0,n=fruits.size();
        vector<int>v(fruits.size()+1);
        for(int l=0,r=0;r<n;)
        {
            while(r<n)
            {
                if(!v[fruits[r]]&&cnt!=2)
                    v[fruits[r]]++,cnt++,total++;
                else if(!v[fruits[r]])break;
                else v[fruits[r]]++,total++;
                mx=max(mx,total);
                r++;
            }
            while(cnt==2)
            {
                v[fruits[l]]--;
                total--;
                if(!v[fruits[l]])cnt--;
                l++;
            }
        }
        return mx;
    }
};