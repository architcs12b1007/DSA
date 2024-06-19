#include <iostream>
#include <vector>
using namespace std;

// Need to return longest common prefix among all these strings. If there is no coomon prefix, we have to return an empty string

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal; // need to avoid anamoly while searching a word: eg: Time, Timer
    int childCount;

    TrieNode(char c)
    {
        data = c;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
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
        int index = word[0] - 'a';

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
            root->childCount++;
        }

        insertUtil(child, word.substr(1));
    }

    // Time Complexity: O(N) N: length of word
    void insert(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (root->childCount == 1)
            {
                ans += str[i];
                int index = str[i] - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }

            if (root->isTerminal)
                break;
        }
    }
};

// Approach 1: Insert all strings in the Trie and traverse the trie till child count of node is 1.

// Time Complexity:O(M*N) Space Complexity:O(M*N)
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    Trie t;

    for (int i = 0; i < arr.size(); i++)
    {
        t.insert(arr[i]);
    }
    t.lcp(arr[0], ans);

    return ans;
}

// Approach 2: Take first string and compare its character with every other string.If it exists in all string, add it to ans, othwerise return my ans.

// Time Complexity: O(N*M), where N is the number of strings in the array and M is the shortest length of the string present in the array.
//  Space Complexity: O(1)
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans;

    string s = arr[0];
    int j = 0;

    while (j < s.length())
    {
        for (int i = 1; i < arr.size(); i++)
        {
            if (j < arr[i].length() && s[j] == arr[i][j])
            {
                continue;
            }
            else
            {
                return ans;
            }
        }

        ans += s[j];
    }

    return ans;
}
int main()
{

    return 0;
}