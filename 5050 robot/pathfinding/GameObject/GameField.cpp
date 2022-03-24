#include "GameField.hpp"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;



// CONSTRUCTOR
GameField::GameField() {
  this->lowerBoundX = -182.88;
  this->lowerBoundY = -182.88;
  this->upperBoundX = 182.88;
  this->upperBoundY = 182.88;
  this->Robot = GameObject(182, -182, 0, 30, 20, false);
  this->numObjects = 5;
  this->numBoundries = 2;
  this->gameObjArr = new GameObject[5];
  // this->gameObjArr = new GameObject[79];
  this->scoreBoundryArr = new float*[2];
  for (int i = 0; i < 2; i++) {
      scoreBoundryArr[i] = new float[5];
  }
}

GameField::GameField(float height_cm, float width_cm, GameObject Robot, unsigned short int numObjects, unsigned short int numBoundries) {
  this->lowerBoundX = -(width_cm/2);
  this->upperBoundX = (width_cm/2);
  this->lowerBoundY = -(height_cm/2);
  this->upperBoundY = (height_cm/2);
  this->Robot = Robot;
  this->numObjects = numObjects;
  this->numBoundries = numBoundries;
  this->gameObjArr = new GameObject[numObjects];
  this->scoreBoundryArr = new float*[numBoundries];
  for (int i = 0; i < numBoundries; i++) {
      scoreBoundryArr[i] = new float[5];
  }
}

// GETTERS
GameObject * GameField::getGameObjects() {
  return this->gameObjArr;
}
float ** GameField::getScoreBoundries() {
  return this->scoreBoundryArr;
}
float GameField::getFieldWidth() {
  return this->upperBoundX - this->lowerBoundX;
}
float GameField::getFieldHeight() {
  return this->upperBoundY - this->lowerBoundY;
}

// SETTERS
void GameField::addScoreBoundry(float startX, float startY, float endX, float endY, float boundID) {
  float newBoundry[5] = {startX, startY, endX, endY, boundID};
  this->scoreBoundryArr[numBoundries] = newBoundry;
  this->numBoundries++;
} 
void GameField::addGameObject(GameObject obj) {
  this->gameObjArr[numObjects] = obj;
  this->numObjects++;
}

void GameField::setFieldWidth(float width_cm) {
  this->lowerBoundX = -(width_cm/2);
  this->upperBoundX = (width_cm/2);
}
void GameField::setFieldHeight(float height_cm) {
  this->lowerBoundY = -(height_cm/2);
  this->upperBoundY = (height_cm/2);
}
    
// OTHER (mostly helper functions)

float getDistance(GameObject obj1, GameObject obj2) {
  return sqrt(pow(obj2.getX()-obj1.getX(),2)+pow(obj2.getY()-obj1.getY(),2));
}

// HEURISTICS
float heuristicOne(GameObject robot, GameObject obj, float** scoreBoundryArr, int boundNum) {
  // get general distance between robot start point and object
  float robToObj = getDistance(robot, obj);
  // replace boundNum with id later or replace id, either way
  // get y distance between object and end of score boundry
  float objToGoal = obj.getY() - scoreBoundryArr[boundNum-1][3];
  // heuristic value: distance to goal and distance to score goal
  float hVal = (robToObj + objToGoal);
  
  return hVal;
} 


// PATHFINDING
GameObject * GameField::generateGreedy() {
  float distanceTraveled = 0; // total distance traveled
  float maxDistance = 1000; // max distance robot can travel at one time (currently arbitrary)
  int objCount = 0; //current number of object nodes appended to final path
  GameObject bestGameObj; // stores best object to append at a given state
  GameObject Robot = this->Robot; // stores robot
  GameObject* currObjArr = this->gameObjArr; // current array of game objects
  GameObject finPath[this->numObjects]; // final array of game objects
  
  
  // append object nodes to path until max distance is reached or all game objects are scored
  while (distanceTraveled <= maxDistance || objCount < this->numObjects) {
    // generate heuristic value for each object, find best object to append at the given state space (object w/ lowest h value)
    bestGameObj = currObjArr[0];
    
    for (int i = 1; i < this->numObjects; i++) {
      // if there is an object with a better heurisitc value...
      if (heuristicOne(Robot, currObjArr[i], this->scoreBoundryArr, 1) < heuristicOne(Robot, bestGameObj, this->scoreBoundryArr, 1)) {
        // that object is now the best object to go to
        bestGameObj = currObjArr[i];
      }
    }

    // append object to final path (THIS PART CAUSES ERRO)
    finPath[objCount] = bestGameObj;
    cout << "ID: " << bestGameObj.getID() << endl;
    // get distance for path (if it exceeds the max, break the while loop)
    distanceTraveled += getDistance(Robot, bestGameObj);
    if (distanceTraveled > maxDistance) {
      break;
    }
    
    // only activates if robot can actually move
    objCount++;

    // object is scored, and cannot be scored further (change later to account for multiple goal areas and stuff)
    bestGameObj.setPointValue(0);
    
    // move robot (add degrees and stuff later, only change x/y position for now. also accuracy method will need improvement later)
    Robot.setX(bestGameObj.getX());
    Robot.setY(bestGameObj.getY());
    // set theta with inverse tangent of (gameObjX -robotX)/(gameObjY - robotY)
  }

  // update position of (and possibly other properties of) the robot
  this->Robot = Robot;
  return finPath;
}

