class Solution {
public:
    void help(vector<vector<int>>& image, int i, int j, int color,int m,int n,int val)
    {
        if(i>=n or j>=m or i<0 or j<0 or image[i][j]!=val)
        {
            return;
        }

        image[i][j]=color;
        
        help(image,i+1,j,color,m,n,val);
        help(image,i-1,j,color,m,n,val);
        help(image,i,j+1,color,m,n,val);
        help(image,i,j-1,color,m,n,val);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        
        if(image[sr][sc]==color) return image;
        help(image,sr,sc,color,m,n,image[sr][sc]);
        return image;
        
    }
};