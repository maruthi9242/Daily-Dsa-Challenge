class Solution {
public:
    void visit(vector<vector<char>>& grid,int i,int j,int n,int m)
    {
        if(i>=n or j>=m or  i<0 or j<0 or grid[i][j]!='1')
        {
            return;
        }
        grid[i][j]='0';
        visit(grid,i+1,j,n,m);
        visit(grid,i,j+1,n,m);
        visit(grid,i-1,j,n,m);
        visit(grid,i,j-1,n,m);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int islands=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    islands++;
                    visit(grid,i,j,n,m);  
                }
            }
        }

        return islands;

        
    }
};