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
TreeNode* makeBST(vector<int>&preorder,int & idx,int ub){
    if(idx==preorder.size() || preorder[idx]>ub)return NULL;
    TreeNode*root=new TreeNode(preorder[idx]);
    idx++;
    root->left=makeBST(preorder,idx,root->val);
    root->right=makeBST(preorder,idx,ub);
    return root;

}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ub=INT_MAX;
        int idx=0;
        
        return makeBST(preorder,idx,ub);
    }
};