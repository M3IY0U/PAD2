#include "Tree.h"
#include <fstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	Tree<string> words;
	ifstream in("Heine.txt", ios::in);
	ofstream os("output.txt",ios::out);
	string temp;
	while (in >> temp) {
		words.insertNode(temp);
	}
	//cout << words.toString();
	os << words.inOrderTraversal();
	os.close();
}