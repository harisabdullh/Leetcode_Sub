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
TreeNode* create(vector<int>&preorder,vector<int>&inorder,int prest,int preend,
int inst,int inend,map<int,int>&mpp){

if(prest>preend|| inst>inend)return NULL;
TreeNode*root= new TreeNode(preorder[prest]);

    int idx=mpp[preorder[prest]];
    int numleft=idx-inst;
    int numright=inorder.size()-1-idx;
    root->left=create(preorder,inorder,prest+1,prest+numleft,inst,idx-1,mpp);
    root->right=create(preorder,inorder,prest+numleft+1,preend,idx+1,inend,mpp);
    return root;

}

    


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mpp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mpp[inorder[i]]=i;
        }
        TreeNode*root=new TreeNode(preorder[0]);
        return create(preorder,inorder,0,n-1,0,n-1,mpp);
    }
};