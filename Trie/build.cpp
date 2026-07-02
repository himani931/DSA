#include <iostream>
using namespace std;

class trieNode
{
public:
  char data;
  trieNode *children[26];
  bool isTerminal;

  trieNode(char ch)
  {
    data = ch;
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
  trieNode *root;

  Trie()
  {
    root = new trieNode('\0');
  }

  void insertUTil(trieNode *root, string word)
  {
    if (word.length() == 0)
    {
      root->isTerminal = true;
      return;
    }

    int idx = word[0] - 'A'; // word in caps

    trieNode *child;

    if (root->children[idx] != NULL)
    {
      // present
      child = root->children[idx];
    }
    else
    {
      // absent
      child = new trieNode(word[0]);
      root->children[idx] = child;
    }
    insertUTil(child, word.substr(1));
  }

  void insertWord(string word)
  {
    insertUTil(root, word);
  }

  bool searchUtil(trieNode *root, string word)
  {
    if (word.length() == 0)
    {
      return root->isTerminal;
    }

    int idx = word[0] - 'A';
    trieNode *child;

    if (root->children[idx] != NULL)
    {
      child = root->children[idx];
    }
    else
    {
      return false;
    }

    return searchUtil(child, word.substr(1));
  }

  bool searchWord(string word)
  {
    return searchUtil(root, word);
  }

  bool isEmpty(trieNode *root)
  {
    for (int i = 0; i < 26; i++)
    {
      if (root->children[i] != NULL)
        return false;
    }
    return true;
  }

  trieNode *removeUtil(trieNode *root, string word, bool isRoot = false)
  {
    if (root == NULL)
      return NULL;

    // Base Case
    if (word.length() == 0)
    {
      root->isTerminal = false;

      if (!isRoot && isEmpty(root))
      {
        delete root;
        return NULL;
      }

      return root;
    }

    int idx = word[0] - 'A';

    if (root->children[idx] != NULL)
    {
      root->children[idx] =
          removeUtil(root->children[idx], word.substr(1));

      if (!isRoot && isEmpty(root) && !root->isTerminal)
      {
        delete root;
        return NULL;
      }
    }

    return root;
  }

  void removeWord(string word)
  {
    root = removeUtil(root, word, true);
  }
};

int main()
{

  Trie *t = new Trie();
  t->insertWord("HIMANI");
  t->insertWord("BHATNAGAR");
  t->insertWord("CSE");
  t->insertWord("BTECH");
  t->insertWord("TIME");

  cout << "present or not : " << t->searchWord("BTECH") << endl;
  cout << "present or not : " << t->searchWord("Btech") << endl;
  cout << "present or not : " << t->searchWord("BTEC") << endl;

  t->removeWord("BTECH");

  cout << "present or not : " << t->searchWord("BTECH") << endl;

  return 0;
}