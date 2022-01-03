#include "point.hpp"


//2) point.cpp--------------------------------------------------------------
float Point::getDistance(const Point &other) { 
  float xDistance = m_x - other.m_x; //x difference
  float yDistance = m_y - other.m_y; //y difference
  float totalDistance = sqrt(pow(xDistance, 2) + pow(yDistance, 2));

  return totalDistance;
}

string Point::toString() const{
  // examples how to create string from small parts
  string str(m_name);
  str += " = (";
  str += std::to_string(m_x);
  str.append(",").append(std::to_string(m_y)).append(")");
  return str;
}


void Point::printPoint() const{
  cout << toString() << endl;
}

// used for printing Point using << operator.
// For example, the following code will work
// Point origin(0,0,'O');
// cout << origin;
ostream& operator<<(ostream &os, const Point &p) {
  return os << p.toString();
}


class LLnode {
  private:
    Point data; //Node of type Point to use in Linked List
    LLnode* next;
  public:
    //Point data;
	  //LLnode* next;

    // default constructor
    // sets the value to be 0
    LLnode() {
        //cout << "default constructor for LLnode" << endl;
        setData(0, 0, "P");
        setNext(NULL);
    }
    
    // constructor with value
    LLnode(int pxvalue, int pyvalue, string name) {
        //constructing a LLnode with values "pxvalue" and "pyvalue"
        //and next points to NULL
        setData(pxvalue, pyvalue, name);
        setNext(NULL); 
    }

    // constructor with value and next
    LLnode(int pxvalue, int pyvalue, string name, LLnode* n) {
        //constructing a LLnode with values "pxvalue" and "pyvalue"
        //and next points to n
        setData(pxvalue, pyvalue, name);
        setNext(n);
    }

    // get node
    LLnode* getNext() {
        return next;
    }

    // set node
    void setNext(LLnode* next_node) {
        next = next_node;
    }

    // get data
    Point getData() {
        return data;
    }

    // set data
    void setData(int xvalue, int yvalue, string name) {
        data = Point(xvalue, yvalue, name);
    }
};
