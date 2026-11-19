class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int temp=0;
        int i=0;

        while(i!=n)
        {
            if(nums[i]!=0)
            {
                temp=i;
                while(temp-1>=0 and nums[temp-1]==0)
                {
                    swap(nums[temp],nums[temp-1]);
                    temp--;
                }
            }
            i++;
        }
        
    }
};