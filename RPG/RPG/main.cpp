#include <iostream>
using namespace std;

class Player {
public:
	int lvl;
	int hp, mp;
	int damage, skilldamage, skilldamage2;
}hero;

class mobork{
public:
	int lvl;
	int hp;
	int damage;
};

class giant {
public:
	int lvl;
	int hp;
	int damage;
}gfirst, gsecond, gthird, gfourth, gfiveth;

void createorks(mobork* ork, int sizelvlorks)
{
	int setmoblvl = 1;
	double setmobhp = 100;
	double setmobdamage = 10;
	for (int i = 0; i < sizelvlorks; i++)
	{
		ork[i].lvl = setmoblvl;
		ork[i].hp = setmobhp;
		ork[i].damage = setmobdamage;
		setmoblvl++;
		setmobhp * 1.5;
		setmobdamage * 1.5;
	}
}

int main() {
	srand(time(NULL));
	const int sizelvlorks = 10;
	mobork ork[sizelvlorks] = {};
	int setlvl = 1, sethp = 500, setmp = 200, setdamage = 25, setskill1damage = 70, setskill2damage = 150;
	int colorks;
	int timestart, timeend;
	int gsetlvl = 1, gsethp = 2000, gdamage = 50;
	hero.lvl = setlvl;
	hero.hp = sethp;
	hero.mp = setmp;
	hero.damage = setdamage;
	hero.skilldamage = setskill1damage;
	hero.skilldamage2 = setskill2damage;
	colorks = 5;
	int cml = 0;
	createorks(ork, sizelvlorks); 
	cout << "You met an Orc, he wants to attack you" << endl;
	cout << "LVL (Mob):" << ork[0].lvl << "   HP (Mob):" << ork[0].hp << "   Damage (Mob):" << ork[0].damage << "   Quantity:" << colorks << endl << endl;
	int choose;
	cout << "The orc took out his sword and started the battle. Press 1 to attack him." << endl;
	cin >> choose;
	if (choose == 1)
	{
		while (ork[0].hp != 0)
		{
			hero.hp -= ork[0].damage;
			cout << "Orc dealt: " << ork[0].damage << ". HP:" << hero.hp << endl;
			ork[0].hp -= hero.damage;
			cout << "You dealt: " << hero.damage << " and left him: " << ork[0].hp << endl;
		}
		cout << "Congratulations! You have defeated the orc. HP:" << hero.hp << "." << endl;
	}
	cout << endl;
	cout << "After defeating okr, you found a health restoration potion, you drink it and your HP starts to regenerate" << endl;
	hero.hp = sethp;
	ork[0].hp = 100;
	cout << "Another orc has seen you and is rapidly approaching. Press 1 to attack him." << endl;
	cin >> choose;
	if (choose == 1)
	{
		cout << "You drew your weapon faster than an orc!";
		while (ork[0].hp != 0)
		{
			ork[0].hp -= hero.damage;
			cout << "You dealt: " << hero.damage << " and left him: " << ork[0].hp << endl;
			hero.hp -= ork[0].damage;
			cout << "Orc dealt you: " << ork[0].damage << ". HP:" << hero.hp << endl;
		}
		cout << "Your HP: " << hero.hp << endl;
		cout << "CAREFULLY! Another orc is approaching you!";
		ork[0].hp = 100;
		while (ork[0].hp != 0)
		{
			hero.hp -= ork[0].damage;
			cout << "First orc dealt you: " << ork[0].damage << ". HP:" << hero.hp << endl;
			ork[0].hp -= hero.damage;
			cout << "You dealt: " << hero.damage << " and left him: " << ork[0].hp << endl;
		}
		ork[0].hp = 100;
		while (ork[0].hp != 0)
		{
			hero.hp -= ork[0].damage;
			cout << "Second orc dealt you: " << ork[0].damage << ". HP:" << hero.hp << endl;
			ork[0].hp -= hero.damage;
			cout << "You dealt: " << hero.damage << " and left him: " << ork[0].hp << endl;
		}
		cout << "You won this tough battle and got level 2!" << endl;
		setlvl = 2;
		hero.lvl = setlvl;
		setmp = 300;
		sethp = 600;
		setdamage = 35;
		hero.mp = setmp;
		hero.hp = sethp;
		hero.damage = setdamage;
		gfirst.lvl = gsetlvl;
		gfirst.hp = gsethp;
		gfirst.damage = gdamage;
		cout << "You have gained the Double Strike skill! Damage:" << setskill1damage << ". MP Consumption: 30. To use it, when choosing an action in battle, enter 2." << endl;
		cout << "HP:" << hero.hp << "  " << "MP:" << hero.mp << "  " << "Damage:" << hero.damage << "  " << "LVL:" << hero.lvl << endl;
		cout << "You decided to hunt down the giant that the traveler told you about." << endl;
		cout << "You have successfully taken his trail and come to the lair!. Enter 1 to attack him.";
		cin >> choose;
		if (choose == 1)
		{
			int attack;
			int fcounter = 0;
			cout << "1. Auto attack." << endl << "2. Use Double Strike." << endl;
			while (gfirst.hp > 0 || hero.hp > 0)
			{
				cin >> attack;
				if (attack == 1)
				{
					gfirst.hp -= hero.damage;
					cout << "You dealt: " << hero.damage << " damage to the giant and left him " << gfirst.hp << endl;
					fcounter++;
					if (fcounter % 5 == 0)
					{
						cout << "The giant uses its abilities and damages you!." << endl;
						hero.hp -= gfirst.damage;
						cout << "Your HP: " << hero.hp << endl;
					}
				}
				if (attack == 2)
				{
					if (hero.mp > 29)
					{
						hero.mp -= 30;
						gfirst.hp -= hero.skilldamage;
						cout << "You dealt: " << hero.skilldamage << " damage to the giant and left him " << gfirst.hp << endl;
						fcounter++;
						if (fcounter % 5 == 0)
						{
							cout << "The giant uses his abilities and damages you!." << endl;
							hero.hp -= gfirst.damage;
							cout << "Your HP: " << hero.hp << endl;
						}
					}
					else
					{
						cout << "Not enough mana!" << endl;
					}
				}
				if (gfirst.hp <= 0)
				{
					cout << "The giant is defeated! In the lair there was a chest with a regeneration potion and a sword" << endl;
					break;
				}
			}
		}
	}
	if (choose == 1)
	{
		cout << endl << endl;
		cout << "Enter 2 to equip a new sword and drink the potion!" << endl;
		cin >> choose;
		if (choose == 2)
		{
			hero.hp = sethp;
			hero.mp = setmp;
			hero.damage = 75;
			hero.skilldamage = 150;
			cout << "Damage: " << hero.damage << endl << "Double Strike damage: " << hero.skilldamage << endl;
			cout << "The potion regenerates your HPand MP." << endl;
		}
		gsecond.hp = gsethp;
		gsecond.damage = gdamage;
		cout << "The giant has found you and is attacking!" << endl;
		hero.hp - gsecond.damage;
		int attack;
		int fcounter = 0;
		cout << "The giant dealt you " << gsecond.damage << " Your HP:" << hero.hp << endl;
		cout << "Enter 1 to use a normal attack and 2 to use Double Strike!" << endl;
		while (gsecond.hp > 0 || hero.hp > 0)
		{
			cin >> attack;
			if (attack == 1)
			{
				gsecond.hp -= hero.damage;
				cout << "You dealt: " << hero.damage << " damage to the giant and left him " << gsecond.hp << endl;
				fcounter++;
				if (fcounter % 5 == 0)
				{
					cout << "The giant uses his abilities and damages you!" << endl;
					hero.hp -= gsecond.damage;
					cout << "Your HP: " << hero.hp << endl;
				}
			}
			if (attack == 2)
			{
				if (hero.mp > 29)
				{
					hero.mp -= 30;
					gsecond.hp -= hero.skilldamage;
					cout << "You dealt: " << hero.skilldamage << " damage to the giant and left him " << gsecond.hp << endl;
					fcounter++;
					if (fcounter % 5 == 0)
					{
						cout << "The giant uses his abilities and damages you!" << endl;
						hero.hp -= gsecond.damage;
						cout << "Your HP: " << hero.hp << endl;
					}
				}
				else
				{
					cout << "Not enough mana." << endl;
				}
			}
			if (gsecond.hp <= 0)
			{
				cout << "You defeated the giant" << endl;
				break;
			}
		}
	}
	cout << "You have completed the game." << endl;
	exit(0);
}