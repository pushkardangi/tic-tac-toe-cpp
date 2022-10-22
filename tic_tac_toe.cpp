#include <iostream>
#include <string>
using namespace std;

// Global variables
int turn = 0;

void check_win(char arr[], char ch)
{

    if (arr[1] == arr[2] && arr[2] == arr[3])
    {
        cout << ch << " WON " << endl;
    }
    if (arr[4] == arr[5] && arr[5] == arr[6])
    {
        cout << ch << " WON " << endl;
    }
    if (arr[7] == arr[8] && arr[8] == arr[9])
    {
        cout << ch << " WON " << endl;
    }
    if (arr[1] == arr[4] && arr[4] == arr[7])
    {
        cout << ch << " WON " << endl;
    }
    if (arr[2] == arr[5] && arr[5] == arr[8])
    {
        cout << ch << " WON " << endl;
    }
    if (arr[3] == arr[6] && arr[6] == arr[9])
    {
        cout << ch << " WON " << endl;
    }
    if (arr[1] == arr[5] && arr[5] == arr[9])
    {
        cout << ch << " WON " << endl;
    }
    if (arr[3] == arr[5] && arr[5] == arr[7])
    {
        cout << ch << " WON " << endl;
    }
}

void print_board(char arr[], int choice_num)
{
    // Variables of function
    char ch;

    // logic
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
    cout<<endl;

    if (turn >= 5)
    {
        check_win(arr, ch);

        // is draw
        if (turn == 9)
        {
            cout << "Well played" << endl;
            cout << "Match Draw" << endl;
            exit(0);
        }
    }

    turn++;

    return;
}

int main()
{
    int choice_num;
    char arr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    string player1, player2;

    cout << endl;
    cout << "-- Tic Tac Toe Game -- " << endl;
    cout << endl;

    cout << "Name of Player 1 : ";
    cin >> player1;
    cout << "Name of Player 2 : ";
    cin >> player2;
    cout << "\n\n";

    cout << "Weapons for the Warriors : \n\n";
    cout << player1 << " : 'O' \n\n";
    cout << player2 << " : 'X' \n\n\n";

    // to hold screen
    cout<<"Press 1 to begin :";
    cin>>choice_num;

    print_board(arr, 0);

    while (1)
    {
        cout << " Enter Choice : ";
        cin >> choice_num;

        print_board(arr, choice_num);
    }

    return 0;
}