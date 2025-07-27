/**
 * @file 211-search-words-data-structure.cpp
 * @author Perry Huang
 * @date 3/4/2024
 * 211. Design Add and Search words Data Structure
 * Design a data structure that supports adding new m_words and finding if a string matches any previously added
 * string.
 */

#include <string>

class Solution {
   public:
    class WordDictionary {
       public:
        WordDictionary() {}

        void end() {
            hasEnd = true;
        }

        void addWord(const std::string& word) {}

        bool search(const std::string& word) {}

       private:
        bool hasEnd;
        WordDictionary** words;
    };

    /**
     * Your WordDictionary object will be instantiated and called as such:
     * WordDictionary* obj = new WordDictionary();
     * obj->addWord(word);
     * bool param_2 = obj->search(word);
     */
};
