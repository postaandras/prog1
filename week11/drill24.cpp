#include "std_lib_facilities.h"
#include "matrix.h"
#include <complex>

using Numeric_lib::Matrix;

void kiir_sqrt(){
	int ertek;
	cin >> ertek;
	if(ertek<0){
		cout << "\nNegatív számnak nincsen gyöke\n";
	}
	else{
		cout << sqrt(ertek) << "\n";
	}
}


int main(){

    // 1.
    cout << "Tárolók mérete:\n"
         << "char: " << sizeof(char) << '\n'
         << "short: " << sizeof(short) << '\n'
         << "int: " << sizeof(int) << '\n'
         << "long: " << sizeof(long) << '\n'
         << "float: " << sizeof(float) << '\n'
         << "double: " << sizeof(double) << '\n'
         << "int*: " << sizeof(int*) << '\n'
         << "double*: " << sizeof(double*) << "\n\n";
    
    //2
    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int,2> d(10,10);
    Matrix<int,3> e(10,10,10);

    cout << "Mátrixok mérete:\n"
              << "Matrix<int>(10): " << sizeof(a) << '\n'
              << "Matrix<int>(100): " << sizeof(b) << '\n'
              << "Matrix<double>(10): " << sizeof(c) << '\n'
              << "Matrix<int,2>(10,10): " << sizeof(d) << '\n'
              << "Matrix<int,3>(10,10,10): " << sizeof(e) << "\n\n";
    
    // 3
    cout << "Mátrixok elemszáma:\n"
              << "Matrix<int>(10): " << a.size() << '\n'
              << "Matrix<int>(100): " << b.size() << '\n'
              << "Matrix<double>(10): " << c.size() << '\n'
              << "Matrix<int,2>(10,10): " << d.size() << '\n'
              << "Matrix<int,3>(10,10,10): " << e.size() << "\n\n";
    
    //4
    cout << "Írjon be integereket gyökvonásra:\n";
    for(int i=0; i<8; i++){
    	kiir_sqrt();
    }
	
    //5
    cout << "\nÍrjon be 10 lebegőpontos számot:\n";
    Matrix<double> szamok(10);
    for(int i=0; i<10; i++){
    	cin >> szamok[i];
    }
    
    cout << "\nA mátrix értékei:\n";
    for (int i = 0; i < szamok.size(); ++i)
	{
		cout << szamok[i] << endl;
	}
	
    //6
    cout << "\nÍrja be a mátrix dimenzióját:\n";
    int m, n;
    cin >> m >> n;
    cout << "\n";
    
    
    Matrix<double,2> mm(m,n);

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            mm(i,j) = i == 0 || j == 0 ? i + j : i * j;
            
    for(int i = 0; i < mm.dim1(); i++){
    	for(int j = 0; j < mm.dim2(); j++){
    		cout << "\t" << mm(i,j);
    	}
    	cout << "\n";
    }
    
    
    //7
    cout << "\nEnter 10 complex numbers:\n";
    Matrix<complex<double>> komplex_matrix(10);
    for(int i=0; i<komplex_matrix.size();i++){
    	cin >> komplex_matrix[i];
    }
    
    cout << "\nÖsszeg:\n" << accumulate(komplex_matrix.data(), komplex_matrix.data() + komplex_matrix.size(),complex<double>{}) << "\n"; 
    
    	
    	
    // 8.
    cout << "\nÍrjon be hat integert a 2x3-as mátrixnak\n";
    Matrix<int,2> mm2 (2,3);
    for (int i = 0; i < mm2.dim1(); ++i)
        for (int j = 0; j < mm2.dim2(); ++j)
            std::cin >> mm2[i][j];

    for(int i = 0; i < mm2.dim1(); i++){
    	for(int j = 0; j < mm2.dim2(); j++){
    		cout << "\t" << mm2(i,j);
    	}
    	cout << "\n";
    }
}

