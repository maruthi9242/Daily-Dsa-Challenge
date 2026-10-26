class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> map;
        int maxi=INT_MIN;
        for(int i:nums)
        {
            map[i]++;
            maxi=max(maxi,map[i]);
        }
        vector<int> v;
        vector<vector<int>> ans;

        for(int i=1;i<=maxi;i++)
        {
            for(auto elem:map)
            {
                if(elem.second>=i)
                {
                    v.push_back(elem.first);
                }
            }
            ans.push_back(v);
            v.resize(0);

        }
        return ans;
    }
};