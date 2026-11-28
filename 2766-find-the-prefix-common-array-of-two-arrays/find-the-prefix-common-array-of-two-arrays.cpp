class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        unordered_set<int> set1;

        unordered_set<int> set2;

        int n=A.size();
        int count=0;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            set1.insert(A[i]);
            set2.insert(B[i]);

                if(A[i]==B[i]){
                     count++;
                     ans.push_back(count);
                     continue;
                }
            
                if(set2.contains(A[i]))
                {
                    count++;
                }
                if(set1.contains(B[i]))
                {
                    count++;
                }
            
            ans.push_back(count);

           // count=0;
        }

        return ans;
    }
};