class Solution {
public:
   void width(TreeNode* root, int &minM, int &maxM, int v) {
        if (v < minM) minM = v;
        if (v > maxM) maxM = v;
        
        if (root->left != NULL) {
            width(root->left, minM, maxM, v - 1);
        }
        if (root->right != NULL) {
            width(root->right, minM, maxM, v + 1);
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int idx = 0;
        int w = 0;
        int minM = INT_MAX;
        int maxM = INT_MIN;
        width(root, minM, maxM, 0);
        w = abs(minM) + maxM;
        idx = w - abs(maxM);
                
        vector<vector<int>> v(w + 1);
        
        queue<pair<TreeNode*, int>> q;
        q.push(pair<TreeNode*, int>(root, idx));
        
        int sz = 0;
        pair<TreeNode*, int> n;
        
        while (!q.empty()) {
            sz = q.size();
            
            vector<vector<int>> vLevel(w + 1);
            for (int i = 0; i < sz; i++) {
                n = q.front();
                q.pop();
                                
                vector<int> temp = vLevel[n.second];
                temp.push_back((n.first)->val);
                vLevel[n.second] = temp;                                
                
                if ((n.first)->left != NULL) {
                    q.push(pair<TreeNode*, int>((n.first)->left, n.second - 1));
                } 
                if ((n.first)->right != NULL) {
                    q.push(pair<TreeNode*, int>((n.first)->right, n.second + 1));
                }
            }
            
            for (int i = 0; i < vLevel.size(); i++) {
                sort(vLevel[i].begin(), vLevel[i].end());               
                v[i].insert(v[i].end(), vLevel[i].begin(), vLevel[i].end());
            }
        }
        return v;
        
    }
};

vector<int> verticalOrder(Node *root)
    {
        vector<int>ans;
         // Base case
    if (!root)
        return ans;

    // Create a map and store vertical oder in
    // map using function getVerticalOrder()
    map<int, vector<int> > m;
    int hd = 0;

    // Create queue to do level order traversal.
    // Every item of queue contains node and
    // horizontal distance.
    queue<pair<Node*, int> > que;
    que.push(make_pair(root, hd));

    while (!que.empty()) {
        // pop from queue front
        pair<Node*, int> temp = que.front();
        que.pop();
        hd = temp.second;
        Node* node = temp.first;

        // insert this node's data in vector of hash
        m[hd].push_back(node->data);

        if (node->left != NULL)
            que.push(make_pair(node->left, hd - 1));
        if (node->right != NULL)
            que.push(make_pair(node->right, hd + 1));
    }

    // Traverse the map and print nodes at
    // every horigontal distance (hd)
    map<int, vector<int> >::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        for (int i = 0; i < it->second.size(); ++i)
            ans.push_back(it->second[i]);
        
    }
    return ans;
        
        
    }
