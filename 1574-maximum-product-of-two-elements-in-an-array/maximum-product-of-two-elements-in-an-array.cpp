class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            maxi=max((nums[i] - 1) * (nums[i+1] - 1),maxi);

        }
        return maxi;
    }
};