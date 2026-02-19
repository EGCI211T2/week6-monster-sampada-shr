#include <iostream>
using namespace std;
#define MAX_hp 50
#define MAX_potion 10
#include <limits>

#include "monster.h"
#include "thanos.h"

// Helper function to clear buffer and wait for Enter once
void waitForKey() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (cin.get() != '\n'); 
}

/*
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
}
*/

int main() {
  srand(time(0));

  cout << R"(
                    _..-'(                        )`-.._
                  ./'. '||\\.       (\_/)       .//||` .`\.
               ./'.|'.'||||\\|..    )O O(    ..|//||||`.`|.`\.
            ./'..|'.|| |||||\`````` '`"'` ''''''/||||| ||.`|..`\.
          ./'.||'.|||| ||||||||||||.     .|||||||||||| |||||.`||.`\.
         /'|||'.|||||| ||||||||||||{     }|||||||||||| ||||||.`|||`\
         '.|||'.||||||| ||||||||||||{     }|||||||||||| |||||||.`|||.`
        '.||| ||||||||| |/'   ``||``     ''||/''   `\| ||||||||| |||.`
        |/' \./'     `\./         \!|\   /|!/         \./'     `\./ `\|
        V   V         V          }' `\ /' `{          V         V    V
        `   `         `                V                '         '    '
    )" <<endl;

  Thanos T;
  int n;
  cout<<"How many monsters do you want to face?";
  cin>>n;

  monster *m=new monster[n]; 

  cout<<endl<< R"(-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=)" << endl;
  char fightAns; 
  while (true) {
      cout << "Do you want the monsters to fight each other? (y/n): ";
      cin >> fightAns;
      cout<<endl;

      if (fightAns == 'y' || fightAns == 'Y') {
          for (int i = 0; i < n - 1; i++) {
              m[i].Attack(m[i + 1]);
          }
          m[n-1].Attack(m[0]);
          cout << "\nThe battle has concluded!\n" << endl;
          break; 
      } 
      else if (fightAns == 'n' || fightAns == 'N') {
          cout << "The monsters decide to maintain a fragile peace." << endl;
          break; // Exit the while loop without fighting
      } 
      else {
          // If they type anything other than y/n
          cout << "Invalid choice. Please enter 'y' for yes or 'n' for no." << endl;
          // Clean up the input buffer in case they typed a whole word
          cin.clear(); 
          cin.ignore(1000, '\n'); 
      }
  }

  char ans;
  while (true) {
      cout << "Would you like to heal some monsters? (y/n): ";
      cin >> ans;
      

      if (ans == 'y' || ans == 'Y') {
        int toheal=rand() % (n - 1);
        if(toheal!=0){
          for(int i = 0; i < toheal; i++) {
              m[i].heal();
          }
        }
        else cout<<"no monsters could be healed this time.\n";
        break; // Exit the loop after healing
      } 
      else if (ans == 'n' || ans == 'N') {
          break; // Exit the loop without doing anything
      } 
      else {
          cout << "Not a valid input. Please try again." << endl;
          // The loop continues, asking for 'ans' again
      }
  }
 
  cout<<endl;
  cout<<"***Suddenly an entity appears.**\n";
  cout << "Press Enter to find out who this entity is...";
  waitForKey();
  cout << R"(
                  /\
                  ||
    ____ (((+))) _||_
   /.--.\  .-.  /.||.\
  /.,   \\(0.0)// || \\
 /;`";/\ \\|m|//  ||  ;\
 |:   \ \__`:`____||__:|
 |:    \__ \T/ (@~)(~@)|
 |:    _/|     |\_\/  :|
 |:   /  |     |  \   :|
 |'  /   |     |   \  '|
  \_/    |     |    \_/
         |     |
         |_____|
         |_____|
    )" << endl;
    cout << "I am Thanos. I am the silence at the end of all things." << endl;
    cout << "This world is choked with life... it needs to breathe." << endl;

    ++T; ++T;
    cout << "\nTwo stones pulse with a hungry, purple light on the Gauntlet Thanos holds." << endl;
    cout << "[ Press ENTER to let him test their hunger ]";
    waitForKey();
    T.snap_finger(m, n);

    ++T; ++T;
    cout << "\nFour stones... the Gauntlet groans under the weight of cosmic power." << endl;
    cout << "Thanos smiles. 'The balance tilts... let us push it further.'" << endl;
    cout << "Press ENTER to let the power surge...";
    waitForKey();
    T.snap_finger(m, n);

    ++T; ++T;
    cout << "\n\033[1;33m*** ALL SIX STONES ARE SECURED. THE UNIVERSE HOLDS ITS BREATH. ***\033[0m" << endl;
    cout << "'It is done,' Thanos whispers. 'Now... behold the mercy of extinction.'" << endl;
    cout << "Press ENTER to execute the Final Snap...";
    waitForKey();

    cout << R"(~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^)" << endl;
    cout << "\033[1;37m*** A BLINDING LIGHT CONSUMES THE WORLD. SILENCE FOLLOWS. ***\033[0m" << endl;
    cout << R"(~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^)" << endl;
  cout << R"(
    (  )   /\   _                 (
     \ |  (  \ ( \.(               )                     _____
   \  \ \  `  `   ) \             (  ___                 / _   \
  (_`    \+    . x  ( .\            \/   \____-----------/ (o)   \_
 - .-                \+  ;          (  O                           \____
                           )        \_____________  `               \  /
 (__                 +- .( -'.- <. - _  VVVVVVV VV V\                 \/
 (_____             ._._: <_ - <- _  (--  _AAAAAAA__A_/                  |
   .    /./.+-  . .- /  +--  - .     \______________//_               \_______
   (__ ' /x  / x _/ (                                  \___'          \     /
  , x / ( '  . / .  /                                      |           \   /
     /  /  _/ /    +                                       /              \/
    '  (__/                                               /                  \
    )" <<endl<<endl;
  T.snap_finger(m,n);//Clear hp n/2(half) of the monster. 
  cout << "\n'Smile,' Thanos commands. 'For even in death, you have become children of balance.'" << endl;

    cout << "\nPress ENTER to count the survivors...";
    waitForKey();

    cout << "\n\033[1;30m*** Half of the names have been carved from existence. ***\033[0m" << endl;
    cout << "The lucky few who remain in the graveyard:\n";

  cout << R"(
            ____                     ,
           /---.'.__             ____//
                '--.\           /.---'
          _______  \\         //
         /.------.\  \|      .'/  ______
        //  ___  \ \ ||/|\  //  _/_----.\__
       |/  /.-.\  \ \:|< >|// _/.'..\   '--'
           //   \'. | \'.|.'/ /_/ /  \\
          //     \ \_\/" ' ~\-'.-'    \\
         //        '-._| :H: |'-.__     \\
        //            (/'==='\)'-._\     ||
        ||                        \\    \|
        ||                         \\    '
        |/                          \\
                                     ||
                                     ||
                                     \\
                                      '
    )" <<endl;
  
  int i;
  for(i=0;i<n;i++)
      m[i].display();// If the hp=0, you do not display"" -->you will see only n/2 monster
  

  delete [] m;

  return 0;
}