/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for assignment 
Fall 2019

Written by Ayse Kucukyilmaz

This file is a representative test file. 
During marking, we will use the exact same notation 
as provided in the brief, so make sure
you follow that guideline. Also make sure that you don't 
change the main body provided to you here.
Otherwise, your code may not pass the test cases...

GOOD LUCK! 

------------------------------------------------------ */

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string userCommand;
	vector <Shape*> shapes;     // this one will hold your shapes
	vector <string> parameters; // this one will hold parameters for the commands


	while (userCommand.compare("exit") != 0) 
	{
		cout << "Enter the command: ";
		
		getline(cin, userCommand);

		char * cstr = new char[userCommand.length() + 1];

		strcpy_s(cstr, userCommand.length()+1, userCommand.c_str());
		
		// implement a string tokenizer to populate the parameters vector 
		// check function strtok_s
		char* nextToken;
		char* tokenized = strtok_s(cstr, " ", &nextToken); //tokenises the string by " "
		while (tokenized != NULL)
		{
			parameters.push_back(tokenized); //tokenised string is added to the parameters vector
			tokenized = strtok_s(NULL, " ", &nextToken);
		}

		// as a result of the process, parameters[0] should hold your command, followed by your parameters 
		string command = parameters[0];


		if (command.compare("addR") == 0) {
			if (parameters.size() == 5) { //checks to see if correct amount of parameters have been input

				int x = stoi(parameters[1].c_str()); //takes in the parameters for the object in the correct order
				int y = stoi(parameters[2].c_str());
				int h = stoi(parameters[3].c_str());
				int w = stoi(parameters[4].c_str());

				Rectangle* r = new Rectangle(x, y, h, w); //new keyword dynamically allocates memory for the rectangle object which is constructed using the parameters
				//this rectangle type object is assigned to a pointer called r

				shapes.push_back(r); //object is added to the shapes vector
				cout << r; //operator overloading is used so that cout prints the rectangle object
			}
			else { //error message to remind the user of the correct input format
				std::cout << "Parameters have not been input correctly. The correct format is: X Y height width";
			}
		}

		else if (command.compare("addS") == 0) {
			if (parameters.size() == 4) {

				int x = stoi(parameters[1].c_str());
				int y = stoi(parameters[2].c_str());
				int e = stoi(parameters[3].c_str());
	
				Square* s = new Square(x, y, e); //new keyword dynamically allocates memory for the square object which is constructed using the parameters
				//this square type object is assigned to a pointer called s
				shapes.push_back(s);
				cout << s;
			}
			else {
				std::cout << "Parameters have not been input correctly. The correct format is: X Y edge";
			}
		}

		else if (command.compare("addC") == 0) {

			if (parameters.size() == 4) {	//checks to see if correct amount of parameters are input
				int x = stoi(parameters[1].c_str());
				int y = stoi(parameters[2].c_str());
				int r = stoi(parameters[3].c_str());

				Circle* c = new Circle(x, y, r); //new keyword dynamically allocates memory for the circle object which is constructed using the parameters
				//this circle type object is assigned to a pointer called r
				shapes.push_back(c);
				cout << c;
			}
			else {
				std::cout << "parameters have not been input correctly. The correct format is X Y radius";
			}
		}

		else if (command.compare("scale") == 0) { 
			int shapeNo = stoi(parameters[1].c_str());
			float scaleX = stoi(parameters[2].c_str());
			float scaleY = stoi(parameters[3].c_str());

			if (shapeNo < shapes.size() + 1 && shapeNo >= 0) {	//checks to see if shape exists at this index
				dynamic_cast<Movable*>(shapes[shapeNo - 1])->scale(scaleX, scaleY); //scale is called for pointer at index (scale and toString are virtual)
				cout << shapes[shapeNo - 1]->toString();
			}
			else {
				std::cout << "No shape exists at this index!";
			}
		}

		else if (command.compare("move") == 0) {
			// moves object at index 

			int shapeNo = stoi(parameters[1].c_str()); // read from parameters
			int x = stoi(parameters[2].c_str());
			int y = stoi(parameters[3].c_str());
			
			if (shapeNo < shapes.size() + 1 && shapeNo >= 0) {	//checks to see if a shape exists at this index
				Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
				m->move(x, y);	//move is used on this pointer to give the object a new x and y (move is virtual and so is toString)
				cout << shapes[shapeNo - 1]->toString();	//objects new coordinates are printed
			}
			else {
				std::cout << "No shape exists at this index!" << std::endl;
			}		
		}
		
		else if (command.compare("display") == 0) { //iterates through the vector and prints all shapes in order of input
			std::vector<Shape*>::iterator pointers;
			for (pointers = shapes.begin(); pointers < shapes.end(); pointers++)
			{
				cout << (*pointers)->toString() << endl;
			}
		}

		else if (command.compare("clear") == 0) { //iterates through the vector and destructs all objects then clears the vector
			std::vector<Shape*>::iterator pointers;
			for (pointers = shapes.begin(); pointers < shapes.end(); pointers++) {
				delete *pointers;
			}
			std::cout << "Memory successfully cleared" << std::endl;
			shapes.clear();
		}

		else { //if invalid commands are entered, the console will inform the user and restart the loop
			std::cout << "Invalid command, try again\n" << std::endl;
		}
		cout << endl << endl;

		if (command != "exit") { //clears all vectors except for shape if the loop resets
			parameters.clear();
			userCommand.clear();
			command.clear();
		}
	}

	cout << "Press any key to continue...";
	std::getchar();

	return 0;
}
