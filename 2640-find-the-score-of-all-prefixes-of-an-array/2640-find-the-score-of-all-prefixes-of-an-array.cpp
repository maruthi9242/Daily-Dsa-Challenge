class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
            nums[i]=maxi+nums[i];
        }
        vector<long long> ans;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            ans.push_back(sum);
        }
        return ans;
    }
};