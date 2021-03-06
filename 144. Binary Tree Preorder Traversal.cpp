//Recursive:

void preorder(Node *root,vector<int> &ans){
    if(!root){
        return ;
    }
    ans.push_back(root->data);
    preorder(root->left,ans);
    preorder(root->right,ans);
    
}
//Function to return a list containing the preorder traversal of the tree.
vector <int> preorder(Node* root)
{
    vector<int>ans;
    preorder(root,ans);
    return ans;
}

//Iterative:

vector<int> preOrder(Node* root)
{
    stack<Node*>st;
    vector<int>ans;
    Node *t=root;
    if(root==NULL) return ans;
    
    while(!st.empty() or t){
        if(t!=NULL){
            ans.push_back(t->data);
            st.push(t);
            t=t->left;
        }
        else{
            t=st.top();
            st.pop();
            t=t->right;
        }
    }
    return ans;
    //code here
}
