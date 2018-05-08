//
// Created by Piotrek on 12.03.2018.
//

#include "SimpleForwardList.h"

ForwardList *CreateNode(int value) {

    ForwardList *new_node;
    new_node= (ForwardList*) malloc(sizeof(ForwardList));
    new_node->value = value;
    new_node->next = nullptr;


    return new_node;
}

void DestroyList(ForwardList *list) {


    ForwardList *n=list->next, *j= list;
    while(j->next!= nullptr){
        while (n->next!= nullptr){
            j=j->next;
            n=n->next;
        }
        j->next=nullptr;
        free(j);
        j=list;
    }

    free(j);
    free(list);



}

ForwardList *PushFront(ForwardList *list, int value) {

    ForwardList *new_node;
    new_node=(ForwardList *) malloc(sizeof(ForwardList));
    new_node->next = list;
    new_node->value=value;
    return new_node;

}

void Append(ForwardList *list, ForwardList *tail) {

    while(list!=nullptr)
        list=list->next;
    list->next=tail;
    tail->next=nullptr;

}