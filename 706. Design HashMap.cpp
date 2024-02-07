#include <array>
#include <bitset>
#include <list>
using namespace std;
// plain solution Runtime 128ms Beats 39.32% of users with C++ Memory 316.18MB Beats 5.12% of users with C++
/*
class MyHashMap
{
public:
    MyHashMap()
    {
        map = vector<pair<int, int>>(sz, {-1, -1});
    }

    void put(int key, int value)
    {
        map[key] = {key, value};
    }

    int get(int key)
    {
        return map[key].second;
    }

    void remove(int key)
    {
        map[key] = {-1, -1};
    }

private:
    static const size_t sz = 1e6 + 1;
    vector<pair<int, int>> map;
};
*/

// list chain + bitset Runtime 90ms Beats 94.39% of users with C++ Memory 62.35MB Beats 62.19% of users with C++
class MyHashMap
{
public:
    MyHashMap()
    {
    }

    void put(int key, int value)
    {
        auto &list = map[key % sz];
        if (!set[key])
        {
            list.push_back({key, value});
            set.set(key);
            return;
        }
        auto it = find(key);
        (*it).second = value;
    }

    int get(int key)
    {
        if (!set[key])
            return -1;
        auto it = find(key);
        return (*it).second;
    }

    void remove(int key)
    {
        if (!set[key])
            return;
        set.reset(key);
        auto it = find(key);
        auto k = key % sz;
        map[k].erase(it);
    }

private:
    static const size_t sz = 1e3;
    array<list<pair<int, int>>, sz> map{};
    bitset<int(1e6) + 1> set;
    list<pair<int, int>>::iterator find(int key)
    {
        int k = key % sz;
        for (auto it = map[k].begin(); it != map[k].end(); it++)
        {
            if (it->first == key)
                return it;
        }
        return map[k].end();
    }
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */