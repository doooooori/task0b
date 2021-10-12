#ifndef TASK0B_WORDCOUNTER_H
#define TASK0B_WORDCOUNTER_H

#include <string>
#include <map>
#include <iostream>
#include <vector>

using std::map;
using std::multimap;
using std::string;

class word_counter {
    map<string, int> wordMap;

    int all = 0;

public:
    word_counter();

    void opentxt(const std::string& fileName);

    void createcsv(const std::string& fileName);
};


#endif
