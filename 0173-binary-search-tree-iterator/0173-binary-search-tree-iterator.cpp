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
void pushallroots(TreeNode*root,stack<TreeNode*>&st){
    if(root==NULL)return;
    st.push(root);
    pushallroots(root->left,st);
    return;
}
stack<TreeNode*>st;

    BSTIterator(TreeNode* root) {
        pushallroots(root,st);
    }
    
    int next() {
        int x=st.top()->val;
        TreeNode*temp=st.top();
        st.pop();
        if(temp->right!=NULL){
            pushallroots(temp->right,st);
            
        }
        return x;

    }
    
    bool hasNext() {
        if(!st.empty())return true;
        else{
            return false;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */