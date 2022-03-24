#include "GameObject.hpp"

//Default constructor
GameObject::GameObject()
{
    this->id = 0;
    this->x = 0;
    this->y = 0;
    this->radiusBound_mm = 0;
    this->pointValue = 0;
    this->isGoal = false;
}

//Constructor with parameters (if unspecified, radiusBound (in mm) is 1, score is 0, and isGoal is false)
GameObject::GameObject(unsigned short int id, float x, float y, unsigned short int radiusBound_mm, signed short int score=0, bool isGoal=false)
{
    this->id = id;
    this->x = x;
    this->y = y;
    this->radiusBound_mm = radiusBound_mm;
    this->pointValue = pointValue;
    this->isGoal = isGoal;
    return;
}

/*=====Getter functions=====*/
unsigned short int GameObject::getID() const //return the object id
{
    return(this->id);
}

float GameObject::getX() const //return the x position of the object
{
    return(this->x);
}

float GameObject::getY() const //return the y position of the object
{
    return(this->y);
}

unsigned short int GameObject::getRadiusBound_mm() const //return the radius for the circular bound that represents the object size (in mm)
{
    return(this->radiusBound_mm);
}

signed short int GameObject::getPointValue() const //return the point value of the object (if it is properly scored)
{
    return(this->pointValue);
}

bool GameObject::isGoalObject() const //return whether or not the object is a goal or not
{
    return(this->isGoal);
}

/*=====Setter functions=====*/
void GameObject::setID(const unsigned short int &id) //change the id of the object
{
    this->id = id;
    return;
}

void GameObject::setX(const float &x) //change the x value of the object
{
    this->x = x;
    return;
}

void GameObject::setY(const float &y) //change the y value of the object
{
    this->y = y;
    return;
}

void GameObject::setRadiusBound_mm(const unsigned short int &radiusBound_mm) //change the radius bound of the object (in mm)
{
    this->radiusBound_mm = radiusBound_mm;
    return;
}

void GameObject::setPointValue(const signed short int &pointValue) //change the point value of an object
{
    this->pointValue = pointValue;
    return;
}
void GameObject::setIsGoalState(const bool &isGoal) //change whether an object is a goal or not
{
    this->isGoal = isGoal;
    return;
}

void GameObject::setObjectCoordinate(const float &x, const float &y) //change the coordinate of an object within a single function
{
    this->x = x;
    this->y = y;
    return;
}