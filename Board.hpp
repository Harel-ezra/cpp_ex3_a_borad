#include <string>
#include "Direction.hpp"

using namespace std;
namespace ariel
{
    class Board
    {
         
    public:
         Board(/* args */)
         {

         }
         ~Board()
         {

         }
        void post(int row, int col, Direction vector,  const string& str);
        static string read(int row, int col, Direction vector, int len);
        void show();
    };
}
