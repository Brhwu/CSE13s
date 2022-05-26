## Overview

HW1

pig.c

written by Brandon Hwu


## Purpose

The purpose of the program is to play out a simplified version of *Pass the Pigs*.  It will have the students be exposed to using a Makefile and use basic programming language facilities.


## Layout

Ask the user how many players are playing.

Ask the user for the seed value.

The game starts 

Program states who is rolling

Program rolls and states how the pig lands

Program keeps rolling until the pig lands on the side.

Next player rolls

Programs states who is the winner when one players points go over 100.

Program ends


## Description

The program asks the user to imput how many players are playing.

The program can only handle 2 to 8 players.

If the user enters in a number between 2 to 10 the program will add that many players to the game.

If the user enters in a number less than 2 or more than 10 the program will default to 2 players playing.

The program will ask the user to input the random seed for the game.

If the user enters in a valid seed value then the program will use that value.

If the player enters in an invalid seed it will default to 2022 as the seed value.

The game starts and will state who is rolling the pig and what position does the pig land on.

If pig lands on any position except side the program will keep rolling the pig.

When the pig lands on the side it will be the next person's turn.

The program will keep going through each player and loop back to the first player.

The game ends when one player gets 100 or more points.

The program will state who the winner is and how many points they got and end.


## Pseudocode

Program Start

   int variable players

   int variable seedvalue

   int array score

   int gamestart = 0 (Only purpose is to make infinite loops)

   int Position pig (The seven positions)

   print "How many players?"

   get input from user and save to players

   if players is more than 10 or players less than 2

       print "Invalid number of players. Using 2 instead."

       set players to 2

   print "Enter in seed value"

   get input from user and save to seedvalue
 
   if seedvalue is less than 0 or seedvalue more than UINTMAX
 
       print "Invalid random seed. Using 2022"

       set seedvalue to 2022 

   define SEED to value saved in seedvalue

   set the random seed

   start infinite loop (gamestart < 1)(game starts)

       loop through the number of players using loop counter

          print "(Reference names.h) rolls the pig... " 

          start infinite loop 
          
              generate a random number between 0 and 6

              apply random number to pig array (it will give back a number between 0 and 4) 
 
              if pig lands on SIDE (0)

                  print "pig lands on side "
 
                  break loop

              if pig lands on RAZORBACK (1)

                  print "pig lands on back "
 
                  add 10 point to score array (position is the same as the player loop counter)
 
                  if score >= 100

                      print "(Reference names.h) wins with (Score number) points!"

                      end program

              if pig lands on TROUTTER (2)

                  print "pig lands upright "

                  add 10 point to score array (position is the same as the player loop counter)

                  if score >= 100

                      print "(Reference names.h) wins with (Score number) points!"

                      end program

              if pig lands on SNOUTER (3)

                  print "pig lands on snout "

                  add 15 point to score

                  if score >= 100

                      print "(Reference names.h) wins with (Score number) points!"

                      end program
    
              if pig lands on JOWLER (4)

                  print "pig lands on ear "

                  add 5 point to score

                  if score >= 100 

                      print "(Reference names.h) wins with (Score number) points!"

                      end program


End of Program     


