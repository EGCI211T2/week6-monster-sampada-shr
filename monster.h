#ifndef monster_h
#define monster_h
#include <cstdlib>
#include <ctime>

class monster{
private:
	string name;
	int hp,potion;
public:
	void Attack(monster &);
    void heal();
	monster(string="unknown", int=1,int=1);
	    ~monster();
	void display();
	int hpreturn();
	void zero_hp_resetter();
};

	void monster::Attack(monster &m){  //attack
		int damage;
		cout<<name<<" has attacked "<<m.name<<"."<<endl;
		if (hp>m.hp){
			damage=rand()%15+1;
			m.hp-=damage;
			hp--;
			cout<<m.name<<" takes "<<damage<<" damage.\n";
			cout<<name<<" takes 1 damage.\n\n";
		}
		else{
			damage=3;
			m.hp-=damage;
			hp-=10;
			cout<<m.name<<" takes "<<damage<<"damage.\n";
			cout<<name<<" takes 10 damage.\n\n";
		}
	}

	void monster::heal(){  //heal
		if (potion>2){
			hp+=10;
			cout<<name<<" +10hp.\n";
		}	
		else {
			cout<<name<<" doesn't have enough potions to heal.\n";
		}
	}

	void monster::display(){  //display monsters
		if (hp>0){
			cout<<name<<endl;
			cout<<hp<<endl;
			cout<<potion<<endl;
			cout<<"----------------------"<<endl;
		}
	}

	monster::~monster(){  //destructor
		cout<<"Monster "<<name<<" is gone."<<endl;
	}

  monster::monster(string n,int a, int b){  //constructor
	cout<<"What monster are you facing? ";
	cin>>n;
	name=n;
	hp=rand()%MAX_hp+1;
	potion=rand()%MAX_potion+1;
	cout<<"Moster "<<name<<" has spawned."<<endl;
//	cout<<name<<" hp and potion: "<<hp<< potion<<endl;
  }

  int monster::hpreturn(){  //return hp value
	return hp;
  }

  void monster::zero_hp_resetter(){  //kill monster
	hp=0;
  }

#endif
