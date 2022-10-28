#include <iostream>
#include <random>
#include <ctime>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

void sleepcp(int milliseconds) // Cross-platform sleep function
{
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_end)
    {
    }
}

int getNumSpartan();
int getNumAthenian();
void printOutResult(int numAthenian, int numSpartan, int startAthenian, int startSpartan);//These are forward declarations.
void simulateBattle(int &numAthenian, int &numSpartan);
int main() {

    int numSpartan = 0;//number of Spartans
    int numAthenian = 0;


    cout << "SPARTAN VS. ATHENIAN!" << endl;
    numAthenian = getNumAthenian();//get input from the users, the getter funtion is defined below
    numSpartan = getNumSpartan();
    int startAthenian = numAthenian;    
    int startSpartan = numSpartan; 
    simulateBattle(numAthenian, numSpartan);
    printOutResult(numAthenian, numSpartan, startAthenian, startSpartan);
    return 0;

}

int getNumAthenian(){
    int numAthenian;
    cout << "Enter the number of Athenian: \n";
    cin >> numAthenian;
    return numAthenian;
}

int getNumSpartan(){
    int numSpartan;
    cout << "Enter the number of Spartan: \n";
    cin >> numSpartan;
    return numSpartan;
}

void printOutResult(int numAthenian, int numSpartan, int startAthenian, int startSpartan){//parameters
    cout << "\nBattle is over!\n" << endl;

    if(numAthenian > 0 && numSpartan == 0)
    {
        cout << "Athenian won!" << endl;
        cout << "There are " << numAthenian << " Athenians left!\n";
    }
    if(numSpartan > 0 && numAthenian == 0)
    {
        cout << "Spartan won!" << endl;
        cout << "There are " << numSpartan << " Spartans left!\n";
    }

    cout << startSpartan - numSpartan << " Spartan and " << startAthenian - numAthenian << " Athenian lost their lives!";
}

void simulateBattle(int &numAthenian, int &numSpartan){//& means reference, while the value of the variable is changing, the same variable in another function is also changing instead of staying the same.
    char turn = 'A';//whose turn to fight

    static mt19937 RandomEngine(time(0));//static variable only run for one, if there is a second time it won't run the same thing again.
    uniform_int_distribution<double>attack(0.0, 1.0);//their attack chance


    double spartanAttack = 16;//their maximum attack chance
    double spartanHealth = 250;
    double spartanDamage = 150;
    double currentSpartanHealth = spartanHealth;


    double athenianAttack = 12;
    double athenianHealth = 200;
    double athenianDamage = 300;
    double currentAthenianHealth = athenianHealth;


    double attackResult;


    cout << "FIGHT!!!!!!!\n\n" << endl;

    while((numSpartan > 0) && (numAthenian > 0)){

        attackResult = attack(RandomEngine);

        if (turn == 'A'){
            cout << "  A ---------  S  " << endl;
            sleepcp(20);//the pause function, with the help of the timing function declared just now
            system("clear");//clear the things appeared on the console
            cout << "  A ->-------  S  " << endl;
            sleepcp(20);
            system("clear");
            cout << "  A -->------  S  " << endl;
            sleepcp(20);
            system("clear"); 
            cout << "  A --->-----  S  " << endl;
            sleepcp(20);
            system("clear"); 
            cout << "  A ---->----  S  " << endl;
            sleepcp(20);
            system("clear"); 
            cout << "  A ----->---  S  " << endl;            
            sleepcp(20);
            system("clear");             
            cout << "  A ------>--  S  " << endl;
            sleepcp(20);              
            system("clear");   
            cout << "  A ------->-  S  " << endl;
            sleepcp(20);
            system("clear");           
            cout << numAthenian << " A ---------XSX " << numSpartan << endl;
            sleepcp(200);
            system("clear");           
            if(attackResult <= athenianAttack){//it means they are attacking successfully
                currentSpartanHealth -= athenianDamage;//health-damage
                if(currentSpartanHealth < 0){//if a spartan dies
                    numSpartan--;
                    cout << numAthenian << " A ---------XXX " << numSpartan << endl;
                    sleepcp(400);
                    system("clear"); 
                    currentSpartanHealth = spartanHealth;//the next spartan has full health
                }
            }
            turn = 'S';
        }
        else {
            cout << "  A ---------  S" << endl;            
            sleepcp(20);
            system("clear");
            cout << "  A -------<-  S" << endl;
            sleepcp(20);
            system("clear");
            cout << "  A ------<--  S" << endl;
            sleepcp(20);
            system("clear"); 
            cout << "  A -----<---  S" << endl;
            sleepcp(20);
            system("clear"); 
            cout << "  A ----<----  S" << endl;
            sleepcp(20);
            system("clear"); 
            cout << "  A ---<-----  S" << endl;
            sleepcp(20);
            system("clear");            
            cout << "  A --<------  S" << endl;
            sleepcp(20);              
            system("clear");   
            cout << "  A -<-------  S" << endl;
            sleepcp(20);
            system("clear");         
            cout << numAthenian << " XAX--------  S " << numSpartan << endl;
            sleepcp(200);
            system("clear");              
            if (attackResult <= spartanAttack) {
                currentAthenianHealth -= spartanDamage;
                if (currentAthenianHealth < 0) {
                    numAthenian--;
                    cout << numAthenian << " XXX--------  S " << numSpartan << endl;                           
                    sleepcp(400);
                    system("clear");              
                    currentAthenianHealth = athenianHealth;
                }
            }
            turn = 'A';//going back to Athenian's turn
        }
    }
}


