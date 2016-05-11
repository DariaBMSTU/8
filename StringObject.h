#ifndef STRINGOBJECT_H
#define STRINGOBJECT_H

#include "IObject.h"
#include <string>

using namespace std;


class StringObject: public IObject
{
    public:
        StringObject(string v = ""):Val(v){};
        bool Less(IObject* Ob);
        IObject* Clone();
        string GetVal();
//        ~StringObject() {};
    protected:
    private:
    string Val;
};

#endif // STRINGOBJECT_H
