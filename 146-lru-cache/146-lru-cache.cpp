struct Node{
    int key;
    int val;
    Node* next;
    Node* prev;
    Node()
    {
        val=0;
        key=0;
        prev=nullptr;
        next=nullptr;
    }
    Node(int key, int val)
    {
        this->val=val;
        this->key=key;
        prev=nullptr;
        next=nullptr;
    }
};

class LRUCache {
private:
    Node* head, *tail;
    int size;
    int cap;
    unordered_map<int,Node*> mpp;
    
    void deletenode(Node* currnode)
    {
        Node* prevnode = currnode->prev;
        Node* nextnode = currnode->next;
        prevnode->next=nextnode;
        nextnode->prev = prevnode;
        mpp.erase(currnode->key);
        delete currnode;
        size--;
    }
    
    void insertfront(Node* newnode)
    {
        newnode->next=head->next;
        head->next->prev=newnode;
        newnode->prev=head;
        head->next=newnode;
        mpp[newnode->key] = newnode;
        size++;
    }
public:
    LRUCache(int capacity) {
        head=new Node();
        tail = new Node();
        head->next=tail;
        tail->prev=head;
        size=0;
        cap=capacity;
    }
    
    int get(int key) {
        if(mpp.count(key)==0) return -1;
        Node* currnode = mpp[key];
        int val=currnode->val;
        
        // deleting from current position
        deletenode(currnode);
        
        // inserting at front
        Node* newnode = new Node(key,val);
        insertfront(newnode);
        
        return val;
    }
    
    void put(int key, int value) {
        if(mpp.count(key)!=0)
        {
            Node* currnode=mpp[key];
            deletenode(currnode);
        }
        Node* newnode = new Node(key,value);
        insertfront(newnode);
        if(size>cap)
        {
            Node* currnode=tail->prev;
            deletenode(currnode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */