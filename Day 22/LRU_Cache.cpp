/*
  Intuition
we need to keep track of most recently used and also a position after which new nodes have to be added
Therefore maintain two dummy notes head and tail, and add LRU just before and new nodes just after head

Approach
doubly linked list and map key with node address in a map to access it in O(1) time

Complexity
Time complexity:
get function: O(log n) //if node is not found else O(1)
put function: O(log n) //if node is not found else O(1)
Space complexity: O(n + n) //DLL and unordered_map
Code
*/
class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* left;
        Node* right;
        Node(){
            left = NULL; right = NULL;
            key = -1;
            val = -1;
        }
        Node(int _key, int _val){
            key = _key; val = _val;
            left = NULL; right = NULL;
        }
    };

    Node* head = new Node();
    Node* tail = new Node();
    unordered_map<int, Node*> mp;  
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->right = tail;
        tail->left = head;
    }
    
    int get(int key) {
        int ans;
        //directly get a value from the map, if it doesn't exist then return -1
        if(mp.find(key)==mp.end()) ans = -1;
        else{
            ans =mp[key]->val;
            Node* newCache = new Node(key, ans);
            Node* recent = mp[key];
            mp.erase(key);
            recent->right->left = recent->left;
            recent->left->right= recent->right;
            recent->left = NULL;
            recent->right= NULL;
            delete(recent);
            
            newCache->left =head;
            newCache->right = head->right;
            head->right = newCache;
            newCache->right->left = newCache;
            mp[key] = newCache;
        }
        return ans;

    }
    
    void put(int key, int value) {
        //whenever you are putting a new node put it near the head, 
        //thus LRU cache will be just before the tail

        if(mp.find(key)==mp.end()){
            Node* newCache = new Node(key, value);

            //if it doesen't exist check if size is full or not
            if(mp.size()==capacity){
                //remove the LRU cache: it will be presenet just before tail
                Node* recent = tail->left;
                recent->left->right = tail;
                tail->left = recent->left;
                recent->right = NULL;
                recent->left = NULL;
                mp.erase(recent->key);
                delete(recent);
            }
            //now add the new cache
            newCache->right = head->right;
            head->right->left = newCache;
            newCache->left = head;
            head->right = newCache;

            mp[key] = newCache;

        }        
        else{    //when node exists then remove it and add the new pair
            Node* newCache = new Node(key, value);
            Node* recent = mp[key];
            mp.erase(key);

            //now remove that node
            recent->left->right = recent->right;
            recent->right->left = recent->left;
            recent->left = NULL;
            recent->right = NULL;
            mp.erase(key);
            delete(recent);

            //add the node to next of head
            newCache->right = head->right;
            head->right->left = newCache;
            newCache->left = head;
            head->right = newCache;

            mp[key] = newCache;
        }
    }
};
