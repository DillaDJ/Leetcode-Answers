#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x, ListNode* next) : val(x), next(next) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode() : val(0), next(nullptr) {}
};
 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if (l1 == nullptr && l2 == nullptr) {
            return new ListNode(0);
        }


        ListNode* head = new ListNode();
        ListNode** tail = &head;

        int carry_over = 0;
        int result;

        while (l1  != nullptr || l2 != nullptr)
        {

            // Set value of current node
            if (l1 != nullptr && l2 != nullptr) {

                result = l1->val + l2->val + carry_over;
                (*tail)->val = result % 10;

            }
            else if ((l1 != nullptr && l2 == nullptr) || (l2 != nullptr && l1 == nullptr)) {

                result = (l1 != nullptr && l2 == nullptr ? l1->val : l2->val) + carry_over;
                (*tail)->val = result % 10;

            }
            carry_over = result >= 10 ? 1 : 0;

            if (l1 != nullptr) {
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                l2 = l2->next;
            }

            // New node
            if (l1 != nullptr || l2 != nullptr || carry_over != 0) {

                (*tail)->next = new ListNode();
                tail = &(*tail)->next;

                if (l1 == nullptr && l2 == nullptr && carry_over != 0) {
                    (*tail)->val = carry_over;
                }

            }
        }

        return head;
    }
};


ListNode* constructLinkedList(int array[], int size) {

    ListNode* prevNode = nullptr;

    for (int i = size - 1; i >= 0; i--)
    {
        if (prevNode == nullptr) {
            prevNode = new ListNode(array[i]);
        }
        else {
            prevNode = new ListNode(array[i], prevNode);
        }
    }

    return prevNode;
}


int main() {
    int array1[7] {9,9,9,9,9,9,9};
    int array2[4] {9,9,9,9};

    ListNode* linkedList1 = constructLinkedList(array1, 7);
    ListNode* linkedList2 = constructLinkedList(array2, 4);

    ListNode* result = Solution().addTwoNumbers(linkedList1, linkedList2);

    while (result != nullptr) {
        cout << result->val << endl;
        result = result->next; 
    }
    
    return 0;
}