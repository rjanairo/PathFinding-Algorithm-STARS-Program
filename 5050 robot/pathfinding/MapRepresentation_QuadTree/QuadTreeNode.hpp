#ifndef QUADTREENODE_HPP
#define QUADTREENODE_HPP

#include "../GameObject/GameObject.hpp"

//Specify what a node within the quadtree looks like
class QuadTreeNode
{
//Public class members
public:
    //Default constructor
    QuadTreeNode();

    //Constructor with parameters
    QuadTreeNode(float xCenter, float yCenter, GameObject* objectData = nullptr);

    //Destructor
    ~QuadTreeNode();

    //getter functions
    const GameObject* getGameObject() const;
    float getCenterX() const;
    float getCenterY() const;

    //Setter functions (pass a constant reference to avoid wasted space of copying data)
    void setGameObject(const GameObject &objectData);
    void setCenterX(const float xCenter);
    void setCenterY(const float yCenter);

//Private class members
private:
    /*We want to QuadTreeNode to consist of:
        CenterX value and CenterY value
        A Game Object (objectData)
        Parent node
        4 child nodes (upper left, upper right, lower left, lower right)
    */
    float xCenter, yCenter;
    GameObject* objectData; //data containing the game object for the node
    QuadTreeNode* parent;
    QuadTreeNode* upperLeft; //upper left child node
    QuadTreeNode* upperRight; //upper right child node
    QuadTreeNode* lowerLeft; //lower left child node
    QuadTreeNode* lowerRight; //lower right child node

    //The QuadTreeNode class entrusts its data to its friend class (GameMap_QuadTree)
    friend class GameMap_QuadTree;
};

#endif