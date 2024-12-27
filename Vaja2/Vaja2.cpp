//HANOJSKI STOLPI

#include <iostream>
using namespace std;

void menu() {
	cout << "1. Nastavi zacetno stanje igre." << endl;
	cout << "2. Prestavi zgornji element iz stolpa Y na palico Z." << endl;
	cout << "3. Izpisi stolpe." << endl;
	cout << "Izbira: ";
}

void push(int* stolp, int stevilo, int& vrh, int max) {
	if ((vrh - 1)== max) {                                               //èe je indeks VRH enak velikosti sklada, je sklad poln 
		cout << "NAPAKA: Stolp je poln!" << endl;
		cout << endl;
	}
	else {
		stolp[vrh] = stevilo;
		vrh++;
	}
}

int pop(int* sklad, int& vrh) {
	if (vrh == 0) {                                                 //èe je indeks VRH enak 0 pomeni, da je skad prazen...
		cout << "NAPAKA: Stolp je prazen!" << endl;
		cout << endl;
	}
	else {
		vrh--;                                                      //...drugaèe izpišemo zaden element v skladu in zmanšamo VRH za 1
		return sklad[vrh];
	}
}

int startingState(int& vrh1, int& vrh2, int& vrh3, int*& stolp1, int*& stolp2, int*& stolp3) {
	int stevilo;
	cout << "Stevilo ploscic na 1. stolpu: ";
	cin >> stevilo;
	const int max = stevilo;							//uporabnik vnese najveèje število v stolpu

	stolp1 = new int[max];
	for (int i = 0; i < max; i++) {				//sestavimo stolp (sklad) dolžine "stevilo" s padajoèimi števili
		push(stolp1, stevilo, vrh1, max);
		stevilo--;
	}

	stolp2 = new int[max];
	/*for (int i = 0; i < max; i++) {
		push(stolp2, NULL , vrh2, max);
	}*/
												//vrednosti v 2. in 3. stolpu nastavimo na null
	stolp3 = new int[max];
	/*for (int i = 0; i < max; i++) {
		push(stolp3, NULL, vrh3, max);
	}*/
												

	/*cout << "STOLP 1: ";
	for (unsigned int i = 0; i < vrh1; i++) {
		cout << stolp1[i] << " ";
	}
	cout << endl;

	cout << "STOLP 2: ";
	cout << stolp2[0] << endl;
	cout << "STOLP 1: ";
	cout << stolp3[0] << endl;
	*/
	cout << endl;
	return max;
}

void transfer(int max, int& vrh1, int& vrh2, int& vrh3, int*& stolp1, int*& stolp2, int*& stolp3) {
	int y;				//stolp, iz katerega prenašamo
	int z;				//stolp v katerga prenašamo
	int prenos;			//število, ki bomo prenašali

	cout << "Iz katerega na kateri stolp zelite prestaviti? (Vrednosti 1-3)." << endl;

	cout << "Iz: ";
	cin >> y;
	while (y < 1 || y>3) {													//dobimo številko stolpa iz katerega prestavljamo
		cout << "Napacna izbira (vrednost med 1-3):" << endl << "Iz: ";
		cin >> y;
	}

	cout << "Na: ";
	cin >> z;
	while ((z < 1 || z>3) || z == y) {													//dobimo številko stolpa v katerga prestavljamo
		cout << "Napacna izbira (vrednost med 1-3): " << endl << "Iz: ";
		cin >> z;
	}
	cout << endl;

	if (y == 1 && z == 2) {													//obstaja 6 kombinacij, preverimo katera ustreza ... 
		if ((stolp1[vrh1] > stolp2[vrh2]) && vrh2 != 0) {
			cout << "Vecjega stevila ne moremo prestaviti na manjsega!" << endl;		//èe je zgornja vrednost na y stolpu veèja od zgornje vrednosti na stolpu z, javi napako ...
		}
		else {
			prenos = pop(stolp1, vrh1);													// ... sicer "vzamemo" zgornjo vrednost z y stolpa in jo prestavimo na zgornjo vrednost z stolpa
			push(stolp2, prenos, vrh2, max);
		}
	}

	else if (y == 1 && z == 3) {
		if (stolp1[vrh1] > stolp3[vrh3] && vrh3 != 0) {
			cout << "Vecjega stevila ne moremo prestaviti na manjsega!" << endl;
			cout << endl;
		}
		else {
			prenos = pop(stolp1, vrh1);
			push(stolp3, prenos, vrh3, max);
		}
	}

	else if (y == 2 && z == 1) {
		if (stolp2[vrh2] > stolp1[vrh1] && vrh1 != 0) {
			cout << "Vecjega stevila ne moremo prestaviti na manjsega!" << endl;
			cout << endl;
		}
		else {
			prenos = pop(stolp2, vrh2);
			push(stolp1, prenos, vrh1, max);
		}
	}

	else if (y == 2 && z == 3) {
		if (stolp2[vrh2] > stolp3[vrh3] && vrh3 != 0) {
			cout << "Vecjega stevila ne moremo prestaviti na manjsega!" << endl;
			cout << endl;
		}
		else {
			prenos = pop(stolp2, vrh2);
			push(stolp3, prenos, vrh3, max);
		}
	}

	else if (y == 3 && z == 1) {
		if (stolp3[vrh3] > stolp1[vrh1] && vrh1 != 0) {
			cout << "Vecjega stevila ne moremo prestaviti na manjsega!" << endl;
			cout << endl;
		}
		else {
			prenos = pop(stolp3, vrh3);
			push(stolp1, prenos, vrh1, max);
		}
	}

	else if (y == 3 && z == 2) {
		if (stolp3[vrh3] > stolp2[vrh2] && vrh2 != 0) {
			cout << "Vecjega stevila ne moremo prestaviti na manjsega!" << endl;
			cout << endl;
		}
		else {
			prenos = pop(stolp3, vrh3);
			push(stolp2, prenos, vrh2, max);
		}
	}

	if (vrh1 == 0) {
		cout << "KONEC IGRE!" << endl;
	}
}

void print(int vrh1, int vrh2, int vrh3, int* stolp1, int* stolp2, int* stolp3) {
	cout << endl;
	cout << "STOLP 1: ";
	for (int i = 0; i < vrh1; i++) {
		cout << stolp1[i] << " ";
	}
	cout << endl;

	cout << "STOLP 2: ";
	for (int i = 0; i < vrh2; i++) {
		cout << stolp2[i] << " ";
	}
	cout << endl;

	cout << "STOLP 3: ";
	for (int i = 0; i < vrh3; i++) {
		cout << stolp3[i] << " ";
	}
	cout << endl;
	cout << endl;

	/*
	for (int j = 1; j < max; j++) {
		for (int k = 0; k < stolp1[vrh1]; k++) {
			cout << "*";
		}
		vrh1--;
		cout << endl;
	}
	*/

}



int main() {
	bool running = true;
	int izbira;

	int* stolp1= nullptr;
	int* stolp2= nullptr;
	int* stolp3= nullptr;

	int vrh1 = 0;
	int vrh2 = 0;
	int vrh3 = 0;
	int max = 0;

	do {
		menu();
		cin >> izbira;
		switch (izbira) {
		case 1:
			max=startingState(vrh1, vrh2, vrh3, stolp1, stolp2, stolp3);
			//system("cls");
			break;
		case 2:
			transfer(max, vrh1, vrh2, vrh3, stolp1, stolp2, stolp3);
			//system("cls");
			break;
		case 3:
			print(vrh1, vrh2, vrh3, stolp1, stolp2, stolp3);
			break;
		default:
			cout << "Narobe izbira!" << endl;
			break;
		}
	} while (running);

	return 0;
}


