

class Solution {
    public: 
        vector<vector<string> > findSequences(string beginWord, string endWord, vector<string>& wordList){
            unordered_set<string> st(wordList.begin(), wordList.end());
            queue<vector<string> > q;
            q.push({beginWord});
            vector<string> usedOnLevel;
            usedOnLevel.push_back(beginWord);
            int level = 0;
            vector<vector<string> > ans;
            while(!q.empty()) {
                vector<string> vec = q.front();
                q.pop();
                // erase all words that has been
                // used in the previous levels to transform
                if(vec.size() > level){
                    level++;
                    for(auto it: usedOnLevel){
                        st.erase(it);
                    }
                    usedOnLevel.clear();
                }
                string word = vec.back();
                // store the answer
                if(word == endWord){
                    // the first sequence where we reached end 
                    if(ans.size() == 0){
                        ans.push_back(vec);
                    }
                    else if(ans[0].size() == vec.size()){
                        ans.push_back(vec);
                    }
                }
                for(int i=0; i<word.size(); i++){
                    char original = word[i];
                    for(char c='a'; c<='z'; c++){
                        word[i] = c;
                        if(st.count(word) > 0){
                            vec.puah_back(vec);
                            q.push_back(vec);
                            // mark as visited on the level
                            usedOnLevel.push_back(word);
                            vec.pop_back();
                        }
                    }
                    word[i] = original;
                }
            }
            return ans;
        }
};


// Optimize approch 

// step1: count minimum steps and store in map with its level
// step 2: backtrack through all steps

// INTUTION: if wr backtrack there are only possible steps to explore therefore its take a less time 
// but if we go in the beginning then we explore all options that is not contribute in the final answer


class Solution {
    unordered_map<string, int> mpp;
    vector<vector<string> > ans;
    string b;

    private: 
        void dfs(string word, vector<string> &seq){
            if(word == b){
                reverse(seq.begin(), seq.end());
                ans.push_back(seq);
                reverse(seq.begin(), seq.end());
                return ;
            }   

            int steps = mpp[word];
            for(int i=0; i< sz; i++){
                char original = word[i];
                for(char c='a'; c<='z'; c++) {
                    word[i] = c;
                    if(mpp.find(word) != mpp.end() && mpp[word] + 1 == steps){
                        seq.push_back(word);
                        dfs(word, seq);
                        seq.pop_back();
                    }
                }
                word[i] = original;
            }
        }


    public: 
        vector<vector<string> > findSequences(string beginWord, string endWord, vector<string>& wordList){
            unordered_set<int> st(wordList.begin(), wordList.end());
            queue<string> q;
            b = beginWord;
            q.push({beginWord});
            mpp[beginWord] = 1;
            st.erase(beginWord);
            int sz = beginWord.size();
            while(!q.empty()){
                string word = q.front();
                int steps = mpp[word];
                q.pop();
                if(word == endWord) break;
                // T.C N X word.lenght X 26 X logN
                for(int i=0; i<sz; i++){
                    char original = word[i];
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        word[i] = ch;
                        // it exits in the set 
                        if(st.count(word)){
                            q.push({word});
                            st.erase(word);
                            mpp[word] = steps + 1;
                        }
                    }
                word[i] = original;
                }
            }

            if(mpp.find(endWord) != mpp.end()){
                vector<string> seq;
                seq.push_back(endWord);
                dfs(endWord,seq);
            }

          return ans;
        }
};