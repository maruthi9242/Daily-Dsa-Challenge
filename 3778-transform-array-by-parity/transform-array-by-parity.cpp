class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int> v;
        int even=0;
        int odd=0;
        for(int i:nums)
        {
            if(i%2==0)
            {
                even++;
            }
            else odd++;
            
        }
        for(int i=0;i<even;i++)
        {
            v.push_back(0);
        }
        for(int i=0;i<odd;i++)
        {
            v.push_back(1);
        }
        
        return v;
        
    }
};