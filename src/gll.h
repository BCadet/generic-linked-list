/* 
 * File:     gll.h
 * Author:   Philip Klostermann 
 */

#ifndef GLL_H
#define GLL_H
#pragma once

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// #define USE_MALLOC

#ifdef GLL_DONT_USE_MALLOC
#ifndef GLL_MAX_NODE_POOL_SIZE
#define GLL_MAX_NODE_POOL_SIZE  255
#endif
#endif

/*
 * Node Type: gll_node_t struct
 */
typedef struct node_t {
  void *data;
  struct node_t *prev;
  struct node_t *next;
} gll_node_t;

/*
 * Generic Linked List Type: gll_t
 */
typedef struct {
  int size;
  gll_node_t *first;
  gll_node_t *last;
} gll_t;


/*  create new list */
gll_t *gll_init(gll_t *list);

/*  get/find functions */
void *gll_get(gll_t *, int);
void *gll_first(gll_t *);
void *gll_last(gll_t *);

/*  add functions */
int gll_add(gll_t *, void *, int);
void *gll_set(gll_t *, void *, int);
int gll_push(gll_t *, void *);
int gll_pushBack(gll_t *, void *);

/*  remove functions */
void *gll_remove(gll_t *, int);
void *gll_pop(gll_t *);
void *gll_popBack(gll_t *);

/*  iterate functions */
void gll_each(gll_t *, void (*f)(void *));
void gll_eachReverse(gll_t *, void (*f)(void *));

/*  destructive functions */
void gll_clear(gll_t *);
void gll_destroy(gll_t *);

#endif