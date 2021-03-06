/*
  Copyright (C) 2015  Alfonso Cabargas Madrid <felipe@cabargas.ninja>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/* DOCUMENTACION

Version del Compilador:         GNU Make 3.81
Version del Sistema Operativo:  Mac OS X 10.10.4-beta
Version del Editor de Texto:    TextMate 2.10-beta

*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <regex>

using namespace std;

//Main functions of the algorithm
void intersection(string filename1, string filename2);
void joinWords(string filename1, string filename2);
void difference(string filename1, string filename2);
void concatWords(string filename1, string filename2);
void moreVowels(string filename1, string filename2);
void bonusTrack(string filename1, string filename2);

//Menu function
void optionSwitch(int option);
void printMenu();

//Auxiliary functions
int isPresent(string word, string filename);
int startsWithConsonant(string word);
int endsWithVowel(string word);
int vowels(string word);

int main(){
	int option;

	cout << "Bienvenido! Ingresa los datos que se te piden: " << endl;

	printMenu();

	cin >> option;
	optionSwitch(option);

	return 0;
}

void printMenu(){
	cout << endl << "====================================================================================\n" << endl;

	cout << "Por favor selecciona una de las siguientes opciones: " << endl;
	cout << "\t (1) Obtener interseccion de ambos archivos" << endl;
	cout << "\t (2) Obtener union de ambos archivos" << endl;
	cout << "\t (3) Obtener diferencia de ambos archivos" << endl;
	cout << "\t (4) Obtener concatenacion de palabras de ambos archivos" << endl;
	cout << "\t (5) Obtener palabra con mas vocales diferentes dentro de ambos archivos" << endl;
	cout << "\t (6) BONUS TRACK" << endl;

	cout << endl << "====================================================================================\n" << endl;
}

void optionSwitch(int option){
	string filename1, filename2;

	cout << "\t - Nombre de Archivo 1: ";
	cin >> filename1;
	cout << endl << "\t - Nombre de Archivo 2: ";
	cin >> filename2;

	cout << endl << "====================================================================================\n" << endl;


	switch(option){
		case 1:
			cout << "Ejecutando funcion 1........." << endl;
			intersection(filename1, filename2);
			cout << "Ejecucion finalizada, tu archivo de salida es intersection.txt" << endl;
			cout << "Selecciona otra opcion o ingresa 0 para terminar." << endl;
			printMenu();
			cin >> option;
		break;
		case 2:
			cout << "Ejecutando funcion 2........." << endl;
			joinWords(filename1, filename2);
			cout << "Ejecucion finalizada, tu archivo de salida es joinWords.txt" << endl;
			cout << "Selecciona otra opcion o ingresa 0 para terminar." << endl;
			printMenu();
			cin >> option;
		break;
		case 3:
			cout << "Ejecutando funcion 3........." << endl;
			difference(filename1, filename2);
			cout << "Ejecucion finalizada, tu archivo de salida es difference.txt" << endl;
			cout << "Selecciona otra opcion o ingresa 0 para terminar." << endl;
			printMenu();
			cin >> option;
		break;
		case 4:
			cout << "Ejecutando funcion 4........." << endl;
			concatWords(filename1, filename2);
			cout << "Ejecucion finalizada, tu archivo de salida es concatWords.txt" << endl;
			cout << "Selecciona otra opcion o ingresa 0 para terminar." << endl;
			printMenu();
			cin >> option;
		break;
		case 5:
			cout << "Ejecutando funcion 5........." << endl;
			moreVowels(filename1, filename2);
			cout << "Ejecucion finalizada, tu archivo de salida es moreVowels.txt" << endl;
			cout << "Selecciona otra opcion o ingresa 0 para terminar." << endl;
			printMenu();
			cin >> option;
		break;
		case 6:
			cout << "Ejecutando funcion 6........." << endl;
			bonusTrack(filename1, filename2);
			cout << "Puedes encontrar un resumen de tu juego en bonusTrack.txt" << endl;
			cout << "Selecciona otra opcion o ingresa 0 para terminar." << endl;
			printMenu();
			cin >> option;
		break;
		default:
			cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* FIN DEL PROGRAMA *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
			option = 0;
		break;
	}

	if(option != 0){
		optionSwitch(option);
	}
}

void intersection(string filename1, string filename2){
	ifstream file1, file2;
	ofstream outputfile;
	string word;
	string outputfilename = "intersection.txt";

	file1.open(filename1);
	file2.open(filename2);

	while(file1 >> word){
		if(isPresent(word, filename2) && !isPresent(word, outputfilename)){
			outputfile.open(outputfilename, ios::app);
			outputfile << word << "\n";
			outputfile.close();
		}
	}

	while(file2 >> word){
		if(isPresent(word, filename1) && !isPresent(word, outputfilename)){
			outputfile.open(outputfilename, ios::app);
			outputfile << word << "\n";
			outputfile.close();
		}
	}

	file1.close();
	file2.close();
}

void joinWords(string filename1, string filename2){
	ifstream file1, file2;
	ofstream outputfile;
	string word;
	string outputfilename = "joinWords.txt";

	file1.open(filename1);
	file2.open(filename2);

	while(file1 >> word){
		if(!isPresent(word, outputfilename)){
			outputfile.open(outputfilename, ios::app);
			outputfile << word << "\n";
			outputfile.close();
		}
	}

	while(file2 >> word){
		if(!isPresent(word, outputfilename)){
			outputfile.open(outputfilename, ios::app);
			outputfile << word << "\n";
			outputfile.close();
		}
	}

	file1.close();
	file2.close();
}

void difference(string filename1, string filename2){
	ifstream file1, file2;
	ofstream outputfile;
	string word;
	string outputfilename = "difference.txt";

	file1.open(filename1);
	file2.open(filename2);

	while(file1 >> word){
		if(!isPresent(word, filename2) && !isPresent(word, outputfilename)){
			outputfile.open(outputfilename, ios::app);
			outputfile << word << "\n";
			outputfile.close();
		}
	}

	while(file2 >> word){
		if(!isPresent(word, filename1) && !isPresent(word, outputfilename)){
			outputfile.open(outputfilename, ios::app);
			outputfile << word << "\n";
			outputfile.close();
		}
	}

	file1.close();
	file2.close();
}

void concatWords(string filename1, string filename2){
	ifstream file1, file2;
	ofstream outputfile;
	string word, word2;
	string outputfilename = "concatWords.txt";

	file1.open(filename1);
	file2.open(filename2);
	outputfile.open(outputfilename);

	while(file1 >> word){
		if(startsWithConsonant(word)){
			while(file2 >> word2){
				if(endsWithVowel(word2)){
					outputfile << word << word2 << "\n";
				}
			}
		}
	}

	file1.close();
	file2.close();
	outputfile.close();
}

void moreVowels(string filename1, string filename2){
	int moreV = 0;
	int fileN; //stores number of the file that contains that word
	ifstream file1, file2;
	ofstream outputfile;
	string word;
	string outputfilename = "moreVowels.txt";

	file1.open(filename1);
	file2.open(filename2);
	outputfile.open(outputfilename);


	/* FIND GREATEST NUMBER OF VOWELS INSIDE FIRST FILE'S WORDS*/
	while(file1 >> word){
		if(vowels(word) > moreV){
			moreV = vowels(word);
			fileN = 1;
		}
	}
	/* FIND GREATEST NUMBER OF VOWELS INSIDE SECOND FILE'S WORDS*/
	while(file2 >> word){
		if(vowels(word) > moreV){
			moreV = vowels(word);
			fileN = 2;
		}
	}

	file1.close();
	file2.close();

	/* GETTING THE WORD */
	cout << "La palabra con mas vocales se encuentra en el archivo " << fileN << " y contiene un total de " << moreV << " vocales." << endl;

	file1.open(filename1);
	file2.open(filename2);

	if(fileN == 1){
		while(file1 >> word){
			if(vowels(word) == moreV){
				outputfile << word << "\n";
			}
		}
	} else {
		while(file2 >> word){
			if(vowels(word) == moreV){
				outputfile << word << "\n";
			}
		}
	}

	outputfile.close();
}

void bonusTrack(string filename1, string filename2){
	ifstream wfile;
	ofstream outputfile;
	char c;
	int i, aux, good=0, tryouts=6;
	string word;
	string outputfilename = "bonusTrack.txt";

	outputfile.open(outputfilename);

	moreVowels(filename1, filename2);
	wfile.open("moreVowels.txt");
	wfile >> word;

	cout << "BIENVENIDO AL JUEGO DEL AHORCADO" << endl;
	cout << "================================" << endl;

	while((tryouts>0) && (good!=word.length())){

		cout << "Ingrese una letra: " << endl;
		cin >> c;
		aux = good;

		for(i=0;i<word.length();i++){
			if(word[i] == c){
				good++;
				outputfile << word[i];
			} else {
				outputfile << "-";
			}
		}

		if(good == aux){
			tryouts--;
			cout << "Respuesta equivocada, solo te quedan: " << tryouts << " intentos.";
		}

		outputfile << "\n";
	}


	wfile.close();
	outputfile.close();
}

//Aux Functions
int isPresent(string word, string filename){
	ifstream checkfile;
	string wordcmp;

	checkfile.open(filename);
  checkfile.clear();
  checkfile.seekg(0, ios::beg);

	while(checkfile >> wordcmp){
		if(word == wordcmp){
			return 1;
		}
	}

	checkfile.close();
	return 0;
}

int startsWithConsonant(string word){
	int i;
	char vowels[5] = {'a','e','i','o','u'};

	for(i=0;i<5;i++){
		if(word[0] == vowels[i]){
			return 0;
		}
	}
	return 1;
}

int endsWithVowel(string word){
	int i;
	char vowels[5] = {'a','e','i','o','u'};

	for(i=0;i<5;i++){
		if(word[word.length()-1] == vowels[i]){
			return 1;
		}
	}
	return 0;
}

int vowels(string word){
	int i, j, c;
	char vowels[5] = {'a','e','i','o','u'};

	c = 0;

	for(i=0;i<word.length();i++){
		for(j=0;j<5;j++){
			if(word[i]==vowels[j]){
				c++;
			}
		}
	}

	return c;
}