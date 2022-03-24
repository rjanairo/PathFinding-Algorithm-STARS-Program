#include "GameMap_QuadTree.hpp"

//Default constructor
GameMap_QuadTree::GameMap_QuadTree()
{
    this->quadTreeRoot = nullptr;
    this->xLowerLimit = 0;
    this->xUpperLimit = 0;
    this->yLowerLimit = 0;
    this->yUpperLimit = 0;
    this->numObjects = 0;
    this->objectArr = nullptr;
}

//Constructor with parameters
GameMap_QuadTree::GameMap_QuadTree(float xLowerLimit, float xUpperLimit, float yLowerLimit, float yUpperLimit, unsigned short int numObjects)
{
    this->quadTreeRoot = nullptr;
    this->xLowerLimit = xLowerLimit;
    this->xUpperLimit = xUpperLimit;
    this->yLowerLimit = yLowerLimit;
    this->yUpperLimit = yUpperLimit;
    this->numObjects = numObjects;
    //case for 0 game objects specified
    if(numObjects == 0)
    {
        this->objectArr = nullptr;
    }
    //case for non-zero game objects specified
    else
    {
        this->objectArr = new GameObject[numObjects];
    }
}

//Getter Functions
const QuadTreeNode* GameMap_QuadTree::getMap() const //return a pointer to the root of the quad tree
{
    return(this->quadTreeRoot);
}
float GameMap_QuadTree::getX_LowerLimit() const
{
    return(this->xLowerLimit);
}
float GameMap_QuadTree::getX_UpperLimit() const
{
    return(this->xUpperLimit);
}
float GameMap_QuadTree::getY_LowerLimit() const
{
    return(this->yLowerLimit);
}
float GameMap_QuadTree::getY_UpperLimit() const
{
    return(this->yUpperLimit);
}
unsigned short int GameMap_QuadTree::getMaxNumObjects() const
{
    return(this->maxNumObjects);
}
unsigned short int GameMap_QuadTree::getNumObjects() const //return the number of objects in the map
{
    return(this->numObjects);
}
const GameObject* GameMap_QuadTree::getGameObjectArray() const
{
    return(this->objectArr);
}

//Setter functions (pass a constant reference to avoid wasted space of copying data)
void GameMap_QuadTree::setMap(const QuadTreeNode &map) //change the map
{
    *(this->quadTreeRoot) = map;
}
void GameMap_QuadTree::setX_LowerLimit(const float xLowerLimit)
{
    this->xLowerLimit = xLowerLimit;
}
void GameMap_QuadTree::setX_UpperLimit(const float xUpperLimit)
{
    this->xUpperLimit = xUpperLimit;
}
void GameMap_QuadTree::setY_LowerLimit(const float yLowerLimit)
{
    this->yLowerLimit = yLowerLimit;
}
void GameMap_QuadTree::setY_UpperLimit(const float yUpperLimit)
{
    this->yUpperLimit = yUpperLimit;
}
void GameMap_QuadTree::setMaxNumObjects(const unsigned short int maxNumObjects) //change the number of objects in the map
{
    //exit if same value used
    if(this->maxNumObjects == maxNumObjects)
    {
        return;
    }

    //declare new array to copy into
    GameObject* temp = new GameObject[maxNumObjects];
    unsigned short int numCopies;
    
    //increase space
    if (this->maxNumObjects < maxNumObjects)
    {
        numCopies = this->maxNumObjects;
    }
    
    //decrease space
    else
    {
        numCopies = maxNumObjects;
    }
    
    //copy data to new array
    for(unsigned short int i = 0; i < numCopies; i++)
    {
        temp[i] = this->objectArr[i];
    }
    
    //delete the previous list
    delete[] this->objectArr;
    
    //set the new list
    this->maxNumObjects = maxNumObjects;
    this->objectArr = temp;
}
void GameMap_QuadTree::setNumObjects(const unsigned short int numObjects) //change the number of objects in the map
{
    this->numObjects = numObjects;
}
void GameMap_QuadTree::setGameObjectArray(const GameObject& objectArr)
{
    *(this->objectArr) = objectArr;
}

//Misc. Functions
bool GameMap_QuadTree::isEmpty()
{
    return(quadTreeRoot == nullptr);
}
bool GameMap_QuadTree::isFilled()
{
    return(numObjects == maxNumObjects);
}
void GameMap_QuadTree::addGameObject(GameObject& obj)
{
    //Create a root node
    if(quadTreeRoot == nullptr)
    {
        quadTreeRoot = new QuadTreeNode((xLowerLimit+xUpperLimit)/2.0, (yLowerLimit+yUpperLimit)/2.0, &obj);
        return;
    }

    //Add a node to the tree
    else
    {

    }
}
void GameMap_QuadTree::removeGameObject(GameObject& obj);
void GameMap_QuadTree::removeGameObjectWithID(unsigned short int ID);
void GameMap_QuadTree::removeGameObjectClosestToPoint(float x, float y);
void GameMap_QuadTree::removeGameObjectInPartitionContainingPoint(float x, float y);
GameObject* GameMap_QuadTree::getNeighborsFromPoint(float x, float y);
GameObject* GameMap_QuadTree::getNeighborsFromGameObject(GameObject obj);