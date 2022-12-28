#include <iostream>

using namespace std;


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* fast{head};
        ListNode* slow{head};
        int list_size{};

        // Get list size
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            list_size += 2;
        }

        // Account for odd size
        if (fast && !fast->next)
            ++list_size;
        

        // Find node to remove
        int remove_idx{ list_size - n };
        int current_idx{list_size / 2};
        ListNode* prev{};

        if (current_idx >= remove_idx)
        {
            current_idx = 0;
            slow = head;
        }

        while (current_idx != remove_idx)
        {
            prev = slow;
            slow = slow->next;

            current_idx++;
        }

        // remove it, accounting for head
        if (slow == head) head = head->next;
        else prev->next = slow->next;

        return head;
    }
};


int main()
{
    ListNode tail{5};
    ListNode rmid{4, &tail};
    ListNode mid {3, &rmid};
    ListNode lmid{2, &mid};
    ListNode head{1, &lmid};

    ListNode* result {Solution{}.removeNthFromEnd(&head, 1)};

    return 0;
}