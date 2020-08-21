
Problem Link - https://leetcode.com/problems/design-add-and-search-words-data-structure/


Solution-----



class WordDictionary {
public:
    /** Initialize your data structure here. */
    map<int,vector<string>>mp;
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int d=word.length();
        mp[d].push_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        
        int n=word.length();
        
        for(int i=0;i<mp[n].size();i++)
        {
            string str=mp[n][i];
            int cnt=0;
            for(int j=0;j<n;j++)
            if(str[j]==word[j] || word[j]=='.')
                cnt++;
            
            if(cnt==n)
                return true;
        }
        
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */