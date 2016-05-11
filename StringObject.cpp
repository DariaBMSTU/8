#include "StringObject.h"

string StringObject::GetVal()
{
    return Val;
}

bool StringObject::Less(IObject* Ob)
{
    StringObject *NOb = dynamic_cast<StringObject*> (Ob);
    if (NOb->GetVal() > Val)
        return true;
    else return false;
}

IObject* StringObject::Clone()
{
    StringObject *ptr = new StringObject;
    ptr->Val = Val;
    return ptr;
}
