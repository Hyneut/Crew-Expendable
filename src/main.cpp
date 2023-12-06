#include "../headers/mainMenu.h"
#include "../headers/gameplay.h"
#include "../headers/characterMenu.h"
#include "../headers/node.h"
#include "../headers/storyTree.h"

using namespace std;

void wait() {
    string unused;
    cout << "Enter any key to continue " ;
    cin >> unused;
}

int main() {
    gameMenu game = gameMenu();
    mainMenu main = mainMenu();
    characterMenu cMenu = characterMenu();

    while (main.getInput() != 1) {
    main.print();
    main.input(3);
    main.choice();
    }

    while (!cMenu.getNext()) {
        cMenu.print();

        while (!cMenu.validClass()) {
            cMenu.printClass();
            cMenu.input(3);
            cout << "HERE";
        }

    cMenu.setClass();
    cMenu.correct();
    cMenu.resetClass();
    }

    cout <<  endl << "===================================" << endl;
    storyTree Tree = storyTree();
    Tree.currChoice(); // PROLOGUE 
    cout << "===================================" << endl;
    wait();

//while(1) only used for testing purposes
    while (1) {
    game.print();
    game.input(5);
    game.inputSelect(Tree);
    }

    return 0;
}
