class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //traverse on the boundary , save the starting points
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || j==0 || i==m-1 || j==n-1) && board[i][j]=='O'){
                        q.push({i,j});
                        vis[i][j]=1;
                }
            }
        }
        //now we have all the starting points, now we traverse accros all string points and mark O's 
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int delr[4]={-1,0,1,0};
            int delc[4]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nr=r+delr[i];
                int nc=c+delc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && board[nr][nc]=='O'){
                    vis[nr][nc]=1;
                    q.push({nr,nc});

                }

            }

        }
        //now we have all of them marked as corners
        //we will modify oyr matrix now;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};