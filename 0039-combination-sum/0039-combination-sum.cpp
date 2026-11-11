class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int>& v,vector<int>& people,int target,int i)
    {
        if(target==0)
        {
            ans.push_back(v);
            return;
        }
        if(i>=people.size() or target<0)
        {
            return;
        }
        if(target>=people[i])
        {
            v.push_back(people[i]);
            solve(ans,v,people,target-people[i],i);
            v.pop_back();
        }
        solve(ans,v,people,target,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;

        solve(ans,v,candidates,target,0);
        return ans;
    }
};