class trieNode {
    public:
    char data;
    trieNode * children[26];
    int childcnt;
    bool isTerminal;

    trieNode(char ch) {
        data = ch;
        for(int i = 0 ; i <  26 ; i++) {
            children[i]  = NULL;
        }
        childcnt = 0 ;
        isTerminal = false;
    }
};

class trie {
    public :
    trieNode *root;
    trie(char ch) {
        root = new trieNode(ch);
    }

     void insertUTil(trieNode *root, string word)
  {
    if (word.length() == 0)
    {
      root->isTerminal = true;
      return;
    }

    int idx = word[0] - 'a'; 

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
      root->childcnt++;
      root->children[idx] = child;
    }
    insertUTil(child, word.substr(1));
  }

  void insertWord(string word)
  {
    insertUTil(root, word);
  
  }

 void lcp(string str, string &ans)
{
    trieNode *temp = root;

    for(char ch : str)
    {
        // If a word ends here, stop.
        if(temp->isTerminal)
            break;

        if(temp->childcnt != 1)
            break;

        int idx = ch - 'a';

        temp = temp->children[idx];
        ans.push_back(ch);
    }
}
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // int n = strs.size();
        // string ans = "";
        // for(int i = 0 ; i< strs[0].length() ; i++) {
        //     char ch = strs[0][i];

        //     bool match = true;

        //     for(int j =  1 ; j <  n ; j++) {
        //         if(strs[j].size() < i ||  ch != strs[j][i]) {
        //             match = false;
        //             break;
        //         }
        //     }
        //     if(match ==  false) break;
        //     else {
        //         ans.push_back(ch);
        //     }
        // }
        // return ans;

        int n = strs.size();
        trie *t = new trie('\0') ;

        for(int i = 0 ; i < n ; i++) {
            t->insertWord(strs[i]);
        }

       string first = strs[0];
       string ans = "";

       t->lcp(first , ans);
       return ans;
    }
};