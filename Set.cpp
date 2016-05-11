#include <cmath>
#include "Set.h"
#include <typeinfo>

using namespace std;


Set::Set(int n)
{
    st = new IObject* [n];
    Size = n;
    Num = 0;
}

Set::Set(const Set &Ob)
{
    Size = Ob.Size;
    Num = Ob.Num;
    st = new IObject* [Size];
    if(Num!=0)
    {
        for(int i = 0; i < Num; i++)
        {
            st[i] = Ob.st[i]->Clone();
        }
    }
}

/*Set::~Set()
{
    for(int i = 0; i < Num; i++)
        delete st[i];
    delete [] st;
}*/


void Set::Add(IObject *ptr)
{
    if(!(Find(ptr)))
    {
        if(Size < Num+1)
        {
            IObject ** stbuf = new IObject* [2 * Size];
            for(int i = 0; i < Size; i++)
            {
                stbuf[i] = st[i];
            }
        //    delete [] st;
            st = stbuf;
            Size *= 2;
        }

        st[Num] = ptr->Clone();
        int i = Num;
        Num++;
        bool label = false;
        while(!label)
        {
            if (i >= 1)
            {
                if(st[i]->Less(st[i-1]))
                {

                    IObject *buf = st[i];
                    st[i] = st[i-1];
                    st[i-1] = buf;
                    i--;
                }
                else label = true;
            }
            else label = true;
        }
    }
}

IObject **Set::Find(IObject *ptr) const
{
    if (DoubleObject *pd = dynamic_cast<DoubleObject*> (ptr))
    {
        if (Num == 0)
        {
            return NULL;
        }
        DoubleObject *pL = dynamic_cast<DoubleObject*> (st[0]);
        DoubleObject *pR = dynamic_cast<DoubleObject*> (st[Num-1]);
        int nL = 0;
        int nR = Num-1;
        if ((pL->GetVal() > pd->GetVal())  || (pR->GetVal() < pd->GetVal()))
        {
            return NULL;
        }
        while (nR - nL > 0)
        {
            int mid = nL + (int)((nR -nL) / 2);
            DoubleObject *pM = dynamic_cast<DoubleObject*> (st[mid]);
            if (pd->GetVal() <=  pM->GetVal())
            {
                nR = mid;
                pR = pM;
            }
            else
            {
                nL = mid + 1;
                pL = dynamic_cast<DoubleObject*> (st[nL]);
            }
        }

        if (fabs(pR->GetVal() - pd->GetVal()) < 1.e-14) {
            return (&st[nR]);
        }

        return NULL;
    }
    else
    {
        StringObject *ps = dynamic_cast<StringObject*> (ptr);
        if (Num == 0)
        {
            return NULL;
        }
        StringObject *pL = dynamic_cast<StringObject*> (st[0]);
        StringObject *pR = dynamic_cast<StringObject*> (st[Num-1]);
        int nL = 0;
        int nR = Num-1;
        if ((pL->GetVal() > ps->GetVal())  || (pR->GetVal() < ps->GetVal()))
        {
            return NULL;
        }
        while (nR - nL > 0)
        {
            int mid = nL + (int)((nR -nL) / 2);
            StringObject *pM = dynamic_cast<StringObject*> (st[mid]);
            if (ps->GetVal() <=  pM->GetVal())
            {
                nR = mid;
                pR = pM;
            }
            else
            {
                nL = mid + 1;
                pL = dynamic_cast<StringObject*> (st[nL]);
            }
        }

        if (pR->GetVal() == ps->GetVal()) {
            return (&st[nR]);
        }

        return NULL;
    }
}//IObject *Set::Find(IObject *ptr)

int Set::FindId(IObject *ptr) const
{
    if (DoubleObject *pd = dynamic_cast<DoubleObject*> (ptr))
    {
        if (Num == 0)
        {
            return -1;
        }
        DoubleObject *pL = dynamic_cast<DoubleObject*> (st[0]);
        DoubleObject *pR = dynamic_cast<DoubleObject*> (st[Num-1]);
        int nL = 0;
        int nR = Num-1;
        if ((pL->GetVal() > pd->GetVal())  || (pR->GetVal() < pd->GetVal()))
        {
            return -1;
        }
        while (nR - nL > 0)
        {
            int mid = nL + (int)((nR -nL) / 2);
            DoubleObject *pM = dynamic_cast<DoubleObject*> (st[mid]);
            if (pd->GetVal() <=  pM->GetVal())
            {
                nR = mid;
                pR = pM;
            }
            else
            {
                nL = mid + 1;
                pL = dynamic_cast<DoubleObject*> (st[nL]);
            }
        }

        if (pR->GetVal() == pd->GetVal()) {
            return nR;
        }
        return -1;

    }
    else
    {
        StringObject *ps = dynamic_cast<StringObject*> (ptr);
        if (Num == 0)
        {
            return 0;
        }
        StringObject *pL = dynamic_cast<StringObject*> (st[0]);
        StringObject *pR = dynamic_cast<StringObject*> (st[Num-1]);
        int nL = 0;
        int nR = Num-1;
        if ((pL->GetVal() > ps->GetVal())  || (pR->GetVal() < ps->GetVal()))
        {
            return 0;
        }
        while (nR - nL > 0)
        {
            int mid = nL + (int)((nR -nL) / 2);
            StringObject *pM = dynamic_cast<StringObject*> (st[mid]);
            if (ps->GetVal() <=  pM->GetVal())
            {
                nR = mid;
                pR = pM;
            }
            else
            {
                nL = mid + 1;
                pL = dynamic_cast<StringObject*> (st[nL]);
            }
        }

        if (pR->GetVal() == ps->GetVal()) {
            return nR;
        }

        return 0;
    }
}//IObject *Set::Find(IObject *ptr)

void Set::Del(IObject *ptr)
{
    int i = (FindId(ptr));
    if(i>=0)
    {
        while(i < Num - 1)
        {
            st[i] = st[i+1];
            i++;
        }
//        delete st[Num];
        Num--;
    }
}


ostream& operator<<(ostream& stt, const Set& outst)
{
     for(int i = 0 ; i < outst.Num; i++)
     {
        if (DoubleObject *pd = dynamic_cast<DoubleObject*> (outst.st[i]))
        {
            stt << pd->GetVal() << " ";
        }
        else if (StringObject *ps = dynamic_cast<StringObject*> (outst.st[i]))
            stt << ps->GetVal() << " ";
     }
     stt << "\n";
     return stt;
}


Set operator+(const Set& st1, const Set& st2)
{
    Set stSum = st1;
    for(int i = 0; i < st2.Num; i++)
        stSum.Add(st2.st[i]);
    return stSum;
}

Set operator-(const Set& st1, const Set& st2)
{
    Set stRazn = Set(max(st1.Num,st2.Num));
    for(int i = 0; i < st1.Num; i++)
    {
        if(!(st2.Find(st1.st[i])))
            stRazn.Add(st1.st[i]);
    }
    return stRazn;
}

Set operator*(const Set& st1, const Set& st2)
{
    Set stProd = Set(st1.Num + st2.Num);
    for(int i = 0; i < st1.Num; i++)
    {
        if(st2.Find(st1.st[i]))
            stProd.Add(st1.st[i]);
    }
    return stProd;
}





