// Trie:(PREFIX TREE/ DIGITAL TREE)
// It is a multiway tree data structure used for storing strings over an alphabet.
// It is used to store a large amount of strings. (eg:Dictionary) -INSERT, SEARCH, DELETE

#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal; // need to avoid anamoly while searching a word: eg: Time, Timer

    TrieNode(char c)
    {
        data = c;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{

public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    // Insertion in Trie

    void insertUtil(TrieNode *root, string word)
    {

        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // assumption words will be in caps
        int index = word[0] - 'A';

        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    // Time Complexity: O(N) N: length of word
    void insert(string word)
    {
        insertUtil(root, word);
    }

    // Search in Trie

    bool searchUtil(TrieNode *root, string word)
    {

        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';

        if (root->children[index] != NULL)
        {
            return searchUtil(root->children[index], word.substr(1));
        }
        else
        {
            return false;
        }
    }

    // Time Complexity: O(N) N: length of word
    bool search(string word)
    {
        return searchUtil(root, word);
    }

    // Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise

    bool startsWithUtil(TrieNode *root, string prefix)
    {
        if (prefix.length() == 0)
        {
            return true;
        }

        int index = prefix[0] - 'A';

        if (root->children[index] != NULL)
        {
            return startsWithUtil(root->children[index], prefix.substr(1));
        }
        else
        {
            return false;
        }
    }

    // Time Complexity: O(N) N: length of prefix
    bool startsWith(string prefix)
    {
        return startsWithUtil(root, prefix);
    }

    // Delete in Trie

    // To find whether current word is prefix to another long word or not
    bool isEmpty(TrieNode *root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
                return false;
        }

        return true;
    }
    TrieNode *solve(TrieNode *root, string word)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (word.length() == 0)
        {
            if (root->isTerminal)
            {
                root->isTerminal = false;
            }
            return root;
        }
        int index = word[0] - 'a';
        root->children[index] = solve(root->children[index], word.substr(1));
        if (isEmpty(root) && root->isTerminal == false)
        {
            delete (root);
            root = NULL;
        }
        return root;
    }

    // Time Complexity: O(N) N: length of word
    TrieNode *deleteWord(TrieNode *root, string word)
    {
        // Write your code here

        root = solve(root, word);
        return root;
    }
};

// Delete in Trie
int main()
{

    Trie *t = new Trie();
    t->insert("ABCD");

    cout << t->search("ABCD") << endl;

    cout << t->search("ABCDEFG") << endl;

    cout << t->search("ABC") << endl;

    return 0;
}

// Note: We have not used hashmap for above operation bcoz (on average it takes O(1) time for all operations and O(N) for worst case) but space complexity is very huge as compare to trie. Also we need to process entir e hashmap to print all string starts with certain prefix.