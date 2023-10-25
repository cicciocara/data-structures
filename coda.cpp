#include <iostream>

using namespace std;

template <typename T>
class Nodo
{
public:
    T val;
    Nodo<T> *succ;

    Nodo() : succ(nullptr){};
};

template <typename T>
class Queue
{
private:
    Nodo<T> *fronte;
    Nodo<T> *fine;

public:
    Queue() { fronte = fine = nullptr; }
    ~Queue();

    bool IsEmpty() { return fronte = nullptr; }
    void Enqueue(T);
    T Dequeue();

    template <typename U>
    friend ostream &operator<<(ostream &os, const Queue<U> &q);
};

template <typename T>
Queue<T>::~Queue()
{
    if (fronte == nullptr)
        return;

    Nodo<T> *iter = new Nodo<T>;
    iter = fronte;

    while (fronte != nullptr)
    {
        Nodo<T> *tmp = fronte;
        fronte = fronte->succ;
        delete tmp;
    }
}

// aggiungiamo elemento in coda
template <typename T>
void Queue<T>::Enqueue(T val)
{
    Nodo<T> *nuovo = new Nodo<T>;
    nuovo->val = val;

    if (fine == nullptr)
        fronte = fine = nuovo;

    fine->succ = nuovo;
    fine = nuovo;
}

// rimuoviamo elemento dalla testa
template <typename T>
T Queue<T>::Dequeue()
{
    Nodo<T> *tmp = fronte;
    T deqVal = fronte->val;

    if (fronte == nullptr)
        cout << "Lista vuota!" << endl;

    fronte = fronte->succ;
    delete tmp;

    return deqVal;
}

template <typename U>
ostream &operator<<(ostream &os, const Queue<U> &q)
{
    os << "Visualizzazione Coda: " << endl;
    if (q.fronte == nullptr)
    {
        os << "Lista vuota" << endl;
        return os;
    }

    Nodo<U> *iter = q.fronte;

    while (iter != q.fine)
    {
        os << "<---[" << iter->val << "]";

        iter = iter->succ;
    }
    os << "<---[" << iter->val << "]<---" << endl;

    os << endl;
    return os;
}

int main()
{

    Queue<char> q;
    q.Enqueue('A');
    q.Enqueue('B');
    q.Enqueue('C');
    q.Enqueue('D');
    q.Enqueue('E');
    q.Enqueue('F');

    cout << q;

    q.Dequeue();
    q.Dequeue();
    q.Dequeue();

    cout << q;

    q.~Queue();

    return 0;
}