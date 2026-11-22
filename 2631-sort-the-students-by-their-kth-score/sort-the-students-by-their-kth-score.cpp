class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {

        priority_queue<pair<int,vector<int>>> pq;
        int n=score.size();
        for(int i=0;i<n;i++)
        {
            pq.push({score[i][k],score[i]});

        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};