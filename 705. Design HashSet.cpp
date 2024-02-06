#include <bitset>
using namespace std;
class MyHashSet
{
public:
    MyHashSet()
    {
    }

    void add(int key)
    {
        r[key] = 1;
    }

    void remove(int key)
    {
        r[key] = 0;
    }

    bool contains(int key)
    {
       return r[key];
    }

private:
    static const size_t sz = 1e6 + 1;
    bitset<sz> r;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */