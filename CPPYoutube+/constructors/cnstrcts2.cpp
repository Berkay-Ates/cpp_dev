#include <iostream>
#include <cstring>

using namespace std;

class StringBeko
{
private:
    char *m_Buffer;
    unsigned int m_size;

public:
    StringBeko(const char *string)
    {

        cout << "String Copied" << endl;

        m_size = strlen(string);
        m_Buffer = new char[m_size + 1];
        memcpy(m_Buffer, string, m_size);
        m_Buffer[m_size] = 0;
    }

    char &operator[](unsigned int index)
    {
        return m_Buffer[index];
    }

    ~StringBeko()
    {
        delete[] m_Buffer;
    }

    // StringBeko(const StringBeko &other) : m_Buffer(other.m_Buffer),
    //                                       m_size(other.m_size)
    // {
    //     // memcpy(this, &other, sizeof(StringBeko)); //* This is much more efficient and attractive
    // }

    StringBeko(const StringBeko &other) : m_size(other.m_size)
    {
        cout << "string copied" << endl;
        // memcpy(this, &other, sizeof(StringBeko)); //* This is much more efficient and attractive
        m_Buffer = new char[m_size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_size + 1);
    }

    friend ostream &operator<<(ostream &stream, const StringBeko &string);
};

ostream &operator<<(ostream &stream, const StringBeko &string)
{
    stream << string.m_Buffer;
    return stream;
}

void PrintString(const StringBeko &beko)
{
    // there must be a reference to avoid from copying objects
    cout << beko << endl;
}

int main(int argc, char const *argv[])
{

    // birinci string icerisindeki pointeri ikinci icerisine kopyalar.
    // Birinci string pointerini free yaptigi anda ikinci objenin pointeri de null olur!!
    StringBeko beko = "BerkayATES";
    StringBeko beko2 = beko;

    beko[2] = 'C';

    PrintString(beko);
    PrintString(beko2);
    return 0;
}