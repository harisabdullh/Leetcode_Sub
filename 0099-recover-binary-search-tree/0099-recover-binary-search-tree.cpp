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
void solve(TreeNode*ptr,TreeNode*&pre,TreeNode*&last,int &ct,TreeNode*&f,TreeNode*&m){
    if(ptr==NULL)return;
    solve(ptr->left,pre,last,ct,f,m);
    if(pre!= NULL && pre->val>ptr->val){
        if(ct==0){
        f=pre;
        m=ptr;
        ct=1;
        }
        else{
            last=ptr;
        }
    }
    
    pre=ptr;

    solve(ptr->right,pre,last,ct,f,m);
}
    void recoverTree(TreeNode* root) {
        TreeNode*pre=NULL;
        TreeNode*f=NULL;
        TreeNode*m=NULL;
        TreeNode*ptr=root;
        TreeNode*last=NULL;
        int ct=0;
        solve(ptr,pre,last,ct,f,m);
        // cout<<f->val<<endl;
        // cout<<m->val<<endl;
        // cout<<last->val<<endl;
        if(last==NULL){
            swap(f->val,m->val);
        }
        else{
            swap(f->val,last->val);
        }
    }
};