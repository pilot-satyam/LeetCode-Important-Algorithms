class Solution {
public:
    
    void dfs(int i,int j,vector<vector<int> >&vis,vector<vector<int> >&image,int newColor,int n,int m,int oldcolor)
    {
        if(i<0 or j<0 or i>=n or j>=m)
            return;
         if(vis[i][j] or image[i][j]!=oldcolor) //if it is visited or is not of the old color
             return;
        vis[i][j]=1; // we are going to valid position
        image[i][j]=newColor; //updating the color
        dfs(i+1,j,vis,image,newColor,n,m,oldcolor);
        dfs(i-1,j,vis,image,newColor,n,m,oldcolor);
        dfs(i,j+1,vis,image,newColor,n,m,oldcolor);
        dfs(i,j-1,vis,image,newColor,n,m,oldcolor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int x = image.size();
        int y = image[0].size();
        vector<vector<int> >  vis(x,vector<int>(y,0));
        int oldcolor = image[sr][sc];
        dfs(sr,sc,vis,image,newColor,x,y,oldcolor);
        return image;
    }
};
