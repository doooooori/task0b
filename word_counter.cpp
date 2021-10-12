#include "word_counter.h"
#include <string>
#include <fstream>
#include <algorithm>

word_counter::word_counter() {
    all = 0;
}

using namespace std;

string GetWord(istream& in) {
    char symbol;
    string ans = "";
    symbol = in.get();
    while (!isalpha(symbol) && !in.eof()) {
        symbol = in.get();
    }
    while (isalpha(symbol)) {
        ans.push_back(symbol);
        symbol = in.get();
    }
    return ans;
}


void word_counter::opentxt(const string& fileName) {
    ifstream input(fileName);
    if (!input) {
        cout << "Input file error";
    }
    string word;
    while (!(word = GetWord(input)).empty()) {
        ++wordMap[word];
        ++all;
    }
}


void word_counter::createcsv(const std::string& fileName) {
    multimap<int, string> sortedWordMap;
    for (auto word = wordMap.rbegin(); word != wordMap.rend(); ++word) {
        sortedWordMap.insert(pair<int, string>(word->second, word->first));
    }
    wordMap.clear();
    ofstream out(fileName);
    if (!out) {
        cout << "Output file error";
    }
    for (auto element = sortedWordMap.rbegin(); element != sortedWordMap.rend(); ++element) {
        out << element->second << ',' << element->first << ',' << element->first / (double)all * 100 << '%'
            << endl;
    }
}