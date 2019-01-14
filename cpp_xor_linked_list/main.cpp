/*
 * A XOR linked list is an improvement over doubly linked list. Instead of
 * storing both prev and next pointers, it has a member called both that is an
 * XOR of prev and next nodes.
 * 
 * TODO: Implement Remove(int), AddFront(int), Get(int)
 */

#include <iostream>

class XorLL
{
public:
    XorLL() :
    head(nullptr),
    tail(nullptr)
    { }

    ~XorLL()
    {
        XorLLNode* cur = head;
        XorLLNode* prev = nullptr;
        while (cur != nullptr)
        {
            XorLLNode* next = reinterpret_cast<XorLLNode*>((uintptr_t)cur->both ^ (uintptr_t)prev);
            delete cur;
            prev = cur;
            cur = next;
        }
    }

    void Add(int val)
    {
        XorLLNode* node = new XorLLNode(val);
        if (nullptr == tail)
        {
            // This is the first element in the list
            node->both = ((uintptr_t)head ^ (uintptr_t)tail);
            head = node;
            tail = node;
        }
        else
        {
            // tail->both needs to adjust for node
            node->both = ((uintptr_t)tail ^ 0);
            tail->both = (((uintptr_t)tail->both ^ 0) ^ (uintptr_t)node);
            tail = node;
        }
    }

    void Print()
    {
        XorLLNode* cur = head;
        XorLLNode* prev = nullptr;
        try
        {
            while (cur != nullptr)
            {
                std::cout << cur->val << ',';
                XorLLNode* next = reinterpret_cast<XorLLNode*>((uintptr_t)cur->both ^ (uintptr_t)prev);
                prev = cur;
                cur = next;
            }
            std::cout << "\n";
        }
        catch (std::exception ex)
        {
            std::cout << ex.what();
        }
    }

private:
    class XorLLNode
    {
    public:
        int val;
        uintptr_t both;

        XorLLNode(int t_val):
        val(t_val),
        both(0)
        { }
    };
    XorLLNode* head;
    XorLLNode* tail;
};

int main(int argc, char const *argv[])
{
    XorLL xll;
    for (int i = 0; i < 10; i++)
    {
        xll.Add(i);
    }
    xll.Print();
    return 0;
}
