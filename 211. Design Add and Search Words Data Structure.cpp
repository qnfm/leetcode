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
class WordDictionary
{
public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode *node = root;
        for (const auto ch : word)
        {
            int idx = ch - 'a';
            if (!node->child[idx])
                node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isword = true;
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';
            if (word[i] == '.')
            {
                for (char c = 'a'; c <= 'z'; c++)
                {
                    string tmp(word);
                    tmp[i] = c;
                    if (search(tmp))
                        return true;
                }
                return false;
            }
            if (!node->child[idx])
                return false;
            node = node->child[idx];
        }
        return node->isword;
    }

private:
    TrieNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */