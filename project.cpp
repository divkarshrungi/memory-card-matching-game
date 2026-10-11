// game_client.cpp (Part 1: Client Side Code)
#include <iostream>
#include "coderside.h" // This header file will include the setup done by the coder
using namespace game;
using namespace std;
// Function to play a turn in the game
void playTurn(LinkedList& list, int index1, int index2)
 {
    Node* card1 = list.findNodeByIndex(index1);
    Node* card2 = list.findNodeByIndex(index2);
    if (!card1 || !card2 || card1->isFaceUp || card2->isFaceUp)
    {
        cout << "Invalid move!" << endl<<endl;
        return;
    }
    card1->isFaceUp = true;
    card2->isFaceUp = true;
    list.displayList();
    if (card1->value == card2->value) {
        cout << "It's a match!" << endl<<endl;
    } else {
        cout << "Not a match!" << endl<<endl;
        card1->isFaceUp = false;
        card2->isFaceUp = false;
    }
}

int main()
{
LinkedList list;
cout<<"\t\t\t\t hello people ,welcome to memory card match game"<<endl;
cout<<"\t\t to play this game you need to flip 2 cards by entering their index numbers"<<endl;
cout<<"\t\t\t if you want to exit this game enter index number as -1"<<endl<<endl;
    setupGame(list);  // Calls function setupgame from external file
    int moves = 0;  // Declare a counter to track the number of moves
    while (!list.isGameOver())
    {
        list.displayList();
        int index1, index2;
        cout << "Enter the index of the first card to flip (or -1 to exit): ";
        cin >> index1;
        if (index1 == -1)
        {
            cout << "Game exited!" << endl;
            cout << "Moves played: " << moves << endl;
            return 0;
        }
        cout << "Enter the index of the second card to flip (or -1 to exit): ";
        cin >> index2;

        if (index2 == -1)
        {
            cout << "Game exited!" << endl;
            cout << "Moves played: " << moves << endl;
            return 0;
        }
        playTurn(list, index1, index2);
        moves++;
    }
    if (list.isGameOver())
    {
        cout << "Game over! You've matched all pairs." << endl;
        cout << "Total moves made: " << moves << endl;  // Display the total number of moves
    }
    return 0;
 }
