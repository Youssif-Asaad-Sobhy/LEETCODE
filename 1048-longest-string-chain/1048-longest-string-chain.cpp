class Solution {
public:
   static bool cmp(string s,string  ss)
    {
        return s.size()<ss.size();
    }
    vector<int>mp;
    int solve(vector<string>&words,int idx,int jdx)
        {
        if(jdx==words.size()||idx==words.size())return 1;
        if(mp[idx])return mp[idx];
        int t=0,l=0;
        if(words[idx].size()==words[jdx].size()-1)
            {int j=0,cnt=0,tr=1;
            for(int i=0;i <words[idx].size();)
                {
                if(cnt>1)
                   {tr=0;break;}
                if(words[idx][i]==words[jdx][j])
                    i++,j++;
                else j++,cnt++;
            }
             if(tr)
            t=1+solve(words,jdx,jdx+1);
        }
        l=solve(words,idx,jdx+1);
        mp[idx]=max(t,l);
        return max(t,l);
    }

    int longestStrChain(vector<string>& words) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        mp.clear();
        mp=vector<int>(words.size(),0);
        sort(words.begin(),words.end(),cmp);
        int ans=0;
        for(int i=0;i<words.size();i++)
            for(int j=i+1;j<words.size();j++)
                ans=max(ans,solve(words,i,j));
        return max(ans,1);
    }
};