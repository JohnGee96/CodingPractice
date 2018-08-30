// Problem in short: 
//      use C++ inheritance to implement a cache w/ linked list and map
// Link to the problem: 
// https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  // capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {    
    public:
    LRUCache(int capacity){ 
        cp = capacity; 
        tail = head = nullptr;
    };
    
    int get(int key);
    void set(int key, int value);
};

void LRUCache::set(int key, int value) {
    Node *node;
    if (mp.empty()) {
        node = new Node(key, value);
        head = tail = node;
        mp[key] = node;
        return;
    };
    // Cache is not empty
    auto it = mp.find(key);  // same as std::map<int,Node*>::iterator it 
    if (it != mp.end()) { // key found
        Node *curNode = it->second;
        curNode->value = value;
        if (curNode == head) // don't do anything if it's at the beginning
            return;
        
        curNode->prev->next = curNode->next; // stitch the prev node to the next node
        if (tail == curNode) // reset tail if curNode is tail
            tail = tail->prev;
        else
            curNode->next->prev = curNode->prev; // stitch the next node back to the prev node
        // reset the node to the beginning
        curNode->prev = nullptr;
        curNode->next = head;
        head->prev = curNode;
        head = curNode;
    } else { // key not found
        // push a new node to the beginning
        node = new Node(head->prev, head, key, value);
        head->prev = node;
        head = node;
        mp[key] = node;
        // remove the tail if over capacity;
        if (mp.size() > cp) { 
            mp.erase(tail->key);
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }   
    }
    return;
}

int LRUCache::get(int key) {
    auto it = mp.find(key);
    if (it == mp.end()) {
        return -1;
    }
    return it->second->value;
}

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
