#include "QuadTreeNode.hpp"

//Default constructor
QuadTreeNode::QuadTreeNode()
{
    //default data for a QuadTreeNode
    this->xCenter = 0;
    this->yCenter = 0;
    this->objectData = nullptr; //data containing the game object for the node
    this->parent = nullptr;
    this->upperLeft = nullptr; //upper left child node
    this->upperRight = nullptr; //upper right child node
    this->lowerLeft = nullptr; //lower left child node
    this->lowerRight = nullptr; //lower right child node
}

//Constructor with parameters
QuadTreeNode::QuadTreeNode(float xCenter, float yCenter, GameObject* objectData)
{
    //specified data for a QuadTreeNode
    this->xCenter = xCenter;
    this->yCenter = yCenter;
    this->objectData = objectData; //data containing the game object for the node
    this->parent = nullptr;
    this->upperLeft = nullptr; //upper left child node
    this->upperRight = nullptr; //upper right child node
    this->lowerLeft = nullptr; //lower left child node
    this->lowerRight = nullptr; //lower right child node
}

//getter functions
float QuadTreeNode::getCenterX() const
{
    return(this->xCenter);
}

float QuadTreeNode::getCenterY() const
{
    return(this->yCenter);
}

const GameObject* QuadTreeNode::getGameObject() const
{
    return(this->objectData);
}

//Setter functions (pass a constant reference to avoid wasted space of copying data)
void QuadTreeNode::setGameObject(const GameObject &objectData)
{
    *(this->objectData) = objectData;
}

void QuadTreeNode::setCenterX(const float xCenter)
{
    this->xCenter = xCenter;
}

void QuadTreeNode::setCenterY(const float yCenter)
{
    this->yCenter = yCenter;
}