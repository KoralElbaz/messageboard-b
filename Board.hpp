#include <string>
#include <map>
#include "Direction.hpp"
using namespace std;

struct emptyChar{
    char val = '_';
};

namespace ariel {
    class Board {
    private:
        map<unsigned int, map< unsigned int, emptyChar> > board;
        unsigned int min_col, max_col;
        unsigned int min_raw, max_raw;
    
    public:
        Board() { 
            max_raw =  max_col = 0;
            min_raw = min_col = INT8_MAX;
        }
        ~Board() { }
        void post(unsigned int row, unsigned int column, Direction direction, string const &message);
        std::string read(unsigned int row,  unsigned int column, Direction direction,  unsigned int length);
        void show();
    };
}