#include <iostream>
#include <vector>

std::vector<int> getLongestSubseq(const std::vector<int> &seq) {
  std::vector<int> list(seq.size(), 1);
  std::vector<int> prev(seq.size(), -1);
  for (size_t i = 1; i < seq.size(); ++i) {
    for (size_t j = 0; j < i; ++j) {
      if (list[i] < list[j] + 1 && seq[i] > seq[j]) {
        list[i] = list[j] + 1;
        prev[i] = j;
      }
    }
  }

  int maxLen = 0;
  int maxLenEnd = 0;
  
  for (size_t i = 0; i < seq.size(); ++i) {
    if (list[i] > maxLen) {
      maxLen = list[i];
      maxLenEnd = i;
    }
  }
  std::vector<int> result;
  int currentIndex = maxLenEnd;
  while (currentIndex != -1) {
    result.insert(result.begin(), seq[currentIndex]);
    currentIndex = prev[currentIndex];
  }

  return result;
}

void print(const std::vector<int> &vector) {
  std::cout << vector.size() << "\n";
  for (auto el : vector) { 
    std::cout << el << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector<int> seq = {7, 1, 4, 3, 3, 5, 4, 8, 6, 9};
  auto longest_seq = getLongestSubseq(seq);
  print(longest_seq);


  return 0;
}
