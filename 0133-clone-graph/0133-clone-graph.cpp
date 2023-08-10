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
    //WATCH AYUSHI - THIS IS DFS TC:- O(V+E) SC:-O(V)
    Node* dfs(Node* cur, unordered_map<Node*,Node*>&mp)//CUR IS ORIGINAL NODE
    {
        vector<Node*>cloneAdj;//CREATE ADJ LIST FOR CLONE GRAPH
        Node* clone=new Node(cur->val);
        mp[cur]=clone;//PUT THE ORIGINAL AND CLONE NODES AS KEY-VALUE PAIRS IN THE MAP
        for(auto it:cur->neighbors)//TRAVERSE THE ADJ LIST OF ORIGIANL GRAPH
        {
            if(mp.find(it)!=mp.end())//IF MAP ALREADY CONTAINS THE GIVEN NODE
                cloneAdj.push_back(mp[it]); //THEN USE THE EXISTING ONE
            else
                cloneAdj.push_back(dfs(it,mp));//IF IT DOESN'T CONTAIN THEN CALL DFS FOR THAT PARTICULAT NODE AND CREATE THAT NODE AND THAT KEY-VALUE PAIR
        }
        clone->neighbors=cloneAdj;//IN THE END JUST MAKE THE neighbours (which is the default adj list of our clone graph (done by constructor)) equal to the ADJ list CLONEADJ that we just now created
        return clone;
        
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>mp;
        if(node==NULL) return NULL;
        if(node->neighbors.size()==0)//if there is only one node that means there will be no neighbors that means adj list will be empty
        {
            Node* clone=new Node(node->val);
            return clone;
        }
        return dfs(node,mp);
    }
};