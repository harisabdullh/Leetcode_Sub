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
void preorder (TreeNode*root,vector<TreeNode*>&arr){
    if(root==NULL)return;
    arr.push_back(root);
    preorder(root->left,arr);
    preorder(root->right,arr);
}
    void flatten(TreeNode* root) {
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL)return;
        vector<TreeNode*>left;
        vector<TreeNode*>right;
        preorder(root->left,left);
        preorder(root->right,right);
        root->left=NULL;
        root->right=NULL;
        TreeNode*temp=root;

        for(int i=0;i<left.size();i++){
            temp->right=left[i];
            left[i]->left=NULL;
            left[i]->right=NULL;
            temp=temp->right;
        }
        
        for(int i=0;i<right.size();i++){
            temp->right=right[i];
            right[i]->left=NULL;
            right[i]->right=NULL;
            temp=temp->right;
        }
        





    }
};