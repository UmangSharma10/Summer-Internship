//cloning graph with deep copy
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* solve(Node* node, unordered_map<Node*, Node*> &mp){
        if(node == NULL){
            return node;
        }
        
        if(mp[node]){
            return mp[node];
        }
        
        Node* graph = new Node(node -> val);
            mp[node] = graph;
        
        for(auto x : node -> neighbors)
            graph -> neighbors.push_back(solve(x,mp));
            return graph;
        
    }
   
    Node* cloneGraph(Node* node) {
    if(node == NULL)
        return node;
    unordered_map<Node*,Node*> mp;
        return solve(node, mp);
        
    }
};
