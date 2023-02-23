class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>>pq1;
        priority_queue<int>pq2;
        for(int i=0;i<profits.size();i++)
            pq1.push({-capital[i],profits[i]});
        while(k)
        {
            while(pq1.size()&&w>=-pq1.top().first)
            {
                pq2.push(pq1.top().second);
                pq1.pop();
            }
            if(pq2.size())
            {
                w+=pq2.top();
                pq2.pop();
                k--;
            }
            else break;
        }
        return w;
    }
};