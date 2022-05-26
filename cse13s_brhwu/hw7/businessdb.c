#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "hashtable.h"

#define NUM_BUCKETS 10


int main() {
	FILE * fp;
    fp = fopen("customers.tsv", "r");
    char str[500];
    int i = 0;
   
Customer* buckets[NUM_BUCKETS] = {NULL};


    while(fgets(str, 500, fp)!=NULL) {   //128? if/while?  fgets  gets one line
       i = 0;
       char *array[4];
       //Customer* buckets[NUM_BUCKETS] = {NULL};
       array[i] = strtok(str, "\t");

       while (array[i] != NULL) {
	       array[++i] = strtok(NULL, "\t");
   }
       printf("%s\t%s\t%s\t%s\n", array[0], array[1], array[2], array[3]);
       add_customer_to_hashtable(array[0], array[1], atoi(array[2]), array[3], buckets, NUM_BUCKETS);
    }
fclose(fp);
    

   //add_customer_to_hashtable("sammy1@ucsc.edu", "Sammy The Slug", atoi("27"), "bananas", buckets, NUM_BUCKETS);
   //add_customer_to_hashtable("bimmy1@ucsc.edu", "bimmy", atoi("4"), "vegan jerky", buckets, NUM_BUCKETS);
   //add_customer_to_hashtable("joe1@example.edu", "Joe Mama", atoi("100"), "borgar", buckets, NUM_BUCKETS);
   //add_customer_to_hashtable("todd1@example.edu", "Todd Todderson", atoi("12"), "tacos", buckets, NUM_BUCKETS);

while(1) {
    printf("command: ");
    char name[10];
    scanf("%s", name);
    if (strcmp(name, "quit") == 0) {
        break;
    }
    else if (strcmp(name, "save") == 0) {
        fopen("customers.tsv", "w");


    }
    else if (strcmp(name, "add") == 0) {
        char iemail[128];
        printf("email address? ");
        scanf("%s", iemail);

        char iname[128];
        printf("name? ");
        scanf(" %[^\n]s", iname);

        int iss = 0;
        printf("shoe size? ");
        scanf("%d", &iss);

        char iff[128];
        printf("favorite food? ");
        scanf(" %[^\n]s", iff);

	//   Customer* buckets[NUM_BUCKETS] = {NULL};
	char *result = NULL;
	result = lookup(iemail, buckets, NUM_BUCKETS);
	if(result == NULL) { //if email was not found
	add_customer_to_hashtable(iemail, iname, iss, iff, buckets, NUM_BUCKETS);
	}
	else {
		replace(iemail, iname, iss, iff, buckets, NUM_BUCKETS);
    }
    }
    else if (strcmp(name, "lookup") == 0) {
        char iemail[128];


        printf("email address? ");
        scanf("%s", iemail);

	//Customer* buckets[NUM_BUCKETS] = {NULL};
	char *result = NULL;
	result = lookup(iemail, buckets, NUM_BUCKETS);
	printf("result: %s\n", result);
	printf("iemail: %s\n", iemail);
	if(result == NULL) {
	    printf("Email not found\n");
	}

	else { //if email was found

        //Customer* buckets[NUM_BUCKETS] = {NULL};
        char *pname = NULL;
        int pshoe = 0;
        char *pfood = NULL;

	pname = name_for_customer(iemail, buckets, NUM_BUCKETS);
	pshoe = shoe_for_customer(iemail, buckets, NUM_BUCKETS);
	pfood = fav_food_for_customer(iemail, buckets, NUM_BUCKETS);

	printf("%s\t%s\t%d\t%s\n", iemail, pname, pshoe, pfood);

        }

    }
    else if (strcmp(name, "delete") == 0) {
        char iemail[128];
        printf("email address? ");
        scanf("%s", iemail);
	char *result = NULL;
	result = lookup(iemail, buckets, NUM_BUCKETS);
	if(result == NULL) {
	    printf("User not found\n");
	}

	else {
		delete(iemail, buckets, NUM_BUCKETS);
    }
}
    else if (strcmp(name, "list") == 0) {
   

        Customer* node;
        for (size_t i = 0; i < NUM_BUCKETS; i++) {
        node = buckets[i];

  while(node != NULL) {
      char *iemail = NULL;
     iemail = node->email;
     char *pname = NULL;
        int pshoe = 0;
        char *pfood = NULL;

	pname = name_for_customer(iemail, buckets, NUM_BUCKETS);
	pshoe = shoe_for_customer(iemail, buckets, NUM_BUCKETS);
	pfood = fav_food_for_customer(iemail, buckets, NUM_BUCKETS);

	printf("%s\t%s\t%d\t%s\n", iemail, pname, pshoe, pfood);
  
    node = node->next;
  }
	}
        }
    
    else {
        printf("Unknown Command\n");
    }
}
}

