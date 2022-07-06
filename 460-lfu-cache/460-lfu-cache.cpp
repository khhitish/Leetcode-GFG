struct Node
{
    int key, val, cnt;
    Node *next, *prev;
    Node()
    {
        val=0;
        key=0;
        cnt=1;
        next=nullptr;
        prev=nullptr;
    }
    Node(int key, int val)
    {
        this->val=val;
        this->key=key;
        cnt=1;
        next=nullptr;
        prev=nullptr;
    }
};

struct LinkedList
{
    Node *head, *tail;
    int size;
    LinkedList()
    {
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    
    void deletenode(Node* currnode)
    {
        Node* nextnode=currnode->next;
        Node* prevnode = currnode->prev;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
        delete currnode;
        size--;
    }
    
    void insertfront(Node* newnode)
    {
        head->next->prev=newnode;
        newnode->next = head->next;
        head->next=newnode;
        newnode->prev=head;
        size++;
    }
};


class LFUCache {
private:
    unordered_map<int,LinkedList*> freqmap;
    unordered_map<int,Node*> addressmap;
    int minfreq;
    int cachesize;
    int cap;
    
    void updatefreqmap(Node* currnode)
    {
        int freq = currnode->cnt;
        int value = currnode->val;
        int key = currnode->key;
        
        // deleting
        freqmap[freq]->deletenode(currnode);
        if(freq==minfreq && freqmap[freq]->size==0)
        {
            minfreq++;
        }
        addressmap.erase(key);
        
        // adding to higher freq map
        freq++;
        if(freqmap[freq]==nullptr)
        {
            freqmap[freq]= new LinkedList();
        }
        Node* newnode =  new Node(key,value);
        newnode->cnt=freq;
        freqmap[freq]->insertfront(newnode);
        addressmap[key]=newnode;
    }
public:
    LFUCache(int capacity) {
        cap=capacity;
        cachesize=0;
        minfreq=0;
    }
    
    int get(int key) {
        if(addressmap.count(key)==0) return -1;
        Node* currnode = addressmap[key];
        int value = currnode->val;
        
        updatefreqmap(currnode);
        return value;
    }
    
    void put(int key, int value) {
        if(cap==0) return;
        if(addressmap.count(key)!=0)
        {
            // already exists just update value and freqmap
            Node* currnode = addressmap[key];
            currnode->val = value;
            updatefreqmap(currnode);
        }
        else
        {
            if(cachesize == cap)
            {
                Node* currnode = freqmap[minfreq]->tail->prev;
                int key = currnode->key;
                addressmap.erase(key);
                freqmap[minfreq]->deletenode(currnode);
                cachesize--;
            }
            Node* newnode = new Node(key,value);
            if(freqmap[1]==nullptr)
            {
                freqmap[1]=new LinkedList();
            }
            freqmap[1]->insertfront(newnode);
            addressmap[key]=newnode;
            cachesize++;
            minfreq=1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */