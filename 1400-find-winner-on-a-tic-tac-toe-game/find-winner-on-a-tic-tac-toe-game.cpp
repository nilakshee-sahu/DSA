class Solution {
private:
    bool isWinner(unordered_set<int>& player, vector<vector<int>>& winningPat) {
        for (int i = 0; i < winningPat.size(); i++) {
            if (player.count(winningPat[i][0]) &&
                player.count(winningPat[i][1]) &&
                player.count(winningPat[i][2])) {
                return true;
            }
        }
        return false;
    }

public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> winningPat = {
            {0,1,2}, {3,4,5}, {6,7,8}, // rows
            {0,3,6}, {1,4,7}, {2,5,8}, // cols
            {0,4,8}, {2,4,6}           // diagonals
        };

        unordered_set<int> A, B;
        for (int i = 0; i < moves.size(); i++) {
            int idx = moves[i][0] * 3 + moves[i][1];
            if (i % 2 == 0) A.insert(idx); 
            else B.insert(idx);            
        }

        if (isWinner(A, winningPat)) return "A";
        if (isWinner(B, winningPat)) return "B";
        return moves.size() == 9 ? "Draw" : "Pending";
        
    }
};