#include "std_lib_facilities.h"
#include <list>

//1. Struktúra készítése
struct Item { 
	string name; 
	int iid; 
	double value;

};

//1. Operátor elkészítése a bevitelhez
istream& operator>>(istream& is, Item& it){
	is >> it.name >> it.iid >> it.value;
	Item {it.name,it.iid,it.value};
	return is;
}

//1. Operátor elkészítése a kiíratáshoz
ostream& operator<<(ostream& os, const Item& it)
{
    return os << it.name << ' '
              << it.iid << ' '
              << it.value;
}


//1. Template elkészítése a kiíratáshoz
template<typename T>
void print(T v, char elv = ' '){
	for(auto& a : v){
		cout << a << elv << '\n';
	}
}


//2
struct nev_szerint{
	bool operator()(Item& it1, Item& it2)
			{ return it1.name < it2.name;}
};

//3
struct iid_szerint{
	bool operator()(Item& it1, Item& it2)
			{ return it1.iid < it2.iid;}
};

//4
struct ertek_szerint_csokkeno{
	bool operator()(Item& it1, Item& it2)
			{ return it1.value > it2.value;}
};


// 6.
class nev_szerinti_torles {
    string name;
public:
    nev_szerinti_torles(const string& nn) : name{nn} { }
    bool operator()(const Item& x) const { return x.name == name; }
};


// 7.
class iid_szerinti_torles {
    int iid;
public:
    iid_szerinti_torles(int id) : iid{id} { }
    bool operator()(const Item& x) const { return x.iid == iid; }
};


int main(){
	//1
	vector<Item> vi;
	
	//1. Létrehozott vektor feltöltése;
	ifstream ifile {"dolgok.txt"};
	for(Item it; ifile >> it;){//while(ifile >> it.name >> it.iid >> it.value){
		vi.push_back(it);//Item {it.name,it.iid,it.value});
	}
	cout << "Alap vektor:\n";
	print(vi);

	ifile.close();
	//2
	sort(vi.begin(),vi.end(),nev_szerint());
		//[](Item& f1, Item& f2){return f1.name < f2.name;});
	cout << "\nNév szerinti szortírozás:\n";
	print(vi);
	
	//3
	sort(vi.begin(),vi.end(),iid_szerint());
	cout << "\nIid szerinti szortírozás:\n";
	print(vi);

	//4
	sort(vi.begin(),vi.end(),ertek_szerint_csokkeno());
	cout << "\nÉrték szeritn csökkenő szortírozás:\n";
	print(vi);

	//5
	vi.push_back(Item {"horse shoe",99,12.34}); 
	vi.push_back(Item {"Canon S400", 9988,499.95});
	cout << "\nÉrtékek hozzáadása után:\n";
	print(vi);
	
	
	// 6.
	vi.erase(find_if(vi.begin(), vi.end(), nev_szerinti_torles("matrac")));
	vi.erase(find_if(vi.begin(), vi.end(), nev_szerinti_torles("alma")));
	
	// 7.
	vi.erase(find_if(vi.begin(), vi.end(), iid_szerinti_torles(12)));
	vi.erase(find_if(vi.begin(), vi.end(), iid_szerinti_torles(1976)));
	
	cout << "\nÉrtékek törlése után:\n";
	print(vi);
	
	
	
	
	//8
	
	
	list<Item> li;
	ifile.open("dolgok.txt");
	for(Item it; ifile >> it;) li.push_back(it);
	cout << "\nAlap lista\n";
	print(li);
	
	li.sort([](const Item& a, const Item& b) { return a.name < b.name; });
	cout << "\nLista név szerint szortírozva:\n";
	print(li);
	
	li.sort([](const Item& a, const Item& b) { return a.iid < b.iid; });
	cout << "\nLista iid szerint szortírozva:\n";
	print(li);
	
	li.sort([](const Item& a, const Item& b) { return a.value > b.value; });
	cout << "\nLista érték szerint csökkenő sorrendben szortírozva:\n";
	print(li);
	
	li.push_back(Item {"horse shoe",99,12.34}); 
	li.push_back(Item {"Canon S400", 9988,499.95});
	
	cout << "\nLista a hozzáadott elemek után:\n";
	print(li);
	
	li.erase(find_if(li.begin(), li.end(), nev_szerinti_torles("matrac")));
	li.erase(find_if(li.begin(), li.end(), nev_szerinti_torles("alma")));

	li.erase(find_if(li.begin(), li.end(), iid_szerinti_torles(12)));
	li.erase(find_if(li.begin(), li.end(), iid_szerinti_torles(1976)));
	
	cout << "\niLista a törölt elemek után:\n";
	print(li);
}
