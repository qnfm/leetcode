/*
#include <iterator>
#include <unordered_set>
#include <string>
using namespace std;
class RandomizedSet
{
public:
    RandomizedSet()
    {
        it = set.end();
    }

    bool insert(int val)
    {
        if (set.contains(val))
            return false;
        set.insert(val);
        return true;
    }

    bool remove(int val)
    {
        if (!set.contains(val))
            return false;
        auto pos = set.find(val);
        if (pos == it)
            it = set.erase(pos);
        else
            set.erase(pos);
        return true;
    }

    int getRandom()
    {
        int r;
        if (it == set.end())
        {
            it = set.begin();
        }
        r = *(it++);
        return r;
    }

private:
    unordered_set<int> set;
    unordered_set<int>::iterator it;
};
*/
#include <unordered_map>
#include <vector>
using namespace std;
class RandomizedSet
{
public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (map.contains(val))
            return false;
        set.push_back(val);
        map[val] = set.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (!map.contains(val))
            return false;
        int last = set.back(), pos = map[val];
        map[last] = pos;
        set[pos] = last;
        set.pop_back();
        map.erase(val);
        return true;
    }

    int getRandom()
    {
        return set[rand() % set.size()];
    }

private:
    unordered_map<int, int> map;
    vector<int> set;
};

#include <iostream>

int main()
{
    RandomizedSet rs;
    cout << (rs.insert(1) ? "true" : "false") << endl;
    cout << (rs.remove(2) ? "true" : "false") << endl;
    cout << (rs.insert(2) ? "true" : "false") << endl;
    cout << rs.getRandom() << endl;
    cout << (rs.remove(1) ? "true" : "false") << endl;
    cout << (rs.insert(2) ? "true" : "false") << endl;
    cout << rs.getRandom();
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */