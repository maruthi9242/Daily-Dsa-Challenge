//

class DisjointSet{
    public:
    vector<int> rank;
    vector<int> parent;

    DisjointSet(int n)
    {
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        {
            parent.push_back(i);
        }
    }
    
    int FindMainParent(int n)
    {
        if(parent[n]==n)
        {
            return n;
        }
        return parent[n]=FindMainParent(parent[n]);
    }
    void Union(int u,int v)
    {
        u=FindMainParent(u);
        v=FindMainParent(v);

        if(rank[u]==rank[v])
        {
            rank[v]++;
            parent[u]=v;
        }
        else if(rank[u]>rank[v])
        {
            parent[v]=u;
        }
        else{
            parent[u]=v;
        }
    }
};

class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DisjointSet dsu(n);
        
        

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1){
                    dsu.Union(i,j);
                }
            }
        }

    

        int sum=0;
        unordered_set<int> set;
        for(int i:dsu.parent)
        {
            dsu.parent[i]=dsu.FindMainParent(i);
            if(!set.contains(dsu.parent[i]))
            {
                sum++;
                set.insert(dsu.parent[i]);
            }

        }

        return sum;
        
    }
};