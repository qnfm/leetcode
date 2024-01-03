#include <string>
using namespace std;
class TrieNode
{
public:
    TrieNode *child[26];
    bool isword;
    TrieNode()
    {
        for (auto &ch : child)
            ch = nullptr;
        this->isword = false;
    }
};
class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (const auto c : word)
        {
            int idx = c - 'a';
            if (node->child[idx] == nullptr)
                node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isword = true;
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (const auto c : word)
        {
            int idx = c - 'a';
            if (!node->child[idx])
                return false;
            node = node->child[idx];
        }
        return node->isword;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (const auto c : prefix)
        {
            int idx = c - 'a';
            if (!node->child[idx])
                return false;
            node = node->child[idx];
        }
        return true;
    }

private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */