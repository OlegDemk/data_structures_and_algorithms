/*
 * linked_list.c
 *
 *  Created on: Apr 17, 2021
 *      Author: odemki
 */

#include <stdlib.h>

typedef struct s_list{
	int id;							// ID елемента
	char *name;						// Назва елемента

	struct s_list *next;			// показник на наступну структуру
}t_list;							// Створення елемента t_list з структкри s_list

// -------------------------------------------------------------------------
t_list *create_node(int set_id, char *set_name)						// функція створення списку
{
	t_list *node = (t_list *)malloc(sizeof(t_list));				// Виділення памяті під структуру node

	node -> id = set_id;											// Запис в структуру node даних через посказник
	node -> name = set_name;										// Запис в структуру node даних через посказник
	node -> next = NULL;											// Запис в структуру node адрес наступного елемента (його немає)

	return node;					// Вертає показник на створену структуру
}
// -------------------------------------------------------------------------
void push_front(t_list **list, int set_id, char *set_name)			// Додавання елемента списку на перед
{
	t_list *new_element = create_node(set_id, set_name);			// Створення нового елемента

	new_element -> next = *list;									// перевизначення поля next на попередній адрес
	*list = new_element;			// присвоїти адрес даного елемента списку змінній list
}
// -------------------------------------------------------------------------
void linked_list(void)
{
	t_list *list = create_node(0, "Name_1");		// Створити один связний список

	// Додавання наступного елементу списку на початок.
	push_front(&list, 1, "Name_2");					// передається адрес попереднього списку.
	push_front(&list, 2, "Name_3");
	push_front(&list, 3, "Name_4");
	push_front(&list, 4, "Name_5");

	while(list != NULL)								// Друкувати елементи допоки вони не ссилаються на NULL
	{
		printf("id = %d, name = %s\n", list -> id, list -> name);
		list = list -> next;						// Запис в list показник на наступний елемент списку
	}
}
// -------------------------------------------------------------------------
// -------------------------------------------------------------------------
// -------------------------------------------------------------------------
// -------------------------------------------------------------------------
