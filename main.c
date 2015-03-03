#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>

//Setting Variables
#define active_high_enable  1; //Set to 0 to enable active_low, else active_high


//Program Variables
int MENU_POS = 0;
int binary_semaphor = 0;
#define MAX_MEN_POINTS  11
#define MAX_SUB_MEN_POINTS  5
#define DEBUG 1; //set 0 for no debug information


int main()
{

	int i = 4; //NICHT VERÄNDERN



	if (wiringPiSetup() == -!)
		return -1
	
	//GPIO 23,24,25 auf Eingang schalten
	for(;i < 6;i++)
	{
		pinMode(i,INPUT);
	}
	
	
	//in einer Dauerschleife das Menü abfragen
	while(1)
	{
	
		if(digitalReader(4) == active_high_enable)
		{

			//Entscheidung ob im Submenu oder im Hauptmenü
			printf("Countet up once!\n");
			if(binary_semaphor == 1)
			{
				if(MENU_POS <= MAX_SUB_MEN_POINTS)
				{
					MENU_POS++;
				}
				else
				{
					MENU_POS = 0;
				}
			
			}
			else
			{
				if(MENU_POS <= MAX_MEN_POINTS)
				{
					MENU_POS++;
				}
				else
				{
					MENU_POS = 0;
				}
			
			}
			
		}
	
	
		if(digitalReader(5) == active_high_enable)
		{
			//Entscheidung ob im Submenu oder im Hauptmenü
			
			printf("Counted down once!\n");
			if(binary_semaphor == 1)
			{
				if(MENU_POS > 0)
				{
					MENU_POS--;
				}
				else
				{
					MENU_POS = MAX_SUB_MEN_POINTS;
				}
			
			}
			else
			{
				if(MENU_POS > 0)
				{
					MENU_POS--;
				}
				else
				{
					MENU_POS = MAX_SUB_MEN_POINTS;
				}
			
			}
		}
	
	
		if(digitalReader(6) == active_high_enable)
		{
			//Menu Punkt entern
			if(MENU_POS == 0)
			{
				binary_semaphor = 1; //Es wurde in ein untermenü gesprungen!
			}
			
			MENU_POS = 0;
			printf("entered Menu-point %d\n", MENU_POS);
		}
	
	
	}
	
	
	














}
