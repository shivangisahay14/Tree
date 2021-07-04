Recursion:

void InOrder(TreeNode *root,vector<int> &ans){
        if(!root){
        return ;
    }
        InOrder(root->left,ans);
        ans.push_back(root->val);
        InOrder(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int>ans;
        InOrder(root,ans);
        return ans;    
    }

**Iteration**:

vector<int> inOrder(Node* root)
    {
        
        stack<Node*>st;
        vector<int>ans;
        if(!root){
            return ans;
        }
        Node *t=root;
        while(!st.empty() or t!=NULL){
            if(t!=NULL){
                st.push(t);
                t=t->left;
            }
            else{
                t=st.top();
                st.pop();
                ans.push_back(t->data);
                t=t->right;
            }
        }
        return ans;
        
    }
