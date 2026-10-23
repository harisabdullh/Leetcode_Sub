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
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int>preorder;
        TreeNode*cur=root;
        int ct=0;
        while(cur!=NULL){
            
            if(cur->left!=NULL){
                preorder.push_back(cur->val);
                TreeNode*temp=cur->left;
                while(temp->right!=NULL && temp->right!=cur){
                    temp=temp->right;
                }
                if(temp->right==cur){
                    
                    temp->right=NULL;
                    cur=cur->right;
                    preorder.pop_back(); //mian line , kyuki agr ye nhi likhra to
                    //wapas jump krne oe dobara aajaraha tha wo inteer"
                    

                    continue;
                }
                temp->right=cur;
                cur=cur->left;
            

            }
            else {
                preorder.push_back(cur->val);
                cur=cur->right;
           
            }
        }
        return preorder;
    }
};