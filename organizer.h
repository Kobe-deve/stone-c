#include "battle.h" // calls back battle functions and basic functions
	
int encount = 0; //used for counting encounter		
	
int d1[10][10][10] = {  {0,0,0,1,0,0,0,0,4,0,
						0,0,0,1,0,1,1,1,1,1,
						0,0,0,28,0,0,0,0,0,0,
						0,0,0,0,0,1,0,0,0,0,
						A,0,0,9,1,0,0,0,0,0,
						1,1,1,1,1,0,0,0,2,0,
						0,4,0,0,1,0,0,0,0,0,
						0,4,4,0,0,0,0,0,0,0,
						1,1,0,1,0,0,0,0,0,0,
						4,4,0,0,0,C,0,0,D,0},
						
						{4,0,0,0,0,0,0,0,0,0,
						 1,1,1,1,0,0,0,0,2,0,
						 4,4,1,0,0,0,0,0,0,0,
						 4,9,1,0,1,1,1,1,1,1,
						 0,0,1,0,1,0,0,0,0,B,
						 1,0,1,0,1,0,1,0,0,0,
						 0,0,1,0,1,0,1,0,3,0,
					 	 0,0,1,0,1,0,1,0,0,0,
						 0,0,1,0,1,0,0,1,1,1,
						 0,0,0,0,0,0,0,0,0,4},
						
						{0,0,0,0,0,0,0,0,0,B,
						 0,0,1,1,1,0,0,0,0,0,
						 0,0,0,0,1,9,0,0,3,0,
						 0,0,0,0,1,1,1,1,1,1,
						 0,0,0,0,0,0,0,0,0,0,
						 1,1,1,1,0,0,0,0,0,0,
						 0,0,4,1,0,0,0,0,0,0,
						 0,0,0,1,0,1,1,1,1,1,
						 0,2,0,0,0,1,0,4,4,0,
						 0,0,0,1,0,0,0,4,4,0},
						
						{1,1,4,4,0,0,0,0,0,0,
						 0,1,4,4,0,0,0,0,0,0,
						 0,1,1,1,1,1,1,1,1,0,
						 0,0,0,0,0,0,0,0,0,0,
						 1,1,1,0,1,1,1,0,1,1,
						 4,0,0,0,1,0,1,0,1,4,
						 1,1,1,0,1,0,1,0,1,0,
						 0,3,1,0,1,0,1,0,2,0,
						 B,0,1,0,1,0,0,0,0,0,
						 0,0,0,0,1,0,0,0,A,0},
						
						{0,1,0,0,0,0,0,0,0,0,
						 0,0,0,0,0,0,0,0,0,0,
						 0,1,0,0,0,0,0,0,0,0,
						 0,1,0,0,0,0,0,0,0,0,
						 0,1,0,1,1,1,1,1,0,0,
						 0,1,0,0,0,0,2,1,20,0,
						 0,1,1,0,1,0,0,1,0,0,
						 0,4,1,0,1,1,1,1,0,0,
						 0,9,1,0,0,0,4,1,3,0,
						 0,4,1,0,0,0,4,1,0,0},
						 		
						{4,0,0,0,0,0,0,0,0,0,
						 1,1,1,0,0,0,0,1,0,2,
						 0,0,0,0,0,0,0,1,0,0,
						 0,0,0,1,1,1,1,1,A,0,
						 0,1,1,1,0,0,0,1,4,4,
						 0,0,0,1,0,0,0,1,1,1,
						 1,1,0,1,0,1,3,1,4,4,
						 0,0,0,1,0,1,1,1,4,4,
						 0,1,1,1,0,1,0,0,0,0,
						 0,0,0,0,0,0,0,0,0,0},
						
						{ 0,0,0,0,0,0,0,0,0,3,
						  0,0,1,1,1,1,1,1,0,0,
						  0,1,2,0,0,0,0,0,1,1,
						  0,1,0,0,A,1,1,0,0,0,
						  0,1,1,1,1,0,0,1,0,0,
						  0,0,0,0,0,2,0,1,0,0,
						  0,1,1,1,0,0,0,1,0,0,
						  0,1,0,0,1,1,1,0,0,0,
						  0,1,4,4,0,0,0,0,0,0,
						  0,1,9,0,0,0,0,0,0,0},
						 
						 {0,0,0,0,0,0,0,0,0,4,
						  0,0,0,0,0,0,0,0,1,1,
						  0,0,0,1,1,0,0,0,0,0,
						  0,0,3,1,0,0,0,0,0,0,
						  0,0,0,1,0,1,1,1,1,1,
						  0,0,1,0,0,0,3,1,0,0,
						  0,0,1,0,2,1,1,0,0,0,
						  0,1,A,0,0,0,1,0,0,0,
						  0,0,1,1,1,1,1,0,0,0,
						  0,0,0,0,0,0,0,0,0,0},
						 
						 {0,0,0,1,0,0,0,0,2,0,
						  0,2,0,1,0,0,1,0,0,0,
						  0,0,A,1,0,0,1,0,0,0,
						  0,0,0,1,0,0,1,1,1,1,
						  0,0,0,1,0,0,0,0,0,0,
						  0,0,0,1,0,0,0,0,0,0,
						  0,0,0,1,0,1,1,1,1,0,
						  0,0,0,1,3,1,4,4,0,0,
						  0,0,0,1,1,1,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0},
						 
						 {0,3,1,4,4,4,4,1,0,3,
						  0,0,1,4,7,4,4,1,0,0,
						  0,0,1,0,0,0,0,1,0,0,
						  0,9,1,0,0,0,0,1,0,0,
						  1,1,0,0,0,0,0,1,0,0,
						  0,0,0,0,0,0,0,1,0,0,
						  0,0,0,0,1,0,0,1,0,0,
						  0,0,0,0,1,1,1,0,0,0,
						  0,0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0},
						};

int d2[5][20][20] = { {0,0,0,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,1,9,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					   
					  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					
					  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					   
					  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					   
					  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},};
 
int seenTiles2[20][20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					   	  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					   	  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					   	  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					  	  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					   	  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					   	  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					   	  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					  	  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					   	  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					   	  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					   	  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					  	  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					   	  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					   	  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					   	  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; 
 
int seenTiles[12][12] = {1,1,1,1,1,1,1,1,1,1,1, // seen tiles for the first dungeon
						 1,1,1,1,1,1,1,1,1,1,1,
						 1,1,1,1,1,1,1,1,1,1,1,
						 1,1,1,1,1,1,1,1,1,1,1,
						 1,1,1,1,1,1,1,1,1,1,1,
						 1,1,1,1,1,1,1,1,1,1,1,
						 1,1,1,1,1,1,1,1,1,1,1,
						 1,1,1,1,1,1,1,1,1,1,1,
						 1,1,1,1,1,1,1,1,1,1,1,
						 1,1,1,1,1,1,1,1,1,1,1,
						 1,1,1,1,1,1,1,1,1,1,1};
	
void introduction() // the introduction of the game
{
	timee = 10;
	day = 1;
	
	garland = 1;
	drake = 1; 
	evelia = 1; 
	sarah = 1; 
	diantra = 1;
	kage = 1; 
	gilgahin = 1; 
	peopleSetting();
	
	printf("\nYou opened your eyes and found yourself in a damp dark stone");
	printf("\nmaze..?");
	preEnter();
	system("cls");
	printSprite(M1,25,0);
	setCursor(0,20);
	printf("\nCreature:\"Hey there, wow you just woke up\"");
	preEnter();
	clearBottom();
	printf("\nCreature:\"Welcome to the Scilo, a prison in space that");
	printf("\n           houses humans and spirits such as myself!\"");
	preEnter();
	clearBottom();
	printf("\nCreature:\"We're mostly hostile but I felt like just saying");
	printf("\n           hello to you since you just appeared. There's a");
	printf("\n           powerful human guarding the exit to this section so");
	printf("\n           you're gonna be here forever. See ya later.\"");
	preEnter();
	clearBottom();
	printf("\nThe creature ran off into the darkness");
	preEnter();
}	

// Social functions - used to organize which character the player is talking with and can recruit (this will occur at the bar so the setCursor is (0,22) when resetting

void garLand() // Garland's social (complex alignment)
{
	
}

void eveLia() // Evelia's social (harsh alignment)
{
}

void diaNtra() // Diantra's social (bright alignment)
{
}

void kaGe() // Kage's social (optimist algignment)
{
}

void gilGahin() // Gilgahin's social (mysterious alignment)
{
}	

void draKe() // Drake's social (mysterious caring alignment)
{
}

void westLand() // Westland's social (unknown alignment)
{
}

void sarAh() // Sarah's social (unknown alignment)
{
}

void weaponoo() // for buying weapons
{
	srand((unsigned)time(NULL));
	
	bool done = false;
	int input;
	char stringer[20];
	clearBottom();
	int x;
	int y;
	int z;
	int checker = 0;
	int length;
	
	struct weapon w1,w2,w3;	
	for(y=0;y<3;y++)
	{
		length = rand()%2+2;
		for(x=0;x<length;x++)
		{
			switch(rand()%15+1)
			{
				case 1:
				case 11:
				default:
				if(x == 0)
					stringer[x*3] = 'M';
				else
					stringer[x*3] = 'm';
				stringer[x*3+1] = 'u';
				stringer[x*3+2] = 'r';
				w1.ATT = w1.ATT + 1;
				break;
				case 2:
				case 12:
				if(x == 0)
					stringer[x*3] = 'A';
				else
					stringer[x*3] = 'a';
				stringer[x*3+1] = 'r';
				stringer[x*3+2] = 'a';
				break;
				case 3:
				case 13:
				if(x == 0)
					stringer[x*3] = 'S';
				else
					stringer[x*3] = 's';
				stringer[x*3+1] = 'u';
				stringer[x*3+2] = 'n';
				break;
				case 4:
				case 14:
				if(x == 0)
					stringer[x*3] = 'X';
				else
					stringer[x*3] = 'x';
				stringer[x*3+1] = 'e';
				stringer[x*3+2] = 'n';
				break;
				case 5:
				case 15:
				if(x == 0)
					stringer[x*3] = 'P';
				else
					stringer[x*3] = 'p';
				stringer[x*3+1] = 'e';
				stringer[x*3+2] = 'y';
				break;
				case 6:
				if(x == 0)
					stringer[x*3] = 'J';
				else
					stringer[x*3] = 'j'; 
				stringer[x*3+1] = 'i';
				stringer[x*3+2] = 'a';
				break;
				case 7:
				if(x == 0)
					stringer[x*3] = 'E';
				else
					stringer[x*3] = 'e';
				stringer[x*3+1] = 'v';
				stringer[x*3+2] = 'a';
				break;
				case 8:
				if(x == 0)
					stringer[x*3] = 'Y';
				else
					stringer[x*3] = 'y';
				stringer[x*3+1] = 'u';
				stringer[x*3+2] = 'n';
				break;
				case 9:
				if(x == 0)
					stringer[x*3] = 'Z';
				else
					stringer[x*3] = 'z';
				stringer[x*3+1] = 'a';
				stringer[x*3+2] = 'y';
				break;
				case 10:
				if(x == 0)
					stringer[x*3] = 'O';
				else
					stringer[x*3] = 'o';
				stringer[x*3+1] = 'p';
				stringer[x*3+2] = 'o';
				break;
			}	
		}	
		switch(y)
		{
			case 0:
			strcpy(w1.label,stringer);
			break;
			case 1:
			strcpy(w2.label,stringer);
			break;
			case 2:
			strcpy(w3.label,stringer);
			break;
		}
		for(z=0;z<20;z++)
			stringer[z] = 0;
	}	
	w1.type = rand()%5+1;
	w1.ATT = rand()%(attack)+1;
	w1.lvl = w1.ATT%10+w1.ATT%2;
	if(w1.type == bow || w1.type == gun)
		w1.chamber = rand()%w1.lvl+2;
	w1.value = w1.ATT*10+w1.lvl+rand()%20;
	
	w2.type = rand()%5+1;
	w2.ATT = rand()%(attack)+1;
	w2.lvl = w2.ATT%10+w2.ATT%2;
	if(w2.type == bow || w2.type == gun)
		w2.chamber = rand()%w2.lvl+2;
	w2.value = w2.ATT*10+w2.lvl+rand()%20;
	
	w3.type = rand()%5+1;
	w3.ATT = rand()%(attack)+1;
	w3.lvl = w3.ATT%10+w3.ATT%2;
	if(w3.type == bow || w3.type == gun)
		w3.chamber = rand()%w3.lvl+2;
	w3.value = w3.ATT*10+w3.lvl+rand()%20;
	while(done == false)
	{
		printf("\n%s - Attack:%d Level:%d Value:%d Type:",w1.label,w1.ATT,w1.lvl,w1.value);
		switch(w1.type)
		{
			case sword:
			printf("Sword");
			break;
			case gun:
			printf("Gun");
			printf("\nChambers:%d",w1.chamber);
			break;
			case bow:
			printf("Bow");
			printf("\nArrows that can be fired:%d",w1.chamber);
			break;
			case lance:
			printf("Lance");
			break;
			case axe:
			printf("Axe");
			break;
		}
		printf("\n%s - Attack:%d Level:%d Value:%d Type:",w2.label,w2.ATT,w2.lvl,w2.value);
		switch(w2.type)
		{
			case sword:
			printf("Sword");	// hey mom, ya gay	
			break;
			case gun:
			printf("Gun");
			printf("\nChambers:%d",w2.chamber);
			break;
			case bow:
			printf("Bow");
			printf("\nArrows that can be fired:%d",w2.chamber);
			break;
			case lance:
			printf("Lance");
			break;
			case axe:
			printf("Axe");
			break;
		}
		printf("\n%s - Attack:%d Level:%d Value:%d Type:",w3.label,w3.ATT,w3.lvl,w3.value);
		switch(w3.type)
		{
			case sword:
			printf("Sword");
			break;
			case gun:
			printf("Gun");
			printf("\nChambers:%d",w3.chamber);
			break;
			case bow:
			printf("Bow");
			printf("\nArrows that can be fired:%d",w3.chamber);
			break;
			case lance:
			printf("Lance");
			break;
			case axe:
			printf("Axe");
			break;
		}
		printf("\nCASH:%d",money);
		switch(options("Which weapon do you want?",w1.label,w2.label,w3.label,"Exit",4,0,30))
		{
			case 1:
			clearBottom();
			if(money >= w1.value && storageFull() == false)
			{
				while(weaponHere(checker) == true)
				{
					checker++;
				}
				strcpy(storage[checker].label,w1.label);
				storage[checker].ATT = w1.ATT;
				storage[checker].lvl = w1.lvl;
				storage[checker].value = w1.value-10;
				storage[checker].type = w1.type;
				storage[checker].chamber = w1.chamber;
				money = money - w1.value;
				clearBottom();
				setCursor(0,27);
				printf("Would you like to equip the %s?",storage[checker].label);
				switch(options("","Yes","No","","",2,0,28))
				{
					case 1:	
					equipped = checker;	
					break;
					case 2:
					break;
				}
				clearBottom();
				switch(options("Do you want to buy another weapon?","Yes","No","","",2,0,27))
				{
					case 1:
					clearBottom();
					break;
					case 2:
					done = true;
					clearBottom();	
					break;
				}
			}
			else
			{
				printf("\nYou don't have enough for that weapon");
				printf("\nor your inventory is full");
				preEnter();
				clearBottom();
			}
			break;
			case 2:
			if(money >= w2.value && storageFull() == false)
			{
				while(weaponHere(checker) == true)
				{
					checker++;
				}
				strcpy(storage[checker].label,w2.label);
				storage[checker].ATT = w2.ATT;
				storage[checker].lvl = w2.lvl;
				storage[checker].value = w2.value-10;
				storage[checker].type = w2.type;
				storage[checker].chamber = w2.chamber;
				money = money - w2.value;
				clearBottom();
				printf("Would you like to equip the %s?",storage[checker].label);
				switch(options("","Yes","No","","",2,0,28))
				{
					case 1:	
					equipped = checker;	
					break;
					case 2:
					break;
				}
				switch(options("Do you want to buy another weapon?","Yes","No","","",2,0,27))
				{
					case 1:
					clearBottom();
					break;
					case 2:
					done = true;
					clearBottom();	
					break;
				}
			}
			else
			{
				printf("\nYou don't have enough for that weapon");
				printf("\nor your inventory is full");
				preEnter();
				clearBottom();
			}
			break;
			case 3:
			if(money >= w3.value && storageFull() == false)
			{
				while(weaponHere(checker) == true)
				{
					checker++;
				}
				strcpy(storage[checker].label,w3.label);
				storage[checker].ATT = w3.ATT;
				storage[checker].lvl = w3.lvl;
				storage[checker].value = w3.value-10;
				storage[checker].type = w3.type;
				storage[checker].chamber = w3.chamber;
				money = money - w3.value;
				clearBottom();
				printf("Would you like to equip the %s?",storage[checker].label);
				switch(options("","Yes","No","","",2,0,28))
				{
					case 1:	
					equipped = checker;	
					break;
					case 2:
					break;
				}
				switch(options("Do you want to buy another weapon?","Yes","No","","",2,0,27))
				{
					case 1:
					clearBottom();
					break;
					case 2:
					done = true;
					clearBottom();	
					break;
				}
			}
			else
			{
				printf("\nYou don't have enough for that weapon");
				printf("\nor your inventory is full");
				preEnter();
				clearBottom();
			}	
			break;
			case 4:
			done = true;
			clearBottom();
			break;
		}
		
	}
}

void grocery() // when the player purchases food
{
	int input = 0;
	int x = 0;
	int price = 0;
	doode:
	clearBottom();
	setCursor(0,21);
	printf("Shopkeeper:\"Ah I see you want some of the spirit");
	printf("\n           food we have, well I'll serve by packets\"");
	printf("\nPress Enter to select the amount of food you desire");
	printf("\nor press escape to exit");
	printf("\nCurrent Food Supply:%d",food);
	while(input != 13 && input != 27)
	{
		setCursor(0,27);
		price = x*level;
		if(x < 10)
			printf("Food:%d   ",x);
		else
			printf("Food: %d",x);
		if(price < 10)
			printf("Price:$%d   ",price);
		else	
			printf("Price:$ %d",price);
		input = getch();
		switch(input)
		{
			case 77:
			x++;
			break;
			case 75:
			if(x!=0)
				x--;	
			break;
			case 13:
			if(price > money)	
			{
				printf("You don't have enough...");
				preEnter();
				goto doode;
			}
			else
			{
				food = food + x;
				money = money - price;
			}
			break;
		}
	}
}

void megamina() // for the shop
{
	bool done = false; // is the player done shopping around?
	int y,x;
	int roomCost;
	
	system("cls");
	printf("\n%s entered the hole in the wall, and found a shop!",name);
	preEnter();
	system("cls");
	printPattern(SHOPPER,80,20);
	while(done == false)
	{
		setCursor(0,21);
		printf("\nShopkeeper:\"Hello welcome to my shop\"");
		switch(options("What do you want to do?","Buy Supplies","Sell Weapons","Fuse Monsters Together with \"Fusion Machine\"","Exit",4,0,23))
		{
			case 1:
			for(y=20;y<28;y++)
			{
				for(x=0;x<80;x++)
				{
					printAt(' ',x,y);	
				}	
			}
			switch(options("What would you like to buy?","Weapons or ammunition","Food","Buy a room (Sleep and rest)","Go back",4,0,23))
			{
				case 1:
				clearBottom();
				switch(options("Which do you want to buy?","Ammunition","Weapons","Go back","",3,0,23))
				{
					case 1:
					clearBottom();
					ammoo();	
					break;
					case 2:
					clearBottom();
					weaponoo();
					break;
					case 3:
					clearBottom();
					break;
				}
				break;
				case 2:
				grocery();
				break;
				case 3:	
				clearBottom();
				setCursor(0,22);
				roomCost = floors[currentLocation-1]*10+day;
				printf("\nShopkeeper:\"Ah yes we have a room for $%d! How does that sound?",roomCost);
				switch(options("","Spend the night here","Don't buy a room","","",2,0,25))
				{
					case 1:
					if(money >= roomCost)
					{
						money = money - roomCost;
						system("cls");
						printf("\nThe shopkeeper gave you keys to a small room in the back");
						printf("\nand you spent the night there...");
						preEnter();
						sleep();
						printPattern(SHOPPER,80,20);	
					}	
					else
					{
						printf("\nShopkeeper:\"Sorry but you don't have enough\"");
						preEnter();
					}
					case 2:
					clearBottom();
					break;
				}
				break;
				case 4:
				clearBottom();
				break;
			}		
			for(y=20;y<28;y++)
			{
				for(x=0;x<80;x++)
				{
					printAt(' ',x,y);	
				}	
			}
			break;
			case 2:
			seller();
			system("cls");
			printPattern(SHOPPER,80,20);
			break;
			case 3:
			system("cls");
			printf("\nYou walked over to a strange machine that has \"Fusion\" written");
			printf("\non it.");
			preEnter();
			fusionTwo();
			system("cls");
			printPattern(SHOPPER,80,20);
			break;
			case 4:
			clearBottom();
			printf("\nThe shopkeeper waved to you as you left");
			done = true;
			preEnter();
			break;
		}	
	}	
}

int clearing() // clears social dialogue and returns line to 1
{
	system("cls");
	return 1;
}	

void backRoomr() // what happens in the backroom stays in this back room
{
	bool done = false; // is the player done talking?
	bool doneB = false; // is the player done selecting something?
	int y = 21;
	int adder1 = 0;
	int adder2 = 0;
	int adder3 = 0;
	int price; // the price of changing
	clearBottom();
	system("cls");
	printPattern(BACK_ROOM,80,20);
	setCursor(0,21);	
	switch(chapter)
	{	
		case 1:
		if(visitedBack == false && demonKind == false)
		{	
				visitedBack = true;
				printf("\nYou found yourself in a strange room with patterns on the wall...");
				preEnter();
				printf("\nA cloaked figure stood in the center of the room and pointed at you.");
				preEnter();
				clearBottom();
				printf("\nCloaked Figure:\"I only exist in the realm of the monsters, I have walked a long");
				printf("\n                 road and now I am neither human nor demon. In life I bent");
				printf("\n                 everything at my will but now I have nothing because");
				printf("\n                 I couldn't decide...\"");
				preEnter();
				clearBottom();
				printf("\nCloaked Figure:\"My name is Deca\"");
				preEnter();
				printf("\nDeca:\"I desire fragments of human soul and seeing as you're a human");
				printf("\n       yourself I'd like to help shape your soul and personality but at");
				printf("\n       a cost...\"");
				preEnter();
		}
		if(demonKind == false)	
		{	
			while(done == false)
			{
				doneB = false;
				clearBottom();
				printf("\nDeca:\"Hello... How can I help you?\"");
				switch(options("","Change your spirit","Ask about spirit","Exit","",3,0,23))
				{
					case 1:
					clearBottom();
					while(doneB == false)
					{
						setCursor(0,21);
						printf(" Light:%d + %d = %d",good,adder1,good+adder1);
						printf("\n Darkness: %d + %d = %d",evil,adder2,evil+adder2);
						printf("\n Neutrality:%d + %d = %d",neutrala,adder3,neutrala+adder3);
						printf("\nPersonality: ");
						switch(alignmentCheck())
						{
							case bright:
							printf("Bright");	
							break;
							case optimist:
							printf("Optimist");
							break;
							case complex:
							printf("Complex");
							break;
							case harsh:
							printf("Harsh");	
							break;
							case mysterious:
							printf("Mysterious");	
							break;
							case mysteriousCar:
							printf("Mysterious Caring");
							break;
							case unknown:
							printf("Unknown");
							break;
						}
						printf("\nSelect which part of you do you want to increase?\n(Press Escape to Quit, Press Enter to Confirm)");
						printAt('>',0,y);
						switch(getch())
						{
							case 72:
							if(y != 21)
								y = y - 1;
							break;
							case 75: // left
							switch(y)
							{
								case 21:
								if(adder1 != 0)
								{
									adder1--;	
									price = price - 40;
								}
								break;
								case 22:
								if(adder2 != 0)
								{
									adder2--;	
									price = price - 40;
								}
								break;
								case 23:
								if(adder3 != 0)
								{
									adder3--;
									price = price - 40;
								}
								break;
							}	
							break;
							case 80:
							if(y != 23)
								y = y + 1;
							break;
							case 77: // right
							switch(y)
							{
								case 21:
								adder1++;	
								break;
								case 22:
								adder2++;	
								break;
								case 23:
								adder3++;
								break;
							}
							price = price + 40;
							break;
							case 13: // enter
							clearBottom();
							setCursor(0,21);
							printf("Deca:\"With this change... The price would be $%d...\"",price);
							switch(options("Pay this amount...?","Yes","No","","",2,0,22))
							{
								case 1:
								if(money >= price)
								{
									doneB = true;
									money = money - price;
									clearBottom();
									printf("\nYou feel... Different...");
									preEnter();
									evil = evil + 2;
								}
								else
								{
									printf("\nDeca:\"You don't have enough money...\"");
									preEnter();
									clearBottom();
								}
								break;
								case 2:
								clearBottom();
								break;
							}
							break;
							case 27:
							doneB = true;
							break;
						}
					}
					break;
					case 2:
					clearBottom();
					printf("\nDeca:\"Your spirit is your characteristic, essentially your");
					printf("\n       persona. For us stone creations this persona can");
					printf("\n       change our destiny so that's why I'm offering my");
					printf("\n       services but there could be effects...\"");
					preEnter();
					break;
					case 3:
					done = true;
					break;
				}	
			}
			clearBottom();
		}
		else
		{
			printf("\nNo one is here...");
		}
		break;
	}
	runAwa:
	timee = timee + 1;
	printf("\nYou went back to the pub...");
	preEnter();
	system("cls");
	printPattern(PUB,80,20);
}

void dreaming() // used for generating dreams
{
	srand((unsigned)time(NULL));
	
	system("cls");
	switch(rand()%6+1)
	{
		case 1:
		switch(alignmentCheck())
		{
			case 1: // bright
			printf("\nYou had a dream that you were a shining paladin");
			printf("\nfalling in an infinte black hole of screams");
			break;
			case 2: // optimist
			printf("\nYou had a dream that the world burned slowly.");
			printf("\nYou tried to clean everything up but soon you disappeared.");
			break;
			case 3: // complex
			printf("\nYou had a dream that you were from an ancient village where");
			printf("\neveryone called you Twilight.");
			break;
			case 4: // harsh
			printf("\nYou had a dream that thousands of hands were grabbing");
			printf("\nat you..?");
			break;
			case 5: // mysterious caring
			printf("\nYou didn't have a dream");
			break;
			case 6: // mysterious
			printf("\nYou didn't have a dream but you remember the name Twilight");
			break;
			case 7: // unknown
			printf("\nYou dreamt of a world where you did not exist, how did they feel?");
			break;
		}	
		break;
		case 2:
		switch(alignmentCheck())
		{
			case 1: // bright
			printf("\nYou had a dream where you split into two halfs, one good");
			printf("\nand one evil");
			break;
			case 2: // optimist
			printf("\nYou had a dream where everyone loved you but soon you faded");
			break;
			case 3: // complex
			printf("\nYou wish you didn't have the dream you just had");
			printf("\nbut you don't remember what it was about...");
			break;
			case 4: // harsh
			printf("\nYou had a dream where you bossed everyone around");
			break;
			case 5: // mysterious caring
			printf("\nYou had a dream where you were dropped off in the");
			printf("\nmiddle of a desert and lived in a strange tall");
			printf("\nbuilding called an \"apartment\"");
			break;
			case 6: // mysterious
			printf("\nYou had a dream about a hallway");
			break;
			case 7: // unknown
			printf("\nYou had a dream of white");
			break;
		}
		break;
		case 3:
		switch(alignmentCheck())
		{
			case 1: // bright
			printf("\nYou had a dream that you were a small");
			printf("\nboy who wore strange armour and walked");
			printf("\ninto a castle beyond the horizon");
			break;
			case 2: // optimist
			printf("\nYou had a dream where you felt nothing");
			break;
			case 3: // complex
			printf("\nYou had a dream where you lost all your weapons");
			printf("\nYou did lose all your weapons...?");
			break;
			case 4: // harsh
			printf("\nYou had a dream that you fought a man who protected");
			printf("\nthe twilight of the planet and absorbed your soul");
			break;
			case 5: // mysterious caring
			printf("\nYou had a dream that you were selling cookies");
			break;
			case 6: // mysterious
			printf("\nYou had a dream that you were solving a murder case");
			printf("\nin a strange town and your \"uncle\" helped you");
			break;
			case 7: // unknown
			printf("\nYou had a dream that the sun and moon became");
			printf("\neyes and they started rolling their eyes at you");
			break;
		}
		break;
		case 4:
		printf("\nYou had a dream about an old scientist");
		printf("\nYou didn't feel well when you woke up");
		break;
		case 5:
		printf("\nYou didn't have a dream");
		break;
		case 6:
		printf("\nYou had a dream about walking around in darkness");
		break;
	}	
	preEnter();
}	

bool garlandInParty() // is garland in the party?
{
	int x =0;
	for(x=0;x<20;x++)
	{
		if(partyMemberHere(x) == true)
		{
			if(strcmp(inbox[x].data,"Garland") == 0)
			{
				return true;
			}
		}
	}
	return false;
}

bool eveliaInParty() // is evelia in the party?
{
	int x =0;
	for(x=0;x<20;x++)
	{
		if(partyMemberHere(x) == true)
		{
			if(strcmp(inbox[x].data,"Evelia") == 0)
			{
				return true;
			}
		}
	}
	return false;
}

bool diantraInParty() // is diantra in the party?
{
	int x =0;
	for(x=0;x<20;x++)
	{
		if(partyMemberHere(x) == true)
		{
			if(strcmp(inbox[x].data,"Diantra") == 0)
			{
				return true;
			}
		}
	}
	return false;
}

bool kageInParty() // is kage in the party?
{
	int x =0;
	for(x=0;x<20;x++)
	{
		if(partyMemberHere(x) == true)
		{
			if(strcmp(inbox[x].data,"Kage") == 0)
			{
				return true;
			}
		}
	}
	return false;
}

bool gilgahinInParty() // is gilgahin in the party?
{
	int x =0;
	for(x=0;x<20;x++)
	{
		if(partyMemberHere(x) == true)
		{
			if(strcmp(inbox[x].data,"Gilgahin") == 0)
			{
				return true;
			}
		}
	}
	return false;
}

bool drakeInParty() // is drake in the party?
{
	int x =0;
	for(x=0;x<20;x++)
	{
		if(partyMemberHere(x) == true)
		{
			if(strcmp(inbox[x].data,"Drake") == 0)
			{
				return true;
			}
		}
	}
	return false;
}

bool sarahInParty() // is sarah in the party?
{
	int x =0;
	for(x=0;x<20;x++)
	{
		if(partyMemberHere(x) == true)
		{
			if(strcmp(inbox[x].data,"Sarah") == 0)
			{
				return true;
			}
		}
	}
	return false;
}

void getFortune() // generates fortune for the day
{
	system("cls");
	srand((unsigned)time(NULL));
	fortune = rand()%12;
	printf("\nYour fortune for the day is...");
	endingUsed = false;
	switch(fortune)
	{
		case 0:
		printf("\nTHE SUN");
		if(alignmentCheck() == bright || alignmentCheck() == optimist)
		{
			printf("\nYour personality echoes this... You feel stronger");
			defense = defense + 1;
		}
		else if(alignmentCheck() == harsh || alignmentCheck() == complex)
		{
			printf("\nYour personality doesn't echo this... What will happen?");
		}	
		else
		{
			printf("\nObeying commands will lead you down an easy route");
		}
		break;
		case 1:
		printf("\nOPENING");
		printf("\nStart something new");
		break;
		case 2:
		printf("\nACTION");
		printf("\nTake action today");
		break;
		case 3:
		printf("\nCLIMAX");
		maxHealth = maxHealth + 1;
		printf("\nThe journey is going to get harder");
		printf("\nYour max health has increased by 1");
		break;
		case 4:
		printf("\nTHOUGHT");
		printf("\nDetermine what is right");
		break;
		case 5:
		printf("\nREMINISCE");
		printf("\nLook back, who are you?");
		money = money + sparedFoes;
		break;
		case 6:
		printf("\nTWILIGHT");
		if(alignmentCheck() == mysteriousCar || alignmentCheck() == mysterious || alignmentCheck() == unknown)
		{
			printf("\nYour personality echoes this... You feel stronger");
			defense = defense + 1;
		}
		else
		{
			printf("\nYou must find balance between light and darkness...");
			printf("\nIf you continue down your path the world will change...");
		}
		break;
		case 7:
		printf("\nJOURNEY");
		printf("\nDecide on a path");
		break;
		case 8:
		printf("\nFREEDOM");
		printf("\nDo what you want to do");
		break;
		case 9:
		printf("\nPAUSE");
		printf("\nTake time to discover what's around you...");
		break;
		case 10:
		printf("\nREALIZATION");
		agility = agility + 1;
		printf("\nYou must explore... Learn more");
		break;
		case 11:
		printf("\nENDING");
		printf("\nYou can live once more if you die...");
		break;
		case 12:
		printf("\nTHE MOON");
		if(alignmentCheck() == bright || alignmentCheck() == optimist)
		{
			printf("\nYour personality doesn't echo this... What will happen?");
		}
		else if(alignmentCheck() == harsh || alignmentCheck() == complex)
		{
			printf("\nYour personality echoes this... You feel stronger");
			defense = defense + 1;
		}	
		else
		{
			printf("\nFollow your heart in what is right and spread darkness");
		}
		break;
	}
	preEnter();
}

int sleep() // when the player goes to sleep
{
	restoreHealth();
	system("cls");
	timee = 6;
	day = day + 1;
	saveFile();
	dreaming();
	system("cls");
	getFortune();
	system("cls");
	peopleSetting();
}

void printPlayer() // prints the layout
{
	int x;
	int y;
	int pep;
	int loopy;
	for(x=0;x<40;x++)
	{
		printString("||",60,x);
		if(x%10 == 0)
		{
			for(y=0;y<18;y++)
			{
				printAt('-',61+y,x);
			}
		}
	}
	printAt('|',60,40);
	for(y=0;y<18;y++)
	{
		printAt('-',61+y,40);
	}
	
	for(x = 0;x<16;x++)
		printAt('-',x,7);
	for(x = 0;x<16;x++)
		printAt('-',x,0);
	for(y = 1;y<24;y++)
		printAt('|',15,y);
	for(y = 1;y<40;y++)
		printAt('|',0,y);
	for(x = 0;x<60;x++)
		printAt('-',x,39);
		
	for(x=1;x<60;x++) // box
	{
		printAt('-',x,24);
	}
	
}

void allSeen() // sets all seenTile pieces to 1
{
	int x;
	int y;
	for(y=0;y<12;y++)
	{
		for(x=0;x<12;x++)
		{
			seenTiles[y][x] = 1;
		}
	}
}

void allSeen2() // sets all seenTile2 pieces to 1
{
	int x;
	int y;
	for(y=0;y<21;y++)
	{
		for(x=0;x<21;x++)
		{
			seenTiles2[y][x] = 1;
		}
	}
}

void clearSeen2() // clears the second seenTiles array
{
	int x;
	int y;
	for(y=0;y<20;y++)
	{
		for(x=0;x<20;x++)
		{
			seenTiles2[y][x] = 0;
		}
	}
}

void clearSeen() // clears the seenTiles array
{
	int x;
	int y;
	for(y=0;y<12;y++)
	{
		for(x=0;x<12;x++)
		{
			seenTiles[y][x] = 0;
		}
	}
}	

void printDungeon(int dungeon) // prints the view of the dungeon with the input being the current dungeon and the other being the floor
{
	int flooring = floors[dungeon-1]-1;
	int x;
	int y;
	int a;
	int b;
	int value;
	
	int playerX;
	int playerY;
	
	setColor(WHITE);
	
	// print from y - 1 to 24 and x - 16 to 57
	switch(dungeon)
	{
		case 2:	
		playerY = coord2[1];
		playerX = coord2[0];
		for(y=-1;y<21;y++)
		{
			for(x=-1;x<21;x++)
			{
				if(seenTiles2[y][x] == 1 || ((x == playerX-1 || x == playerX || x == playerX+1) && (y == playerY - 1 || y == playerY || y == playerY + 1))) // checks if the spot has been seen or is near the player to print
				{
					seenTiles2[y][x] = 1;	
					if(x == playerX && y == playerY)
					{
						
					}	
					else if((x<0 || x > 19 || y < 0 || y > 19))
					{
						setColor(DARK_YELLOW);
						printAt(219,x+28,y+2);
					}
					else if(d2[floors[1]-1][y][x] == 1)
					{	
						setColor(DARK_YELLOW);
						printAt(219,x+28,y+2);
					}
					else if(d2[floors[1]-1][y][x] == 2 || d2[floors[0]-1][y][x] == 3)
					{
						setColor(DARK_RED);
						printAt(220,x+28,y+2);
					}
					else if(d2[floors[1]-1][y][x] == 3)
					{
						setColor(5);
						printAt(220,x+28,y+2);
					}
					else if(d2[floors[1]-1][y][x] == 4)
					{
						printAt(233,x+28,y+2);
					}
					else if(d2[floors[1]-1][y][x] == 5)
					{
						printAt(237,x+28,y+2);
					}
					else if(d2[floors[1]-1][y][x] == 6 || d2[floors[1]-1][y][x] == A || d2[floors[1]-1][y][x] == B || d2[floors[1]-1][y][x] == C || d2[floors[1]-1][y][x] == D || d2[floors[1]-1][y][x] == E || d2[floors[1]-1][y][x] == F || d2[floors[1]-1][y][x] == G)
					{
						switch(d2[floors[1]-1][y][x])
						{
							case A:
							setColor(YELLOW);
							break;
							case B:
							setColor(SILVER);
							break;
							case C:
							setColor(BABY_BLUE);
							break;
							case D:
							setColor(BLUE);
							break;
							case E:
							setColor(DARK_RED);
							break;
							case F:
							setColor(DARK_GREEN);
							break;
							case G:
							setColor(GREEN);
							break;
						}
						printAt(1,x+28,y+2);
						setColor(WHITE);
					}
					else if(d2[floors[1]-1][y][x] == 7)
					{
						printAt(1,x+28,y+2);
					}
					else if(d2[floors[1]-1][y][x] == 8 || d2[floors[1]-1][y][x] == 17 || d2[floors[1]-1][y][x] == 18 || d2[floors[1]-1][y][x] == 19 || d2[floors[1]-1][y][x] == 20 || d2[floors[1]-1][y][x] == 21)
					{
						printAt(234,x+28,y+2);
					}
					else if(d2[floors[1]-1][y][x] == 7)
					{
						printAt(154,x+28,y+2);
					}
					else if(d2[floors[1]-1][y][x] == 9)
					{
						printAt(206,x+28,y+2);
					}
					else
						printAt(178,x+28,y+2);
					setColor(WHITE);
				}
			}
		}
		break;
		case 1:
		playerY = coord1[1];
		playerX = coord1[0];
		for(y=-1;y<11;y++)
		{
			for(x=-1;x<11;x++)
			{
				if(seenTiles[y][x] == 1 || ((x == playerX-1 || x == playerX || x == playerX+1) && (y == playerY - 1 || y == playerY || y == playerY + 1))) // checks if the spot has been seen or is near the player to print
				{
					seenTiles[y][x] = 1;	
					if(x == playerX && y == playerY)
					{
						
					}	
					else if((x<0 || x > 9 || y < 0 || y > 9))
					{
						setColor(DARK_BLUE);
						printAt(219,x+32,y+10);
					}
					else if(d1[floors[0]-1][y][x] == 1)
					{	
						setColor(DARK_BLUE);
						printAt(219,x+32,y+10);
					}
					else if(d1[floors[0]-1][y][x] == 2 || d1[floors[0]-1][y][x] == 3)
					{
						switch(d1[floors[0]-1][y][x])
						{
							case 2:
							setColor(DARK_RED);
							break;
							case 3:
							setColor(5);
							break;
						}
						printAt(220,x+32,y+10);
					}
					else if(d1[floors[0]-1][y][x] == 4)
					{
						printAt(233,x+32,y+10);
					}
					else if(d1[floors[0]-1][y][x] == 5)
					{
						printAt(237,x+32,y+10);
					}
					else if(d1[floors[0]-1][y][x] == 6 || d1[floors[0]-1][y][x] == A || d1[floors[0]-1][y][x] == B || d1[floors[0]-1][y][x] == C || d1[floors[0]-1][y][x] == D || d1[floors[0]-1][y][x] == E || d1[floors[0]-1][y][x] == F || d1[floors[0]-1][y][x] == G)
					{
						switch(d1[floors[0]-1][y][x])
						{
							case A:
							setColor(YELLOW);
							break;
							case B:
							setColor(SILVER);
							break;
							case C:
							setColor(BABY_BLUE);
							break;
							case D:
							setColor(BLUE);
							break;
							case E:
							setColor(DARK_RED);
							break;
							case F:
							setColor(DARK_GREEN);
							break;
							case G:
							setColor(GREEN);
							break;
						}
						printAt(1,x+32,y+10);
						setColor(WHITE);
					}
					else if(d1[floors[0]-1][y][x] == 7)
					{
						printAt(1,x+32,y+10);
					}
					else if(d1[floors[0]-1][y][x] == 8 || d1[floors[0]-1][y][x] == 17 || d1[floors[0]-1][y][x] == 18 || d1[floors[0]-1][y][x] == 19 || d1[floors[0]-1][y][x] == 20 || d1[floors[0]-1][y][x] == 21)
					{
						printAt(234,x+32,y+10);
					}
					else if(d1[floors[0]-1][y][x] == 7)
					{
						printAt(154,x+32,y+10);
					}
					else if(d1[floors[0]-1][y][x] == 9)
					{
						printAt(206,x+32,y+10);
					}
					else
						printAt(178,x+32,y+10);
					setColor(WHITE);
				}
			}
		}
		break;
	}
	setColor(WHITE);
}

void printInfo() // prints the party information
{
	int x;
	int y;
	int pep;
	int loopy;
	printString(name,65,4);
	setCursor(65,5);
	printf("%d/%d",health,maxHealth);
	for(loopy =0;loopy<3;loopy++)
	{
		if(partyMemberHere(loopy))
		{
			pep = party[loopy];
			printString(inbox[pep].data,65,5+((loopy+1)*9));	
			setCursor(65,(4+(loopy+1)*9)+2);
			printf("%d/%d",inbox[pep].health,inbox[pep].maxHP);
		}	
	}
}

int printEncounter(int pacing, int maxer) // prints the encounter rate bar on the top left and returns when a battle starts
{
	int x;
	int y;
	srand((unsigned)time(NULL));
	printString("Encounter",2,3);
	setCursor(5,4);
	printf("%d/%d",pacing,maxer);
	if(level < 3)
	{
		if(fortune == 9)
			return 2;
		return rand()%5+1;
	}
	else
	{
		return 1;
	}
}

void printCondition(int dun, int mer) // prints the description of what is happening in the dungeon based off the current tile
{
	srand((unsigned)time(NULL));
	
	int f = floors[mer] - 1;
	int y;
	int x;
	int loop;
	int loopx;
	int mag;
	
	clearMiddle();
	
	y = coord1[1];
	x = coord1[0];
	setCursor(1,25);
	if(partyCount() > 0)
	{
		for(loop=0;loop<partyCount();loop++)	
		{
			setCursor(1,26+loop);
			mag = party[loop];
			if(inbox[mag].health > 0)
			{
				switch(inbox[mag].personality)
				{
					case happy:
					switch(rand()%4+1)
					{
						case 1:	
						printf("%s is humming to themselves",inbox[mag].data);
						break;
						case 2:
						printf("%s is smiling",inbox[mag].data);
						break;
						case 3:
						printf("%s:\"I wonder where we're going\"",inbox[mag].data);	
						break;
						case 4:
						printf("%s is skipping around",inbox[mag].data);	
						break;
					}
					break;
					case sad:
					switch(rand()%4+1)
					{
						case 1:
						printf("%s slowly walks behind you",inbox[mag].data);
						break;
						case 2:
						printf("%s sighs",inbox[mag].data);	
						break;
						case 3:
						printf("%s:\"What even are we doing here..?\"",inbox[mag].data);	
						break;
						case 4:
						printf("%s sniffs a bit",inbox[mag].data);	
						break;
					}
					break;
					case angry:
					switch(rand()%4+1)
					{
						case 1:
						printf("%s is making punching noises",inbox[mag].data);	
						break;
						case 2:
						printf("%s stomped behind you",inbox[mag].data);	
						break;
						case 3:
						printf("%s:\"Come on lets fight!!\"",inbox[mag].data);	
						break;
						case 4:
						printf("%s kicks at the ground",inbox[mag].data);	
						break;
					}
					break;
					case neutral:
					switch(rand()%4+1)
					{
						case 1:
						printf("%s quietly watches you",inbox[mag].data);	
						break;
						case 2:
						printf("%s follows behind you slowly",inbox[mag].data);	
						break;
						case 3:
						printf("%s:\"Get ready for a fight\"",inbox[mag].data);	
						break;
						case 4:
						printf("%s looks around",inbox[mag].data);	
						break;
					}
					break;
					case bossy:
					switch(rand()%4+1)
					{
						case 1:
						printf("%s:\"Why can't I lead?!\"",inbox[mag].data);
						break;
						case 2:
						printf("%s is mumbling to themselves",inbox[mag].data);	
						break;
						case 3:
						printf("%s watches you suspiciously",inbox[mag].data);	
						break;
						case 4:
						printf("%s laughs for some reason",inbox[mag].data);	
						break;
					}
					break;
					case lonely:
					switch(rand()%2+1)
					{
						case 1:
						printf("%s follows you closely",inbox[mag].data);	
						break;
						case 2:
						printf("%s prepares for enemy encounters",inbox[mag].data);	
						break;
					}
					break;
					case boss1:
					break;
					case boss2:
					break;
				}	
			}	
		}
	}
	setCursor(1,28);
	switch(d1[f][y][x])
	{
		case 4:
		printf("A chest, you can open it");
		setCursor(1,29);
		printf("by pressing enter");
		break;
		case 5:
		printf("An opened chest is here");
		break;
		case 6:
		break;
		case 7:
		break;
		case 8:
		break;
		case 9:
		printf("A hole in the wall, you can enter");
		setCursor(1,29);
		printf("it if you press enter");
		break;
		case 28:
		printf("A cold shower is here,");
		setCursor(1,29);
		printf("press enter to heal yourself");	
		break;
		default:
		printString("                          	    ",1,28);
		printString("                          	    ",1,29);
		break;
	}
	if(valueNearby(currentLocation,A) == true)
	{
		setCursor(1,34);
		switch(currentLocation)
		{
			case 1:
			switch(floors[0])
			{
				case 1:
				printf("A cloaked figure watches you...");
				break;
				case 4:
				printf("A young girl is here...");
				break;
				case 6:
				if(talkedWith[1][0] == false)
				{	
					printf("An armoured man is here...");
				}
				else
				{
					printf("An armoured statue is here?");
				}
				break;
				case 7:
				printf("An old man is here...");
				break;
				case 8:
				printf("A black knight is here...");
				break;
				case 9:
				printf("A woman is sitting here...");
				break;
			}
			break;
		}
		setCursor(1,35);
		printf("Press Enter to talk with them");
	}
	else if(valueNearby(currentLocation,B) == true)
	{
		setCursor(1,34);
		switch(currentLocation)
		{
			case 1:
			if(d1[floors[0]-1][coord1[1]][coord1[0]] == 0)
			{	
				switch(floors[0])
				{
					case 2:
					printf("A young man is here...");
					break;
					case 3:
					if(talkedWith[5][0] == false)
						printf("A young boy is here...");
					else
						printf("A strange painting is here...");
					break;
					case 4:
					printf("A white knight is here...");	
					break;
				}
			}
			setCursor(1,35);
			printf("Press Enter to talk with them");
			break;
		}
	}
	else if(valueNearby(currentLocation,C) == true)
	{
		setCursor(1,34);
		switch(currentLocation)
		{
			case 1:
			switch(floors[0])
			{
				case 1:
				printf("A very tall knight is here...");	
				break;
			}
			break;
		}
		setCursor(1,35);
		printf("Press Enter to talk with them");
	}
	else if(valueNearby(currentLocation,D) == true)
	{
		setCursor(1,34);
		switch(currentLocation)
		{
			case 1:
			switch(floors[0])
			{
				case 1:
				printf("A young woman is here...");
				break;
			}
			break;
		}
		setCursor(1,35);
		printf("Press Enter to talk with them");
	}
	else
	{
	}
}

void replaceFloor1(int x,int y) // for when the player moves and a texture needs to be updated for the first dungeon
{
	if(d1[floors[0]-1][y][x] == 1)
		printAt(219,x+32,y+10);
	else if(d1[floors[0]-1][y][x] == 2)
		printAt(220,x+32,y+10);
	else
		printAt(178,x+32,y+10);
}

void replaceFloor2(int x,int y) // for when the player moves and a texture needs to be updated for the first dungeon
{	
	if(d2[floors[1]-1][y][x] == 1)
		printAt(219,x+28,y+2);
	else if(d2[floors[1]-1][y][x] == 2)
		printAt(220,x+28,y+2);
	else
		printAt(178,x+28,y+2);
}

void printSideBar(int dun) // prints the sidebar
{
	setCursor(1,10);
	if(dun == 100)
	{
		printf("You are");
		setCursor(1,11);
		printf("in a dream");
	}
	else
	{
		if(floors[dun] < 10)
			printf("Floor:0%d",floors[dun]);
		else	
			printf("Floor:%d",floors[dun]);
		setCursor(1,11);
		printf("Ammo:%d",ammunition);
		setCursor(1,13);
		printf("Fortune:");
		setCursor(1,14);
		switch(fortune)
		{
			case 0:
			printf("Sun");	
			break;
			case 1:
			printf("Opening");
			break;
			case 2:
			printf("Action");
			break;
			case 3:
			printf("Climax");
			break;
			case 4:
			printf("Thought");
			break;
			case 5:
			printf("Reminisce");
			break;
			case 6:
			printf("Twilight");
			break;
			case 7:
			printf("Journey");
			break;
			case 8:
			printf("Freedom");
			break; 
			case 9:
			printf("Pause");
			break;
			case 10:
			printf("Realize");
			break;
			case 11:
			printf("Ending");
			break;
			case 12:
			printf("Moon");
			break;
		}
		setCursor(1,18);
		printf("Day:%d",day+1);
	}
}

void clearScreener() // clears the screen when the player gets to a new floor
{
	int y,x;
	
	for(y=0;y<10;y++)
	{
		for(x=0;x<10;x++)
		{
			printAt(' ',x+32,y+10);
		}	
	}
}

void clearMiddle() // clears the middle dungeon conditions
{
	int y;
	
	for(y=25;y<39;y++)
	{
		for(x=1;x<59;x++)
			printAt(' ',x,y);
	}
}

bool bossNearby(int dun) // checks if the boss is near the player
{
	int y = 0;
	int x =0;
	
	switch(dun)
	{
		case 1:
		x = coord1[0];
		y = coord1[1];
		if(d1[floors[0]-1][y][x+1] == 7 || d1[floors[0]-1][y][x-1] == 7 || d1[floors[0]-1][y-1][x-1] == 7 || d1[floors[0]-1][y+1][x+1] == 7 || d1[floors[0]-1][y+1][x] == 7 || d1[floors[0]-1][y-1][x] == 7)
		{
			return true;
		}
		break;
	}
	return false;
}

bool valueNearby(int dun, int val) // checks if an npc is nearby depending on the val
{
	int y = 0;
	int x = 0;
	
	switch(dun)
	{
		case 1:
		x = coord1[0];
		y = coord1[1];
		if((d1[floors[0]-1][y][x+1] == val && x+1 <= 10)|| (d1[floors[0]-1][y][x-1] == val && x-1 >= 0) || (d1[floors[0]-1][y+1][x] == val && y+1 <= 10) || (d1[floors[0]-1][y-1][x] == val && y-1 >= 0))
		{
		 	return true;
		}
		break;
	}
	return false;
}

void gilaMonologue()
{
	int deleting = 0;
		
	system("cls");
	printf("\nGila:\"Okay... You see I was hired to guard");
	printf("\n       this section by the higher ups of another");
	printf("\n       section. I'm a prisoner here as well.\"");
	preEnter();
	system("cls");
	if(alignmentCheck() == harsh || alignmentCheck() == complex)	
	{
		printf("\nGila:\"I think maybe we could work well together,");
		printf("\n       I still have some of my strength left but");
		printf("\n       know that I may be a target from mercenaries\"");
		switch(options("Let Gila join you?","Yes","No","","",2,0,7))
		{
			case 1:
			system("cls");	
			if(inboxFull() == true)
			{
				printf("\nGila:\"Well dang you have too many members, I");
				printf("\n       guess I'll have to delete one for you HAAA\"");
				while(inbox[deleting].humanPerson == true)
				{
					deleting = rand()%20+1;
				}
				preEnter();
				printf("Gila deleted %s!",inbox[deleting].data);
				preEnter();
				deleteMember(deleting);
			}	
			addHuman("Gila",95,95,13,10,10,5,10,900,boss1,axe,lance);
			printf("Gila joined the party...");
			preEnter();
			break;
			case 2:
			system("cls");
			printf("\nGila:\"Ugh fine then\"");
			preEnter();
			break;
		}
	}
	else
	{
		system("cls");
		printf("\nGila:\"Be careful as you're going through this");
		printf("\n       dungeon, the group that hired me wants to");
		printf("\n       maintain some sort of order here in the Scilo");
		preEnter();
		printf("\nGila:\"You should go... I'm gonna stay here and heal,");
		printf("\n       maybe we'll run into each other if the guys who");
		printf("\n       hired me don't try to end me...\"");
		preEnter();
	}
}

void chapterFinish1()  // when the player finishes chapter 1
{
	int x;
	
	system("cls");
	setCursor(0,0);
	printf("Gila fell to the ground revealing a\ndoorway behind him that he was blocking\n");
	switch(options("What will you do?","Go through the door","Interrogate Gila","Finish off Gila","",3,0,5))
	{
		case 1:
		neutrala = neutrala + 2;	
		system("cls");
		printf("You left Gila behind and started heading\ntowards the door.");
		preEnter();
		system("cls");
		printf("Gila:\"Wait! I have to tell you something!\"");
		switch(options("Listen to Gila?","Yes","No","","",2,0,3))
		{
			case 1:
			system("cls");
			printf("You stopped and listened to Gila");
			preEnter();
			gilaMonologue();
			break;
			case 2:
			evil = evil + 5;
			system("cls");
			printf("\nYou ignored Gila and walked through the doorway");
			gilaSpare = true;
			preEnter();	
			break;
		}
		break;
		case 2:
		system("cls");
		printf("You walked over to Gila");
		preEnter();
		printf("Gila:\"Hey! I have to tell you something!\"");
		preEnter();
		gilaMonologue();
		break;
		case 3:
		evil = evil + 1;	
		system("cls");
		printf("You walked towards Gila and got your weapon ready...");
		preEnter();
		system("cls");
		printf("Gila:\"Wait! I have to tell you something!\"");
		switch(options("Listen to Gila?","Yes","No","","",2,0,3))
		{
			case 1:
			system("cls");
			printf("You stopped and listened to Gila");
			preEnter();
			gilaMonologue();
			system("cls");
			if(gilaInParty() != true)
			{
				printf("Will you still finish off Gila...?");
				switch(options("","Yes","No","","",2,0,3))
				{
					case 1:
					break;
					case 2:
					evil = evil + 5;
					gilaSpare = false;
					system("cls");
					evil = evil + 10;
					printf("\nGila:\"WAIT WHAT ARE YOU DOING?\"");
					preEnter();
					printf("\nYou took your weapon and finished him off...");
					preEnter();
					printf("\nYou decided to go through the doorway...");
					preEnter();
					break;
				}
			}
			break;
			case 2:
			gilaSpare = false;
			system("cls");
			evil = evil + 10;
			printf("\nYou ignored Gila and finished him off...");
			preEnter();
			printf("\nYou decided to go through the doorway...");
			preEnter();
			break;
		}	
		break;
	}
	system("cls");
	printf("\nWhen you walked through the other side, you");
	printf("\nnoticed that the building material was similar");
	printf("\nto the previous section you were in but there was");
	printf("\na bit more polish to it...");
	preEnter();
	if(demoStatus == true)
	{
		system("cls");
		printf("\nThank you for playing the first chapter of Stone Crawler!");
		printf("\nIf you want you can replay it and see how your personality");
		printf("\nalters the ending of this chapter or explore! The next");
		printf("\ngame that will be released will be the full game that will");
		printf("\nalso include this chapter! Thanks for playing and I hope");
		printf("\nyou enjoyed the game.");
		preEnter();
		exit(1);
	}
	chapter = 2;
}

int dungeonInput(int dun) // gets input from the player
{
	srand((unsigned)time(NULL));
	
	int dabloons;
	int input;
	int f = floors[dun]-1;
	int y;
	int x;
	int loop;
	int ynin;
	
	yarg:
	switch(dun)
	{
		case 0:
		y = coord1[1];
		x = coord1[0];
		break;
		case 1:
		y = coord2[1];
		x = coord2[0];
		break;
		case 100:
		y = coordInfy;
		x = coordInfx;
		break;
	}
	switch(getch())
	{
		case 224:
		goto yarg;	
		break;
		case 109: // 'm'
		system("cls");
		menu();
		system("cls");
		printPlayer();
		break;
		case 72: //up
		switch(dun)
		{
			case 0:
			if(d1[f][y-1][x] != 1 && y != 0 && d1[f][y-1][x] != A && d1[f][y-1][x] != B && d1[f][y-1][x] != C && d1[f][y-1][x] != D && d1[f][y-1][x] != E && d1[f][y-1][x] != F && d1[f][y-1][x] != G)
			{
				replaceFloor1(x,y);
				coord1[1] = coord1[1] - 1;
			}	
			break;
			case 1:
			if(d2[f][y-1][x] != 1 && y != 0 && d2[f][y-1][x] != A && d2[f][y-1][x] != B && d2[f][y-1][x] != C && d2[f][y-1][x] != D && d2[f][y-1][x] != E && d2[f][y-1][x] != F && d2[f][y-1][x] != G)
			{
				replaceFloor2(x,y);
				coord2[1] = coord2[1] - 1;
			}	
			break;
			case 100:
			if(coordInfy+1 != 0)
				coordInfy = coordInfy-1;
			break;
		}
		break;
		case 75: //left
		switch(dun)
		{
			case 0:
			if(dun == 0)
			{
				if(d1[f][y][x-1] != 1 && x != 0 && d1[f][y][x-1] != A && d1[f][y][x-1] != B && d1[f][y][x-1] != C && d1[f][y][x-1] != D && d1[f][y][x-1] != F && d1[f][y][x-1] != G && d1[f][y][x-1] != E)
				{
					replaceFloor1(x,y);
					coord1[0] = coord1[0] - 1;
				}	
			}	
			break;
			case 1:
			if(d2[f][y][x-1] != 1 && x != 0 && d2[f][y][x-1] != A && d2[f][y][x-1] != B && d2[f][y][x-1] != C && d2[f][y][x-1] != D && d2[f][y][x-1] != F && d2[f][y][x-1] != G && d2[f][y][x-1] != E)
			{
				replaceFloor2(x,y);
				coord2[0] = coord2[0] - 1;
			}	
			break;
			case 100:
			if(coordInfx-1 != 18)
				coordInfx = coordInfx - 1;
			break;
		}
		break;
		case 80: //down
		switch(dun)
		{
			case 0:
			if(dun == 0)
			{
				if(d1[f][y+1][x] != 1 && d1[f][y+1][x] != A && d1[f][y+1][x] != B && d1[f][y+1][x] != C && d1[f][y+1][x] != D && d1[f][y+1][x] != E && d1[f][y+1][x] != F && d1[f][y+1][x] != G && y != 9)
				{
					replaceFloor1(x,y);
					coord1[1] = coord1[1] + 1;
				}	
			}
			break;
			case 1:
			if(d2[f][y+1][x] != 1 && d2[f][y+1][x] != A && d2[f][y+1][x] != B && d2[f][y+1][x] != C && d2[f][y+1][x] != D && d2[f][y+1][x] != E && d2[f][y+1][x] != F && d2[f][y+1][x] != G && y != 19)
			{
				replaceFloor2(x,y);
				coord2[1] = coord2[1] + 1;
			}	
			break;
			case 100:
			if(coordInfy+1 != 25)
				coordInfy = coordInfy+1;
			break;
		}
		break;
		case 77: //right
		switch(dun)
		{
			case 0:
			if(dun == 0)
			{
				if(d1[f][y][x+1] != 1 && x != 9 && d1[f][y][x+1] != A && d1[f][y][x+1] != B && d1[f][y][x+1] != C && d1[f][y][x+1] != D && d1[f][y][x+1] != E && d1[f][y][x+1] != F && d1[f][y][x+1] != G)
				{
					replaceFloor1(x,y);
					coord1[0] = coord1[0] + 1;
				}	
			}
			break;
			case 1:
			if(d2[f][y][x+1] != 1 && x != 19 && d2[f][y][x+1] != A && d2[f][y][x+1] != B && d2[f][y][x+1] != C && d2[f][y][x+1] != D && d2[f][y][x+1] != E && d2[f][y][x+1] != F && d2[f][y][x+1] != G)
			{
				replaceFloor2(x,y);
				coord2[0] = coord2[0] + 1;
			}	
			break;
			case 100:
			if(coordInfx+1 != 55)
				coordInfx = coordInfx + 1;
			break;
		}
		break;
		case 13: // enter key
		if(dun == 0)
		{
			if(d1[floors[0]-1][coord1[1]][coord1[0]] == 9)
			{
				megamina();
				system("cls");
				printPlayer();
			}
			else if(d1[floors[0]-1][coord1[1]][coord1[0]] == 28)
			{
				clearMiddle();
				setCursor(1,30);
				printf("You take a cold shower... Your wounds");
				setCursor(1,31);
				printf("naturally are healed?");
				restoreHealth();
				setCursor(1,32);
				printf("Press Enter");
				getch();
			}
			else if(d1[floors[0]-1][coord1[1]][coord1[0]] == 4)
			{
				d1[floors[0]-1][coord1[1]][coord1[0]] = 5;
				for(ynin=27;ynin<32;ynin++)
				{		
					printString("                        		    ",17,ynin);
				}
				setCursor(1,30);
				printf("You opened a chest and found");
				dabloons = rand()%(level*2)+10;
				setCursor(1,31);
				printf("%d cash",dabloons);
				money = money + dabloons;
				setCursor(1,32);
				printf("Press Enter");
				getch();
			}		
			else if(valueNearby(1,A) == true)
			{
				clearMiddle();
				setCursor(1,30);
				switch(floors[0])
				{
					case 1:
					if(talkedWith[0][0] == false)
					{
						printf("Cloaked Figure:\"Ah another inmate, welcome");
						setCursor(1,31);
						printf("                 to Scilo.\"");
						setCursor(1,32);
						printf("Press Enter");
						getch();	
						clearMiddle();
						setCursor(1,30);
						printf("Cloaked Figure:\"So what got you here?\" ");
						switch(options("","\"I don't know\"","\"I stole something\"","","",2,17,31))
						{
							case 1:
							clearMiddle();
							setCursor(1,30);
							neutrala = neutrala + 3;	
							printf("Cloaked Figure:\"Ah some people don't");
							setCursor(1,31);
							printf("                 seem to remember either");
							setCursor(1,32);
							printf("                 but they're more focused");
							setCursor(1,33);
							printf("                 on surviving here now");
							setCursor(1,34);
							printf("                 than anything else.\"");
							setCursor(1,35);
							printf("Press Enter");
							getchar();
							break;
							case 2:
							evil = evil + 1;
							clearMiddle();
							setCursor(1,30);
							printf("Cloaked Figure:\"You... Stole something?");
							setCursor(1,31);
							printf("                 So you remember the world");
							setCursor(1,32);
							printf("                 too!? The outside world!");	
							setCursor(1,33);
							printf("                 How is the country!\"");
							setCursor(1,34);
							printf("Press Enter");
							getchar();
							clearMiddle();
							setCursor(1,30);
							printf("The figure calmed down");
							setCursor(1,31);
							printf("Press Enter");
							getchar();
							clearMiddle();
							break;
						}
						clearMiddle();
						setCursor(1,30);
						printf("Cloaked Figure: \"Okay I might as well help");
						setCursor(1,31);
						printf("                  you, you see in Scilo are");
						setCursor(1,32);
						printf("                  are given the ability to");
						setCursor(1,33);
						printf("                  see other spirits on some");
						setCursor(1,34);
						printf("                  other realm. We can talk");
						setCursor(1,35);
						printf("                  and recruit these spirits");
						setCursor(1,36);
						printf("                  to join us but they will");
						setCursor(1,37);
						printf("                  mostly try to hurt us...\"");
						setCursor(1,38);
						printf("Press Enter");
						getchar();
						clearMiddle();
						talkedWith[0][0] = true;	
					}
					else
					{
						setCursor(1,30);
						printf("Cloaked Figure:\"Hey if you want to");
						setCursor(1,31);
						printf("                 get out of here maybe");
						setCursor(1,32);
						printf("                 you could get rid of");
						setCursor(1,33);
						printf("                 this guy who's blocking");
						setCursor(1,34);
						printf("                 the entrance to the other");
						setCursor(1,35);
						printf("                 section of the prison.\"");
						setCursor(1,36);
						printf("Press Enter");
						getchar();
						clearMiddle();
						setCursor(1,30);
						printf("Cloaked Figure:\"He doesn't work for");
						setCursor(1,31);
						printf("                 the prison but I heard");
						setCursor(1,32);
						printf("                 he is blocking this ");
						setCursor(1,33);
						printf("                 sector because he's being");
						setCursor(1,34);
						printf("                 hired by some organization");
						setCursor(1,35);
						printf("                 in another sector.\"");
						setCursor(1,36);
						printf("Press Enter");
						getchar();
						clearMiddle();
					}
					break;
					case 4:
					printf("Young Girl:\"Hello! Nice to");
					setCursor(1,31);
					printf("             meet ya!\"");
					setCursor(1,32);
					printf("Press Enter");
					getchar();
					clearMiddle();
					break;
					case 6:
					if(talkedWith[1][0] == false && hasHired() == false)
					{
						printf("Armoured Man:\"Hello, how's the");
						setCursor(1,31);
						printf("               surviving going?\"");
						switch(options("","\"It's brutal here\"","\"It's pretty easy\"","\"Why do you care?\"","",3,17,32))
						{
							case 3:
							neutrala = neutrala + 2;
							case 1:
							clearMiddle();
							setCursor(1,30);
							printf("Armoured man:\"Ah well you");
							setCursor(1,31);
							printf("               see I'm a");
							setCursor(1,32);
							printf("               mercenary and");
							setCursor(1,33);
							printf("               I'm looking for");
							setCursor(1,34);
							printf("               $90...\"");
							switch(options("Hire the man for $90?","Yes","No","","",2,17,36))
							{
								case 1:	
								clearMiddle();
								setCursor(1,30);
								if(money >= 90)
								{
									printf("A mercenary joined you!");
									setCursor(1,31);
									printf("Press Enter");
									getchar();
									money = money - 90;
									evil = evil + 1;
									addHuman("Mercenary",20,30,5,1,1,2,10,100,hired,gun,sword);
								}
								else
								{
									setCursor(1,30);
									printf("Armoured Man:\"You don't");
									setCursor(1,31);
									printf("               have enough!\"");
									setCursor(1,32);
									printf("The man walked off");
									setCursor(1,33);
									printf("Press Enter");
									getchar();
								}	
								break;
								case 2:
								clearMiddle();
								setCursor(1,30);
								printf("Armoured Man:\"Fine then");
								setCursor(1,31);
								printf("               loser!\"");
								setCursor(1,32);
								printf("The man walked off");
								setCursor(1,33);
								printf("Press Enter");
								getchar();
								break;
							}
							break;
							case 2:
							clearMiddle();
							setCursor(1,30);
							printf("Armoured Man:\"AHH! Come on!");
							setCursor(1,31);
							printf("               If it's so easy");
							setCursor(1,32);
							printf("               for you then");
							setCursor(1,33);
							printf("               leave me alone!\"");
							setCursor(1,34);
							printf("Press Enter");
							getchar();
							break;
						}
						clearMiddle();
						talkedWith[1][0] = true;
					}
					else
					{
						setCursor(1,30);
						printf("You can't really");
						setCursor(1,31);
						printf("talk with a statue.");
						setCursor(1,34);
						printf("Press Enter");
						getchar();
					}
					break;
					case 7:
					if(talkedWith[2][0] == false)
					{
						printf("You walked over to the old");
						setCursor(1,31);
						printf("man.");
						setCursor(1,32);
						printf("Press Enter");
						getchar();
						clearMiddle();
						setCursor(1,30);
						printf("Old man:\"Hello there, how");
						setCursor(1,31);
						printf("          are you?\"");
						switch(options("","Good","Not good","I'm okay'","",3,17,32))
						{
							case 1:
							clearMiddle();
							setCursor(1,30);
							printf("Old man:\"Oh really? I'm happy for you then,");
							setCursor(1,31);
							printf("          lets hope your optimism helps others...\"");
							break;
							case 2:
							clearMiddle();
							setCursor(1,30);
							printf("Old man:\"Ah well I don't blame");
							setCursor(1,31);
							printf("          you, we're all trapped");
							setCursor(1,32);
							printf("          here...\"");
							break;
							case 3:
							clearMiddle();
							setCursor(1,30);
							printf("Old man:\"Ah okay...");	
							break;
						}
						setCursor(1,33);
						printf("Press Enter");
						getchar();
						talkedWith[2][0] = true;
					}
					else
					{
						setCursor(1,30);
						printf("Old man:\"Hey, I hope you're");
						setCursor(1,31);
						printf("          doing well...\"");
						setCursor(1,32);
						printf("Press Enter");
						getchar();
					}
					break;
					case 8:
					if(talkedWith[3][0] == false)
					{
						printf("Black Knight:\"Ah I see you're making it up the");
						setCursor(1,31);
						printf("               dungeon as well, I'm with the guild");
						setCursor(1,32);
						printf("               that's paying Gila to guard this section");
						setCursor(1,33);
						printf("               so I just wanted to see what it was like");
						setCursor(1,34);
						printf("               coming back over here.\"");
						setCursor(1,35);
						printf("Press Enter");
						getchar();
						talkedWith[3][0] = true;
					}
					else
					{
						printf("Black Knight:\"Oh hey there, good luck with");
						setCursor(1,32);
						printf("               whatever the heck you're doing\"");
						setCursor(1,33);
						printf("Press Enter");
						getchar();
					}
					break;
					case 9:
					if(talkedWith[4][0] == false)
					{
						printf("Woman:\"Hey are you trying to get out of this");
						setCursor(1,31);
						printf("        section?\"");
						switch(options("","Yes","No","Why do you care?","",3,1,33))
						{
							case 1:
							good = good + 3;	
							clearMiddle();
							setCursor(1,30);
							printf("Woman:\"Trust me, you better prepare for");
							setCursor(1,31);
							printf("        the man who's guarding this section,");
							setCursor(1,32);
							printf("        a lot of people have gone through and");
							setCursor(1,33);
							printf("        died from his lance, be safe.\"");
							break;
							case 2:
							clearMiddle();
							setCursor(1,30);
							printf("Woman:\"Ah I see, well be careful with the");
							setCursor(1,31);
							printf("        spirits out there\"");
							break;
							case 3:
							neutrala = neutrala + 3;
							clearMiddle();
							setCursor(1,30);
							printf("Woman:\"I just want to make sure you're okay,");
							setCursor(1,31);
							printf("        we all just mysteriously appeared here");
							setCursor(1,32);
							printf("        so we should stick together and find a");
							setCursor(1,33);
							printf("        way back home.\"");
							break;
						}
						setCursor(1,36);
						printf("Press Enter");
						getchar();
						talkedWith[4][0] = true;
					}
					else
					{
						printf("Woman:\"Take care of yourself\"");
						setCursor(1,36);
						printf("Press Enter");
						getchar();
					}
					break;
				}
			}
			else if(valueNearby(1,B) == true)
			{
				clearMiddle();
				setCursor(1,30);
				switch(floors[0])
				{
					case 2:
					printf("Young man:\"Hey be careful as you're going through'");
					setCursor(1,31);
					printf("            Scilo, I heard there's someone offering free");
					setCursor(1,32);
					printf("           bread but it's actually poisoned!\"");
					setCursor(1,33);
					printf("Press Enter");
					getchar();
					break;
					case 3:
					if(talkedWith[5][0] == false)
					{	
						printf("Young boy:\"Hey have you seen a young man");
						setCursor(1,31);
						printf("            ranting about bread...?\"");
						switch(options("","Yes","No","","",2,1,34))
						{
							case 1:
							clearMiddle();
							talkedWith[5][0] = true;
							switch(options("Young boy:\"Oh on what floor?\"","Floor 1","Floor 2","Floor 3","Floor 4",4,1,32))
							{
								case 2:
								good = good + 4;
								break;
								default:
								evil = evil + 4;
								break;
							}
							clearMiddle();	
							setCursor(1,30);
							printf("Young boy:\"Thanks!\"");
							setCursor(1,31);
							printf("The boy ran off");		
							setCursor(1,32);
							printf("Press Enter");
							getchar();
							break;
							case 2:
							clearMiddle();
							setCursor(1,30);
							printf("Young boy:\"Ah okay...\"");
							setCursor(1,32);
							printf("Press Enter");
							getchar();
							break;
						}
					}
					else
					{
						printf("You get closer to the painting...");
						setCursor(1,31);
						printf("Press Enter");
						getchar();
						clearMiddle();
						setCursor(1,30);
						printf("The painting is a strange symbol");
						setCursor(1,31);
						printf("that looks like a unknown language");
						setCursor(1,32);
						printf("Press Enter");
						getchar();
					}
					break;
					case 4:
					printf("White Knight:\"Traveler, stay safe and");
					setCursor(1,31);
					printf("               don't lose your humanity out");
					setCursor(1,32);
					printf("               there. I heard rumors that the");
					setCursor(1,33);
					printf("               fusion gift we humans have can be");
					setCursor(1,34);
					printf("               used to fuse with our own spirits but");
					setCursor(1,35);
					printf("               we need to stay human...\"");
					setCursor(1,36);
					printf("Press Enter");
					getchar();
					break;
				}
			}
			else if(valueNearby(1,C) == true)
			{
				clearMiddle();
				setCursor(1,30);
				if(talkedWith[6][0] == false)
				{
					talkedWith[6][0] = true;
					printf("You walk over to the tall knight");
					setCursor(1,31);
					printf("Press Enter");
					getchar();
					clearMiddle();
					setCursor(1,30);
					printf("Tall Knight:\"...\"");
					switch(options("What will you say?","\"Hey there\"","\"What are you doing?\"","\"You think you're tough?\"","",3,1,32))
					{
						case 3:
						clearMiddle();	
						evil = evil + 4;
						setCursor(1,30);
						printf("Tall Knight:\"...\"");
						setCursor(1,31);
						printf("Press Enter");
						getchar();
						talkedWith[6][0] = false;
						break;
						default:
						clearMiddle();
						good = good + 1;
						setCursor(1,30);
						printf("Tall Knight:\"Yo, I have a spare");
						setCursor(1,31);
						printf("              spirit do you want");
						setCursor(1,32);
						printf("              it?\"");	
						printf("Press Enter");
						getchar();
						break;
					}
				}
				else
				{
					printf("Tall Knight:\"Hey make sure to");
					setCursor(1,31);
					printf("              take care of Floyd...\"");
					setCursor(1,32);
					printf("Press Enter");
					getchar();
				}
			}
			else if(valueNearby(1,D) == true)
			{
				clearMiddle();
				setCursor(1,30);
				if(talkedWith[7][0] == false)
				{
					
				}
				else
				{
					
				}
			}
		}
		else if(dun == 1)
		{
			if(d2[floors[1]-1][coord2[1]][coord2[0]] == 9)
				return 1;
			else if(d2[floors[1]-1][coord2[1]][coord2[0]] == 28)
			{
				clearMiddle();
				setCursor(1,30);
				printf("You take a cold shower... Your wounds");
				setCursor(1,31);
				printf("naturally are healed?");
				restoreHealth();
				setCursor(1,32);
				printf("Press Enter");
				getch();
			}
			else if(d2[floors[1]-1][coord2[1]][coord2[0]] == 4)
			{
				d2[floors[1]-1][coord2[1]][coord2[0]] = 5;
				for(ynin=27;ynin<32;ynin++)
				{		
					printString("                        		    ",17,ynin);
				}
				setCursor(1,30);
				printf("You opened a chest and found");
				dabloons = rand()%(level*2)+10;
				setCursor(1,31);
				printf("%d cash",dabloons);
				money = money + dabloons;
				setCursor(1,32);
				printf("Press Enter");
				getch();
			}
		}
		break;
	}
	return 0;
}

void crawler1() // the first dungeon
{
	int runAwayX = 0; // for running away loop
	int runAwayY = 0;
	
	currentLocation = 1;
	
	srand((unsigned)time(NULL));
	
	bool foughtA = false; // did the player fight certain dungeon enemies?
	bool foughtB = false;
	bool foughtC = false;
	bool foughtD = false;
	
	bool getOut = false; // is the player out of the dungeon?
	int pacer = 0; // used for encounter progression
	int timetime = 0; // used to add time as the player is in the dungeon 
	
	int x,y;
	
	printPlayer();
	newFloorArea:
	clearSeen();
	clearScreener();
	if(floors[0] < maxFloors[0])
		allSeen();
	while(getOut == false)
	{
		printDungeon(1);
		if(d1[floors[0]-1][coord1[1]][coord1[0]] == 2)
		{
			foughtA = false;
			foughtB = false;
			foughtC = false;
			foughtD = false;
			setCursor(1,31);
			printf("You head upstairs");
			setCursor(1,32);
			printf("Press Enter");
			getch();
			clearScreener();
			floors[0] = floors[0] + 1;
			if(floors[0] > maxFloors[0])
				maxFloors[0] = floors[0];
			else
			{
				allSeen();
				printDungeon(1);
			}
			if(fortune == 7)
			{
				health = health + 5;
				if(health > maxHealth)
				{
					health = maxHealth;
				}
			}
			else
				goto newFloorArea;
		}
		else if(d1[floors[0]-1][coord1[1]][coord1[0]] == 3)
		{
			foughtA = false;
			foughtB = false;
			foughtC = false;
			foughtD = false;
			setCursor(1,31);
			printf("You head downstairs");
			setCursor(1,32);
			printf("Press Enter");
			getch();
			if(floors[0] > maxFloors[0]) // double checks to make sure max floor is updated
				maxFloors[0] = floors[0];
			floors[0] = floors[0] - 1;
			clearScreener();
			allSeen();
			printDungeon(1);
		}
		printAt(1,coord1[0]+32,coord1[1]+10);
		printInfo();
		printSideBar(0);
		printCondition(d1[floors[0]-1][coord1[0]][coord1[1]],0);
		if(pacer < 0)
			pacer = 0;
		pacer = pacer + printEncounter(pacer,50);
		if(pacer >= 50)
		{
			system("cls");
			battle(1);
			pacer = 0;
			system("cls");
			printDungeon(1);
			printPlayer();
		}	
		else if(dungeonInput(0) == 1)
			getOut = true;
		timetime = timetime + 1;
		if(timetime % 7 == 0)
			timee++;
		if(bossNearby(1) == true)
		{	
			pacer = 0;
			printAt(1,coord1[0]+32,coord1[1]+10);
			setCursor(1,32);
			printf("A giant knight approaches");
			setCursor(1,33);
			printf("Press Enter");
			getchar();
			system("cls");
			battle(2);	
			chapterFinish1();
			getOut = true;		
		}	
	}
}

void crawler2() // the second dungeon
{
	int pacer = 0;
	currentLocation = 2;
	srand((unsigned)time(NULL));
	
	bool getOut = false; // is the player out of the dungeon?
	printPlayer();
	newFloorAre:
	clearSeen2();
	clearScreener();
	allSeen2();
	while(getOut == false)
	{
		printDungeon(2);
		if(d2[floors[1]-1][coord2[1]][coord2[0]] == 2)
		{
			setCursor(1,31);
			printf("You head upstairs");
			setCursor(1,32);
			printf("Press Enter");
			getch();
			floors[1] = floors[1] + 1;
			if(floors[1] > maxFloors[1])
				maxFloors[1] = floors[1];
			else
			{
				clearScreener();
				allSeen2();
				printDungeon(2);
			}
			if(fortune == 7)
			{
				health = health + 5;
				if(health > maxHealth)
				{
					health = maxHealth;
				}
			}
			else
				goto newFloorAre;
		}
		else if(d2[floors[1]-1][coord2[1]][coord2[0]] == 3)
		{
			setCursor(1,31);
			printf("You head downstairs");
			setCursor(1,32);
			printf("Press Enter");
			getch();
			if(floors[1] > maxFloors[1]) // double checks to make sure max floor is updated
				maxFloors[1] = floors[1];
			floors[1] = floors[1] - 1;
			clearScreener();
			allSeen2();
			printDungeon(2);
		}
		printInfo();
		printSideBar(1);
		printCondition(d2[floors[1]-1][coord2[0]][coord2[1]],0);
		printAt(1,coord2[0]+28,coord2[1]+2);
		pacer = pacer + printEncounter(pacer,60);
		if(pacer >= 60)
		{
			system("cls");
			battle(1);
			pacer = 0;
			system("cls");
			printDungeon(2);
			printPlayer();
		}
		else if(dungeonInput(1) == 1)
			getOut = true;	
	}
}

void crawler3() // the third dungeon
{
	bool getOut = false; // is the player out of the dungeon?
	while(getOut == false)
	{
		
	}
}

void crawler4() // the fourth dungeon
{
	bool getOut = false; // is the player out of the dungeon?
	while(getOut == false)
	{
		
	}
}

void crawler5() // the fifth dungeon
{
	bool getOut = false; // is the player out of the dungeon?
	while(getOut == false)
	{
		
	}
}

void crawler6() // the sixth dungeon
{
	bool getOut = false; // is the player out of the dungeon?
	while(getOut == false)
	{
		
	}
}

void crawler7() // the seventh dungeon
{
	bool getOut = false; // is the player out of the dungeon?
	while(getOut == false)
	{
		
	}
}

void bookKeeper() // organizes what dungeon the player is on
{
	for(;;) // loops until the player saves and exits
	{	
		if(day == 0)
			introduction();
		hubby:
		switch(chapter)
		{
			case 1:
			system("cls");
			crawler1();
			case 2:
			system("cls");
			crawler2();
			case 3:
			system("cls");
			case 4:
			system("cls");
			case 5:
			system("cls");
			case 6:
			system("cls");
			case 7:
			system("cls");
			break;
		}
	}
}
