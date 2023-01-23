class Solution {
public:
    int maxProduct(vector<int>& v) {
        int mx=INT_MIN,cur=1,crr=1,mn,ans,t;
        mx=mn=ans=v[0];
        for(int i=1;i<v.size();i++)
        {
            t=max({v[i],mx*v[i],mn*v[i]});
            mn=min({v[i],mx*v[i],mn*v[i]});
            mx=t;
            ans=max(mx,ans);
            cout<<mx<<" "<<mn<<" "<<ans<<endl;
        }
        return ans;
    }
};