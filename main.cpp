#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <limits>
#include <IObject.h>
#include <DoubleObject.h>
#include <StringObject.h>
#include <Set.h>

using namespace std;

double DoubleRand(double _max, double _min)
{
    return _min + double(rand()) / RAND_MAX * (_max - _min);
}

int main()
{
    int n1, n2;
    for(;;)
    {
        cout << "Insert the number of the first double set:\n";
        cin >> n1;

        if(cin.fail() || n1 <= 0) // if( !(std::cin >> n) )
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else break;
    }


    Set DoubSet1 = Set(n1);

    cout << "Insert "<< n1 <<" elements of first double set:\n";
    for(int i = 0; i < n1; i++)
    {
        double buf;
        for(;;)
        {
            cout << "Insert the "<< i+1 << " double number:\n";
            cin >> buf;

            if(cin.fail()) // if( !(std::cin >> n) )
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else break;
        }
        DoubleObject DOb = DoubleObject(buf);
        IObject *PDOb = &DOb;
        DoubSet1.Add(PDOb);
    }
    cout.precision(12);
    cout << "Set1: " << DoubSet1;

    for(;;)
    {
        cout << "Insert the number of the second double set:\n";
        cin >> n2;

        if(cin.fail() || n2 <= 0) // if( !(std::cin >> n) )
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else break;
    }

    Set DoubSet2 = Set(n2);
    cout << "Insert "<< n2 <<" elements of second double set:\n";
    for(int i = 0; i < n2; i++)
    {
        double buf;
        for(;;)
        {
            cout << "Insert the "<< i+1 << " double number:\n";
            cin >> buf;

            if(cin.fail()) // if( !(std::cin >> n) )
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else break;
        }
        DoubleObject DOb = DoubleObject(buf);
        IObject *PDOb = &DOb;
        DoubSet2.Add(PDOb);
    }
    cout << "Set2: " << DoubSet2;

    Set DoubSet3 = DoubSet1 + DoubSet2;
    cout << "\n";
    cout << "Sum of Set1 and Set2:\n Set3 = " << DoubSet3;

    Set DoubSet4 = DoubSet1 - DoubSet2;
    cout << "\n";
    cout << "Difference of Set1 and Set2:\n Set4 = " << DoubSet4;

    Set DoubSet5 = DoubSet1 * DoubSet2;
    cout << "\n";
    cout << "Product of Set1 and Set2:\n Set5 = " << DoubSet5;

    cout << "\n";
    cout << "\n";

    for(;;)
    {
        cout << "Insert the number of the first string set:\n";
        cin >> n1;

        if(cin.fail() || n1 <= 0) // if( !(std::cin >> n) )
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else break;
    }


    Set StringSet1 = Set(n1);

    srand(time(NULL));
    cout << "Insert "<< n1 <<" elements of first string set:\n";
    for(int i = 0; i < n1; i++)
    {
        string buf;
        for(;;)
        {
            cout << "Insert the "<< i+1 << " string number:\n";
            cin >> buf;

            if(cin.fail()) // if( !(std::cin >> n) )
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else break;
        }
        StringObject SOb = StringObject(buf);
        IObject *PSOb = &SOb;
        StringSet1.Add(PSOb);
    }

    cout << "Set1: " << StringSet1;

    for(;;)
    {
        cout << "Insert the number of the second string set:\n";
        cin >> n2;

        if(cin.fail() || n2 <= 0) // if( !(std::cin >> n) )
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else break;
    }
    Set StringSet2 = Set(n2);
    cout << "Insert "<< n2 <<" elements of second string set:\n";
    for(int i = 0; i < n2; i++)
    {
        string buf;
        cin >> buf;
        StringObject SOb = StringObject(buf);
        IObject *PSOb = &SOb;
        StringSet2.Add(PSOb);
    }
    cout << "Set2: " << StringSet2;

    Set StringSet3 = StringSet1 + StringSet2;
    cout << "\n";
    cout << "Sum of Set1 and Set2:\n Set3 = " << StringSet3;

    Set StringSet4 = StringSet1 - StringSet2;
    cout << "\n";
    cout << "Difference of Set1 and Set2:\n Set4 = " << StringSet4;

    Set StringSet5 = StringSet1 * StringSet2;
    cout << "\n";
    cout << "Product of Set1 and Set2:\n Set5 = " << StringSet5;


    cin.get();

    return 0;
}
