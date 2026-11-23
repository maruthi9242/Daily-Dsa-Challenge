class Solution {
public:


    void sortascAndPlace(vector<vector<int>>& grid,int n,int i,int j)
    {
        int x=i;
        int y=j;
        priority_queue<int,vector<int>,greater<int>> pq;

        
        while(x<n and y<n)
        {
            pq.push(grid[x++][y++]);
        }
        x=i;
        y=j;
        while(x<n and y<n)
        {
            grid[x++][y++]=pq.top();
            pq.pop();
        }
    }

    void sortdescAndPlace(vector<vector<int>>& grid,int n,int i,int j)
    {
        int x=i;
        int y=j;
        priority_queue<int> pq;

        
        while(x<n and y<n)
        {
            pq.push(grid[x++][y++]);
        }
        x=i;
        y=j;
        while(x<n and y<n)
        {
            grid[x++][y++]=pq.top();
            pq.pop();
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1)
        {
            return grid;
        }

        //row (increase)
        for(int i=0;i<n;i++)
        {
            
            sortdescAndPlace(grid,n,i,0);
        }
        //column decrease
        for(int i=1;i<n;i++)
        {
            sortascAndPlace(grid,n,0,i);
            
        }
        return grid;
    }
};