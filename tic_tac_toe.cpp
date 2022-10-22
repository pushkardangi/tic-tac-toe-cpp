// Issues :
// overwriting of the data in box : o can be changed to x and vice versa

// Covered
// players name should be global var, to declare them as winners
// when turn == 5 then start checking who wins

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

// Global variables
char arr[10];
int turn = 0, choice;
int win = 0;

struct username
{
    char player1[20];
    char player2[20];
} instance;

// Function Declarations
void initial_setup();
void input_username();
void check_win(char arr[], char ch);
void print_board(char arr[], int choice_num);
void declare_winner(char ch);
void play_again();

int main()
{
    cout << endl;
    cout<<"----- Welcome to -----\n";
    cout << "-- Tic Tac Toe Game -- " << endl;
    cout << endl;

    input_username();

    cout << "Weapons for the Warriors : \n\n";
    cout << instance.player1 << " : 'O' \n\n";
    cout << instance.player2 << " : 'X' \n\n";
    cout<<"-------------------------\n\n";

    // to hold screen
    cout << "Enter any integer to begin : ";
    cin >> choice;

    initial_setup();

    return 0;
}

void initial_setup()
{
    arr[1] = '1';
    arr[2] = '2';
    arr[3] = '3';
    arr[4] = '4';
    arr[5] = '5';
    arr[6] = '6';
    arr[7] = '7';
    arr[8] = '8';
    arr[9] = '9';

    turn = 0;

    print_board(arr, 0);

    while (1)
    {
        cout << " Enter Choice : ";
        cin >> choice;

        print_board(arr, choice);
    }
}

void input_username()
{
    cout << "Name of Player 1 : ";
    cin >> instance.player1;

    cout << "Name of Player 2 : ";
    cin >> instance.player2;

    cout<<"-------------------------\n\n";

    return;
}

void check_win(char arr[], char ch)
{

    if (arr[1] == arr[2] && arr[2] == arr[3])
    {
        declare_winner(ch);
    }
    if (arr[4] == arr[5] && arr[5] == arr[6])
    {
        declare_winner(ch);
    }
    if (arr[7] == arr[8] && arr[8] == arr[9])
    {
        declare_winner(ch);
    }
    if (arr[1] == arr[4] && arr[4] == arr[7])
    {
        declare_winner(ch);
    }
    if (arr[2] == arr[5] && arr[5] == arr[8])
    {
        declare_winner(ch);
    }
    if (arr[3] == arr[6] && arr[6] == arr[9])
    {
        declare_winner(ch);
    }
    if (arr[1] == arr[5] && arr[5] == arr[9])
    {
        declare_winner(ch);
    }
    if (arr[3] == arr[5] && arr[5] == arr[7])
    {
        declare_winner(ch);
    }
}

void print_board(char arr[], int choice_num)
{
    // Variables of function
    char ch;

    // logic for giving chance
    if (turn % 2 == 0)
    {
        ch = 'X';
    }
    else
    {
        ch = 'O';
    }

    arr[choice_num] = ch;

    // Clear screen
    cout << "\033[2J\033[1;1H";

    cout << "        |        |        " << endl;
    cout << "   " << arr[1] << "    |    " << arr[2] << "   |    " << arr[3] << "   " << endl;
    cout << "        |        |        " << endl;
    cout << "--------------------------" << endl;
    cout << "        |        |        " << endl;
    cout << "   " << arr[4] << "    |    " << arr[5] << "   |    " << arr[6] << "   " << endl;
    cout << "        |        |        " << endl;
    cout << "--------------------------" << endl;
    cout << "        |        |        " << endl;
    cout << "   " << arr[7] << "    |    " << arr[8] << "   |    " << arr[9] << "   " << endl;
    cout << "        |        |        " << endl;
    cout << endl;

    if (turn >= 5)
    {
        check_win(arr, ch);

        // is draw
        if (turn == 9)
        {
            cout << "Well played" << endl;
            cout << instance.player1 << " and " << instance.player2 << endl;
            cout << "Match Draw" << endl;

            void play_again();
        }
    }

    turn++;

    return;
}

void declare_winner(char ch)
{
    if (ch == 'O')
    {
        cout << "---- " << instance.player1 << " Won ----\n\n"
             << endl;
    }
    else
    {
        cout << "---- " << instance.player2 << " Won ----\n\n"
             << endl;
    }

    play_again();
}

void play_again()
{
    int input;

    cout << "Press :\n";
    cout << "1. Play again.\n";
    cout << "2. Exit from game.\n";
    cout << "3. Say bye bye to us.\n\n";

    cout << "Enter your choice : ";
    cin >> input;

    switch (input)
    {
    case 1:
        initial_setup();
        break;
    case 2:
        cout << "\nExit Successfully.\n";
        exit(0); // Successful Program Exit
        break;
    case 3:
        cout << "\nBye Bye.\n";
        cout << "Thank you for playing the game.\n";
        exit(0);
        break;

    default:
        // handle it, if wrong option is input
        cout << "Input correct option.\n";
        break;
    }
}