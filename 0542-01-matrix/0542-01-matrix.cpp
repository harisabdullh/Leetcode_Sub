class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,-1));
        queue<pair<pair<int,int>,int>>q;
        //push every zero in bfs?

        // Push all zeroes into the queue
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({{i,j},0});
                }
            }
        }
        // BFS
        while(!q.empty()){

            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;

            q.pop();

            // Up
            if(r-1>=0 && ans[r-1][c]==-1){
                ans[r-1][c]=d+1;
                q.push({{r-1,c},d+1});
            }

            // Down
            if(r+1<m && ans[r+1][c]==-1){
                ans[r+1][c]=d+1;
                q.push({{r+1,c},d+1});
            }

            // Left
            if(c-1>=0 && ans[r][c-1]==-1){
                ans[r][c-1]=d+1;
                q.push({{r,c-1},d+1});
            }

            // Right
            if(c+1<n && ans[r][c+1]==-1){
                ans[r][c+1]=d+1;
                q.push({{r,c+1},d+1});
            }
        }

        return ans;

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(mat[i][j]==0){
        //             ans[i][j]=0;
        //         }
        //         else{
        //             int d=0;
        //             q.push({{i,j},d});
        // vector<vector<int>>vis(m,vector<int>(n,0));
        // vis[i][j]=1;
        //             while(!q.empty()){
        //                 int r=q.front().first.first;
        //                 int c=q.front().first.second;
        //                 //check neighbors
        //                 d=q.front().second;
        //                 q.pop();
        //                 if(r-1<m && r-1>=0 && c<n && c>=0 && mat[r-1][c]==0 ){
        //                     ans[i][j]=d+1;
        //                     break;
        //                 }
        //                 else if(r-1<m && r-1>=0 && c<n && c>=0 && mat[r-1][c]==1 && !vis[r-1][c]){
        //                     vis[r-1][c]=1;
        //                     q.push({{r-1,c},d+1});
        //                 }
        //                 if(r+1<m && r+1>=0 && c<n && c>=0 && mat[r+1][c]==0 ){
        //                     ans[i][j]=d+1;
        //                     break;
        //                 }
        //                 else if(r+1<m && r+1>=0 && c<n && c>=0 && mat[r+1][c]==1 && !vis[r+1][c]){
        //                     q.push({{r+1,c},d+1});
        //                     vis[r+1][c]=1;
        //                 }
        //                 if(r<m && r>=0 && c-1<n && c-1>=0 && mat[r][c-1]==0 ){
        //                     ans[i][j]=d+1;
        //                     break;
        //                 }
        //                 else if(r<m && r>=0 && c-1<n && c-1>=0 && mat[r][c-1]==1 && !vis[r][c-1]){
        //                     q.push({{r,c-1},d+1});
        //                     vis[r][c-1]=1;
        //                 }
        //                 if(r<m && r>=0 && c+1<n && c+1>=0 && mat[r][c+1]==0 ){
        //                     ans[i][j]=d+1;
        //                     break;
        //                 }
        //                 else if(r<m && r>=0 && c+1<n && c+1>=0 && mat[r][c+1]==1 && !vis[r][c+1]){
        //                     q.push({{r,c+1},d+1});
        //                     vis[r][c+1]=1;
        //                 }

        //             }
        //             while(!q.empty())q.pop();
        //         }
        //     }
        // }
        // return ans;
        
    }
};