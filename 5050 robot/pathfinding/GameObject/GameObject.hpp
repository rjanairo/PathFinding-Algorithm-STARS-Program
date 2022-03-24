#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

//Define a game object in terms of it's location, identification, size/area on map, point value, and whether or not it is a goal
class GameObject
{
//Public class members
public:
    //Default constructor
    GameObject();

    //Constructor with parameters (if unspecified, score is 0 and isGoal is false)
    GameObject(unsigned short int id, float x, float y, unsigned short int radiusBound_mm=1, signed short int score=0, bool isGoal=false);

    //Destructor
    ~GameObject();

    //Getter functions
    unsigned short int getID() const; //return the object id
    float getX() const; //return the x position of the object
    float getY() const; //return the y position of the object
    unsigned short int getRadiusBound_mm() const; //return the radius for the circular bound that represents the object size (in mm)
    signed short int getPointValue() const; //return the point value of the object (if it is properly scored)
    bool isGoalObject() const; //return whether or not the object is a goal or not

    //Setter functions (pass a constant reference to avoid wasted space of copying data)
    void setID(const unsigned short int &id); //change the id of the object
    void setX(const float &x); //change the x value of the object
    void setY(const float &y); //change the y value of the object
    void setRadiusBound_mm(const unsigned short int &radiusBound_mm); //change the radius bound of the object (in mm)
    void setPointValue(const signed short int &pointValue); //change the point value of an object
    void setIsGoalState(const bool &isGoal); //change whether an object is a goal or not
    void setObjectCoordinate(const float &x, const float &y); //change the coordinate of an object within a single function

//Private class members
private:
    //Private data members
    /*We want a game object to consist of:
        identifier (id) - non-negative integer
        point (x, y) - real value
        radiusBound_mm - non-negative integer
        score value (pointValue) - integer
        goal identifier (isGoal) - boolean
    */
    unsigned short int id; //????
    float x, y;
    unsigned short int radiusBound_mm;
    signed short int pointValue;
    bool isGoal;
};

#endif