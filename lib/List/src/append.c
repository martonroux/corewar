/*
** EPITECH PROJECT, 2023
** append
** File description:
** file for append functions for list library
*/

#include "list.h"

void list_append(list_t * list, void * data)
{
    node_t * node = create_node(data);
    if (!list)
        return;

    list->size++;
    if (!list->tail) {
        list->tail = node;
        list->head = node;
    } else {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
}
