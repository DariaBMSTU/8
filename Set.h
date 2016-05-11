#ifndef SET_H
#define SET_H

#include "DoubleObject.h"
#include "StringObject.h"

#include <iostream>

using namespace std;


class Set
{
    public:
        Set(int n = 8);
        Set(const Set &Ob);
//        ~Set();
        void Show();
        IObject **Find(IObject *ptr) const;
        int FindId(IObject *ptr) const;
        void Add(IObject *ptr);
        void Del(IObject *ptr);
        friend Set operator+(const Set& st1, const Set& st2);
        friend Set operator-(const Set& st1, const Set& st2);
        friend Set operator*(const Set& st1, const Set& st2);
        friend ostream& operator<<(ostream& stt, const Set& outst);
        int Size;
        int Num;
    protected:
    private:
    IObject ** st;
};

#endif // SET_H
