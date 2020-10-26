#ifndef ACTION_H_
#define ACTION_H_

#include <string>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Action {
    public:
        void setMessage(std::string msg);
        void setIntValue(int v);
        void setCharValue(char c);
        void addAction(Action * action);
        void freeAction();
    private:
        std::vector <Action *> actionVector;
        int actionCount = 0;
    
};

#endif