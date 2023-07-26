#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                        order using the Insertion sort algorithm.
 *
 * @list: Pointer to a pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
listint_t *sorted = NULL;
listint_t *current = *list;
listint_t *next = NULL;
if (!list || !(*list) || !(*list)->next)
return;

while (current)
{
next = current->next;

if (!sorted || sorted->n >= current->n)
{
current->next = sorted;
current->prev = NULL;
if (sorted)
sorted->prev = current;
sorted = current;
}
else
{
listint_t *temp = sorted;
while (temp->next && temp->next->n < current->n)
temp = temp->next;

current->next = temp->next;
if (temp->next)
temp->next->prev = current;
temp->next = current;
current->prev = temp;
}

current = next;
if (next)
next->prev = current;
print_list(sorted);
}

*list = sorted;
}
