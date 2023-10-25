#include <iostream>

using namespace std;

template <typename T>
class Nodo
{
public:
    T val;
    Nodo<T> *succ;
};

template <typename T>
class Stack
{
private:
    Nodo<T> *top;

public:
    Stack() { top = nullptr; }
    ~Stack();

    template <typename U>
    friend ostream &operator<<(ostream &os, const Stack<U> &s);

    void Push(T);
    T Pop();
    void Peek();
};

template <typename T>
Stack<T>::~Stack()
{
    while (top != nullptr)
    {
        Nodo<T> *tmp = top;
        top = top->succ;
        delete tmp;
    }
}

template <typename U>
ostream &operator<<(ostream &os, const Stack<U> &s)
{
    Nodo<U> *iter = s.top;
    os << "TOP-->";

    while (iter != nullptr)
    {
        if (iter->succ == nullptr)
            os << "BOT-->";
        os << "\t[" << iter->val << "]" << endl;
        iter = iter->succ;
    }
    os << endl;
    return os;
}

template <typename T>
void Stack<T>::Push(T val)
{
    Nodo<T> *nuovo = new Nodo<T>;
    nuovo->val = val;
    nuovo->succ = top;
    top = nuovo;
}

template <typename T>
T Stack<T>::Pop()
{
    Nodo<T> *tmp = top;
    T val = top->val;
    top = top->succ;
    delete tmp;

    return val;
}

template <typename T>
void Stack<T>::Peek()
{
    cout << "Il nodo in cima alla pila e': " << top->val << endl;
}

class Punto2D
{
public:
    int x, y;

    friend ostream &operator<<(ostream &os, const Punto2D &p)
    {
        os << "(" << p.x << "," << p.y << ")";

        return os;
    }
};

int main()
{

    Stack<int> s;
    s.Push(9);
    s.Push(10);
    s.Push(14);
    s.Push(200);

    s.Pop();
    s.Pop();

    cout << s;

    Stack<Punto2D> points;

    points.Push({1, 1});
    points.Push({2, 2});
    points.Push({3, 3});

    points.Pop();

    points.Push({15, 15});

    cout << points;

    points.Peek();

    return 0;
}