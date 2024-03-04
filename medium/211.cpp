/*
@file: 211.cpp
@author: Perry Huang
@date: 3/4/2024
*/

#include <iostream>
#include <string>
#include <vector>

class WordDictionary {
 public:
  WordDictionary() {}

  void addWord(std::string word) {
    m_words.push_back(word);
  }

  bool search(std::string word) {
    bool match = true;
    for (size_t i = 0; i < m_words.size(); ++i) {
      if (m_words[i].size() == word.size()) {
        match = true;
        for (size_t j = 0; j < word.size(); ++j) {
          if (m_words[i][j] != word[j] && word[j] != '.') {
            match = false;
            break;
          }
        }
        if (match) return true;
      }
    }
    return false;
  }
 private:
  std::vector<std::string> m_words;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */