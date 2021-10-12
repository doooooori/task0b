#include "word_counter.h"

int main(int argc, char* argv[]) {
    if (argc > 2) {
        word_counter wordStatistic;
        
        wordStatistic.opentxt(argv[1]);
        
        wordStatistic.createcsv(argv[2]);
    }
    else {
        std::cout << "Enter two arguments at least" << std::endl;
    }
}