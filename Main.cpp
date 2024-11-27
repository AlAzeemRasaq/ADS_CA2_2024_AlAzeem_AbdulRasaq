#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "BinaryTree.h"
#include "BSTNode.h"
using namespace std;

void question2();

int main() {
	question2();
}

// Create an application that reads in a text file and organises all of the unique words contained within the file by their first letter
void question2() {
	ifstream txtFile("TextFile.txt");
	string txtText;

	while (getline(txtFile, txtText)) {
		cout << txtText;
	}

	txtFile.close();
}

// Write a C++ application which will allow a user to view and search the data generated in stage 3
void question4() {

}