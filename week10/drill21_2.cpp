#include "std_lib_facilities.h"
#include <map>

//3
template<typename T>
void kiir(T v, char elv = ' '){
	for(auto& a : v)
		cout << a.first << elv << a.second << '\n';
}


//5
void beker(map<string, int>& m)
{
    string s;
    int k = 0;
        for(int i=1; i<11; i++){
        	cin >> s >> k;
       	m.insert(make_pair(s, i));
        }
    }

int main(){
	//1
	map<string,int> msi;
	
	//2
	msi["Lecture"] = 21;
	msi["Notes"] = 31;
	msi["Bookmark"] = 41;
	msi["Pen"] = 51;
	msi["Laptop"] = 91;
	msi["Pendrive"] = 71;
	msi["Lunch"] = 29;
	msi["Papersheet"] = 23;
	msi["Notification"] = 33;
	msi["etc"] = 55;
	
	
	//3
	kiir(msi);
	
	//4
	msi.erase(msi.begin(),msi.end());
	
	//6
	cout << "\nÍrjon be adatokat! (név, id):\n";
	beker(msi);
	
	//7
	cout << "\nBevitt adatok:\n";
	kiir(msi);
	
	int sum = 0;
	for(auto& a : msi)
		sum +=  a.second;
	cout << "Értékek összege: " << sum << '\n';
	
	map<int, string> mis;
	
	for (const auto& a : msi)
        mis[a.second] = a.first;
    	cout << "\nFordított map:\n";
    	kiir(mis);
}
