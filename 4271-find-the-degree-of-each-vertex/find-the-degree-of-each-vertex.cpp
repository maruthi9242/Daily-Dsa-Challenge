class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ans;
        int count=0;
        for(auto i:matrix)
        {
            for(auto j:i)
            {
                if(j==1) count++;
            }
            ans.push_back(count);
            count=0;
        }
        return ans;
        
    }
};