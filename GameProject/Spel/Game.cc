#include "Game.h"

using namespace std;

void Game::get_help()
{
    string line;
    ifstream helpfile ("spelfil.txt");
    if (helpfile.is_open())
    {
        while (getline(helpfile,line))
        {
            cout << line << endl;
        }

        helpfile.close();
    }

    else
        cout << "Unable to open file \n";

    return;
}
