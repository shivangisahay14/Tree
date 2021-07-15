bool NodetoRootPath(Node *root,int node,vector<int>&v){
    
    if(!root) return false;
    v.push_back(root->data);
    
    if(root->data==node){
        
        return true;
    }
    
    if(NodetoRootPath(root->left,node,v) or NodetoRootPath(root->right,node,v)){
        return true;
    }

    v.pop_back();
    return false;
}

int kthAncestor(Node *root, int k, int node)
{
    if(!root) return 0;
    vector<int>v;
    
    if(NodetoRootPath(root,node,v) && k<v.size()){
        return v[v.size()-k-1];
    }
    return -1;
    
}
