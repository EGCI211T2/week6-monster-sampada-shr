#include <iostream>
using namespace std;

#include "monster.h"

int main(int argc, char* argv[]) {
    monster A("Pikachu",10,15);
    monster B("Daisuke");

    monster x[5]={{"sam"},{"sarah",20},{"james"},{"tom"},{"ant"}};

    monster *p;
    p=&A;
    p->display();
    p=new monster ("Sarina",20);
    p->display();

    p=new monster [3];
    delete []p;
  /*
 
 monster *p,x;
  p=&x;
  p=new monster;
 delete p;

 p=new monster[3];
 delete []p;

*/

}
