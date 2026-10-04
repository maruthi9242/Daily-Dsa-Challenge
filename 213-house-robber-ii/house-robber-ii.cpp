class Solution {
public:
    int Rob(vector<int>& nums,int i,int n,vector<int>& dp)
    {
        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int take=nums[i]+Rob(nums,i+2,n,dp);
        
        int NotTake=Rob(nums,i+1,n,dp);

        return dp[i]=max(take,NotTake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size()+1,-1);
        vector<int> dp2(nums.size()+1,-1);

        if(nums.size()==1)
        {
            return nums[0];
        }
        if(nums.size()==2)
        {
            return max(nums[0],nums[1]);
        }
        return max(Rob(nums,0,nums.size()-2,dp1),Rob(nums,1,nums.size()-1,dp2));
    }
};