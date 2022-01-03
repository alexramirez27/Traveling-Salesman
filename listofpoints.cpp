#include "listofpoints.hpp"


//4) listofpoints.cpp-----------------------------------------------------
ListOfPoints::ListOfPoints() {}

void ListOfPoints::addPoint(Point &newPt) { 
  component.push_back(newPt); //adds point to the end of the list
}

void ListOfPoints::printList() const { 
  int actualSize = component.size(); //number of points in the Linked List
  int counter = 0;
  for(auto temp = component.begin(); temp != component.end(); temp++) {
      if (counter == actualSize - 1) //if last point, do not add "->""
        cout << temp->getName();
      else
        cout << temp->getName() << "->"; //if not last point, add "->"
      counter++;
  }
  cout << '\n';
}

void ListOfPoints::draw() const { //IMPLEMENT!!!
  cout << "drawing the points..." << endl;
  bool condition = true; //condition to decide whether to print "-"
  for (int col = 20; col >= 0; col--) { //20 columns
    for (int row = 0; row < 21; row++) { //20 rows
      for (auto temp = component.begin(); temp != component.end(); ++temp) {
        if (temp->getX() == row && temp->getY() == col) { 
          condition = false; //do not print "-"
          cout << temp->getName(); //print the name of the point
        }
      }
      if (condition == true)
        cout << "-"; //print "-"
      condition = true; //always set condition back to true at the end
    }
    cout << endl;
  }

}
 