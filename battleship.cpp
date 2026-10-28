
//<Sources if necessary>
//Include statements
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;
//Global declarations: Constants and type definitions only -- no variables
//Function prototypes
void printboard(char board[25][25]);
void fire(char playerboard[25][25], char completeboard[25][25], int y, int x);
bool fleetsunk(char completeboard[25][25]);
int main()
{
//In cout statement below SUBSTITUTE your name and lab number
cout << "Jacob Jones Lab 8" << endl << endl;
//Variable declarations
char playerboard[25][25];
char completeboard[25][25];
ifstream inputfile;
int y=0;
int x=0;
bool flag;
bool validInput;
//Program logic
// open the inputfile
inputfile.open("board.txt");
if (!inputfile) {
    cerr << "Error: could not open board.txt." << endl;
    return 1;
}
// initalize the player board and set it all to open water
for (int y=0; y<25; y++){
    for(int x=0; x<25; x++){
        playerboard[y][x]='~';}}
// initalise the completboard and set it to the inputfile
for (int y=0; y<25; y++){
    for(int x=0; x<25; x++){
        if (!(inputfile >> completeboard[y][x]) ||
            (completeboard[y][x] != '~' && completeboard[y][x] != '#')) {
            cerr << "Error: board.txt must contain a complete 25x25 board of '~' and '#' characters." << endl;
            return 1;
        }
    }
}
inputfile.close();
// while the row number is not -1 ask for cordinates and fire at them 
while(y!= -1){
    printboard(playerboard);
    // ask for and validate row number
    do{
        validInput = false;
        cout<<"What is your row number? Type -1 to end the game. "<< endl;
        if (!(cin >> y)) {
            if (cin.eof()) {
                return 0;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<< "Incorrect input; please enter a whole number between 0 and 24, or -1 to end the game."<< endl<< endl;
        } else if((y>= 25 || y<0) && y!= -1){
        cout<< "Incorect number please enter a whole number between 0 and 24"<< endl<< endl;}
        else {
            validInput = true;
        }
    }while(!validInput);
    // if row number is -1 end the game
    if(y==-1){
        break;}
    // ask for and validate the column number
        do{
         validInput = false;
         cout<<"What is your column number? "<< endl;
        if (!(cin >> x)) {
            if (cin.eof()) {
                return 0;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<< "Incorrect input; please enter a whole number between 0 and 24."<< endl<< endl;
        } else if(x>= 25 || x<0){
            cout<< "Incorect number please insert a whole number between 0 and 24"<< endl<< endl;}
        else {
            validInput = true;
        }
    }while(!validInput);
        // fire at the cordinates specifyed
        fire(playerboard, completeboard, y,x);
        // check the complete board for any ships left if not then end game
        flag= fleetsunk(completeboard);
        if(flag== true){
            cout <<"Congradulations you won fleet is sunk! "<<endl<<endl;
            printboard(playerboard);
            return 0;
        }
    }
//Closing program statements
system("pause");
return 0;
}
//Function definitions
void printboard(char board[25][25]){
// print the board 
    for (int y=0; y<25; y++){
    for(int x=0; x<25; x++){
    cout<< board[y][x];}
   cout<< endl;}
cout<< endl;}
void fire(char playerboard[25][25], char completeboard[25][25], int y, int x){
    // get the charater from completeboard
    char compare= completeboard[y][x];
    // compare the character if it is a ship say hit if not say miss git rid of the # in complete board so fleet sunk can check for no #
    if (compare== '~'){
        cout<< "MISS"<<endl<<endl;
        playerboard[y][x]= 'M';
        completeboard[y][x]= 'M';}
    else if(compare== '#'){
        cout<<"HIT "<< endl<<endl;
        playerboard[y][x]='H';
        completeboard[y][x]='H';}
    else if (compare== 'H'){
        cout<<"Already Hit please enter a new number"<<endl<<endl;}
    else {
        cout<<"Already Missed please enter a new number"<<endl<<endl;
    }}
    
bool fleetsunk(char completeboard[25][25]){
   // loop through complete board to check if any # are left
    
    char check;
    for (int y=0; y<25; y++){
    for(int x=0; x<25; x++){
        check= completeboard[y][x];
        if (check== '#'){
            return  false;}}}
    return  true;
}
   
