#include <iostream>

struct listnode
{
    int data;
    listnode* next;

    listnode(int data = 0)
    {
        this->data = data;
        next = nullptr;
    }

    void print()
    {
        std::cout << data << ' ';

        if (next != nullptr)
            next->print();
        else
            std::cout << '\n';
    }

    void pushback(int data = 0)
    {
        listnode* addr = this;

        while (addr->next != nullptr)
            addr = addr->next;

        addr->next = new listnode(data);
    }

    unsigned size()
    {
        listnode* addr = this;
        int size = 1;

        while (addr->next != nullptr)
        {
            addr = addr->next;
            size++;
        }

        return size;
    }

    int& at(unsigned index)
    {
        listnode* addr = this;

        for (unsigned i = 0; i < index; i++)
        {
            addr = addr->next;
        }

        return addr->data;
    }

    void flip()
    {
        for (unsigned i = 0, j = this->size() - 1; i <= this->size() / 2, j >= this->size() / 2; i++, j--)
        {
            std::swap(this->at(i), this->at(j));
        }
    }

    ~listnode()
    {
        delete next;
    }
};

int main()
{
    listnode spisok = listnode();

    spisok.pushback(1);
    spisok.pushback(-2);
    spisok.pushback(3);
    spisok.pushback(-4);
    spisok.pushback(5);
    spisok.pushback(-6);
    spisok.pushback(7);
    spisok.pushback(-8);
    spisok.pushback(9);

    for (unsigned i = 0; i < spisok.size(); i++)
        std::cout << spisok.at(i) << " ";
    std::cout << '\n';

    spisok.flip();

    for (unsigned i = 0; i < spisok.size(); i++)
        std::cout << spisok.at(i) << " ";

    return 0;
}
