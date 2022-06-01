/**
 * This program will create a game of battleship and will allow the user to play
 * The board sizes are currently 3x3 and 5x5, with 2x1 ships
 * Author: Kody Takada || Date Created: 05/31/2022
 */
#include <iostream>
#include <cmath>
#include <vector>
#include "Matrix.h"

using namespace std;

struct Boat{
    vector<pair<int,int>> location;
    int hitCounter;
    bool sunk;
};
//Class that creates a board to be used
class Board{
    private: 
        int height;
        int width;
        int numBoats;
        vector<Boat> boats;
        Matrix *mat;

    public:
        //Default Constructor
        //EFFECTS: Sets the default height to be 1x1 with no boats
        Board():height(1), width(1), numBoats(0){
            Matrix_init(mat, height, width);
        }

        //Custom Constructor
        Board(int &height_in, int &width_in):
        height(height_in), width(width_in){
            if(height == 3){
                numBoats = 1;
            }
            else if(height == 5){
                numBoats = 2;
            }
            //If you want to expand the board sizes and the boats
            Matrix_init(mat, height, width);
        }
        
        //Destructor
        ~Board(){
            delete mat;
        }

        int get_height(){return height;}
        int get_width(){return width;}

        //Fills the board with O's and the ships
        void setBoard(){
            Matrix_fill(mat, 'O');
            //Use random to figure out the placement
            for(int i = 0; i < numBoats; ++i){
                int heightb = rand(height-1);
                int widthb = rand(width-1);
                while(check_boat(heightb, widthb)){
                    heightb = rand(height-1);
                    widthb = rand(width-1);
                }
                Boat pontoon;
                pontoon.hitCounter = 0; pontoon.sunk = false;
                pontoon.location.push_back({heightb, widthb});
                
                //Top corners
                
                //Bottom corners

                //Side edges

                //Top edges

                //Middle
            }

            //Double check to make sure the boats do not overlap
            //Could use a for loop but rando might have a exception argument
        }

        //Checks whether or not a boat is in the given height and width
        //RETURNS: return true if a boat is there or false if it is open
        bool check_boat(int &heightToCheck, int &widthToCheck){
            for(int i = 0; i < (int) boats.size(); ++i){
                for(int j = 0; j < (int) boats[i].location.size(); ++j){
                    if(boats[i].location[j].first == heightToCheck &&
                    boats[i].location[j].second == widthToCheck){
                        return true;
                    }
                }
            }
            return false;
        }

        void print(); //Could go to the player class

        void reset();
};


//Class where the prompts for the user will be written
class Player{
    //Board size


    //what spot to hit


    //Print board to terminal

    //
};


//Class that the game will be played
class Game{
    private:
        Board board;
        Player player;
        bool game;
    public:
};

int main(){


    return 1;
}