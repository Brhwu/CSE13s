## Overview

HW4

graphsearch.c

written by Brandon Hwu

## Purpose

The purpose of the program is to find a path through a directed graph from start to end.

It will have the student work with algorithms and allocating data structures.

## Layout

LLint add_to_set(LLint set, int val)

bool set_contains(LLint set, int val)

LLPath enqueue_path(LLPath q, Path path)

bool dequeue_path(LLPath q, Path ret)

Graph graph_create(int vertices)

void graph_add_edge(Graph g, int i, int j)

bool graph_has_edge(Graph g, int i, int j)

Path path_extend(Path path, int new_vertex)

void print_path(Path path)

Path graph_find_path_bfs(Graph g, int i, int j)

LLPath stack_path(LLPath q, Path path)

Path graph_find_path_dfs(Graph g, int i, int j)

## Description

LLPath enqueue_path

Will return the new front of queue, for a queue of Path structs.


bool dequeue_path

Will free memory used in enqueue path.


Path graph_find_path_bfs

Uses the breadth-first search algorithm to figure out a path.


LLPath stack_pat

This is a helper function for graph_find_path_dfs and replaces enqueue_path in graph_find_path_dfs.


Path graph_find_path_dfs

Uses the depth-first search algorithm to figure out a path.

## Pseudocode

LLPath enqueue_path(LLint q, int val)

Code is based on class demo graphs.c

Prepare node(newnode)

make newnode val equal to path

if q is NULL

   return newnode

make LLPath pointer(cur) equal to q

while cur next is not NULL

   move cur to next

make cur next equal to newnode

return q


bool dequeue_path(LLint q, int ret)

Code is based on class demo graphs.c

if pointer q equals NULL

   return false

make ret equal to pointer q val

make LLPath pointer(freethis) equal to pointer q

make pointer q equal to pointer q next

free freethis

return true


Path graph_find_path_bfs(Graph g, i, j)

Code is based on class demo graphs.c

Make a set of verticies in LLint (visited)

Make a queue of vertices in LLPath (to_visit)

Make a path (starting)

Set the starting steps to 0

Call Path_extend with starting and i

Make to_visit equal to Enqueue_path with the to_visit and starting

If i equals j

   Return starting

While to_visit is not NULL

   Make new path (current)

   Dequeue_path with to_visit and current

   If the last element in current vertices visited equals j

      Return current

   Make visited equal to add_to_set with visited and current vertices

   For loop with variable neighbors being incremented and less than neighbor vertices

      if graph_has_edge and is not in visited

         Make new path(next) equal to path extend with current and neighbors

         Make to_visit equal to enqueue_path with to_visit and next


LLPath stack_path(LLPath q, Path path)

This is a modified version of enqueue_path

Prepare node(newnode)

make newnode val equal to path

if q is NULL

   return newnode

make LLPath pointer(cur) equal to q

make cur next equal to newnode

return q


Path graph_find_path_dfs(Graph g, i, j)

Make a set of verticies in LLint (visited)

Make a queue of vertices in LLPath (to_visit)

Make a path (starting)

Set the starting steps to 0

Call Path_extend with starting and i

Make to_visit equal to stack_path with the to_visit and starting

If i equals j

   Return starting

While to_visit is not NULL

   Make new path (current)

   Dequeue_path with to_visit and current

   If the last element in current vertices visited equals j

      Return current

   Make visited equal to add_to_set with visited and current vertices

   For loop with variable neighbors being incremented and less than neighbor vertices

      if graph_has_edge and is not in visited

         Make new path(next) equal to path extend with current and neighbors

         Make to_visit equal to stack_path with to_visit and next

