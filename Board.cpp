#include <iostream>
#include "Board.hpp"
using namespace std;

namespace ariel {

    void Board::post(unsigned int row, unsigned int col, Direction direction, string const &message) {
        this->max_raw = max(this->max_raw, row);
        this->max_col = max(this->max_col, col);
        this->min_raw = min(this->min_raw, row);
        this->min_col = min(this->min_col, col);
        for(char ch: message){
            this->board[row][col].val = ch;
            (direction == Direction::Vertical)? row++ : col++;
        }
    }
//----------------------------------------------------------------------------------------------
    
    string Board::read(unsigned int row,  unsigned int col, Direction direction,  unsigned int length) {
        string ans;
        for(unsigned int i=0; i<length; i++){
            ans += this->board[row][col].val;
            (direction == Direction::Vertical)? row++ : col++;
        }
        return ans;
    }
//----------------------------------------------------------------------------------------------
    
    void Board::show() {
        for (unsigned int i = this->min_raw; i <= this->max_raw; i++) {
            for (unsigned int j = this->min_col; j <= this->max_col; j++) {
                cout << this->board[i][j].val << " ";
            }
            cout << "\n\n";
        }
    }
}