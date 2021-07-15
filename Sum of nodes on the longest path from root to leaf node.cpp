void sumOfLongRootToLeafPath(Node* root, int sum,
                      int len, int& maxLen, int& maxSum)
{
    // if true, then we have traversed a
    // root to leaf path
    if (!root) {
        
        if (maxLen < len) {
            maxLen = len;
            maxSum = sum;
        } else if (maxLen == len && maxSum < sum)
            maxSum = sum;
        return;
    }
 
    // recur for left subtree
    sumOfLongRootToLeafPath(root->left, sum + root->data,
                            len + 1, maxLen, maxSum);
 
    // recur for right subtree
    sumOfLongRootToLeafPath(root->right, sum + root->data,
                            len + 1, maxLen, maxSum);
}
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        if (!root) return 0;
 
        int maxSum = INT_MIN, maxLen = 0;
        
        sumOfLongRootToLeafPath(root, 0, 0, maxLen, maxSum);
    
        return maxSum;
        
    }
