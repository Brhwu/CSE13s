#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct Customer {
  char *email; //the key
  char *name;   // values
  int shoe_size; // values pointer?
  char *fav_food;  // values
  struct Customer *next;
} Customer;


unsigned long hash(char *str);

Customer *add_customer_to_list(char *email, char *name, int s_size, char *food, Customer *bucket);

void delete(char *email, Customer **buckets, size_t num_buckets);

char *lookup(char *email, Customer **buckets,
    size_t num_buckets);

void replace(char *email, char *name, int s_size, 
    char *food, Customer **buckets, size_t num_buckets);

void add_customer_to_hashtable(char *email, char *name, int s_size,  //need
    char *food, Customer **buckets, size_t num_buckets);

char *name_for_customer(char *email, Customer **buckets,
    size_t num_buckets);

int shoe_for_customer(char *email, Customer **buckets,
    size_t num_buckets);

char *fav_food_for_customer(char *email, Customer **buckets,
    size_t num_buckets);









