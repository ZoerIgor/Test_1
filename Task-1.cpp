#include <iostream>
#include <memory>
#include <exception>

#define SIZE 4

class SomeClass
{
    public:
        SomeClass(size_t size)
        {
            // Create x1
            try
            {
                sizeX1 = size;
                x1 = new char[sizeX1];
            }
            catch (const std::exception& ex)
            {
                sizeX1 = NULL;
                x1 = nullptr;
            }
            // Create x2
            try
            {
                sizeX2 = new size_t(size * size);
                x2 = new char[*sizeX2];
            }
            catch (const std::exception& ex)
            {
                if (sizeX2 != nullptr)
                {
                    delete sizeX2;
                    sizeX2 = nullptr;
                }
                x2 = nullptr;
            }
            // Create x3
            try
            {
                sizeX3 = std::make_unique<size_t>(size + size * size);
                x3 = new char[*sizeX3];
            }
            catch (const std::exception& ex)
            {
                sizeX3 = nullptr;
                x3 = nullptr;
            }
        }
        ~SomeClass()
        {
            delete[] x1;
            delete[] x2;
            delete[] x3;
            delete sizeX2;
        }
        SomeClass(const SomeClass &other)
        {
            // Copy x1
            if (other.sizeX1 != NULL)
            {
                sizeX1 = other.sizeX1;
                try
                {
                    x1 = new char[sizeX1];
                    memcpy(x1, other.x1, sizeX1);
                }
                catch (const std::exception& ex)
                {
                    sizeX1 = NULL;
                    x1 = nullptr;
                }
            }
            else
            {
                sizeX1 = NULL;
                x1 = nullptr;
            }
            // Copy x2
            if (other.sizeX2 != nullptr)
            {
                try
                {
                    sizeX2 = new size_t(*other.sizeX2);
                    x2 = new char[*sizeX2];
                    memcpy(x2, other.x2, *sizeX2);
                }
                catch (const std::exception& ex)
                {
                    if (sizeX2 != nullptr)
                    {
                        delete sizeX2;
                        sizeX2 = nullptr;
                    }
                    x2 = nullptr;
                }
            }
            else
            {
                sizeX2 = nullptr;
                x2 = nullptr;
            }
            size_t i2 = (sizeX2 == nullptr) ? 0 : *sizeX2;
            // Copy x3
            if (other.x3 != nullptr)
            {
                try
                {
                    sizeX3 = std::make_unique<size_t>(*other.sizeX3);
                    x3 = new char[*sizeX3];
                    memcpy(x3, other.x3, *sizeX3);
                }
                catch (const std::exception& ex)
                {
                    sizeX3 = nullptr;
                    x3 = nullptr;
                }
            }
            else
            {
                sizeX3 = nullptr;
                x3 = nullptr;
            }
            size_t i3 = (sizeX3 == nullptr) ? 0 : *sizeX3;
        }
        SomeClass& operator = (const SomeClass& other)
        {
            // Assign x1
            if (other.sizeX1 != NULL)
            {
                try
                {
                    if (x1 != nullptr)
                    {
                        delete[] x1;
                    }
                    sizeX1 = other.sizeX1;
                    x1 = new char[sizeX1];
                    memcpy(x1, other.x1, sizeX1);
                }
                catch (const std::exception& ex)
                {
                    sizeX1 = NULL;
                    x1 = nullptr;
                }
            }
            else
            {
                sizeX1 = NULL;
                x1 = nullptr;
            }
            // Assign x2
            if (other.sizeX2 != nullptr)
            {
                try
                {
                    if (x2 != nullptr)
                    {
                        delete[] x2;
                        delete sizeX2;
                    }
                    sizeX2 = new size_t(*other.sizeX2);
                    x2 = new char[*sizeX2];
                    memcpy(x2, other.x2, *sizeX2);
                }
                catch (const std::exception& ex)
                {
                    if (sizeX2 != nullptr)
                    {
                        delete sizeX2;
                        sizeX2 = nullptr;
                    }
                    x2 = nullptr;
                }
            }
            else
            {
                sizeX2 = nullptr;
                x2 = nullptr;
            }
            // Assign x3
            if (other.sizeX3 != nullptr)
            {
                try
                {
                    if (x3 != nullptr)
                    {
                        delete[] x3;
                    }
                    sizeX3 = std::make_unique<size_t>(*other.sizeX3);
                    x3 = new char[*sizeX3];
                    memcpy(x3, other.x3, *sizeX3);
                }
                catch (const std::exception& ex)
                {
                    sizeX3 = nullptr;
                    x3 = nullptr;
                }
            }
            else
            {
                sizeX3 = nullptr;
                x3 = nullptr;
            }
            return *this;
        }
        void Fill(char value)
        {
            // x1
            if (sizeX1 != NULL)
            {
                for (auto i = 0; i < sizeX1; i++)
                {
                    x1[i] = value;
                }
            }
            // x2
            if (sizeX2 != nullptr)
            {
                for (auto i = 0; i < *sizeX2; i++)
                {
                    x2[i] = value;
                }
            }
            // x3
            if (sizeX3 != nullptr)
            {
                for (auto i = 0; i < *sizeX3; i++)
                {
                    x3[i] = value;
                }
            }
        }
        void Print()
        {
            std::cout << this << std::endl;
            // x1
            if (sizeX1 != NULL)
            {
                for (auto i = 0; i < sizeX1; i++)
                {
                    std::cout << x1[i] << " ";
                }
                std::cout << std::endl;
            }
            // x2
            if (sizeX2 != nullptr)
            {
                for (auto i = 0; i < *sizeX2; i++)
                {
                    std::cout << x2[i] << " ";
                }
                std::cout << std::endl;
            }
            // x3
            if (sizeX3 != nullptr)
            {
                for (auto i = 0; i < *sizeX3; i++)
                {
                    std::cout << x3[i] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    private:
        char *x1, *x2, *x3;
        size_t sizeX1;
        size_t* sizeX2;
        std::unique_ptr<size_t> sizeX3;
};

int main()
{
    SomeClass sc(SIZE);
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