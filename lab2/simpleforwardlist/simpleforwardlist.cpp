//
// Created by Piotrek on 12.03.2018.
//

#include "simpleforwardlist.h"

ForwardList *CreateNode(int value) {

    auto new_node = new ForwardList;
    new_node->value = value;

    return new_node;
}

void DestroyList(ForwardList *list) {

    if(list)
    {
        ForwardList *nextToDelete = list->next;
        delete list;
        DestroyList(nextToDelete);
    }




}

ForwardList *PushFront(ForwardList *list, int value) {

    if(list)
    {
        ForwardList *new_node = CreateNode(value);
        new_node->next = list;

        return new_node;
    }
    else return nullptr;
}

void Append(ForwardList *list, ForwardList *tail) {

    if(list)
    {
        auto current = list;
        ForwardList *prev = nullptr;

        while(current) {
            prev = current;
            current = current->next;

        }

        prev->next = tail;
    }

}