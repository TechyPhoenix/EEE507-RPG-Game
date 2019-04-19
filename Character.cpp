#include <iostream>
#include "Character.h"
#include "Item.h"

//#include "Item.h"
using namespace std;

// Here the Stats for Character are kept
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
	this->hpMax = 1;
	this->att = 1;
	this->def = 1;
	this->direction = 0;
	
	if (aggro)
	{
			this->threat = true;
	}
} 

/*void Character::generateEnemy(int, bool aggro)
{
	this->enemyX = 17;
	this->enemyY = 17;
	this->enemyXp = 20;
	this->enemyHp = 10;
	this->enemyHpMax = 10;
	this->enemyAtt = 1;
	this->enemyDir = 0;
	//this->enemyAggro = true;
}

/*void Enemy(int, bool aggro)
{
		this->enemyX = 17;
		this->enemyY = 17;
		this->enemyXp = 20;
		this->enemyHp = 10;
		this->enemyHpMax = 10;
		this->enemyAtt = 1;
		this->enemyDir = 0;
		//this->enemyAggro = true;
}*/


/*int Character::enemyTakeDamage()
{
	
	this-> enemyHp - (getAtt() + Weapon::GetDamage() );
}*/

/*int Character::playerTakeDamage()
{
	this-> hp - (getEnemyAtt() );
}*/


Character::~Character()
{

}
//Functions below
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
	this->statPoints = 0;
	this->direction = 0;
}

void Character::resetAggro(const std::string name)
{
	this->threat = true;
}

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
	{
		this->xp -= this->xpNext;
		this->level++;
		this->xp = 0;
		this->xpNext= this->level*50;
		this->hpMax = this->level*2+8;
		this->hp=hpMax;
		this->statPoints++;
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

int Character::getEnemyX()
{
	return enemyX;
}

int Character::getEnemyY()
{
	return enemyY;
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

int Character::getEnemyDir()
{
	return enemyDir;
}


// Jeremy
void Character::move()
{

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
/* void Character::takeDamage(Character & me, Character & attacking , item & weapon )
 {
	Weapon obj(int);
	

	this->hp/obj.GetDamage()
 }
 */
 
/*void main()
{
	string name;
	Character obj(name, false);
	&Character::generateCharacter;
	obj.getPlayerName();
	obj.getLevel();
	obj.getXp();
	obj.getAtt();
	obj.getDir();


	char dud;
	cin >> dud;
}
*/