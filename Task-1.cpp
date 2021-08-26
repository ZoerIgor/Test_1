#include <iostream>

using namespace std;

//#define SIZE 1024
#define SIZE 4

class SomeClass
{
    public:
        SomeClass()
        {
            x1 = new char[SIZE];
            x2 = new char[SIZE * SIZE];
        }
        ~SomeClass()
        {
            delete[] x1;
            delete[] x2;
        }
        SomeClass(const SomeClass &object)
        {
            // x1
            this->x1 = new char[SIZE];
            for (auto i = 0; i < SIZE; i++)
            {
                this->x1[i] = object.x1[i];
            }
            // x2
            auto size = SIZE * SIZE;
            this->x2 = new char[size];
            for (auto i = 0; i < size; i++)
            {
                this->x2[i] = object.x2[i];
            }
        }
        SomeClass& operator = (const SomeClass& object)
        {
            // x1
            if (this->x1 != nullptr)
            {
                delete[] this->x1;
            }
            this->x1 = new char[SIZE];
            for (auto i = 0; i < SIZE; i++)
            {
                this->x1[i] = object.x1[i];
            }
            // x2
            if (this->x2 != nullptr)
            {
                delete[] this->x2;
            }
            auto size = SIZE * SIZE;
            this->x2 = new char[size];
            for (auto i = 0; i < size; i++)
            {
                this->x2[i] = object.x2[i];
            }
            return *this;
        }
        void Fill(char value)
        {
            // x1
            for (auto i = 0; i < SIZE; i++)
            {
                x1[i] = value;
            }
            // x2
            auto size = SIZE * SIZE;
            for (auto i = 0; i < size; i++)
            {
                x2[i] = value;
            }
        }
        void Print()
        {
            cout << this << "\t" << endl;
            // x1
            for (auto i = 0; i < SIZE; i++)
            {
                cout << x1[i] << " ";
            }
            cout << endl;
            // x2
            auto size = SIZE * SIZE;
            for (auto i = 0; i < size; i++)
            {
                cout << x2[i] << " ";
            }
            cout << endl;
            cout << endl;
        }
    private:
        char *x1;
        char *x2;
};

int main()
{
    SomeClass sc;
    sc.Fill('A');
    sc.Print();

    SomeClass nSc(sc);
    nSc.Print();

    SomeClass newSc = nSc;
    newSc.Print();
    newSc.Fill('B');
    newSc.Print();
    
    sc = newSc;
    sc.Print();
}