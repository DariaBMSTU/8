#ifndef DOUBLEOBJECT_H
#define DOUBLEOBJECT_H

#include "IObject.h"


class DoubleObject: public IObject
{
    public:
        DoubleObject(double v = 0):Val(v){};
        bool Less(IObject* Ob);
        IObject* Clone();
        double GetVal();
//        ~DoubleObject(){};
    protected:
    private:
    double Val;
};

#endif // DOUBLEOBJECT_H
