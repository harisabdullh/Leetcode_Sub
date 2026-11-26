class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        int t=0;
        //setting up all starting rotten oranges in queue , ie starting points at t=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},t});

                }
            }
        }
        

        //now applying bfs;
        
        while(!q.empty()){
            t=max(q.front().second,t);
            int r=q.front().first.first;
            int c=q.front().first.second;
            q.pop();
            //check up down right left , if idx is valid and orange is fresh or not
            // up 
            if(r+1>=0 && r+1<m && c>=0 && c<n && vis[r+1][c]!=2 && grid[r+1][c]==1){
                    q.push({{r+1,c},t+1});
                    vis[r+1][c]=2;
            }
            if(r-1>=0 && r-1<m && c>=0 && c<n && vis[r-1][c]!=2 && grid[r-1][c]==1){
                    q.push({{r-1,c},t+1});
                    vis[r-1][c]=2;
            }
            if(r>=0 && r<m && c-1>=0 && c-1<n && vis[r][c-1]!=2 && grid[r][c-1]==1){
                    q.push({{r,c-1},t+1});
                    vis[r][c-1]=2;
            }
            if(r>=0 && r<m && c+1>=0 && c+1<n && vis[r][c+1]!=2 && grid[r][c+1]==1){
                    q.push({{r,c+1},t+1});
                    vis[r][c+1]=2;
            }
            
        }
        //now check wheter all become
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j])return -1;
            }
        }
        return t;

    }
};