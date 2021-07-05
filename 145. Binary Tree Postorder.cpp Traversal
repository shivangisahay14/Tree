Recursion:

void PostOrder(Node *root,vector<int> &ans){
        if(!root){
        return ;
    }
        PostOrder(root->left,ans);
        PostOrder(root->right,ans);
        ans.push_back(root->data);
    }
//Function to return a list containing the postorder traversal of the tree.
vector <int> postOrder(Node* root)
{
    vector<int>ans;
        PostOrder(root,ans);
        return ans;
}


Iterative:

vector<int> postorderTraversal(TreeNode* root) {
        
        stack<TreeNode*>st;
        vector<int>ans;
        TreeNode *t=root;
        TreeNode *prev=NULL;
        
        if(!root){
            return ans;
        }
        
        while(!st.empty() or t!=NULL){
            if(t!=NULL){
                st.push(t);
                t=t->left;
            }
            else{
                t=st.top();
                if(t->right==NULL or t->right==prev){
                    ans.push_back(t->val);
                    st.pop();
                    prev=t;
                    t=NULL;
                }    
                else{
                    t=t->right;
                }


            }
        }
        return ans;

    }
