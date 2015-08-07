/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define NULL 0
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution 
{
public:
    ListNode *addTwoNumbers(ListNode *node1, ListNode *node2) 
    {
		ListNode* head = new ListNode(-1);
		ListNode* node = head;
		int sum = 0;
		int carry = 0;
		do 
		{
			int v1 = (node1 == NULL) ? 0 : node1->val;
			int v2 = (node2 == NULL) ? 0 : node2->val;
			int v_sum = v1 + v2 + carry;

			int sum = (v_sum) % 10 ;
			carry = (v_sum) / 10;
			node->next = new ListNode(sum);
			node = node->next;
			
			if (node1 != NULL) node1 = node1->next;
			if (node2 != NULL) node2 = node2->next;

		} while ((node1 != NULL) || (node2 != NULL));

		if (carry) 
		{
			node->next = new ListNode(1);
		}

		ListNode *data = head->next;
		delete head;
		return data;
    }
};
