#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

int main();

int tryAgain(int lastuse, int current, bool start){
    int ret;
    if(start == true){
        cout << "Number is more than twice last used number or the number of coins!! please enter a valid number: " << endl;
        cin >> ret;
    }
    else cout << "You can't take all the coins directly. \n Please enter a valid number: " << endl;

    while(ret > 2*lastuse || ret > current){
        if(start == true) cout << "Number is more than twice last used number or the number of coins!! please enter a valid number: " << endl;
        else cout << "You can't take all the coins directly. \n Please enter a valid number: " << endl;
    }
    return ret;
}

void player1(string name, int &lastuse, int &current, bool &start){
    int p1;
    cout << name << "'s turn: ";
    cin >> p1;

    if(p1 > 2*lastuse || p1 > current) p1 = tryAgain(lastuse, current, start);
    lastuse = p1;
    current -= lastuse;
    start = true;
    cout << "There are " << current << " coins on the table." << endl;
}

void player2(string name, int &lastuse, int &current, bool &start){
    int p2;
    cout << name << "'s turn: ";
    cin >> p2;

    if(p2 > 2*lastuse || p2 > current) p2 = tryAgain(lastuse, current, start);
    lastuse = p2;
    current -= lastuse;
    cout << "There are " << current << " coins on the table." << endl;
}

void comp(int &lastuse, int &current, bool &start){
    int cplay;
    if(current <= 2*lastuse) cplay = current;
    else{
        cplay = current / 4;
        if(cplay > 2*lastuse) cplay = 2*lastuse;
        if(cplay == 0) cplay == 1;
    }

    cout << "Computer:Hmm..." << endl;
    Sleep(1500);
    cout << "Computer chose the number " << cplay << endl;
    lastuse = cplay;
    current -= lastuse;
    cout << "There are " << current << " coins on the table: " << endl;
}

int playAgain(int &lastuse, int &current, bool &start){
    char x;
    cout << "Do you wanna play again? (y/n) ";
    cin >> x;
    if(x == 'y'){
        current = rand() % 1000 + 1;
        lastuse = (current - 1) / 2;
        start = false;
        main();
    }
    else return 0;
}

void multiplayer(string &name1, string &name2, int &lastuse, int &current, bool &start){
    cout << "There are " << current << " on the table." << endl;
    while(current != 0){
        player1(name1, lastuse, current, start);
        if(current == 0){
            cout << name1 << " wins!!" << endl;
            playAgain(lastuse, current, start);
        }
        player2(name2, lastuse, current, start);
    }
    cout << name2 << " wins!!" << endl;
    playAgain(lastuse, current, start);
}

void oneplayer(string &name1, int &lastuse, int &current, bool &start ){
    cout << "There are " << current << " coins on the table." << endl;
    while(current != 0){
        player1(name1, lastuse, current, start);
        if(current == 0){
            cout << name1 << " wins!!" << endl;
            playAgain(lastuse, current, start);
        }
        comp(lastuse, current, start);
    }
    cout << "Computer wins!!" << endl;
    playAgain(lastuse, current, start);
}

int main()
{
    int orig = rand() % 1000 + 1;
    int last = (orig-1)/2;
    bool beg = false;
    string p1Name = "", p2Name = "", playmood;

    cout << "Enter 1 for one player or 2 for two players: ";
    cin >> playmood;
    if(playmood == "1"){
        cout << "Player 1 name: ";
        cin >> p1Name;
        oneplayer(p1Name, last, orig, beg);
    }
    else{
        cout << "Player 1 name: ";
        cin >> p1Name;
        cout << "Player 2 name: ";
        cin >> p2Name;
        multiplayer(p1Name, p2Name, last, orig, beg);
    }
}
