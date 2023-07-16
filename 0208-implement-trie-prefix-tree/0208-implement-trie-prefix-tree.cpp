struct Node{
    Node *links[26];
    bool flag=false;
    
    //check if key is there
    bool containKey(char ch)
    {
        if(links[ch-'a']!=NULL) return true;
        return false;
    }
    
    //create the reference node for any character
    void put(char ch, Node* node)
    {
        links[ch-'a']=node;
    }
    
    //Move to the reference node
    Node *get(char ch)
    {
        return links[ch-'a'];
    }
    
    //word has ended so set the flag as true
    void setEnd()
    {
        flag=true;
    }
    
    //get the value of flag
    bool isEnd()
    {
        return flag;
    }
    
};


class Trie {
public:
    Node* root;
    public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;  //start from root node
        for(int i=0;i<word.size();i++)
        {
            if(!node->containKey(word[i]))
                node->put(word[i],new Node());
            
                node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;  //start from root node
        for(int i=0;i<word.size();i++)
        {
            if(!node->containKey(word[i]))
                return false;
            node=node->get(word[i]);
        }
        if(node->isEnd()==true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* node=root; //start from root node
        
        for(int i=0;i<prefix.size();i++)
        {
            if(!node->containKey(prefix[i]))
                return false;
            node=node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */