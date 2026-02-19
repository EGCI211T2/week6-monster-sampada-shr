#include"monster.h"
#include <iostream>
using namespace std;

void swap(int &a,int &b){
	int hold=a;
	a=b;
	b=hold;
}

class Thanos {
private:
    int stones;
    int hp; //extra hp;
public:
    /* constructor and destructor */
Thanos(int =0,int=1000); //stone hp
~Thanos();
    void snap_finger(monster[],int); 
    /* show all hps
    / clear half of monster hp, if stone =6*/
    void operator++(); // increase the stone;
};

void Thanos::operator++(){  //add stones operator
	++stones;
}

Thanos::Thanos(int a, int b){
	stones=a;
	hp=b;
}

Thanos::~Thanos(){  //destructor
	cout<<"Thanos is gone.\n";
}

void Thanos::snap_finger(monster m[],int n){  //sort the weakest monsters in the beginning and kill them by setting hp=0 
	if(stones<6){
		cout<<endl;
		cout << R"(_.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._)" << endl;
		cout<<"***Thanos doesn't have enough power to cause change.***"<<endl;
		cout << R"(_.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._)" << endl<<endl;
	}
	else{
		int i,j;
		for(i=1;i<n;i++){
			j=i;
			while(j>0 && m[j-1].hpreturn()>m[j].hpreturn()){
				swap(m[j-1],m[j]);
				j--;
			}
		}
		//for(i=0;i<n;i++){
		//	m[i].display();
		//}
		for(i=0;i<n/2;i++){
			m[i].zero_hp_resetter();
		}
	} 
}