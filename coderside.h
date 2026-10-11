// (Part 2: Coder Side Setup)
#include<iostream>
#define GAME_SETUP_H
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
namespace game
{
class Node// Node structure representing a card
{
public:
    char value;//values like A,B,C...
    bool isFaceUp;
    Node* next;
    Node(char val)// Constructor
    {
        value=val;
        isFaceUp=false;
        next=nullptr;
    }
};

class LinkedList// LinkedList class
{
public:
    Node* head;
    LinkedList() {  head=nullptr;  }// Constructor
    void appendNode(char value)// Function to create and append new node
    {
        Node* newNode = new Node(value);
        if (!head) { head = newNode;}
        else
        {
            Node* temp = head;
            while (temp->next != nullptr) {temp = temp->next;}
            temp->next = newNode;
        }
    }

    void shuffleList() // Function to shuffle the linked list
    {
        if (!head) {return;}
        vector<Node*> nodes;//create vector and store pointer to each node
        Node* current = head;
        while (current)     // Store all nodes in a vector
        {
            nodes.push_back(current);//add each node to vector
            current = current->next;
        }
        srand(time(0));        // generate random num with current time
        for (size_t i = 0; i < nodes.size(); ++i)
        {
            int randomIndex = rand() % nodes.size();//generate random num within size(index)
            std::swap(nodes[i]->value, nodes[randomIndex]->value);
        }
    }
    Node* findNodeByIndex(int index)    // Function to find a node by its index
    {
        Node* current = head;
        int count = 0;
        while (current && count < index)
        {
            current = current->next;
            count++;
        }
        return current;
    }
    void displayList()     // Function to display the current state of the game
    {
        Node* current = head;
        int index = 0;
        while (current)
        {
            if (current->isFaceUp)  { cout << "[" << current->value << "] "; }
            else  {std::cout << "[" << index << "] "; }
            current = current->next;
            index++;
        }
        cout << endl;
    }
    bool isGameOver()    // Function to check if the game is over
    {
        Node* current = head;
        while (current)
        {
            if (!current->isFaceUp) { return false; }
            current = current->next;
        }
        return true;
    }
    ~LinkedList()    // Destructor to free up memory
    {
        Node* current = head;
        while (current)
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};
void setupGame(LinkedList& list)// Function to set up the game
 {
    vector<char>cardValues = {'A', 'B', 'C', 'D'}; // Add more values if needed
    int numPairs = cardValues.size();
    for (int i = 0; i < numPairs; i++) // Create pairs of cards and add them to list
    {
        list.appendNode(cardValues[i]);//create node for first value
        list.appendNode(cardValues[i]);//create node for its duplicate
    }
    list.shuffleList();    // Shuffle the list after assigning node
}
}
