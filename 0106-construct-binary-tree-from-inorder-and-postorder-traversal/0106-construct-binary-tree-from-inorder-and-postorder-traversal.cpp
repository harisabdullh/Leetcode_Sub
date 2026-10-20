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
TreeNode*create(vector<int>&inorder,vector<int>&postorder,int postst,int postend,int inst,int inend, map<int,int>&mpp){
    if(postst<postend || inst>inend)return NULL;
    TreeNode*root=new TreeNode(postorder[postst]);
    int idx=mpp[postorder[postst]];
    int numright=inend-idx;

    root->right=create(inorder,postorder,postst-1,postst-numright , idx+1,inend,mpp);
    root->left=create(inorder,postorder,postst-numright-1, postend , inst,idx-1,mpp);
    return root;

}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mpp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mpp[inorder[i]]=i;
        }
        return create(inorder,postorder,n-1,0,0,n-1,mpp);
    }
};