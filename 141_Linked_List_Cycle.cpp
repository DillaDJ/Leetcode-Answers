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
    bool hasCycle(ListNode *head) 
    {
        // Floyd's Cycle Detection Algorithm
        ListNode* slow = head;
        ListNode* fast = head;

        while (true) {
            if (fast == nullptr || fast->next == nullptr) 
                return false; // No loops

            slow = slow->next;
            fast = fast->next->next; 
        
            if (fast == slow)
                break;
        }

        return true;
    }
};


int main() 
{
    ListNode* tail = new ListNode(5);
    ListNode* mid2 = new ListNode(4, tail);
    ListNode* mid1 = new ListNode(3, mid2);
    ListNode* mid = new ListNode(2, mid1);
    ListNode* head = new ListNode(1, mid);

    cout << boolalpha << Solution{}.hasCycle(head) << endl;

    return 0;
}