/*
输入两个链表，找出它们的第一个公共结点。

当不存在公共节点时，返回空节点。

数据范围
链表长度 [1,30000]
。
保证两个链表不完全相同，即两链表的头结点不相同。

样例
给出两个链表如下所示：
A：        a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3

输出第一个公共节点c1
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} ;
}
;
// 1.使用两个指针p1和p2分别指向链表A和链表B的头结点
// 2.当p1和p2不相等时，p1指向链表A的下一个结点，p2指向链表B的下一个结点
// 3.当p1指向链表A的尾结点时，p1指向链表B的头结点；当p2指向链表B的尾结点时，p2指向链表A的头结点
// 4.当p1和p2相等时，返回p1
// 5.时间复杂度O(m+n)，空间复杂度O(1)
class Solution {
    public:
        ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
            ListNode *p1=headA,*p2=headB;
            while(p1!=p2){
                if(p1!=NULL)
                    p1=p1->next;
                else p1=headB;
                if(p2!=NULL)
                    p2=p2->next;
                else p2=headA;
            }
            return p1;
            
        }
    };