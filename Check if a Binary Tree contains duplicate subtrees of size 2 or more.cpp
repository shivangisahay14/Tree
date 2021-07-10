unordered_map<string,int>m;
string solve(Node *root){
    if(!root) return "$";
    
    string s;
    //if leaf node
    if(!root->left && !root->right){
        s=s+to_string(root->data);
        return s;
    }
    
    s=s+to_string(root->data);
    s=s+solve(root->left);
    s=s+solve(root->right);
    
    m[s]++;
    return s;
}
/*This function returns true if the tree contains 
a duplicate subtree of size 2 or more else returns false*/
bool dupSub(Node *root)
{
    m.clear();
    solve(root);
    for(auto x:m){
        if(x.second>=2)
            return true;
    }
    return false;
}
