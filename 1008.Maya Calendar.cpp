#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main () {
	int T;
	cin >> T;
	cout << T << endl;
	string s;
	int y, day, md, d, s2, num;
	while(T--) {
		scanf("%d.",&d);
        cin >> s >> y;
        if(s == "pop") md = 0;
        if(s == "no") md = 20;
        if(s == "zip") md = 40;
        if(s == "zotz") md = 60;
        if(s == "tzec") md = 80;
        if(s == "xul") md = 100;
        if(s == "yoxkin") md = 120;
        if(s == "mol") md = 140;
        if(s == "chen") md = 160;
        if(s == "yax") md = 180;
        if(s == "zac") md = 200;
        if(s == "ceh") md = 220;
        if(s == "mac") md = 240;
        if(s == "kankin") md = 260;
        if(s == "muan") md = 280;
        if(s == "pax") md = 300;
        if(s == "koyab") md = 320;
        if(s == "cumhu") md = 340;
        if(s == "uayet") md = 360;

        day = d + md + y * 365 + 1;

        y = day / 260;
        day %= 260;
        if(day == 0) cout << 13 << " ahau " << y-1 << endl;
        else {
        	num = day % 13;
	        if(num == 0) num = 13;
	        s2 = day % 20;
	        if(s2 == 0) s2 = 20;
	        switch(s2) {
	            case 1 : s = "imix";break;
	            case 2 : s = "ik";break;
	            case 3 : s = "akbal";break;
	            case 4 : s = "kan";break;
	            case 5 : s = "chicchan";break;
	            case 6 : s = "cimi";break;
	            case 7 : s = "manik";break;
	            case 8 : s = "lamat";break;
	            case 9 : s = "muluk";break;
	            case 10 : s = "ok";break;
	            case 11 : s = "chuen";break;
	            case 12 : s = "eb";break;
	            case 13 : s = "ben";break;
	            case 14 : s = "ix";break;
	            case 15 : s = "mem";break;
	            case 16 : s = "cib";break;
	            case 17 : s = "caban";break;
	            case 18 : s = "eznab";break;
	            case 19 : s = "canac";break;
	            case 20 : s = "ahau";break;
	        }
        	cout << num << " " << s << " " << y << endl;
        }
	}
}