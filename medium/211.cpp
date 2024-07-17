/**
 * @file: 211.cpp
 * @author: Perry Huang
 * @date: 3/4/2024
 * 211. Design Add and Search words Data Structure
 * Design a data structure that supports adding new m_words and finding if a string matches any previously added string.
 */

#include <iostream>
#include <string>

class WordDictionary {
 public:
  WordDictionary() {
    hasEnd = false;
    for (int i = 0; i < 26; ++i) {
      words[i] = nullptr;
    }
  }

  void addWord(const std::string& word) {
    
  }

  bool search(const std::string& word) {
    return true;
  }

 private:
  bool hasEnd;
  int depth;
  WordDictionary* words[26];

};

int main() {}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
