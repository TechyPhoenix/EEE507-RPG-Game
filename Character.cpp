/** 
	This is the character stats, for both enemies and characters including all 
	stats, generation and attack damage.
	Author Cathal O'Callaghan B00669476	
	Copyright (c) [2019] [If(!Broken{don'tFixIt();}]
	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:
	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#include <iostream>
#include "Character.h"
#include "Item.h"

//#include "Item.h"
using namespace std;

// Here the Stats for Character are kept
//
void Character::generateCharacter()
{
	this->X = 10;
	this->Y = 10;

	this->playerName = "";
	this->level = 1;
	this->xp = 0;
	this->xpNext = 0;
	this->hp = 1;
	this->hpMax = 1;
	this->att = 1;
	this->def = 1;
	this->direction = 0;
	// Player Icon will be first letter of name Capitalised
	threat = true;
	playerIcon= "T";
}


//This constructs the character stats
Character::Character(std::string name, bool aggro)
{
	this->X = 10;
	this->Y = 10;
	this->playerName = name;
	this->level = 1;
	this->xp = 0;
	this->xpNext = level*50;
	this->hp = level*2+8;
	this->hpMax = level*2+8;
	this->att = 1;
	this->def = 1;
	this->direction = 0;

//If the player attacks it will trigger the aggro function
//This will cause player threat to become true
	
	if (aggro)
	{
			this->threat = true;
	}
} 

Character::~Character()
{

}
//Functions below

//This simply prints to screen and asks player for the character name
void Character::namePlayer()
{
	cout << "Name your hero... ";
	cin >> this->playerName;
}

/*char Character::getPlayerIcon(string str)
{
	string (playerName);
	str.at(1) = this->playerIcon;
}*/

//This function when run will return the character stats to their initial value
//
void Character::resetStat(const std::string name)
{
	this->playerName = "";
	this->level = 1;
	this->xp = 0;
	this->xpNext = level*50;
	this->hp = 8;
	this->hpMax = level*2+8;
	this->att = level +1;
	this->def = level +1;
	this->threat = true;
	this->direction = 0;
}

void Character::resetAggro(const std::string name)
{
	this->threat = true;
}

//This uses cout and pointers to display the value of each variable
void Character::printStats() const
{
	cout<<"Name: " << this->playerName << endl;
	cout<< "Level: " << this->level << endl;
	cout<< "Xp: " << this->xp << " / " << this->xpNext << endl;
	cout<< "Hp: " << this->hp << " / " << this->hpMax << endl;
	cout<< "Att: " << this->att << endl;
	cout<< "Stat Points: " << this->statPoints << endl;			
}

void Character::levelUp()
{

	if (this->xp >= this->xpNext)
		//When player xp reached xp next will trigger level up
	{
		this->xp -= this->xpNext;
		//triggers level to go up by one
		this->level++;
		this->xp = 0;
		//as level has increased health and xp requ will go up
		this->xpNext= this->level*50;
		this->hpMax = this->level*2+8;
		this->hp=hpMax;
		//cout display xp
		cout << "You are now level " << this->level << "!!!" << endl;
	}
}
		
string Character::getPlayerName()
{
	//cout << this->playerName << endl;
	return playerName;
	
}

int Character::getLevel()
{
	
	//cout << this->level << endl;
	return level;
}

int Character::getXp()
{
	//cout << this->xp << endl;
	return xp;
}

int Character::getXpNext()
{
	//cout << this->xpNext;
	return xpNext;
}

int Character::getX()
{
	return X;
}

int Character::getY()
{
	return Y;
}

int Character::getAtt()
{
	//cout << this->att;
	return att;
	}

int Character::getDef()
{
	return def;
}

int Character::getHp()
{
	return hp;
}

int Character::getEnemyXp()
{
	return enemyXp;
}

int Character::getEnemyHp()
{
	return enemyHp;
}

int Character::getEnemyHpMax()
{
	return enemyHpMax;
}

int Character::getEnemyAtt()
{
	return enemyAtt;
}
//The enemy direction is described as listed as in the .h file
int Character::getEnemyDir()
{
	return enemyDir;
}

void Character::move()
{
	//Makes uses of switches to change 
	//the x and y using case. Case has been defined in the .h
	switch (direction)
	{
	case UP: 
		this-> Y++;
		break;
	case DOWN:
		this -> Y--;
		break;
	case LEFT:
		this-> X--;
		break;
	case RIGHT:
		this-> X++;
		break;
	}
}

//Sets input value as the set symbol
void Character::setSymb(char symbol)
{
	this-> symbol = symbol;
}

int Character::getDir()
{
	//cout << this->direction;
	return direction;

}
 void Character::setDir(int newDir)
 {
	 newDir = this->direction ;

 }
 //This will use the following functions to cause damage to each healthbar
 void Character::TakeDamage(int damage)
 {
	
	hp-= damage;
 }
 //damage for sword, pistol and shotgun are
 //calculated by passing in Get Damage function which
 //will vary depending on the weapon used
 void Character::DealSwdDamage()
 {
	Sword bro;
	int swd=bro.GetDamage();
	TakeDamage(swd);
 }
 
 void Character::DealPDamage()
  {
	Pistol guy;
	int pis=guy.GetDamage();
	TakeDamage(pis);
  }

 void Character::DealStgDamage()
 {
	 Shotgun man;
	 int gun=man.GetDamage();
	 TakeDamage(gun);
 }
