#include <deque>
#include <unordered_map>
using namespace std;
class Node
{
public:
    int k;
    int val;
    Node *prev;
    Node *next;
    Node(int key, int value)
    {
        k = key;
        val = value;
        prev = next = nullptr;
    }
};
class LRUCache
{
public:
    LRUCache(int capacity)
    {
        cap = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }

    int get(int key)
    {
        if (!cache.contains(key))
            return -1;
        remove(cache[key]);
        insert(cache[key]);
        return cache[key]->val;
    }

    void put(int key, int value)
    {
        if (cache.contains(key))
        {
            remove(cache[key]);
            delete cache[key];
        }
        cache[key] = new Node(key, value);
        insert(cache[key]);
        if (cache.size() > cap)
        {
            auto lru = left->next;
            remove(lru);
            cache.erase(lru->k);
            delete lru;
        }
    }

private:
    unordered_map<int, Node *> cache;
    int cap;
    Node *left;
    Node *right;
    void remove(Node *node)
    {
        Node *prev = node->prev, *next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    // Insert to right
    void insert(Node *node)
    {
        Node *prev = right->prev, *next = right;
        prev->next = next->prev = node;
        node->prev = prev;
        node->next = next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */