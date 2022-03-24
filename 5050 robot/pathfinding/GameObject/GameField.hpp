#ifndef GAMEFIELD_HPP
#define GAMEFIELD_HPP
#include "GameObject.hpp"

/*

NOTES FOR REVISIONS

-let user pass in "scoring method" functions for gameobjects
-adding another robot and their potential path in future revision
-platform is considered a dead zone for now (as in no moving there or scoring there)
-add ability to make more "unique" goal boundries later (add different scores/procedures for different boundries). May make it a whole seperate object, but that might be unoptimal.
-add ability to choose metric (cm, m, ft, etc)
-(for greedy path generator) add ability to immediately move when optimal path to 1 object is found rather then making the full path at once (also helps create path in a more dynamic field)
-add ability to pass in a custom heuristic function for greedy path generator
-implement a factor of probability and time into a future heurisitic

*/

class GameField {

  public:
    // Constructor (set game field, specify the robot, and specify the max number of field objects excluding the controlled robot)
    GameField();

    GameField(float height_cm, float width_cm, GameObject Robot, unsigned short int numObjects, unsigned short int numBoundries);

    // GETTERS
    GameObject * getGameObjects(); // Return array of current game objects
    float ** getScoreBoundries(); // Return nested array of score boundaries 
    float getFieldWidth(); // Return float denoting the field width
    float getFieldHeight(); // Return float denoting the field height
    
    
    // SETTERS
    void addScoreBoundry(float startX, float startY,  float endX, float endY, float boundryID); // Set a rectangular boundry for what is considered the score zone on the field (creates a 5-entry array inside a nested array). 
    void addGameObject(GameObject obj); // add one game object (can add multiple through main file using for loop)
    void setFieldWidth(float width_cm);
    void setFieldHeight(float height_cm);


    // OTHER
    GameObject * generateGreedy(); // Return an array of nodes denoting the path that the robot takes (would actually run auton functions in vexcode, but currently just returns distance/object pairs)
    GameObject runPath(); // Run the path specified (pretty much only applicable for vex code)


  private:
    unsigned short int numObjects = 0; // max number of objects in game field (excluding controlled robot)
    unsigned short int numBoundries = 0; // number of given boundries
    float lowerBoundX, lowerBoundY;
    float upperBoundX, upperBoundY;
    GameObject Robot; // for the robot specifically
    GameObject* gameObjArr; // Array of other game objects
    float** scoreBoundryArr; // 2d array representing boundries of score zones and ID of boundary (to specify behavior)
    
};

#endif