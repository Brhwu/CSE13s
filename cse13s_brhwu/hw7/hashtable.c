#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "hashtable.h"

#define NUM_BUCKETS 10

// Thank you Dan Bernstein.
unsigned long hash(char *str) {
  unsigned long hash = 5381;
  int c;

  while (*str != '\0') {
    c = *str;
    hash = ((hash << 5) + hash) + (unsigned char)c; /* hash * 33 + c */
    str++;
  }
  return hash;
}

Customer *add_customer_to_list(char *email, char *name, int s_size, char *food, Customer *bucket) { //helper
  Customer* new_customer;

  new_customer = malloc(sizeof(Customer));
  new_customer->email = strdup(email);
  new_customer->name = strdup(name);
  new_customer->shoe_size = s_size; //??
  new_customer->fav_food = strdup(food);
  new_customer->next = bucket;

  return new_customer;
}


void delete(char *email, Customer **buckets, size_t num_buckets) {
    
    size_t which_bucket = hash(email) % num_buckets;
    
    Customer* node;
  node = buckets[which_bucket];
  Customer* prev = NULL;
  
    while(node != NULL) {
      prev = node;
      
       if (strcmp(node->email, email) == 0) {
        
        if (which_bucket == 0 && node->next == NULL)  {
		printf("Trig");
		free(node->fav_food);
      node->shoe_size = 0;  //need?
      free(node->name);
      free(node->email);
      free(node);
      break;
	}
	    if(buckets[which_bucket-1] == NULL) {
		    printf("Trig1");
		    free(node->fav_food);
      node->shoe_size = 0;  //need?
      free(node->name);
      free(node->email);
      free(node);
      break;
	    }
	    if(buckets[which_bucket-1] != NULL && buckets[which_bucket+1] != NULL) {
		    free(node->fav_food);
		    printf("Trig2");
      node->shoe_size = 0;  //need?
      free(node->name);
      free(node->email);
      free(node);
      break;
	    }
	    else{
		    printf("Trig3");
	free(node->fav_food);
      node->shoe_size = 0;  //need?
      free(node->name);
      free(node->email);
      free(node);
      break;

	    } 
    }
       printf("Move");
    prev = node;
    node = node->next;
}
}


char *lookup(char *email, Customer **buckets,
    size_t num_buckets) {

  size_t which_bucket = hash(email) % num_buckets;

  char *key = NULL;
  Customer* node;
  node = buckets[which_bucket];


  while(node != NULL) {
      
    if (strcmp(node->email, email) == 0) {
        
      key = node->email;
    }
    node = node->next;
    
}
return key;
}


void replace(char *email, char *name, int s_size, 
    char *food, Customer **buckets, size_t num_buckets) {

  size_t which_bucket = hash(email) % num_buckets;

  Customer* node;
  node = buckets[which_bucket];


  while(node != NULL) {
      
    if (strcmp(node->email, email) == 0) {
      
      
      //free(node->name);
      node->name = strdup(name);
     
      node->shoe_size = s_size;
      //free(node->fav_food);
      //free(node);
      node->fav_food = strdup(food);
      
    }
    node = node->next;
  }
}



void add_customer_to_hashtable(char *email, char *name, int s_size,  //need
    char *food, Customer **buckets, size_t num_buckets) {

  size_t which_bucket = hash(email) % num_buckets;

  buckets[which_bucket] = add_customer_to_list(email, name, s_size, food, buckets[which_bucket]);

 // printf("friend %s goes in bucket %lu .\n", email, which_bucket);
}

char *name_for_customer(char *email, Customer **buckets,
    size_t num_buckets) {

  size_t which_bucket = hash(email) % num_buckets;

  char *result = NULL;
  Customer* node;
  node = buckets[which_bucket];

  while(node != NULL) {
    if (strcmp(node->email, email) == 0) {
      result = node->name;
    }
    node = node->next;
  }
  return result;
}

int shoe_for_customer(char *email, Customer **buckets,
    size_t num_buckets) {

  size_t which_bucket = hash(email) % num_buckets;

  int result = 0;
  Customer* node;
  node = buckets[which_bucket];

  while(node != NULL) {
    if (strcmp(node->email, email) == 0) {
      result = node->shoe_size;  //&
    }
    node = node->next;
  }
  return result;
}

char *fav_food_for_customer(char *email, Customer **buckets,
    size_t num_buckets) {

  size_t which_bucket = hash(email) % num_buckets;

  char *result = NULL;
  Customer* node;
  node = buckets[which_bucket];

  while(node != NULL) {
    if (strcmp(node->email, email) == 0) {
      result = node->fav_food;
    }
    node = node->next;
  }
  return result;
}


