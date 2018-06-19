#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

string s;
int i;

struct Node
{
	char val;
	Node* left;
	Node* right;
	Node(char c) {
		val = c;
		left = NULL;
		right = NULL;
	}
};

Node* creatTree() {
	char ch = s[i++];
	if(ch == '#') return NULL;
	Node* node = new Node(ch);
	node->left = creatTree();
	node->right = creatTree();
	return node;
}

void inorderVisit(Node* node) {
	if(node != NULL) {
		inorderVisit(node->left);
		cout << node->val << " ";
		inorderVisit(node->right);
	}
}

int main () {
	cin >> s;
	i = 0;
	Node* root = creatTree();
	inorderVisit(root);
	cout << endl;
}