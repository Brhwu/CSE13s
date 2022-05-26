## Overview

HW7

businessdb

businessdb.c

written by Brandon Hwu

## Purpose

The purpose of the program is to have the student design and implement a database that tracks customers and their info.

## Layout

Establish data base

(Functions)

add

lookup

delete

list

save

quit

(Main)

## Description

add 

When the user types add it will prompt them to enter an email address, display name, shoe size, and favorite food.

If the email address is present in the data base then replace the data with the new entry.

lookup

Prompt the user for an email address and find the email address in the hash table.

If there is no address in the hash table then state that the address was not found.

If the address was found then list all information on the user

delete

Prompt the user for an email address and find the email address in the hash table.

Delete the data

If email address was not found then state that it was not found

list

display every user in the database.

save

write the current state of the database back to customers.tsv.

quit

clean up all memory and exit program.



## Pseudocode

Initialize database

fget customers.tsc

duplicate text from database


(Functions)

save

overwrite customers.tsv


add(email, name, ssize, ffood)

iterate through database

   if email equals email address 

      replace name, shoe size and favorite food

   else

      add new entry with information


lookup

   print all information


delete(email)

iterate through database

   delete all information


Main

while true

   if user input equals quit

      break

   elif user input equals save

      save database on customers.tsv

      (function) save

   elif user input equals add

      prompt for email address (email)

      prompt for name (name)

      prompt for shoe size (ssize)

      prompt for favorite food (ffood)

      (function) add(email, name, ssize, ffood)

   elif user input equals lookup

      prompt for email address

      search for email address in database

      if in database 

         (function) lookup

      else 

         print user not found

   elif user input equals delete

      prompt for email address

      search for email address in database

      if in database

         (function) delete(email)

      else 

         print user not found

   elif user input equals list

      go through database

         print information

   else

      print unknowm command


