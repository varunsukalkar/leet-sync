class LRUCache {
public:


class Node{
      public:
    int key ; 
    int val;
    Node * prev;
    Node * next;
    
    Node(int key , int val){
        this->key = key;
        this->val = val;
    }
};

Node * head = new Node(-1,-1);
Node * tail = new Node(-1,-1);
int cap ;
unordered_map<int,Node *> m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addnode(Node * newnode){
        Node * temp = head->next ; 
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(Node * delnode){
        Node * prev = delnode->prev;
        Node * next = delnode->next;
        prev->next = next;
        next->prev = prev;

    }
    int get(int key) {
        if(m.find(key)!=m.end()){
            Node * resnode = m[key];
            int ans  = resnode->val;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key]=head->next;
            return ans ;

        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node *  curr = m[key];
            m.erase(key);
            deletenode(curr);

        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);

        }
        addnode(new Node(key,value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */