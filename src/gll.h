/**
* \file gll.h
* \brief Header file of the generic-linked-list
* \author: BCadet
*/

/** 
 * \defgroup gll 
 * This is the generic-linked-list class
 * @{
 */

#ifndef GLL_H
#define GLL_H
#pragma once

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#ifdef GLL_DONT_USE_MALLOC
#ifndef GLL_MAX_NODE_POOL_SIZE
#define GLL_MAX_NODE_POOL_SIZE  255
#endif
#endif

/*
 * \brief: gll_node_t struct. node of the liked list
 */
typedef struct node_t {
  void *data; ///< pointer to data stored in node
  struct node_t *prev; ///< pointer to previous node
  struct node_t *next; ///< pointer to next node
} gll_node_t;

/*
 * \brief head of the linked list
 */
typedef struct {
  int size; ///< number of elements
  gll_node_t *first; ///< pointer to head node
  gll_node_t *last; ///< pointer to tail node
} gll_t;


/**
 * \ingroup gll
 * \brief Allocates (if malloc enabled) and initializes a new list.
 * 
 * \param[in] list pointer of the head structure of the list
 * \return the same pointer of the list
 */
gll_t *gll_init(gll_t *list);

/**
 * \ingroup gll
 * \brief Gets the pointer to the data stored at the node in an arbitrary position. Returns NULL if position does not exist.
 * 
 * \param[in] pointer pointer to list to retrieve data from
 * \param[in] int position of node in the list
 * \return void pointer to data or NULL if not found
 */
void *gll_get(gll_t *list, int position);

/**
 * \ingroup gll
 * \brief Gets the pointer to the data at the head of the list (position 0). Returns NULL if list is empty.
 * 
 * \param[in] list pointer to list to retrieve data from
 * \return void pointer to data or NULL if list is empty
 */
void *gll_first(gll_t *list);

/**
 * \ingroup gll
 * \brief Gets the pointer to the data stored at the tail of the list (last position). Returns NULL if list is empty.
 * 
 * \param[in] list pointer to list to retrieve data from
 * \return void pointer to data or NULL if list is empty
 */
void *gll_last(gll_t *list);

/**
 * \ingroup gll
 * \brief Adds a new element at an arbitrary position. Returns -1 if unsuccessful.
 * 
 * \param[in] list pointer to list to add data to
 * \param[in] data pointer to data to be stored
 * \param[in] index position of data in the list
 * \return 0 on success, -1 on failure
 */
int gll_add(gll_t *list, void *data, int position);

/**
 * \ingroup gll
 * \brief Sets the data pointer of a node at an arbitrary position. Returns pointer that was previously stored at that node or NULL if position does not exist.
 * 
 * \param[in] list pointer to list to store data
 * \param[in] data pointer to new data to be stored
 * \param[in] index position of node in the list
 * \return 0 on success, -1 on failure
 */
void *gll_set(gll_t *list, void *data, int position);

/**
 * \ingroup gll
 * \brief Adds a new element at the head of the list (position 0).
 * 
 * \param[in] list pointer to list to add data to
 * \param[in] data pointer to new data to be stored
 * \return 0 on success, -1 on failure
 */
int gll_push(gll_t *list, void *data);

/**
 * \ingroup gll
 * \brief Adds a new element at the tail of the list (last position).
 * 
 * \param[in] list pointer to list to add data to
 * \param[in] data pointer to data to be stored
 * \return 0 on success, -1 on failure
 */
int gll_pushBack(gll_t *list, void *data);

/**
 * \ingroup gll
 * \brief Removes an element at an arbitrary position. Returns the pointer to the data stored at the removed node, or NULL if unsuccessful.
 * 
 * \param[in] list pointer to list to remove data from
 * \param[in] index position of element to remove
 * \return pointer to data or NULL if not found
 */
void *gll_remove(gll_t *list, int position);

/**
 * \ingroup gll
 * \brief Removes the head of the list (position 0) and return the pointer stored at that position. Returns NULL if list is empty.
 * 
 * \param[in] list pointer to list to remove data from
 * \return pointer to data or NULL if list is empty
 */
void *gll_pop(gll_t *list);

/**
 * \ingroup gll
 * \brief Removes the tail of the list (last position) and return the pointer stored at that position. Returns NULL if list is empty.
 * 
 * \param[in] list pointer to list to remove data from
 * \return pointer to data or NULL if list is empty
 */
void *gll_popBack(gll_t *list);

/**
 * \ingroup gll
 * \brief Iterates over the entire list from beginning to end and calls the specified function with each element as a parameter. The function must be of return type void and take a void pointer (void *) parameter.
 * 
 * \param[in] list pointer to list
 * \param[in] f  pointer to function
 */
void gll_each(gll_t *list, void (*f)(void *));

/**
 * \ingroup gll
 * \brief Iterates over the entire list from end to beginning and calls the specified function with each element as a parameter. The function must be of return type void and take a void pointer (void *) parameter.
 * 
 * \param[in] list pointer to list
 * \param[in] f  pointer to function
 */
void gll_eachReverse(gll_t *list, void (*f)(void *));

/**
 * \ingroup gll
 * \brief Clears the entire list and deallocates all **nodes**. The data that is referenced by each node is not touched.
 * 
 * \param[in] list pointer to list
 */
void gll_clear(gll_t *list);

/**
 * \ingroup gll
 * \brief Clears the list and deallocates all list-related memory (if malloc enabled). The data referenced by each node is not touched.
 * 
 * \param[in] list pointer to list
 */
void gll_destroy(gll_t *list);

/** @} */ // end of device group 

#endif