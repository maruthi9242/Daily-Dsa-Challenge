class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> un={'a','e','i','o','u','A','E','I','O','U'};
        int size=s.size();
        vector<int> ovl;
        for(int i=0;i<size;i++)
        {
            if(un.contains(s[i]))
            {
                ovl.push_back(s[i]);
            }
        }
        int i=0;
        int j=0;
        reverse(ovl.begin(),ovl.end());
        int s1=ovl.size();
        while(i<size and j<s1)
        {
            if(un.contains(s[i]))
            {
                s[i]=ovl[j++];
            }
            i++;
        }
        return s;
    }
};