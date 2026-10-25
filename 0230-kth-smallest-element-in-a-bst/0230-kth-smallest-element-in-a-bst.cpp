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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        //push all elements in pq;
        push(root,pq);
        for(int i=1;i<k;i++){
            pq.pop();
        }
        return pq.top();

    }
};