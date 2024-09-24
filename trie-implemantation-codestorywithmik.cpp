// Trie Implementation with codewithmik
struct trieNode {
  bool endOfWord;
  string word;
  trieNode* children[26];
};

trieNode* getNode() {
  trieNode* newNode = new trieNode();
  newNode->endOfWord = false;
  newNode->word = "";

  for(int i=0; i<26; i++) {
      newNode->children[i] = NULL;
  }
  return newNode;
}

void insert(trieNode* root, string& word) {
  trieNode* crawler = root;

  // check for each character of word
  for(int i=0; i<word.length(); i++) {
      char ch = word[i];  

      if(crawler->children[ch-'a'] == NULL) {
          crawler->children[ch-'a'] = getNode();
      }
      crawler = crawler->children[ch-'a'];
  }

  crawler->endOfWord = true;
  crawler->word = word;
}
  
