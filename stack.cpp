#include <iostream>
#include <stdlib.h>
using namespace std;
template <typename t>
struct tcontainer
{
    virtual void push(const t&) = 0;
    virtual void pop() = 0;
    virtual /*const*/ t& begin() = 0;
    virtual /*const*/ t& end() = 0;
    virtual size_t size() = 0;
};
template <typename t>
struct tvector:public tcontainer<t>
{
    static const size_t _step = 100;
    tvector()
    {
        _size = 0;
        _cap = _step;
        buf = 0;
        re_capacity(_cap);
    }
    ~tvector()
    {
        free(buf);
    }
    void re_capacity(size_t s)
    {
        if (!buf)
            buf = (t*)malloc(sizeof(t) * s);
        else
            buf = (t*)realloc(buf, sizeof(t) * s);
    }
    virtual void push(const t& v)
    {
        if (_size >= _cap)
            re_capacity(_cap += _step);
        buf[_size++] = v;
    }
    virtual void pop()
    {
        if (_size)
            _size--;
    }
    virtual /*const*/ t& begin()
    {
        return buf[0];
    }
    virtual /*const*/ t& end()
    {
        if(_size)
        {
            return buf[_size - 1];
        }
    }
    virtual size_t size()
    {
        return _size;
    }

    const t& operator[] (size_t i)
    {
        if (i >= 0 && i < _size)
            return buf[i];
    }

//private:
    size_t _size;
    size_t _cap;
    t *buf;

};
int main()
{
    tvector<int> v;
    for (int i = 0; i < 1000; ++i)
        v.push(i);
    for (int i = 0; i < 1000; ++i)
        cout <<v[i]<<endl;
    v.begin() = 1;
    cout << v.begin() << v.end()<<endl;
}
