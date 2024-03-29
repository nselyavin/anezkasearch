#ifndef ANEZKASEARCH_VOCABULARY_H
#define ANEZKASEARCH_VOCABULARY_H

#include <utils/Generator.h>
#include <array>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

namespace anezkasearch {
class Vocabulary {
 public:
  class TrieNode {
   public:
    std::unordered_map<int16_t, std::shared_ptr<TrieNode>> children;
    bool m_is_end{false};
    char letter{'\0'};
  };

  explicit Vocabulary() noexcept;

  ~Vocabulary() noexcept;

  void Insert(const std::string& key) noexcept;

  void SearchWords(const std::string& prefix,
                   std::vector<std::string>& words) noexcept;
  Generator<std::string> SearchWordsSeq(const std::string& prefix) noexcept;

  bool Contains(const std::string& key) noexcept;

 private:
  std::shared_ptr<TrieNode> m_root;
  size_t m_alph_size;

  void _SearchWords(std::shared_ptr<TrieNode> current, std::string word,
                    std::vector<std::string>& words) noexcept;

  Generator<std::string> _SearchWordsSeq(std::shared_ptr<TrieNode> current,
                                         std::string word) noexcept;
};

}  // namespace anezkasearch

#endif
