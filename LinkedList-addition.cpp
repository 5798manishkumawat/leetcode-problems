
 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        string sum="";
        int s=0;
        ListNode* res=new ListNode();
        ListNode* ans=res;
        while(l1!=nullptr && l2!=nullptr)
        {
          if(carry>0)
          {
              s=(l1->val)+(l2->val)+carry;
              ans->next=new ListNode(s%10);
              ans=ans->next;
              carry=s/10;
              
          }
            else
            {
              s=(l1->val)+(l2->val);
             ans->next=new ListNode(s%10);
              ans=ans->next;
              carry=s/10;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=nullptr)
        {
            if(carry>0)
            {
              s=(l1->val)+carry;
              ans->next=new ListNode(s%10);
              ans=ans->next;
              carry=s/10;
            } 
            else
            {
               s=(l1->val);
               ans->next=new ListNode(s%10);
              ans=ans->next;
              carry=s/10; 
            }
             l1=l1->next;
        }
        while(l2!=nullptr)
        {
            if(carry>0)
            {
              s=(l2->val)+carry;
               ans->next=new ListNode(s%10);
              ans=ans->next;
              carry=s/10;
            } 
            else
            {
               s=(l2->val);
               ans->next=new ListNode(s%10);
              ans=ans->next;
              carry=s/10; 
            }
             l2=l2->next;
        }
        if(carry>0)
        {     
              ans->next=new ListNode(carry);
              ans=ans->next;
        }
      return res->next;  
    }
};


