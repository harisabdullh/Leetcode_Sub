class Solution {
public:
//approach 1 shall I first travel on boundaryies and marks all the ones and then simply just count inside 

void count(vector<vector<int>>&grid , vector<vector<int>>&vis, int i, int j){
    if(i<0 || i>=grid.size() || j>=grid[0].size() || j<0 || vis[i][j]==1 || grid[i][j]==0){
        return ;
    }
    vis[i][j]=1;
    count(grid,vis,i+1,j);
    count(grid,vis,i-1,j);
    count(grid,vis,i,j+1);
    count(grid,vis,i,j-1);

}
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int cnt=0;
        //boundary traversalsss
        for(int i=0;i<m;i++){
            if(i==0 || i==m-1 ){
                for(int j=0;j<n;j++){
                    count(grid,vis,i,j);
                }
            }
            else{
            count(grid,vis,i,0);
            count(grid,vis,i,n-1);
            }
        }
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;

    }
};