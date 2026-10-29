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
class BSTIterator {
public:
 int idx=1;
        vector<int>arr;
int count(TreeNode*root){
    if(root==NULL)return 0;
    return 1+count(root->left)+count(root->right);
}
void fill(TreeNode*root,vector<int>&arr){
    if(root==NULL)return;
    fill(root->left,arr);
    arr.push_back(root->val);
    fill(root->right,arr);
}
       
    BSTIterator(TreeNode* root) {
        arr.push_back(-1);
        //count number of nodes in bst and make n+1 array
        int ct=count(root);
        fill(root,arr);


    }
    
    int next() {
        int x=arr[idx++];
        return x;
    }
    
    bool hasNext() {
        if(idx<arr.size())return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */