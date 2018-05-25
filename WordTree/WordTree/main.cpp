#include "Tree.h"
#include <fstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	Tree<string> words;
	unsigned wordCount = 0;
	ifstream in("Heine.txt", ios::in);
	ofstream os("output.txt", ios::out);
	string temp;
	while (in >> temp) {
		wordCount++;
		words.insertNode(temp);
	}
	cout << "Wörter insgesamt: " << wordCount << endl
		<< "Unterschiedliche Wörter: " << words.getNodeCount() << endl;
	os << words.inOrderTraversal();
	os.close();
}