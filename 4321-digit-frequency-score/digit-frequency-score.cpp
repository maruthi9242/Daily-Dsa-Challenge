class Solution {
public:
    int digitFrequencyScore(int n) {
        string s=to_string(n);
        unordered_map<int,int> map;
        int i;
        for(char c:s){

            i=c-'0';
            map[i]++;

        }

        int sum=0;

        for(auto i:map)
        {
            sum+=i.first*i.second;
        }
        return sum;
    }
};