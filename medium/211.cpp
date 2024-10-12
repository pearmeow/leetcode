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
    words = new WordDictionary*[26];
    for (int i = 0; i < 26; ++i) {
      words[i] = nullptr;
    }
  }

  void end() { hasEnd = true; }

  void addWord(const std::string& word) {
    WordDictionary* curr = this;
    for (int i = 0; i < word.size(); ++i) {
      if (curr->words[word[i] - 'a'] == nullptr) {
        curr->words[word[i] - 'a'] = new WordDictionary();
      }
      curr = curr->words[word[i] - 'a'];
    }
    curr->end();
  }

  bool search(const std::string& word) {
    WordDictionary* curr = this;

  }

 private:
  bool hasEnd;
  WordDictionary** words;

};

int main() {}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
