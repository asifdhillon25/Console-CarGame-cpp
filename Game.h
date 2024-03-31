#ifndef CAR_GAME_GAME_H
#define CAR_GAME_GAME_H
#include<iostream>
#include<conio.h>
#include<dos.h>
#include <windows.h>
#include <time.h>
#include <ctime>
using namespace std;

class Game {

	//****DATA MEMBERS****
    int ScreenWidth;
    int ScreenHeight;
    int Score;
    int Collision;
    int Level;
    int CarPos;
    int CarY;
    int EnemyPos;
    int EnemyY[3];
    int EnemyX[3];
    char Ascii;
    char car[4][4] = {{  ' ','!','!',' '},
						{'@','!','!','@'},
						{' ','!','!',' ',},
						{'@','!','!','@' }};
						
	 char Enemy[4][4] = {{'!','*','*','!'},
						 {' ','*','*',' '},
						 {' ','*','*',' ',},
						 {' ','!','!',' ' }};
						 
						
						
public:
	
	Game();//constructor
    void SetCursorPosition(int x, int y);//to move cursor on window
    void DrawBoard();//drawing game board
    void SetAscii(int x);//ascii value to print special symbols
    void DrawCar();//loop t draw car
    void SetCarPosX(int);//set car x coordinate
    int &GetCarPosX();//get car x coordinate
    void SetCarPosY(int);//set car y coordinate
    int &GetCarPosY();//get car y coordinate
    void UpdateCarPosX(char);//update car X coordinate
    void UpdateCarPosY(char);//update car Y coordinate
    void DrawEnemy(int);	//draw enemy car
    void UpdateEnemy(int ind);//update enemy position
    void SetEnemyX(int ind);//set enemy x coordinate
    int &GetEnemyX(int ind);//get enemy x coordinate
    void SetEnemyY(int y,int ind);//set enemy Y coordinate
    int &GetEnemyY(int ind);//get enemy Y coordinate
    void inlzXY();//set x and y coordinates of enemy array
    void SetCollision();//check collision with enemy 
    int& GetCollision();//get collision status
    int &GetScore();//return score
    void ShowGameData();//show score,lives ,collision
    void SetGameLevel();//claculate level
    int &GetGameLevel();//return level
    void PrintLives();//print lives
	
	
};


#endif //CAR_GAME_GAME_H

