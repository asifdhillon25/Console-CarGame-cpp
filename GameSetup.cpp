#include "GameSetup.h"


void Vehicle:: GameSetup()
{
	GetCollision()=0;
	GetScore()=0;
	GetGameLevel()=0;
	inlzXY();
	SetCarPosX(20);
 	SetCarPosY(20);
 	
	DrawBoard();
	DrawCar();
	

}

void Vehicle:: PlayGame()
{
	GameSetup();
	do{
		
		DrawBoard();
		DrawCar();
		DrawEnemy(0);
		DrawEnemy(1);
		DrawEnemy(2);
		
		
		
		if(kbhit())
		{	choice=getch();
			UpdateCarPosX(choice);
			UpdateCarPosY(choice);
		}
		UpdateEnemy(0);
		UpdateEnemy(1);
		UpdateEnemy(2);
		
		SetCollision();
		SetGameLevel();
		ShowGameData();
		Sleep(0);
		
		
		
	}
	while(GetCollision()<3);

}

char Vehicle::GetChoice()
{
	return Userchoice;
}

void Vehicle::SetChoice()
{
	Userchoice=getch();
}

void Vehicle:: Menu()
{
	do
	{
		 cout << "\n\n\t  Main Menu\n\n";
  	cout << "\t1: Start Game\n\n"
         << "\t2: Instructions\n\n"
         << "\t3: Quit\n\n";
    	SetChoice();
		system("cls");
	}
	while(GetChoice()<'1'||GetChoice()>'3');
	
}

void Vehicle:: GameOver()
{
	system("cls");
	cout << "\n\n\t***Game Over***\n\n"
         << "Score : "<<GetScore()<<"\n\n";
        cout<<"\n\n\tPress any key to continue.....\n";
		getch();
		system("cls");
}


void Vehicle:: Quit()
{
	cout << "\n\n\tThanks For Playing \n\n"
         << "\tMade By: Muhammad Asif\n\n"
         << "\tID: F2022266062\n\n"
         << "\tMade By: Hamza Saeed\n\n"
         << "\tID: F2022266056\n\n"
         << "\tUniversity of Management and Technology\n\n";
}

void Vehicle::Instructions()
{
	cout << "\n\n\tInstructions \n\n"
         << "\tUse 'W','A','S','D' Keys to move\n\n"
         << "\tAvoid colliding with Enemies\n\n"
         << "\tEnjoy\n\n";	
}

void Vehicle:: Play()
{	
	do
 {
	Menu();
	if(GetChoice()=='1')
	{
			PlayGame();
		GameOver();
		
	}
	else if(GetChoice()=='2')
	{
		Instructions();
		cout<<"\n\n\tPress any key to continue.....\n";
		getch();
		system("cls");
	}
	else if(GetChoice()=='3')
	{
		Quit();
	}	
  }while(GetChoice()!='3');
	
	
}
