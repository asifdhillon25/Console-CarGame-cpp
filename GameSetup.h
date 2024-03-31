#ifndef VEHICLE
#define VEHICLE
#include "Game.h"
using namespace std; 

class Vehicle:public Game{
	
	//****DATA MEMBERS****
	char choice;
	char Userchoice;
	
	
	
public:
	
	//****Function Prototypes****
	
	void Play();//main function from wich 
	void GameSetup();//initialize values
	void PlayGame();//run basic functions to play
	void Menu();//draw menu
	void SetChoice();//get input from user
	char GetChoice();//return input of user
	void Quit();//print outro
	void Instructions();//print instructoins
	void GameOver();//to print stats after game over
	
	
	
	
	
};


#endif//VEHICLE
