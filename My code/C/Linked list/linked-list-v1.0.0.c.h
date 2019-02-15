//filename: linked-list-v1.0.0.c.h
//author: PenG
//create time: 2019/02/15
//version: 1.0.0
//description: linked list in c language for c program

#pragma once
#ifndef LINKED_LIST_C_H_
#define LINKED_LIST_C_H_

#include <stdlib.h>
#include <string.h>

/*
	here is data area, you need edit it to fit your own need.
*/

typedef struct Unidirectional_data
{
	int data;//TODO
}Unidirectional_linked_list_data;

typedef struct Bidirectional_Data
{
	int data;//TODO
}Bidirectional_linked_list_data;

/*
	here is node area, you ought not to edit it.
*/
typedef struct Unidirectional_node
{
	Unidirectional_linked_list_data data;
	struct Unidirectional_node *next;
}Unidirectional_linked_list_node;

typedef struct Bidirectional_node
{
	Bidirectional_linked_list_data data;
	struct Bidirectional_node *last;
	struct Bidirectional_node *next;
}Bidirectional_linked_list_node;



/*
	here is linked list control area, you ought not to edit it.
*/


/*
	Unidirectional list control.
*/

typedef struct UnidirectionalListInfo
{
	unsigned int length;
	Unidirectional_linked_list_node *head;
	Unidirectional_linked_list_node *tail;
}UnidirectionalListInfo;


/*
	create an unidirection list, just init list information.
		
	if list equals to NULL then return -1
	success return 0
*/
int createUnidirectionalList(UnidirectionalListInfo *list);

/*
	get length of list
	
	if list equals to NULL then return -1
	else reutrn length of list
*/
int getUnidirectionalListLength(UnidirectionalListInfo *list);

/*
	append a data to list.

	if list equals to NULL then return -1
	if memory request failure then return -2
	success return 0
*/
int appendUnidirectionalListData(UnidirectionalListInfo *list, Unidirectional_linked_list_data data);

/*
	releast list memory

	if list equals to NULL then retur -1
	success return 0
*/
int releastUnidirectionalList(UnidirectionalListInfo *list);





/*
	Bidirectional list control.
*/

typedef struct BidirectionalListInfo
{
	unsigned int length;
	Bidirectional_linked_list_node *head;
	Bidirectional_linked_list_node *tail;
}BidirectionalListInfo;

/*
create a bidirectional list, just init list information.

if list equals to NULL then return -1
success return 0
*/
int createBidirectionalList(BidirectionalListInfo *list);

/*
get length of list

if list equals to NULL then return -1
else reutrn length of list
*/
int getBidirectionalListLength(BidirectionalListInfo *list);

/*
append a data to list.

if list equals to NULL then return -1
if memory request failure then return -2
success return 0
*/
int appendBidirectionalListLenght(BidirectionalListInfo *list, Bidirectional_linked_list_data data);

/*
releast list memory

if list equals to NULL then retur -1
success return 0
*/
int releaseBidirectionalList(BidirectionalListInfo *list);

#endif
