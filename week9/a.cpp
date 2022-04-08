#include "std_lib_facilities.h"


template<typename T>
void increment(T& c, int n){
	for(auto& i : c){
		i += n;
	}
}
template<typename Iter1, typename Iter2>
Iter2 own_copy(Iter1 f1, Iter1 e1, Iter2 f2){

	for(Iter1 p = f1; p != e1; ++p){
		*f2++ = *p;
		}
	return f2;
}

int main(){
		constexpr int size = 10;
		int arr[size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

		array<int, size> array1;
		copy(arr, arr+size, array1.begin());
		cout << "Array: \n";
	    	for(int i = 0; i<10; i++){
	    		cout << array1[i] << "\n";
	    	}

		vector<int> vector1(size);
		copy(arr, arr + size, vector1.begin());
		cout << "Vector: \n";
	    	for(int i = 0; i<10; i++){
	    		cout << vector1[i] << "\n";
	    	}

		list<int> list1(size);
		copy(arr, arr + size, list1.begin());
		cout << "List: \n";
		for(int& i: list1){
    			cout << i << "\n";
    		}
		
		array<int,size> array2 = array1; //első array copyja
		vector<int> vector2 = vector1; //első vector copyja
		list<int> list2 = list1; //első list copyja
		
		
		cout << "Array copy: \n";
	    	for(int i = 0; i<10; i++){
	    		cout << array2[i] << "\n";
	    	}

		
		cout << "Vector copy: \n";
	    	for(int i = 0; i<10; i++){
	    		cout << vector2[i] << "\n";
	    	}

		
		cout << "List copy: \n";
		for(int& i: list2){
    			cout << i << "\n";
    		}
		
		

		increment(array2, 2); //increase by
		increment(vector2, 3);
		increment(list2, 5);
		
		cout << "Array copy ingreased: \n";
	    	for(int i = 0; i<10; i++){
	    		cout << array2[i] << "\n";
	    	}

		
		cout << "Vector copy ingreased: \n";
	    	for(int i = 0; i<10; i++){
	    		cout << vector2[i] << "\n";
	    	}

		
		cout << "List copy increased: \n";
		for(int& i: list2){
    			cout << i << "\n";
    		}
		


		own_copy(array2.begin(), array2.end(), vector2.begin());
		own_copy(list2.begin(), list2.end(), array2.begin());


		cout << "Array after copy: \n";
	    	for(int i = 0; i<10; i++){
	    		cout << array2[i] << "\n";
	    	}

		
		cout << "Vector after copy: \n";
	    	for(int i = 0; i<10; i++){
	    		cout << vector2[i] << "\n";
	    	}

		
		cout << "List copy increased: \n";
		for(int& i: list2){
    			cout << i << "\n";
    		}




		vector<int>::iterator vit;
		vit = find(vector2.begin(), vector2.end(), 3);
		if( vit != vector2.end()){
			cout << "(3) Found at: " << distance(vector2.begin(), vit) << "\n";
		}else{
			cout << "(3) Not found\n";
		}

		list<int>::iterator lit;
		lit = find(list2.begin(),list2.end(), 27);
		if (lit != list2.end()){
			cout << "(27) Found at: " << distance(list2.begin(), lit) << "\n";
		}else{
			cout << "(27) Not found\n";
		}

	
}
