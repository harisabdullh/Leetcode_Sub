class Solution {
public:
void fill(vector<vector<int>>&image, vector<vector<int>>&vis, int r, int j, int c,int i){
    if( r<0 || r>=image.size() || j<0 || j>=image[0].size() || image[r][j]!=i || vis[r][j]==1 ){
        return;
    }
    vis[r][j]=1;
    image[r][j]=c;
    fill(image,vis,r+1,j,c,i);
    fill(image,vis,r-1,j,c,i);
    fill(image,vis,r,j+1,c,i);
    fill(image,vis,r,j-1,c,i);
    return;
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int in=image[sr][sc];
        fill(image,vis,sr,sc,color,in);
        return image;
    }
};