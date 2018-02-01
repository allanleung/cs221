#include "Hashtable.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;


void usage(char* argv[]) {
	cerr << "Usage: " << argv[0] << " scheme numberOfKeys sizeOfTable" << endl;
	exit(-1);
}

int main(int argc, char *argv[]) {
	int n, m;
	srand(time(0));

	if (argc == 1) {
		cout << "Running your test code..." << endl;

		Hashtable T(7);
		T.qinsert(76);
		T.qinsert(40);
		T.qinsert(48);
		T.qinsert(5);
		T.qinsert(55);
		T.print();
		T.printStats();
		
		/* Testing endless Quadratic */
		Hashtable Q(7);
		Q.qinsert(76);
		Q.qinsert(93);
		Q.qinsert(40);
		Q.qinsert(35);
		Q.qinsert(47);
		Q.print();
		Q.printStats();
		
		/* Testing linear */
		Hashtable L(7);
		L.linsert(76);
		L.linsert(93);
		L.linsert(40);
		L.linsert(47);
		L.linsert(10);
		L.linsert(55);
		L.print();
		L.printStats();
		
		/* Testing Double */
		Hashtable D(23);
		D.dinsert(120);
		D.dinsert(130);
		D.dinsert(70);
		D.dinsert(30);
		D.dinsert(50);
		D.dinsert(20);
		D.dinsert(40);
		D.dinsert(140);
		D.dinsert(150);
		D.dinsert(60);
		D.dinsert(10);
		D.dinsert(97);
		D.dinsert(110);
		D.dinsert(96);
		D.dinsert(93);
		D.print();
		D.printStats();

		int size = 1000;
		for (int j = size; j > 0; j = j - size/10){
			Hashtable A(size);
			for (int i = 0; i < j; i++){
				A.linsert(rand(
					) + 1);
			}
			cout << "LINEAR with "<< j << " keys and size " << size << " :"<< endl;
			A.printStats();
			A.clear();
			

			for (int i = 0; i < j; i++){
				A.qinsert(rand() + 1);
			}
			cout << "QUADRATIC with " << j << " keys and size " << size << " :"<< endl;
			A.printStats();
			A.clear();
			
			for (int i = 0; i < j; i++){
				A.dinsert(rand() + 1);
			}
			cout << "DOUBLE with " << j << " keys and size " << size << " :"<< endl;
			A.printStats();
			A.clear();
			
			cout<<"\n"<<endl;
		}
		
	}
	
	if (argc != 4) {
		usage(argv);
	}
	n = atoi(argv[2]);
	m = atoi(argv[3]);
	Hashtable H(m);
	
	switch(argv[1][0]) {
	case 'l':
		for (int i=0; i<n; ++i) {
			H.linsert(rand() + 1);
		}
		//    H.print();
		cout << "Linear: ";  
		H.printStats();
		break;
	case 'q':
		for (int i=0; i<n; ++i) {
			H.qinsert(rand() + 1);
		}
		//    H.print();
		cout << "Quadratic: ";
		H.printStats();
		break;
	case 'd':
		for (int i=0; i<n; ++i) {
			H.dinsert(rand() + 1);
		}
		//    H.print();
		cout << "Double Hashing: "; 
		H.printStats();
		break;
	default:
		usage(argv);
	}
		
}

