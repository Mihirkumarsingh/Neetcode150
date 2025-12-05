#include<iostream>
using namespace std;

struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v){
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

/*
Initialize LRU Cache with a given capacity.
Also initialize a dummy head and dummy tail.
*/
class LRUCache{
public:
    int capacity; // Maximum number of items allowed in cache
    unordered_map<int, Node*> mp; // Maps key → Node* (gives O(1) lookup)
    Node* head;   // Dummy head (Most recently used side)
    Node* tail;   // Dummy tail (Least recently used side)

    LRUCache(int capacity){
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void removeNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        //unlink node
        prevNode->next = nextNode;
        nextNode->prev = prevNode;

    }

    /*
    * Helper function to insert a node right after head.
    * This marks the node as MOST RECENTLY USED.
    */
    void addToFront(Node* node){
        Node* first = head->next;

        node->next = first;
        node->prev = head;

        head->next = node;
        first->prev = node;
    }

    /*
    * get(key):
    * - If key not found → return -1
    * - If found:
    *      - Move it to the front (mark as most recently used)
    *      - Return its value
    */
    int get(int key){
        if(mp.find(key) == mp.end()){
            return -1;
        }
        Node* node = mp[key];

        // Move the accessed node to front(MRU)
        removeNode(node);
        addToFront(node);

        return node->value;
    }

    /*
    * put(key, value):
    * Cases:
    * 1. Key already exists → update value + move to front
    * 2. Key does not exist:
    *      - If capacity full → remove LRU (node before tail)
    *      - Insert new node at front (MRU)
    */

   void put(int key, int value){
        // Case 1: Key exists → update + move to front
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->value = value;

            // Move it to MRU
            removeNode(node);
            addToFront(node);
            return;
        }

        // case 2: Key does not exist -> check capacity
        if(mp.size() == capacity){
            // Remove LRU node = node just before tail
            Node* lru = tail->prev;
            mp.erase(lru->key);
            removeNode(lru);
            delete lru; // free memory
        }

        // Add new node to front
        Node* newNode = new Node(key, value);
        addToFront(newNode);
        mp[key] = newNode;
   }

};

int main(){
    LRUCache cache(2); // capacity = 2

    cache.put(1, 1); // Cache = {1=1}
    cache.put(2, 2); // Cache = {2=2, 1=1}

    cout << cache.get(1) << endl; // Output: 1 → makes 1 most recently used

    cache.put(3, 3); // Removes key 2 (LRU)
    
    cout << cache.get(2) << endl; // Output: -1 (2 was evicted)

    cache.put(4, 4); // Removes key 1 (LRU)

    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 3
    cout << cache.get(4) << endl; // 4

    return 0;

}