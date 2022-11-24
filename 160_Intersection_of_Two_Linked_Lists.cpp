#include <iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* ptr{headA};    

        int m{};
        int n{};

        while (ptr != nullptr)
        {
            ptr = ptr->next;
            ++m;
        }
        
        ptr = headB;

        while (ptr != nullptr)
        {
            ptr = ptr->next;
            ++n;
        }

        int diff{abs(m - n)};


        if (diff == 0)
        {
            ptr = headA;
            ListNode* ptrb{headB};

            while (ptr && ptr != ptrb)
            {
                ptr = ptr->next;
                ptrb = ptrb->next;
            }
        }
        else
        {
            if (m > n)
                ptr = headB;
            else
                ptr = headA;

            for(int i{}; i < diff; ++i)
                ptr = ptr->next;
        }

        return ptr;
    }
};


int main() 
{
    ListNode* tailc = new ListNode(4);
    ListNode* midc = new ListNode(3, tailc);

    // ListNode* mida = new ListNode(2, midc);
    ListNode* heada = new ListNode(1, midc);

    ListNode* midb = new ListNode(2, midc);
    ListNode* headb = new ListNode(1, midb);

    cout << Solution{}.getIntersectionNode(heada, headb)->val;

    return 0;
}