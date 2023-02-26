
//通信1305班共44名同学，每名同学都有姓名，学号和年龄等属性，
//C++中标准模板库（STL）实现对同学信息的遍历，要求按照学号从小到大和从大到小两种次序输出学生信息
#include <iostream> 
#include <string>
#include <sstream>
#include <vector> 
using namespace std;
 
/* object可以是任意类型的变量 */
typedef int object;
 
class Iterator
{
public:
    virtual object begin() = 0;
    virtual void   next() = 0;
    virtual object end() = 0;
    virtual object current() = 0;
    virtual bool   IsDone() = 0;
};
 
class Aggregate
{

public:
    virtual void AddObject(object obj) =0;
    virtual object& operator[](int index) =0;
    virtual int size() =0;
};

class ConcreteAggregate:public Aggregate
{
private:
    vector<object> _objects;
 
public:
    virtual void AddObject(object obj)
    {
        _objects.push_back(obj);
    }
 
    virtual object& operator[](int index)
    {
        return _objects[index];
    }
    virtual int size()
    {
        return _objects.size();
    }
};
 


class ConcreteIterator :public Iterator
{
public:
    ConcreteAggregate *agg;
    int _index;
public:
    ConcreteIterator(ConcreteAggregate *agg)
    {
        this->agg = agg;
        _index = 0;
    }
    virtual object begin()
    {
        return (*agg)[0];
    }
    virtual void next()
    {
        _index++;
    }
    virtual void preious()
    {
        _index--;
    }
 
    virtual object end()
    {
        _index = agg->size();
        return (*agg)[_index - 1];
    }
 
    virtual object current()
    {
        return (*agg)[_index];
    }
 
    virtual bool IsDone()
    {
        return (_index == agg->size());
    }
    virtual bool IsFirst()
    {
        return (_index == 0);
    }
};
 
int main()
{
    ConcreteAggregate *objects = new ConcreteAggregate();
    cout << "信1305班同学:" << endl;
    object a = 20130001;
    object b = 20130002;
    object c = 20130003;
    object d = 20130004;
    object e = 20130005;
    object f = 20130006;
    object g = 20130007;
 
    objects->AddObject(a);
    objects->AddObject(b);
    objects->AddObject(c);
    objects->AddObject(d);
    objects->AddObject(e);
    objects->AddObject(f);
    objects->AddObject(g);
 
 
    ConcreteIterator *iter = new ConcreteIterator(objects);
    ConcreteIterator *iter1 = new ConcreteIterator(objects);
 
    object tmp_begin = iter->begin();
    cout << "从小到大输出:" << endl;
    while (!iter->IsDone())
    {
        cout << iter->current() << endl;
        iter->next();
    }
    cout << endl;
 
    object tmp_begin1 = iter1->end();
    cout << "从大到小输出:" << endl;
    while (!iter1->IsFirst())
    {
        iter1->preious();
        cout << iter1->current() << endl;
    }
    cout << endl;
 
    delete objects;
    delete iter;
 
    return 0;
}
