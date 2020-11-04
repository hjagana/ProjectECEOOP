#ifndef ACTION_H_
#define ACTION_H_

#include <string>
#include <vector>


class Action{
    private:

    public:
        Action();
        virtual void setMessage(std::string msg);
        virtual void setIntValue(int v);
        virtual void setCharValue(char c);
};

#endif /* ACTION_H_ */