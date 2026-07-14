class Solution {
public:
    void bfs(int row , int col , vector<vector<char>>& grid , vector<vector<int>> &vis , int n , int m){
        queue<pair<int , int>> q;
        vis[row][col]=1;
        q.push({row,col});

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            int delrow[]={-1 ,0 , 1 , 0};
            int delcol[]={0 , 1 , 0 , -1};
            for(int i=0 ; i<4 ; i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                    vis[nrow][ncol]=1;
                    q.push({nrow , ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>> vis(n , vector<int>(m , 0));
        for(int row=0 ; row<n ; row++){
            for(int col=0 ; col<m ; col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    bfs(row , col , grid , vis , n , m );
                    count++;
                }
            }
        }
        return count;
    }
};