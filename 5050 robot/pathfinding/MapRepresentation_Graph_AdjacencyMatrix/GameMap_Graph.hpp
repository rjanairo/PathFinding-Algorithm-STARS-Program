#include "../GameObject/GameObject.hpp"

//Define a virtual map for the field as a directed graph, represented by an adjacency matrix
class GameMap_Graph
{
//Public class members
public:
    //Default constructor
    GameMap_Graph();

    //Constructor with parameters
    GameMap_Graph(unsigned short int numObjects);

    //Destructor
    ~GameMap_Graph();

    //Getter Functions
    float** getMap(); //return a pointer to the adjacency matrix
    unsigned short int getNumObjects(); //return the number of objects in the map

    //Setter functions (pass a constant reference to avoid wasted space of copying data)
    void setMap(const float** &map); //change the map
    void getnumObjects(const unsigned short int &numObjects); //change the number of objects in the map

    //Construction functions (to build the map)
    void constructMap(const GameObject* &GameObjectList); //build the map edges from a list

//Private class members
private:
    //private data members
    /*We want the map to consist of:
        A pointer to a 2D array (**map)
        The number of objects in the map (numObjects)
        A list of the game objects (*gameObjectList)
    */
    float** map;
    unsigned short int numObjects;
    GameObject* gameObjectList;
};