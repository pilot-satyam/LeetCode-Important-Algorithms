/* Since it is given the shortest path , we need to use the BFS*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n = g.size();
        // invalid src OR des
        if(g[0][0] == 1 || g[n-1][n-1] == 1)
            return -1;
        queue<pair<int,int>>q;
        q.push({0,0});
        
        int dir_4[5] =   {0, -1, 0,  1, 0};
        int dir_dig[5] = {1, -1, -1, 1, 1};
        
        int step = 1;
        
        while(!q.empty()){
            
            queue<pair<int,int>>qq;
            
            while(!q.empty()){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                if(i < 0 || j < 0 || i==n || j==n || g[i][j]==1){
                    continue;
                }
                
                g[i][j] = 1;
                
                if(i == n-1 && j == n-1)
                    return step;
                
                for(int d=1; d < 5; ++d){
                    qq.push({i+dir_4[d], j+dir_4[d-1]});
                    qq.push({i+dir_dig[d], j+dir_dig[d-1]});
                }
            }
            ++step;
            q = qq; 
        }
        return -1;
    }
};
