class Solution {
public:
    void sortMat(vector<vector<int>>& mat,int i,int j,int n,int m)
    {
        int x=i;
        int y=j;
        priority_queue<int,vector<int>,greater<int>> pq;
        while(x<n and y<m)
        {
            pq.push(mat[x++][y++]);
        }
        x=i;
        y=j;
        while(x<n and y<m)
        {
            mat[x++][y++]=pq.top();
            pq.pop();
        }
        
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        for(int i=0;i<n;i++)
        {
            sortMat(mat,i,0,n,m);
        }
        for(int i=1;i<m;i++)
        {
            sortMat(mat,0,i,n,m);
        }
        return mat;
    }
};