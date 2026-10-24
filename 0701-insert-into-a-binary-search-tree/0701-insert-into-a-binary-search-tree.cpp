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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //okay so we can attach at the end always i guesss
        TreeNode*op=new TreeNode(val);
        if(root==NULL)return op;
        TreeNode*temp=root;
        TreeNode*prev=root;
        while(temp!=NULL){
            prev=temp;
            if(val>temp->val){
                temp=temp->right;
            }
            else{
                temp=temp->left;
            }
        }
        if(prev->val>val){
            prev->left=op;
        }
        else{
            prev->right=op;
        }
        return root;
    }
};