class Solution {
public:
    int maxDistinct(string s) {
        unordered_map<char,int> map;
        int count=0;
        for(char c:s)
        {
            map[c]++;
            if(map[c]<2)
            {
                count++;
            }
        }
        return count;
        
    }
};