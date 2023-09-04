// T.C O(l) L=>lenth of word for insertion 
// T.C O(L) for Searching 
// T.C O(L) for deletion 

#include <iostream>
using namespace std;


class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }

            isTerminal = false;
        }
};

class Trie{
    public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        // base case 
        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        }

        // assumption , word will be in CAPS
        int index = word[0] - 'A';
        TrieNode* child = NULL;

        // present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion Call

        insertUtil(child, word.substr(1));
    }


    void insertWord(string word){
        insertUtil(root,word);
    }

    // --------------Search functionality_----------------
    bool searchUtil(TrieNode* root, string word){
        // base case 
        if(word.length() == 0 ){
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child = NULL;

        // present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else {
            // absent
            return false;
        }

        // Recursive call
       return searchUtil(child, word.substr(1));
    }

    bool search(string word){
        return searchUtil(root,word);
    }
};

int main(){
     
    Trie *t = new Trie();

    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");

    cout<<"Present or NOt "<< t->search("DO")<<endl;


return 0;
}