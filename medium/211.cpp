/*
@file: 211.cpp
@author: Perry Huang
@date: 3/4/2024

211. Design Add and Search words Data Structure
Design a data structure that supports adding new m_words and finding if a string matches any previously added string.

OPTIMIZE

*/

#include <iostream>
#include <string>
#include <unordered_set>

const std::string LETTERS = "abcdefghijklmnopqrstuvwxyz";

class WordDictionary {
 public:
  WordDictionary() {}

  void addWord(const std::string& word) {
    m_words.emplace(word);
  }

  bool search(std::string word) {
    if (m_words.find(word) != m_words.end()) return true;
    size_t dots[2] = {26, 26};
    size_t dotPos = 0;
    // find dots in search where no dots means nonexistent
    for (size_t i = 0; i < word.size(); ++i) {
      if (word[i] == '.') {
        dots[dotPos] = i;
        ++dotPos;
      }
    }
    switch(dotPos) {
      case 1: 
        for (size_t i = 0; i < 26; ++i) {
          word[dots[0]] = LETTERS[i];
          if (m_words.find(word) != m_words.end()) return true;
        }
        return false;
      case 2: 
        for (size_t i = 0; i < 26; ++i) {
          word[dots[0]] = LETTERS[i];
          for (size_t j = 0; j < 26; ++j) {
            word[dots[1]] = LETTERS[j];
            if (m_words.find(word) != m_words.end()) return true;
          }
        }
        return false;
      default:
        return false;
    }
  }
 private:
  std::unordered_set<std::string> m_words;
};

int main() {}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */