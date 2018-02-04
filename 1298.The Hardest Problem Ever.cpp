#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;

int main () {
	string start, content, end;
	map<char, char> mymap;
	mymap['A'] = 'V';
	mymap['B'] = 'W';mymap['C'] = 'X';mymap['D'] = 'Y';mymap['E'] = 'Z';mymap['F'] = 'A';
	mymap['G'] = 'B';mymap['H'] = 'C';mymap['I'] = 'D';mymap['J'] = 'E';mymap['K'] = 'F';
	mymap['L'] = 'G';mymap['M'] = 'H';mymap['N'] = 'I';mymap['O'] = 'J';mymap['P'] = 'K';
	mymap['Q'] = 'L';mymap['R'] = 'M';mymap['S'] = 'N';mymap['T'] = 'O';mymap['U'] = 'P';
	mymap['V'] = 'Q';mymap['W'] = 'R';mymap['X'] = 'S';mymap['Y'] = 'T';mymap['Z'] = 'U';
	while(cin >> start) {
		if(start == "ENDOFINPUT") break;
		if(start == "START") {
			getchar();
			getline(cin, content);
			cin >> end;
			for(int i = 0; i < content.length(); i++) {
				if(content[i] >= 'A' && content[i] <= 'Z') cout << mymap[content[i]];
				else cout << content[i];
			}
			cout << endl;
		}
	}
}