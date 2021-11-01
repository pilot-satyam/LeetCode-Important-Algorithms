class Solution {
public:
    void dfs(int start , vector<vector<int>> &isConnected ,  vector<int> &vis, int n)
{
             vis[start]  = true;
     for(int i = 0 ; i < n;i++)
     {
         if(vis[i] == false && isConnected[start][i] == 1)
         {
             dfs(i,isConnected, vis, n);
         }
     }
     
}
int findCircleNum(vector<vector<int>>& isConnected) {
    
    int n = isConnected.size() ;
       vector<int> vis(n ,0);
    int cnt = 0 ;
    
    for(int i  = 0 ; i < n; i++)
    {
        if(vis[i] == 0)
        {
            cnt++;
            dfs(i,isConnected,vis,n);
        }
    }
    return cnt ;
}
};
