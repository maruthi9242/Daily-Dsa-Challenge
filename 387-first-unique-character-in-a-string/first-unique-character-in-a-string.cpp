class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> map;
        unordered_map<char,int> index;
        int latest_unique=0;
        for(int i=0;i<s.size();i++)
        {
            map[s[i]]++;
            index[s[i]]=i;
        }

        int minimum=INT_MAX;

        for(auto i:map)
        {
            if(i.second==1)
            {
                minimum=min(minimum,index[i.first]);
            }
        }
        if(minimum==INT_MAX)
        {
            return -1;
        }
        return minimum;
        
    }
};