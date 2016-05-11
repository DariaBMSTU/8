#ifndef IOBJECT_H
#define IOBJECT_H


class IObject
{
    public:
        virtual bool Less(IObject*) = 0;
        virtual IObject* Clone() = 0;
 //       virtual ~IObject() {};
    protected:
    private:
};

#endif // IOBJECT_H
