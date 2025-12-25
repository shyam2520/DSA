/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int amount = lists.length;
        int interval = 1;
        while (interval < amount) {
            for (int i = 0; i < amount - interval; i += interval * 2) {
                lists[i] = merge2Lists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        return amount > 0 ? lists[0] : null;
    }

    ListNode merge2Lists(ListNode l1, ListNode l2) {
        if (l1 == null || l2 == null) {
            return l1 == null? l2 : l1;
        }

        if (l1.val <= l2.val) {
            l1.next = merge2Lists(l1.next, l2);
            return l1; 
        } else {
            l2.next = merge2Lists(l1, l2.next);
            return l2;
        }
    }
}