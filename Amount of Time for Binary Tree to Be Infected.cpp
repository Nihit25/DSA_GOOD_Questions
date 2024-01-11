// 2385. Amount of Time for Binary Tree to Be Infected 




unordered_map<int,vector<int>>graph;
     void constructGraph(TreeNode *root){
         if(root==NULL){
             return;
         }
         if(root->left){
             graph[root->val].push_back(root->left->val);
             graph[root->left->val].push_back(root->val);
         }
         if(root->right){
             graph[root->val].push_back(root->right->val);
             graph[root->right->val].push_back(root->val);
         }
         constructGraph(root->left);
         constructGraph(root->right);
     }
    int amountOfTime(TreeNode* root, int start) {
        int minutesPassed=-1;
        constructGraph(root);
        queue<int>q;
        q.push(start);
        // q.push(start);
        unordered_set<int>visited;
        while(!q.empty()){
            minutesPassed++;
            for(int level=q.size();level>0;level--){
                int currNode=q.front();
                q.pop();
                visited.insert(currNode);
                for(int adjacentNode:graph[currNode]){
                    if(!visited.count(adjacentNode)){
                        q.push(adjacentNode);
                    }
                }
            }
        }
        return minutesPassed;
    }
