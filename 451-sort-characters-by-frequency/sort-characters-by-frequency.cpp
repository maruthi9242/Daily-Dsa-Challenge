class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        for(char c:s)
        {
            map[c]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto i:map)
        {
            pq.push({i.second,i.first});
        }
        string ans="";
        while(!pq.empty())
        {
            pair<int,char> temp=pq.top();
            pq.pop();
            for(int i=0;i<temp.first;i++)
            {
                ans+=temp.second;
            }
        }
        return ans;
        
    }
};