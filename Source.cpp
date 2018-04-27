#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <ctime>
#include <stdlib.h>

using namespace std;

vector<vector<int>> aim = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 0 } };
vector<vector<int>> init = { { 1, 2, 3 }, { 4, 0, 5 }, { 7, 8, 6 } };

string result_string;

bool solved = false;

vector <pair<vector<vector<int>>, string>> storage;

int convert(int ascii, int add = 3) {
	return ((ascii + add) % 95);
}


bool Contain(vector<vector<int>> vector) {
	for (int i = storage.size() - 1; i >= 0; i--) {
		if (storage[i].first == vector) {
			return true;
		}
	}
	return false;
}

void Display_vector(vector<vector<int>> vector) {
	for (unsigned i = 0; i < vector.size(); i++) {
		for (unsigned j = 0; j < vector[i].size(); j++) {
			cout << vector[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-------------" << endl;
}

void Swaps(pair<vector<vector<int>>, string> puzzle) {
	vector<vector<int>> num = puzzle.first;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			num = puzzle.first;
			if (num[i][j] == 0) {
				//UP
				if (j - 1 >= 0 && (puzzle.second[puzzle.second.size() - 1] != '2' || puzzle.second.size() == 1)) {
					swap(num[i][j - 1], num[i][j]);
					if (aim == num) {
						//cout << "Solved :D" << endl;
						//Display_vector(num);
						solved = true;
						pair<vector<vector<int>>, string> temp;
						temp.first = num;
						temp.second = puzzle.second + "1";
						result_string = temp.second;
						storage.push_back(temp);
						return;
					}
					else if (true) {
						pair<vector<vector<int>>, string> temp;
						temp.first = num;
						temp.second = puzzle.second + "1";
						storage.push_back(temp);
					}
				}

				//DOWN
				num = puzzle.first;
				if (j + 1 <= 2 && (puzzle.second[puzzle.second.size() - 1] != '1' || puzzle.second.size() == 1)) {
					swap(num[i][j + 1], num[i][j]);
					if (aim == num) {
						//cout << "Solved :D" << endl;
						//Display_vector(num);
						solved = true;
						pair<vector<vector<int>>, string> temp;
						temp.first = num;
						temp.second = puzzle.second + "2";
						result_string = temp.second;
						storage.push_back(temp);
						return;
					}
					else if (true) {
						pair<vector<vector<int>>, string> temp;
						temp.first = num;
						temp.second = puzzle.second + "2";
						storage.push_back(temp);
					}
				}
				//LEFT
				num = puzzle.first;
				if (i - 1 >= 0 && (puzzle.second[puzzle.second.size() - 1] != '4' || puzzle.second.size() == 1)) {
					swap(num[i - 1][j], num[i][j]);
					if (aim == num) {
						solved = true;
						pair<vector<vector<int>>, string> temp;
						temp.first = num;
						temp.second = puzzle.second + "3";
						result_string = temp.second;
						storage.push_back(temp);
						return;
					}
					else if (true) {
						pair<vector<vector<int>>, string> temp;
						temp.first = num;
						temp.second = puzzle.second + "3";
						storage.push_back(temp);
					}
				}

				//RIGHT
				num = puzzle.first;
				if (i + 1 <= 2 && (puzzle.second[puzzle.second.size() - 1] != '3' || puzzle.second.size() == 1)) {
					swap(num[i + 1][j], num[i][j]);
					if (aim == num) {
						solved = true;
						pair<vector<vector<int>>, string> temp;
						temp.first = num;
						temp.second = puzzle.second + "4";
						result_string = temp.second;
						storage.push_back(temp);
						return;
					}
					else if (true) {
						pair<vector<vector<int>>, string> temp;
						temp.first = num;
						temp.second = puzzle.second + "4";
						storage.push_back(temp);
					}
				}
				return;
			}
		}
	}
}

int main() {
	/////////////////
	srand(time(NULL)); //random number generator created;
	string text;
	cout << "Enter the text you wanna encrypt: ";
	getline(cin, text); // get the text;

	vector<vector<int>> puzzle = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 0 } };
	//Display_vector(puzzle);
	//cout << endl;
	string ways;
	for (int i = 0; i < 20; i++) {
		ways += to_string(rand() % 4);
	}
	//cout << ways << endl;


	bool up = false, down = false, left = false, right = false;

	int swaps = 0;
	int random;

	int random_way = 0;
	for (int k = 0; k < (rand() % 7) + 200; k++) {
		for (int i = 0; i < puzzle.size(); i++) {
			for (int j = 0; j < puzzle.size(); j++) {
				if (puzzle[i][j] == 0) {
					random = (rand() % 4) + 1;
					//Up;
					if (j - 1 >= 0) {
						random--;
						if (random == 0) {
							swap(puzzle[i][j - 1], puzzle[i][j]);
							goto endloop;
						}
					}
					//Down;
					if (j + 1 < 3) {
						random--;
						if (random == 0) {
							swap(puzzle[i][j + 1], puzzle[i][j]);
							goto endloop;
						}
					}
					//Left;
					if (i - 1 >= 0) {
						random--;
						if (random == 0) {
							swap(puzzle[i - 1][j], puzzle[i][j]);
							goto endloop;
						}
					}
					//Right;
					if (i + 1 < 3) {
						swap(puzzle[i + 1][j], puzzle[i][j]);
						goto endloop;
					}

				}
			}
		}
	endloop:;
	}
	init = puzzle;



	////////////////////
	//Display_vector(init);
	////////////////////
	pair <vector<vector<int>>, string> temp;
	temp.first = init;
	temp.second = "1";
	storage.push_back(temp);

	int floor = 1;
	int size;

	while (!solved) {
		size = storage.size();
		for (int i = size - 1; i >= 0; i--) {
			if (storage[i].second.size() == floor) {
				Swaps(storage[i]);
				//Sleep(1000);
				if (solved) {
					break;
				}
			}
			else {
				break;
			}
		}
		floor++;
	}

	vector<vector<vector<int>>> answers;

	for (int i = result_string.size(); i >= 1; i--) {
		string temp = result_string.substr(0, i);
		for (unsigned j = storage.size() - 1; j >= 0; j--) {
			if (storage[j].second == temp) {
				//Display_vector(storage[j].first);
				answers.push_back(storage[j].first);
				break;
			}
		}
	}

	vector<int> values;

	for (int k = 0; k < answers.size(); k++) {
		int sum = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				sum += answers[k][i][j] * ((j * 3) + (i + 1));
			}
		}
		values.push_back(sum);
	}
	vector<int> values_copy = values;
	if (text.size() > values_copy.size()) {
		for (int i = 0; i < text.size() / values_copy.size(); i++) {
			for (int j = 0; j < values_copy.size(); j++) {
				values.push_back(values_copy[j]);
			}
		}
		for (int i = 0; i < text.size() % values_copy.size(); i++) {
			values.push_back(values_copy[i]);
		}
	}
	char ch;
	int ascii;
	string encrypted;
	for (int i = 0; i < text.size(); i++) {
		ch = text[i];
		if (ch >= 32 && ch <= 126) {
			ascii = ch;
			ascii = convert(ascii - 32, values[i]);
			ch = static_cast<char>(ascii + 32);
			encrypted += ch;
		}
		else {
			encrypted += '|';
		}
	}
	string pass;
	for (int i = 0; i < init.size(); i++) {
		for (int j = 0; j < init.size(); j++) {
			pass += to_string(init[i][j]);
		}
	}
	cout << "Encrypted message: " << encrypted << endl;
	cout << "Password: " << pass << endl;
	cout << "Good bye!" << endl;
}
