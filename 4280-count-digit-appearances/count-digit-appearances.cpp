class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        string s;
        char dig=digit+'0';
        int count=0;

        for(int i:nums)
        {
            s=to_string(i);
            for(char c:s)
            {
                if(c==dig)
                {
                    count++;
                }
            }
        }
        return count;
    }
};