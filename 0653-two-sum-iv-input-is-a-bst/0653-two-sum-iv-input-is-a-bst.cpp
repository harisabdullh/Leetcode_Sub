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
bool check(TreeNode*ptr1,TreeNode*ptr2, int k){
    if(ptr1==NULL || ptr2==NULL)return false;
    // if(ptr1->val==ptr2->val)return false;
    int sum=ptr1->val+ptr2->val;
    if(sum==k && ptr1!=ptr2)return true; //this ptr1 != ptr2 was the ultimate goal
    if(sum>k){
        //mtlab ab sum reduce krna hai

        return check(ptr1->left,ptr2,k) || check(ptr1,ptr2->left,k);

    }
    else{
        return check(ptr1->right,ptr2,k)|| check(ptr1,ptr2->right,k);
    }
    return false;
}
    bool findTarget(TreeNode* root, int k) {
        if(root->right==NULL && root->left==NULL)return false;
        TreeNode*ptr1=root;
        TreeNode*ptr2=root;

        // if(root->left!=NULL)ptr2=root->left;
        // else{
        //     ptr2=root->right;
        // }
        // TreeNode*ptr3;
        // if(root->right!=NULL){
        //     ptr3=root->right;
        // }
        int sum=ptr1->val+ptr2->val;
        return check(ptr1,ptr2,k);
    }
};