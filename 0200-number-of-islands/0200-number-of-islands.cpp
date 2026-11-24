class Solution {
public:
void count (vector<vector<char>>&grid, vector<vector<int>>&vis,int i, int j){
   if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0' || vis[i][j]==1)return;
   vis[i][j]=1;
   count(grid,vis,i+1,j);
   count(grid,vis,i-1,j);
   count(grid,vis,i,j+1);
   count(grid,vis,i,j-1);
   return;

}
    int numIslands(vector<vector<char>>& grid) {
        int total=0;
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         vis[i][j]=0;
        //     }
        // }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    total++;
                    count(grid,vis,i,j);
                    
                }
                else{
                    vis[i][j]=1;
                }
            }
        }
        return total;
    }
};