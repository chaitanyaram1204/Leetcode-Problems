struct Trie{
    Trie* children[26];
    bool flag = false;
};
class Solution {
public:
    Trie* root;

    Solution()
    {
        root = new Trie();
    }

    void insert(string word)
    {
        Trie* node = root;
        for(int i = 0;i<word.size();i++)
        {
            if(!node->children[word[i]-'a'])
            {
                node->children[word[i]-'a']=new Trie();
            }
            node = node->children[word[i]-'a'];
        }
        node->flag = true;
    }

    string search(string word) {
        Trie* node = root;
        string result;
        for (char c : word) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                return word;
            }
            result += c;
            if (node->children[i]->flag) {
                return result;
            }
            node = node->children[i];
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        for (string word : dictionary) {
            insert(word);
        }

        stringstream ss(sentence);
        string word, result;
        while (ss >> word) {
            if (!result.empty()) {
                result += " ";
            }
            result += search(word);
        }
        return result;
    }
};