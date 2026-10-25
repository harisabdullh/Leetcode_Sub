/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
TreeNode* lca(TreeNode*root,TreeNode*p,TreeNode*q){
    if(root->val<=p->val && root->val>=q->val || root->val>=p->val && root->val<=q->val)return root;
    if(root->val >p->val && root->val>q->val){
        //dono left wale subtree me hai
        return lca(root->left,p,q);
    }
    else if(root->val<p->val && root->val<q->val){
        //dono right wale subtree me hai
        return lca(root->right,p,q);
    }
    return NULL;
}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //agr alag alag side hain
        return lca(root,p,q);
        //agr ye nhi to matlab ye dono ek hi subtree me hai , lets find out

    }
};