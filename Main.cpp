#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "TreeMap.h"
#include "BinaryTree.h"
#include "BSTNode.h"
#include <algorithm>
#include <vector>
using namespace std;

void question2();
void question4();

int main() {
	//question2();
	question4();
	
	return 0;
}

// Create an application that reads in a text file and organises all of the unique words contained within the file by their first letter
void question2() {
	ifstream txtFile("TextFile.txt");

	if (!txtFile.is_open()) {
		cout << "Failed to open file." << endl;
		return;
	}

	TreeMap<char, BinaryTree<string>> wordOrg;

	string line;
	while (getline(txtFile, line)) {
		string word = "";
		for (int i = 0; i <= line.size(); i++) {
			char ch = (i < line.size()) ? line[i] : '.';

			if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
				word += ch;
			} else {
				if (!word.empty()) {
					char char1 = word[0];

					if (char1 >= 'A' && char1 <= 'Z')
						char1 = char1 - 'A' + 'a';

					if (!wordOrg.containsKey(char1)) {
						BinaryTree<string> newTree;
						wordOrg.put(char1, newTree);
					}
					
					wordOrg.get(char1).add(word);
					word = "";
				}
			}
		}
	}

	txtFile.close();

	cout << "Organised words by first letter: " << endl;
	BinaryTree<char> keys = wordOrg.keySet();
	char* keyArray = keys.toArray();
	int keyCount = keys.count();

	for (int i = 0; i < keyCount; i++) {
		char letter = keyArray[i];
		cout << letter << ": ";
		wordOrg.get(letter).printInOrder();
		cout << endl;
	}

	delete[] keyArray;
}

struct Anime {
	string name, author, studio, producer, year;
};

void loadData(const string& fileName, vector<Anime>& animeList) {
	ifstream file(fileName);
	if (!file) {
		cerr << "Cannot open file" << fileName << endl;
		return;
	}

	string line;
	getline(file, line);
	while (getline(file, line)) {
		istringstream ss(line);
		string name, author, studio, producer, year;

		getline(ss, name, ',');
		getline(ss, author, ',');
		getline(ss, studio, ',');
		getline(ss, producer, ',');
		getline(ss, year, ',');

		Anime anime = { name, author, studio, producer, year };
		animeList.push_back(anime);
	}
	file.close();
}

void displayData(const vector<Anime>& animeList) {
	cout << "\nAnime List: \n";
	for (const auto& anime : animeList) {
		cout << "Name: " << anime.name
			<< ", Author: " << anime.author
			<< ", Studio: " << anime.studio
			<< ", Producer: " << anime.producer
			<< ", Year: " << anime.year << "\n";
	}
}

void searchAnime(const vector<Anime>& animeList) {
	string keyword;
	cout << "Enter a keyword (Name/Author/Studio/Producer/Year): ";
	cin.ignore();
	getline(cin, keyword);

	bool found = false;
	for (const auto& anime : animeList) {
		if (anime.name.find(keyword) != string::npos ||
			anime.author.find(keyword) != string::npos ||
			anime.studio.find(keyword) != string::npos ||
			anime.producer.find(keyword) != string::npos ||
			anime.year.find(keyword) != string::npos) {

			cout << "Name: " << anime.name
				<< ", Author: " << anime.author
				<< ", Studio: " << anime.studio
				<< ", Producer: " << anime.producer
				<< ", Year: " << anime.year << "\n";
			found = true;
		}
	}
	if (!found) {
		cout << "No anime found with the keyword '" << keyword << "'\n";
	}
}

// Write a C++ application which will allow a user to view and search the data generated in stage 3
void question4() {
	vector<Anime> animeList;
	loadData("Anime.csv", animeList);

	if (animeList.empty()) {
		cout << "no data available. sorry." << endl; return;
	}

	while (true) {
		cout << "Menu: \n";
		cout << "1: View all anime \n";
		cout << "2. Search anime\n";
		cout << "3. Exit\n";
		cout << "Enter your choice: ";
		int choice;
		cin >> choice;

		switch (choice) {
		case 1:
			displayData(animeList);
			break;
		case 2:
			searchAnime(animeList);
			break;
		case 3:
			cout << "Exiting app...\n";
			return;
		default:
			cout << "Invalid choice.Please try again." << endl;
		}
	}
}
