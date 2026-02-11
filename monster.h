#ifndef monster_h
#define monster_h

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

};

	void monster::display(){
		cout<<name<<endl;
		cout<<hp<<endl;
		cout<<potion<<endl;
	}

	monster::~monster(){
		cout<<"Monster "<<name<<" is gone."<<endl;
	}

  monster::monster(string n,int a, int b){
	name=n;
	hp=a;
	potion=b;
	cout<<"Moster "<<name<<" is here"<<endl;
//	cout<<name<<" hp and potion: "<<hp<< potion<<endl;
  }

#endif
