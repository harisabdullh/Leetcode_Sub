class Solution {
public:
void dfs(int node,int arr[],vector<vector<int>> adj){
    arr[node]=1;
    for(auto it: adj[node]){
        if(!arr[it]){
            dfs(it,arr,adj);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        int vis[n];
        for(int i=0;i<n;i++){
            vis[i]=0;
        }
        int pro=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                pro++;
            }
        }
        return pro;
    }
};