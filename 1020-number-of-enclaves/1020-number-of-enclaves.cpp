class Solution {
public:
    void toogle(vector<vector<int>>& grid,int n,int m,int i,int j)
    {
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]!=1)
        {
            return;
        }
        grid[i][j]=0;
        toogle(grid,n,m,i+1,j);
        toogle(grid,n,m,i,j+1);
        toogle(grid,n,m,i-1,j);
        toogle(grid,n,m,i,j-1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1) {
                toogle(grid,n,m,0,i);
               
            }
        }

        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1) {
                toogle(grid,n,m,i,0);
               
            }
        }

        for(int i=0;i<m;i++)
        {
            if(grid[n-1][i]==1)
            {
                toogle(grid,n,m,n-1,i);
                
            }
        }
        for(int i=0;i<n;i++)
        {
            if(grid[i][m-1]==1)
            {
                toogle(grid,n,m,i,m-1);
               
            }
        }

        int count=0;

        for(auto i:grid){
            for(auto j:i)
            {
                if(j==1) count++;
            }
        }
        return count;
        
    }
};