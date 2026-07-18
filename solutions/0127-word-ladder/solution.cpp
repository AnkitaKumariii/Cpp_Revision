class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        queue<pair<string, int>>q;
        q.push({beginWord, 1});
        unordered_set<string> ump(wordList.begin(), wordList.end());
        ump.erase(beginWord);
        while(!q.empty()) {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word == endWord) return step;
            for(int i = 0; i<word.size(); i++) {
                char old_word = word[i];
                for(int j = 'a'; j<= 'z'; j++) {
                    word[i] = j;
                    if(ump.find(word) != ump.end()) {
                        ump.erase(word);
                        q.push({word, step+1});
                    }
                }
                word[i] = old_word;
            }
        }
        return 0;
    }
};


