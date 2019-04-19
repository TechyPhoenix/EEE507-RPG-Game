#pragma once
#include <conio.h>
#include <sstream>
#include <vector>
#include <iostream>
#include <string>
#include "Item.h"

/**Definitions for each direction are set. These will be used later for movement*/

#define STOP 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

using namespace std;

class Character
{
	/**These functions are public and may be accessed outside of the file*/
public:
	/**This function constains the character stats when they are active*/
	void generateCharacter();
	/**The below function is the constructor and initially defines the stats*/
	Character(const std::string name, bool agro);
	/**This contains enemy stats*/
	int Character::Enemy(int, bool agro);

	virtual ~Character();

	/**This function is used for naming the player*/
	void namePlayer();
	/**Functions for getting stats*/
	int getX();
	int getY();
	string getPlayerName();
	int getLevel();
	int getXp();
	int getXpNext();
	int getHp();
	int getHpMax();
	int getAtt();
	int getDef();
	int getDir();

	/**Get Enemy Stats*/
	int getEnemyXp();
	int getEnemyHp();
	int getEnemyHpMax();
	int getEnemyAtt();
	int getEnemyDir();
	bool enemyAggro();


	/**Additional functions
	/This initialises stats which by resetting to default values
	/used for game over*/
	void resetStat(const std::string name);
	/**When played xp reaches max for level, levels up and refills health*/
	void levelUp();
	/**Used for resetting health separate from all stats*/
	void resetAggro(const std::string name);
	/**Used to print all character stats to screen*/
	void Character::printStats() const;

	void createNewCharacter();
	void createNewEnemy();
	void generateEnemy();
	void enemy();

	/**Used to define what will be used for player icon*/
	char Character::getPlayerIcon(string str);
	
	/**The set symb will set a value to a denoted value*/
	void setSymb(char symbol); /** CCreator.addEnemies(int) ->  G, R, B or Z  
	/**Used to set the new direction*/
	void setDir(int newDir);
	void takeDamage(Character & me, Character & attacking);/** parse in weapon for damage modifier*/
	void move();
	
	/**Uses variables to have the player and enemy take damage*/
	void TakeDamage(int damage);
	void Character::DealSwdDamage();
	void Character::DealPDamage();
	void Character::DealStgDamage();
	void Character::attackEnemy();

private:
	/**Below are private variables which may not be accessed
	outside of the file
	Player stats below*/
	int X;
	int Y;

	string playerName;
	int level;
	int xp;
	int xpNext;
	int hp;
	int hpMax;
	int att;
	int def;
	int direction;
	int statPoints;
	const char * playerIcon;

	/**Enemy Stats below*/
	int enemyX;
	int enemyY;
	int enemyXp;
	int enemyHp;
	int enemyHpMax;
	int enemyAtt;
	int enemyDir;
/**	bool enemyAggro; */

	char symbol; // on map
	bool threat;
	
};
