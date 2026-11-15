class Solution {
public:
    bool safe=true;

    void fillX(vector<vector<char>>& grid,int n,int m,int i,int j)
    {
        if(i>=n or j>=m or i<0 or j<0 or grid[i][j]!='O')
        {
            return;
        }
        
        grid[i][j]='X';

        fillX(grid,m,n,i+1,j);
        fillX(grid,m,n,i-1,j);
        fillX(grid,m,n,i,j+1);
        fillX(grid,m,n,i,j-1);
    }

    void isSafe(vector<vector<char>>& grid,vector<vector<int>>& visited,int n,int m,int i,int j)
    {
        
        if(i>=n or j>=m or j<0 or i<0 or grid[i][j]!='O' or visited[i][j]==1)
        {
            return;
        }
        if( (i==n-1 or i==0 or j==m-1 or j==0) and grid[i][j]=='O')
        {
            visited[i][j]=1;
            safe=false;
            return;
        }
        
        visited[i][j]=1;

        isSafe(grid,visited,n,m,i+1,j);
        isSafe(grid,visited,n,m,i-1,j);
        isSafe(grid,visited,n,m,i,j+1);
        isSafe(grid,visited,n,m,i,j-1);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' and !visited[i][j] and i!=0 and j!=0 and i!=n-1 and j!=m-1)
                {
                    isSafe(board,visited,n,m,i,j);
                    if(safe)
                    {
                        fillX(board,n,m,i,j);
                    }
                    safe=true;
                }
            }
        }


    }
};