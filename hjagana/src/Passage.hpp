#ifndef PASSAGE_H_
#define PASSAGE_H_

#include "Structure.hpp"
#include <string>
#include <vector>

class Passage: public Structure {
    public:
        Passage();
        void setName(std::string n);
        void setID(int room1, int room2);
        void addPassage(Passage *passage);
        void freePassage();
    private:
        int passageCount = 0;
        std::vector <Passage *> passageVector;
};

#endif