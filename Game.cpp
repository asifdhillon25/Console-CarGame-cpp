#include "Game.h"
#include <windows.h>


Game::Game()
{
	ScreenWidth=60;
	ScreenHeight=25;
	Collision=0;
	Ascii='a';
	Score=0;
	 Level=0;
	srand(time(0));
	
}

void Game::SetCursorPosition(int x, int y) {
    COORD CursorPosition;
    CursorPosition.X=x;
    CursorPosition.Y=y;
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE),CursorPosition);
}

void Game::DrawBoard() {
    
    SetAscii(122);
    for (int i = 0; i < ScreenHeight; ++i) {
		//loop for printing left border
        for (int j = 0; j < ScreenWidth/3; ++j) {
            SetCursorPosition(j,i);cout<<Ascii;

        }

		//loop ffor printing inner white space
        for (int j = 0; j < ScreenWidth ; ++j) {
                SetCursorPosition(j + 20, i );cout << ' ';

        }
		//loop for printing left border
        for (int j = 0; j < 5 ; ++j) {
            SetCursorPosition(j + 80, i );cout << Ascii;

        }
        
         for (int j = 0; j < 5 ; ++j) {
            SetCursorPosition(j + 100, i );cout << Ascii;

        }
      
    }

}

void Game::SetAscii(int x) 
{
	Ascii='a';
	Ascii+=x;
}

void Game::SetCarPosX(int x)
{
	CarPos=x;
}

int& Game:: GetCarPosX()
 {
 	return CarPos;
 }

void Game:: SetCarPosY(int y)
{
	CarY=y;
}

int &Game::GetCarPosY()
{
	return CarY;
}

void Game::DrawCar()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			 SetCursorPosition(GetCarPosX()+j,i+GetCarPosY());cout<<car[i][j];
		}
	}
}

void Game::UpdateCarPosX(char x)
{
	if(x=='a'||x=='A')
	{
		if(GetCarPosX()>20)
		GetCarPosX()-=4;
	}
	if(x=='d'||x=='D')
	{
		if(GetCarPosX()<76)
		GetCarPosX()+=4;
	}
	
}

void Game:: UpdateCarPosY(char x)
{
		if(x=='s'||x=='S')
	{
		if(GetCarPosY()<=16)
			GetCarPosY()+=4;
	}
	if(x=='w'||x=='W')
	{
		if(GetCarPosY()>=4)
			GetCarPosY()-=4;
	}
}

void Game::DrawEnemy(int ind)
{	
	if(GetEnemyY(ind)>=0)
	{
	SetCursorPosition(GetEnemyX(ind)-4,GetEnemyY(ind));cout<<"!**!";
	SetCursorPosition(GetEnemyX(ind)-4,GetEnemyY(ind)+1);cout<<" ** ";
	SetCursorPosition(GetEnemyX(ind)-4,GetEnemyY(ind)+2);cout<<" ** ";
	SetCursorPosition(GetEnemyX(ind)-4,GetEnemyY(ind)+3);cout<<" !! ";
	}
	
		
	
}

void Game::UpdateEnemy(int ind)
{
	if(GetEnemyY(ind)==ScreenHeight-5)
	{
		GetEnemyY(ind)=0;
		Score++;
		SetEnemyX(ind);
	}
	else
	{		if(GetGameLevel()==1)
				GetEnemyY(ind)+=1;
			else if(GetGameLevel()==2)
				GetEnemyY(ind)+=2;
			
	}

	
}

void Game::SetEnemyX(int ind)
{
	
	EnemyX[ind]=((1+rand()%15)*4)+20;
}

int& Game:: GetEnemyX(int ind)
 {
 	return EnemyX[ind];
 }

 
void Game:: SetEnemyY(int y,int ind)
{
	EnemyY[ind]=y;
}

int& Game:: GetEnemyY(int ind)
{
	return EnemyY[ind];
}
void Game:: inlzXY()
{
	int j=0;
	for(int i=0;i<3;i++)
	{
		SetEnemyX(i);
		
	}
	for(int i=0;i<3;i++)
	{
		
		SetEnemyY(j,i);
		j-=16;
	}
	
}

void Game:: SetCollision()
{
	if((GetEnemyX(0)-4==GetCarPosX() &&GetEnemyY(0)==GetCarPosY())||(GetEnemyX(1)-4==GetCarPosX() &&GetEnemyY(1)==GetCarPosY())||
	(GetEnemyX(2)-4==GetCarPosX() &&GetEnemyY(2)==GetCarPosY()))
		{
			Collision+=1;
			cout<<"\a";
		}
	
}

int& Game::GetCollision()
{
	return Collision;
}

int &Game:: GetScore()
{
	return Score;
}

void Game:: SetGameLevel()
{
	if(GetScore()==0)
	{
		Level=1;
	}	
	else if(GetScore()>=15)
	{
		Level=1;
	}	

		
	
}

int &Game:: GetGameLevel()
{
	return Level;
}

void Game:: PrintLives()
{
	char heart='a';
	heart+=162;
	int lives;
	cout<<3-GetCollision();
	
}

void Game:: ShowGameData()
{
	SetCursorPosition(85,5);cout<<" Score: "<<GetScore();
	SetCursorPosition(85,6);cout<<"          ";
	SetCursorPosition(85,7);cout<<" Level: "<<GetGameLevel();
	SetCursorPosition(87,10);cout<<"***Lives***";
	SetCursorPosition(91,11); PrintLives();
	SetCursorPosition(87,13); cout<<"Collision: "<<GetCollision();
}
