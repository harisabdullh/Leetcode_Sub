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
void push(TreeNode*root,priority_queue<int,vector<int>,greater<int>>&pq){
    if(root==NULL)return;
    pq.push(root->val);
    push(root->left,pq);
    push(root->right,pq);
}
void smallest(TreeNode*root,int &op,int k,vector<int>&ans){
    if(root==NULL)return ;
    smallest(root->left,op,k,ans);
    op++;
    if(op==k)
    ans.push_back(root->val);
  
    // smallest(root->left,op,k);
    
    smallest(root->right,op,k,ans);
    

}
    int kthSmallest(TreeNode* root, int k) {
        // priority_queue<int,vector<int>,greater<int>>pq;
        // //push all elements in pq;
        // push(root,pq);
        // for(int i=1;i<k;i++){
        //     pq.pop();
        // }
        // return pq.top();
        //i observed something like inorder

        
        //approach 2
        int op=0;
        vector<int>ans;
        
        smallest(root,op,k,ans);
        return ans[0];


    }
};