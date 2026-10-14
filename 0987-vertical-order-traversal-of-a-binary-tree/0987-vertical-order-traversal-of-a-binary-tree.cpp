/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void solve(TreeNode*root,int row,int col,vector<vector<pair<int,int>>> &ans,int mincolumn){
    if(root==NULL)return;
    // left root right
    solve(root->left,row+1,col-1,ans,mincolumn);
    
    ans[col-mincolumn].push_back({root->val,row});
    

    solve(root->right,row+1,col+1,ans,mincolumn);
}
void cols(TreeNode*root,int &mincol, int& maxcol,int lef,int righ){
    if(root==NULL)return ;
    mincol=min(lef,mincol);
    maxcol=max(righ,maxcol);
    cols(root->left,mincol,maxcol,lef-1,righ);
    cols(root->right,mincol,maxcol,lef,righ+1);
    
}

int width(TreeNode*root,queue<pair<TreeNode*,long long >>&q,int w){
    if(root==NULL)return 0;
    
    while(!q.empty()){
        int size=q.size();
        int min=q.front().second;
        int first,last;
        for(int i=0;i<size;i++){
            long long curid=q.front().second-min;
            TreeNode*temp=q.front().first;
            q.pop();
            if(i==0){
                first=curid;

            }
            if(i==size-1){
                last=curid;
            }
            if(temp->left!=NULL){
                q.push({temp->left,curid*2+1});
            }
            if(temp->right!=NULL){
                q.push({temp->right,curid*2+2});
            }

        }
        w=max(w,last-first+1);
    }
    return w;

}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        int x=0;
        int w=width(root,q,x);
       
        int mincolumn=0;
        int maxcolumn=0;
        cols(root,mincolumn,maxcolumn,0,0);
        vector<vector<pair<int,int>>>ans(maxcolumn-mincolumn+1);
        solve(root, 0, 0, ans, mincolumn);
        //now sort the vector according to the row if row same then value
        for (int i = 0; i < ans.size(); i++) {
         sort(ans[i].begin(), ans[i].end(),
         [](pair<int,int> a, pair<int,int> b) {
             if (a.second == b.second)
                 return a.first < b.first;

             return a.second < b.second;
         });
        }
         vector<vector<int>>fnf;
         for(int i=0;i<ans.size();i++){
            vector<int>temp;
            for(int j=0;j<ans[i].size();j++){
                temp.push_back(ans[i][j].first);
            }
            if(!temp.empty()){
            fnf.push_back(temp);
            }
         }
         return fnf;
  }
    
};
