class Solution {
public:
    void lb(Node *root,vector<int>&v){
        if(!root) return;
        
        if(root->left or root->right) v.push_back(root->data);
        if(root->left) lb(root->left,v);
        else if(root->right) lb(root->right,v);
    }
    void rb(Node *root,vector<int>&v){
        if(!root) return;
        
        if(root->right) rb(root->right,v);
        else if(root->left) rb(root->left,v);
        if(root->left or root->right) v.push_back(root->data);
        
    }
    void leafNodes(Node *root,vector<int>&v){
        if(!root) return;
        
        leafNodes(root->left,v);
        
        if(!root->left and !root->right){
            v.push_back(root->data);
        }
        
        leafNodes(root->right,v);
        
    }
    vector <int> printBoundary(Node *root)
    {
        vector<int>v;
        if(!root) return v;
        
        v.push_back(root->data);
        
        if(!root->left and !root->right){
            return v;
        }
        lb(root->left,v);
        leafNodes(root,v);
        rb(root->right,v);
        
        return v;
        
    }
};
