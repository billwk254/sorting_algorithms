#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @list: Pointer to the head of the doubly linked list.
 * @node1: First node to swap.
 * @node2: Second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
if (node1->prev)
node1->prev->next = node2;
if (node2->next)
node2->next->prev = node1;

node1->next = node2->next;
node2->prev = node1->prev;

node2->next = node1;
node1->prev = node2;

if (!node2->prev)
*list = node2;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Cocktail shaker sort algorithm.
 *
 * @list: Pointer to a pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
int swapped;
listint_t *start = NULL;
listint_t *end = NULL;

if (!list || !(*list) || !(*list)->next)
return;

do
{
swapped = 0;
for (start = *list; start->next != end; start = start->next)
{
if (start->n > start->next->n)
{
swap_nodes(list, start, start->next);
swapped = 1;
print_list(*list);
}
}
if (!swapped)
break;
swapped = 0;
end = start;
for (end = start; end->prev != *list; end = end->prev)
{
if (end->n < end->prev->n)
{
swap_nodes(list, end->prev, end);
swapped = 1;
print_list(*list);
}
}

}
while (swapped);
}
