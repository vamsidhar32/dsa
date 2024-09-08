class Node{
public:
    Node* prev ;
    Node* next ;
    int key ;
    int value ;
    Node(int a , int b){
        key = a ;
        value = b ;
        prev = NULL ;
        next = NULL ;
    }
};

class LRUCache {
public:
    Node* head ;
    Node* tail ;
    int cap ;
    unordered_map<int,Node*> mpp;
    LRUCache(int capacity) {
        cap = capacity ;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail ;
        tail->prev = head ;
    }
    

    void deletenode(Node* node){
        Node* nex = node->next ;
        Node* pre = node->prev ;
        node->next = NULL;
        node->prev = NULL ;
        pre->next = nex ;
        nex->prev = pre ;
    }

    void insertathead(Node* node){
        Node* next = head->next ;
        head->next = node;
        node->prev = head ;
        next->prev = node ;
        node->next = next ;
    }
    int get(int key) {
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            deletenode(node);
            insertathead(node);
            return node->value;
        }
        else {
            return -1 ;
        }
    }
    
    void put(int key, int value) {
        
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->value = value ;
            deletenode(node);
            insertathead(node);
            return ;
        }
        if(mpp.size() >= cap){
            mpp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        Node* temp = new Node(key,value);
        insertathead(temp);
        mpp[key] = temp ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */