#ifndef GAMEMAP_QUADTREE_HPP
#define GAMEMAP_QUADTREE_HPP

#include "QuadTreeNode.hpp"

//Define a virtual map for the field as a QuadTree
class GameMap_QuadTree
{
//Public class members
public:
    //Default constructor
    GameMap_QuadTree();

    //Constructor with parameters
    GameMap_QuadTree(float xLowerLimit, float xUpperLimit, float yLowerLimit, float yUpperLimit, unsigned short int maxNumObjects = 0);

    //Destructor
    ~GameMap_QuadTree();

    //Getter Functions
    const QuadTreeNode* getMap() const; //return a pointer to the root of the quad tree
    float getX_LowerLimit() const;
    float getX_UpperLimit() const;
    float getY_LowerLimit() const;
    float getY_UpperLimit() const;
    unsigned short int getMaxNumObjects() const;
    unsigned short int getNumObjects() const; //return the number of objects in the map
    const GameObject* getGameObjectArray() const;

    //Setter functions (pass a constant reference to avoid wasted space of copying data)
    void setMap(const QuadTreeNode &map); //change the map
    void setX_LowerLimit(const float xLowerLimit);
    void setX_UpperLimit(const float xUpperLimit);
    void setY_LowerLimit(const float yLowerLimit);
    void setY_UpperLimit(const float yUpperLimit);
    void setMaxNumObjects(const unsigned short int maxNumObjects);
    void setNumObjects(const unsigned short int numObjects); //change the number of objects in the map
    void setGameObjectArray(const GameObject& objectArr);

    //Misc. Functions
    bool isEmpty();
    bool isFilled();
    void addGameObject(GameObject& obj);
    void removeGameObject(GameObject& obj);
    void removeGameObjectWithID(unsigned short int ID);
    void removeGameObjectClosestToPoint(float x, float y);
    void removeGameObjectInPartitionContainingPoint(float x, float y);
    GameObject* getNeighborsFromPoint(float x, float y);
    GameObject* getNeighborsFromGameObject(GameObject obj);

    //Pathfinding Algorithms
    int** GameMap_QuadTree::GreedySearch();
    int** GameMap_QuadTree::A_StarSearch();

//Private class members
private:
    //private data members
    /*We want the map to consist of:
        A pointer to the root of the QuadTree (quadTreeRoot)
        The x lower and upper limits
        The y lower and upper limits
        The number of objects in the map (numObjects)
        Game Object Array
    */
    QuadTreeNode* quadTreeRoot;
    float xLowerLimit, xUpperLimit;
    float yLowerLimit, yUpperLimit;
    unsigned short int maxNumObjects;
    unsigned short int numObjects;
    GameObject* objectArr;
};

#endif