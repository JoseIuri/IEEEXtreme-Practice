#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct state{
    char mat[3][3];
    bool bobTurn;
    int moveNum;

    vector< pair<int,int> > myMoves;
    
};

//-1 = we win
// 0 = no one
// 1 = bob win
int whoWin (state x){
    for (int i = 0; i < 3; i++){
        int countX = 0;
        int countO = 0;
        for (int j = 0; j < 3; j++){
            if(x.mat[i][j] == 'x') countX++;
            if(x.mat[i][j] == 'o') countO++;
        }
        
        if(countO == 3) return -1;
        if(countX == 3) return 1;
    }
    
    for (int j = 0; j < 3; j++){
        int countX = 0;
        int countO = 0;
        for (int i = 0; i < 3; i++){
            if(x.mat[i][j] == 'x') countX++;
            if(x.mat[i][j] == 'o') countO++;
        }
        
        if(countO == 3) return -1;
        if(countX == 3) return 1;
    }
    
    int countPrimX = 0;
    int countPrimO = 0;
    int countSecX = 0;
    int countSecO = 0;
    for (int i = 0; i < 3; i++){
        if(x.mat[i][i] == 'x') countPrimX++;
        if(x.mat[i][i] == 'o') countPrimO++;
        if(x.mat[i][2-i] == 'x') countSecX++;
        if(x.mat[i][2-i] == 'o') countSecO++;
    }
    
    if(countPrimO == 3) return -1;
    if(countPrimX == 3) return 1;
    
    if(countSecO == 3) return -1;
    if(countSecX == 3) return 1;
    
    return 0;
}

int main() {
    int bobRow[9], bobCol[9];
    
    //read the inputs
    for (int i = 0; i < 9; i++){
        cin >> bobRow[i] >> bobCol[i];
        bobCol[i]--;
        bobRow[i]--;
    }
    
    queue<state> q;
    
    state initial;
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            initial.mat[i][j] = '.';
        }
    }
    
    initial.moveNum = 0;
    initial.bobTurn = true;
    
    q.push(initial);
    
    while(!q.empty()){
        state tmp = q.front();
        q.pop();
        
        int winner = whoWin(tmp);
        
        if(winner == -1){
            continue;
        }
        
        if(winner == 1){
            for(int i = 0; i < (int)tmp.myMoves.size(); i++){
                cout << tmp.myMoves[i].first + 1 << " " << tmp.myMoves[i].second + 1 << endl;
            }
            break;
        }
        
        if(tmp.bobTurn){
            int lastMove = tmp.moveNum;
            bool moveFound = false;
            for(int i = lastMove; i < 9 && !moveFound; i++){
                int r = bobRow[i];
                int c = bobCol[i];
                
                if(tmp.mat[r][c] == '.'){
                    tmp.mat[r][c] = 'x';
                    tmp.moveNum = i + 1;
                    tmp.bobTurn = false;
                    moveFound = true;
                    q.push(tmp);
                }
            }
        }
        else{
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    if(tmp.mat[i][j] != '.'){
                        continue;
                    }
                
                
                state newState = tmp;
                
                newState.mat[i][j] = 'o';
                newState.bobTurn = true;
                
                newState.myMoves.push_back(make_pair(i,j));
                
                q.push(newState);
                }
            }
        }
    }
    
    return 0;
    
}