#include "DoubleObject.h"

double DoubleObject::GetVal()
{
    return Val;
}


bool DoubleObject::Less(IObject* Ob)
{
    DoubleObject *NOb = dynamic_cast<DoubleObject*> (Ob);
    if (NOb->GetVal() > Val)
        return true;
    else return false;
}

IObject* DoubleObject::Clone()
{
    DoubleObject *ptr = new DoubleObject;
    ptr->Val = Val;
    return ptr;
}


