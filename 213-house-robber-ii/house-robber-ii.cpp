class Solution {
public:
    int Rob(vector<int>& nums,int i,int n,bool isTaken,unordered_map<int,array<int,2>>& dp)
    {
        if(i>n) return 0;
        if(!dp.contains(i)){
            dp[i]={-1,-1};
        }
        if(dp[i][isTaken]!=-1){ 
            return dp[i][isTaken];
        };
        
        if(isTaken)
        {
            return Rob(nums,i+1,n,0,dp);
        }
        int take=nums[i]+Rob(nums,i+1,n,1,dp);
        
        int NotTake=Rob(nums,i+1,n,0,dp);

        return dp[i][isTaken]=max(take,NotTake);
    }
    int rob(vector<int>& nums) {
        unordered_map<int,array<int,2>> dp;
        unordered_map<int,array<int,2>> dp1;
        if(nums.size()==1)
        {
            return nums[0];
        }
        if(nums.size()==2)
        {
            return max(nums[0],nums[1]);
        }
        return max(Rob(nums,0,nums.size()-2,0,dp),Rob(nums,1,nums.size()-1,0,dp1));
    }
};