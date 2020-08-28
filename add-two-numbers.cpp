
Problem Link - https://leetcode.com/problems/add-two-numbers/



Solution--------------



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

    void sum(ListNode* l1, ListNode* l2, ListNode* ans,int carry)
    {
        int x=0,y=0;
        if(l1!=NULL)
        x=l1->val;
        
        if(l2!=NULL)
        y=l2->val;
        
        int s=x+y+carry;
        carry=0;
        if(s>9)
        {
            carry=s/10;
            s%=10;
        }
        
        ans->val=s;
        ListNode* temp = new ListNode();
        temp->next=NULL;
        ans->next=temp;
        
         if(l1->next==NULL && l2->next==NULL)
        {
            if(carry!=0)
            {
                ans->next->val=carry;
                ListNode* temp = new ListNode();
                temp->next=NULL;
                ans->next->next=temp;
            }
         
            return;
        }
        
        if(l1->next==NULL)
        {
            l1->val=0;
            sum(l1,l2->next,ans->next,carry);
        }   
        else if(l2->next==NULL)
        {
            l2->val=0;
            sum(l1->next,l2,ans->next,carry);
        } 
        else
         sum(l1->next,l2->next,ans->next,carry);  
        
        return;
    }
    
    
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ans = new ListNode();
        ans->next=NULL;
    
        
        sum(l1,l2,ans,0);
        
        ListNode* second_last = ans; 
        while (second_last->next->next != NULL) 
        second_last = second_last->next; 
        
        if(second_last->next->val==0)
        delete (second_last->next); 
        
        second_last->next=NULL;

        
        return ans;
    }
};