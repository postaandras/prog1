#include "std_lib_facilities.h"
#include <fstream>

template<typename C> void kiir(const C& c, char elv = '\n')
{
    for (const auto elem : c)
        cout << elem << elv;

    cout << '\n';
}

//9
struct Less_than {
   private:
	double v;
   public:
   Less_than(double vv) : v{vv} {}
   
   bool operator()(const double ertek) {return ertek<v;}
   };

int main(){
	//1
	vector<double> vd;
	ifstream bemenet {"szamok.txt"};
	for(float f; bemenet >> f;) vd.push_back(f);
	
	//2
	kiir(vd);
	
	//3
	vector<int> vi (vd.size());
	copy(vd.begin(), vd.end(), vi.begin());
	
	//4
	for (int i = 0; i < vi.size(); i++){
		cout << "1: " << vd[i] << ", 2: " << vi[i] << '\n';
	}
	
	//5
	float osszeg = 0;
	for (int i = 0; i<vd.size(); i++){
		osszeg += vd[i];
	}
	cout << "Az eredeti vektor elemeine összege:" << osszeg << "\n";

	int osszeg2 = 0;
	for (int i = 0; i<vi.size(); i++){
		osszeg2 += vi[i];
	}
	cout << "A levágott vektor elemeine összege:" << osszeg2 << "\n";
	
	//6
	cout << "Az erredeti és a levágott vektor elemeinek összegeinek a különbsége:" << osszeg-osszeg2 << "\n";


	//7
	reverse(vd.begin(), vd.end());
	cout << "/n Az eredeti vektor megfordítva: \n";
	kiir(vd);
	
	
	//8
	double vd_kozep = osszeg / vd.size();
	cout << "Az eredeti vektor középértéke: " << vd_kozep << "\n";
	
	//9
	vector<double> vd2(vd.size());
	auto it = copy_if(vd.begin(), vd.end(), vd2.begin(),Less_than(vd_kozep));
	vd2.resize(distance(vd2.begin(), it));
	cout << "\n A középértéknél nagyobb elemek \n";
	kiir(vd2);
	
	//10
	sort(vd.begin(), vd.end());
	cout << "\n Az eredeti vektor rendezve:\n";
	kiir(vd);
}
