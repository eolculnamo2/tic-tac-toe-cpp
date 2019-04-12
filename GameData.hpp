#include <iostream>
#include <vector>
using namespace std;

#ifndef GAMEDATA_H_
#define GAMEDATA_H_

struct space  {
  string player;
  string space;
};

class GameData {
  public:
    string player1;
    string player2;
    vector<space> board;
    string winner;
    bool player1sTurn;
    GameData();
    ~GameData();
    void round();
};

#endif /* GAMEDATA_H_ */