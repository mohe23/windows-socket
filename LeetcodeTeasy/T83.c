//    ɾ�����������е��ظ�Ԫ��

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct ListNode{// ������Ľṹ��
    int val;// ������
    struct ListNode*next;//ָ����
};


void pri(struct ListNode *h){// ��ӡ�����������нڵ��ֵ
    printf("pri\n");
    struct ListNode *pt;
    pt = h;
    while(pt!=NULL){
        printf("%d ",pt->val);
        pt = pt->next;
    }

}

struct ListNode* deleteDuplicates(struct ListNode* head) {// �����ܺ���
    struct ListNode *ptr,*p,*q;//ptr-ɨ�����������ָ�룬p- �ظ����ĵ�1����㡣 q- ��1�����ظ���㡣
    int flag = -1;//��ʼֵΪ-1.�������ظ����ʱ��flag=1,�����������ظ���㣬flag=0��
    ptr = head;// �������ṩ�ĵ������У���1�����������ݽ�㡣
    if(head==NULL||(ptr->next==NULL))
         printf("0����1�����\n");
    else{// 2���������
        while(ptr->next!=NULL){// ֻҪ��ǰ��ָ�����ָ���򲻿գ���ѭ��һ�Σ�ֱ��ptr��ָ����Ϊ�ա�
            if(ptr->val == ptr->next->val){// �������ظ����
                if(1!=flag){// ֻ����ظ����ĵ�1����㡣
                   flag = 1;//��ǳ������ظ���㡣
                   p = ptr;//����ظ�����еĵ�1����㡣
                }
            }
            else{// ��ǰ�ڵ�ֵ ��= ��һ���ֵ������2�������һ���ǵ�ǰ��㲻������������һ�����ʱ��ǰ�ڵ����ظ����
                if(1==flag){// ����ǵ�����ǰ����ǡ��ظ���㡱��
                    flag = 0;
                    q = ptr->next;// q- ָ���1�������ظ���㡱��
                    p->next = q;// Ȼ�������ظ�����
                }

             }
            //uptr = ptr;
            ptr = ptr->next;//���µ�ǰ��㡣
        }
        if(1==flag){// �ظ�������������β��
            p->next = NULL;
        }
    }


return head;
}


int main(){
    struct ListNode *h,*h1,*h2,*h3,*h4,*h5;
    h = (struct ListNode*)malloc(sizeof(struct ListNode));
    h1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    h2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    h3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    h4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    h5 = (struct ListNode*)malloc(sizeof(struct ListNode));
     h->val=1;h1->val=1;h2->val=2;h3->val=4;h4->val=5;h5->val=2;
     h->next=h1;h1->next=h2;//h2->next=h3;//h3->next=h4;h4->next=h5;h5->next=NULL;
     h2->next =NULL;
     printf("1123\n");
     printf("����ǰ��\n");
     pri(h);
     h = deleteDuplicates(h);
     printf("�����\n");
     pri(h);
return 0;
}
