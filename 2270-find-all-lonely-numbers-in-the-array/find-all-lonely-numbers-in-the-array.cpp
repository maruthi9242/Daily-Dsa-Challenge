class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> map;

        for(int i:nums)
        {
            map[i]++;
        }

        vector<int> v;
        for(auto i: map)
        {
            if(i.second==1 and !map.count(i.first-1) and !map.count(i.first+1))
            {
                v.push_back(i.first);
            }
        }
        return v;
    }
};