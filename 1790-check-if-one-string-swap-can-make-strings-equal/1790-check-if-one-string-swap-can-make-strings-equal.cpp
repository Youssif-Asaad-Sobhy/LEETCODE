class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        char dif1='?',dif2='?',dif3='?',dif4='?';
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                if(dif1=='?')dif1=s1[i],dif2=s2[i];
                else if(dif3=='?')dif3=s1[i],dif4=s2[i];
                else return 0;
            }
        }
        return dif1==dif4&&dif2==dif3;
    }
};