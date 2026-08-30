/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* merge(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (list1 != NULL && list2 != NULL) {

            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            }
            else {
                current->next = list2;
                list2 = list2->next;
            }

            current = current->next;
        }

        if (list1 != NULL)
            current->next = list1;
        else
            current->next = list2;

        return dummy->next;
    }


    ListNode* sortList(ListNode* head) {

        // Base case
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split
        ListNode* second = slow->next;
        slow->next = NULL;

        // Sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(second);

        // Merge sorted halves
        return merge(left, right);
    }
};