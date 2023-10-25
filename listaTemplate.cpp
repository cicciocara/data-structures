#include <iostream>

using namespace std;

template <typename T>
class Nodo
{
public:
    T val;
    Nodo *succ;
};

template <typename T>
class Lista
{
private:
    Nodo<T> *testa;

public:
    Lista() { testa = nullptr; }
    ~Lista();

    Nodo<T> *Ricerca(T);
    void InserisciInTesta(T);
    void Inserisci(Nodo<T> *, T);
    void InserisciInCoda(T);
    void Rimuovi(T);

    template <typename U>
    friend ostream &operator<<(ostream &os, const Lista<U> &l);
};

template <typename T>
Lista<T>::~Lista()
{
    Nodo<T> *iter = this->testa;
    while (iter != nullptr)
    {
        Nodo<T> *tmp = this->testa;
        testa = testa->succ;
        delete tmp;

        iter = iter->succ;
    }
}

template <typename T>
Nodo<T> *Lista<T>::Ricerca(T val)
{
    Nodo<T> *iter = this->testa;

    while (iter != nullptr)
    {
        if (iter->val == val)
            return iter;

        iter = iter->succ;
    }

    return nullptr;
}

template <typename T>
void Lista<T>::InserisciInTesta(T val)
{
    Nodo<T> *nuovo = new Nodo<T>;
    nuovo->val = val;

    nuovo->succ = this->testa;
    this->testa = nuovo;
}

template <typename T>
void Lista<T>::Inserisci(Nodo<T> *pre, T val)
{
    Nodo<T> *nuovo = new Nodo<T>;
    nuovo->val = val;

    nuovo->succ = pre->succ;
    pre->succ = nuovo;
}

template <typename T>
void Lista<T>::InserisciInCoda(T val)
{
    Nodo<T> *nuovo = new Nodo<T>;
    Nodo<T> *iter = this->testa;
    nuovo->val = val;
    nuovo->succ = nullptr;

    if (this->testa == nullptr)
        this->testa = nuovo;

    while (iter->succ != nullptr)
    {
        iter = iter->succ;
    }

    iter->succ = nuovo;
}

template <typename T>
void Lista<T>::Rimuovi(T val)
{
    Nodo<T> *prec;
    Nodo<T> *curr;

    if (this->testa == nullptr)
        cout << "Lista vuota, nessun elemento da poter rimuovere" << endl;
    else if (this->testa->val == val)
    {
        prec = this->testa;
        this->testa = this->testa->succ;
        delete prec;
    }
    else
    {
        prec = this->testa;
        curr = this->testa->succ;

        while ((curr != nullptr) && (curr->val != val))
        {
            prec = prec->succ;
            curr = curr->succ;
        }

        if (curr != nullptr)
        {
            prec->succ = curr->succ;
            delete curr;
        }
    }
}

template <typename U>
ostream &operator<<(ostream &os, const Lista<U> &l)
{
    Nodo<U> *iter = l.testa;

    if (l.testa == nullptr)
        os << "nessun elemento stampabile, lista vuota" << endl;

    os << "HEAD-->";
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

int main()
{
    Lista<int> ls;
    ls.InserisciInTesta(10);
    ls.InserisciInTesta(20);
    ls.InserisciInTesta(30);
    ls.InserisciInCoda(100);
    ls.InserisciInCoda(200);

    int pre, in;
    Nodo<int> *p = nullptr;
    do
    {
        cout << "Scegli un elemento dalla lista: ";
        cin >> pre;
        p = ls.Ricerca(pre);
    } while (p == nullptr);

    cout << "Quale elemento vuoi inserire dopo " << pre << "? ";
    cin >> in;
    ls.Inserisci(p, in);

    cout << ls;

    cout << "rimuovo gli elementi 200 e 100" << endl;
    cout << endl;

    ls.Rimuovi(200);
    ls.Rimuovi(100);

    cout << ls;

    return 0;
}