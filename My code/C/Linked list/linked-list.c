//filename: linked-list.c
//author: PenG
//create time: 2019/02/15
//version: 1.0.0
//description: linked list in c language for c program

#include "linked-list.c.h"

int createUnidirectionalList(UnidirectionalListInfo *list)
{
	if (NULL == list)
	{
		return -1;
	}

	list->length = 0;
	list->head = NULL;
	list->tail = NULL;
	return 0;
}

int getUnidirectionalListLength(UnidirectionalListInfo *list)
{
	if (NULL == list)
	{
		return -1;
	}

	return list->length;
}

int appendUnidirectionalListData(UnidirectionalListInfo *list, Unidirectional_linked_list_data data)
{
	//pointer check
	if (NULL == list)
	{
		return -1;
	}

	//memory request and check
	Unidirectional_linked_list_node *l_node 
		= (Unidirectional_linked_list_node *)malloc(sizeof(Unidirectional_linked_list_node));
	if (NULL == l_node)
	{
		return -2;
	}

	//data copy
	memcpy(&l_node->data, &data, sizeof(Unidirectional_linked_list_data));
	
	//list linking
	l_node->next = NULL;
	if (0 == list->length)
	{
		list->head = l_node;
		list->tail = l_node;
	}
	else
	{
		list->tail->next = l_node;
		list->tail = l_node;
	}

	//length++
	list->length++;
	return 0;
}

int releastUnidirectionalList(UnidirectionalListInfo *list)
{
	if (NULL == list)
	{
		return -1;
	}

	while (list->length-- > 0)
	{
		list->tail = list->head->next;
		free(list->head);
		list->head = list->tail;
	}

	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return 0;
}





int createBidirectionalList(BidirectionalListInfo *list)
{
	if (NULL == list)
	{
		return -1;
	}

	list->length = 0;
	list->head = NULL;
	list->tail = NULL;
	return 0;
}

int getBidirectionalListLength(BidirectionalListInfo *list)
{
	if (NULL == list)
	{
		return -1;
	}

	return list->length;
}

int appendBidirectionalListLenght(BidirectionalListInfo *list, Bidirectional_linked_list_data data)
{
	//pointer check
	if (NULL == list)
	{
		return -1;
	}

	//memory request and check
	Bidirectional_linked_list_node *l_node
		= (Bidirectional_linked_list_node *)malloc(sizeof(Bidirectional_linked_list_node));
	if (NULL == l_node)
	{
		return -2;
	}

	//data copy
	memcpy(&l_node->data, &data, sizeof(Bidirectional_linked_list_data));

	//list linking
	l_node->next = NULL;
	l_node->last = NULL;
	if (0 == list->length)
	{
		list->head = l_node;
		list->tail = l_node;
	}
	else
	{
		list->tail->next = l_node;
		l_node->last = list->tail;
		list->tail = l_node;
	}

	//length++
	list->length++;
	return 0;
}

int releaseBidirectionalList(BidirectionalListInfo *list)
{
	if (NULL == list)
	{
		return -1;
	}

	while (list->length-- > 0)
	{
		list->tail = list->head->next;
		free(list->head);
		list->head = list->tail;
	}

	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return 0;
}