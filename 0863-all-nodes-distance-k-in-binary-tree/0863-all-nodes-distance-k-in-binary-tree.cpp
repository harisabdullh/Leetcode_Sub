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
void sat(TreeNode*prev,TreeNode*root,vector<int>&ans,int k,map<TreeNode*,TreeNode*>mpp){
    //no need of prev==root condition , becoz see below , if this condition holds , we 
    // are not even calling the function
    if( root==NULL){return;}
    if(k==0 && root!=NULL){ans.push_back(root->val);return;}
    if(root->left!=prev)
    sat(root,root->left,ans,k-1,mpp);

    if(root->right!=prev)
    sat(root,root->right,ans,k-1,mpp);

    TreeNode*parent=mpp[root];

    if(parent!=prev)
    sat(root,parent,ans,k-1,mpp);
    
    

}
void sbt(TreeNode*root,vector<int>& ans,int k){
    if(root==NULL)return ;
    if(k==0 && root!=NULL){ans.push_back(root->val);}
    sbt(root->left,ans,k-1);
    sbt(root->right,ans,k-1);
    return;
}

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>mpp;//child, parent
        queue<TreeNode*>q;
        q.push(root);
        mpp[root]=NULL;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
            TreeNode*temp=q.front();
                if(temp->left!=NULL){
                    q.push(temp->left);
                    mpp[temp->left]=temp;
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                    mpp[temp->right]=temp;
                }

            q.pop();
            }
      }
      //now we have parent pointers also , //and also given that all values are unique
    vector<int>ans;
    //also given the parent the target;
    sbt(target,ans,k);
    sat(target,mpp[target],ans,k-1,mpp);


        return ans;


    }
};