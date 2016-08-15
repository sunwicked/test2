// Copyright: ThoughtSpot Inc 2016
// Author: Amit Arya (amit.arya@thoughtspot.com)
//
#include <iostream>
#include <vector>
#include <climits>
#include <cstdint>

using namespace std;

int cost(int length) {
  if (length <= 80) {
    return (80 - length)*(80-length);
  } else {
    return INT_MAX;
  }
}


int64_t MinComputeInternal(string text, int i, vector<int64_t>& mem) {
  if (i >= text.size()) {
    return 0;
  }
  if (mem[i] != -1) {
    return  mem[i];
  }
  mem[i] = INT_MAX;
  for (int j=i+1; j < i + 80; j++) {
    cout << i << " -- "  << j << endl;
    mem[i] = min(MinComputeInternal(text, j, mem) + cost(j - i), mem[i]);
  }
  return mem[i];
}

vector<string> StringFormatter(string text) {
  vector<int64_t> mem(text.size(), -1);
  MinComputeInternal(text, 0, mem);
  for (int index = 0; index < text.size(); index++) {
    cout << mem[index] << endl;
  }
  vector<string> formatted_text;
  int line_begin = 0;
  int64_t min_value = INT_MAX;
  while (line_begin < text.size()) {
    int line_end = line_begin;
    cout << "line_begin "  << line_begin << endl;
    for (int index = line_begin+1; index < line_begin + 80; index++) {
      if (mem[index] + cost(index - line_begin) < min_value) {
        min_value = mem[index] + cost(index - line_begin);
        line_end = index;
      }
    }
    formatted_text.push_back(text.substr(line_begin, line_end-line_begin+1));
    line_begin = line_end + 1;
  }
  return formatted_text;
}

int main() {
  string text = "You are given a search trie that represents an arbitrary block of text. In the trie, each node represents exactly one character. Implement a function that, given a word, returns whether or not the word exists in the trie. Your function must support a wildcard character, which represents any single character.";
  for (auto t : StringFormatter(text)) {
    cout << t << endl;
  }
}
