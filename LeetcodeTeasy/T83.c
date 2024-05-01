//    删除排序链表中的重复元素

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct ListNode{// 定义结点的结构体
    int val;// 数据域
    struct ListNode*next;//指针域
};


void pri(struct ListNode *h){// 打印单链表中所有节点的值
    printf("pri\n");
    struct ListNode *pt;
    pt = h;
    while(pt!=NULL){
        printf("%d ",pt->val);
        pt = pt->next;
    }

}

struct ListNode* deleteDuplicates(struct ListNode* head) {// 主功能函数
    struct ListNode *ptr,*p,*q;//ptr-扫描整个链表的指针，p- 重复结点的第1个结点。 q- 第1个不重复结点。
    int flag = -1;//初始值为-1.当出现重复结点时，flag=1,。当不出现重复结点，flag=0。
    ptr = head;// 在力扣提供的单链表中，第1个结点就是数据结点。
    if(head==NULL||(ptr->next==NULL))
         printf("0个或1个结点\n");
    else{// 2个结点以上
        while(ptr->next!=NULL){// 只要当前所指向结点的指针域不空，就循环一次，直到ptr的指针域为空。
            if(ptr->val == ptr->next->val){// 出现了重复结点
                if(1!=flag){// 只标记重复结点的第1个结点。
                   flag = 1;//标记出现了重复结点。
                   p = ptr;//标记重复结点中的第1个结点。
                }
            }
            else{// 当前节点值 ！= 下一结点值。这有2种情况，一种是当前结点不存在相等情况；一种情况时当前节点是重复结点
                if(1==flag){// 这个是调出当前结点是“重复结点”。
                    flag = 0;
                    q = ptr->next;// q- 指向第1个“不重复结点”。
                    p->next = q;// 然后将连续重复结点的
                }

             }
            //uptr = ptr;
            ptr = ptr->next;//更新当前结点。
        }
        if(1==flag){// 重复结点出现在链表尾部
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
     printf("处理前：\n");
     pri(h);
     h = deleteDuplicates(h);
     printf("处理后：\n");
     pri(h);
return 0;
}
