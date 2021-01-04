#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
    int n, temp;
    int Array[105];
    //Lay du lieu tu stdin.
    ifstream inFile("stdin");
    inFile >> n;
    for (int i = 0; i < n; i++) {
        inFile >> Array[i];
    }
    inFile.close(); //Thoat file.
    //Sap xep du lieu.
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
        	if (abs(Array[i]) < abs(Array[j])) {
        		temp = Array[i];
        		Array[i] = Array[j];
        		Array[j] = temp;
			}
		}
	}
	ofstream OutFile("stdout");
	//Sap xep neu 2 phan tu co gia tri tuyet doi bang nhau, so duong truoc, so am sau, dong thoi in ra stdout.
	for (int i = 0; i < n-1; i ++) {
		if ((abs(Array[i]) == abs(Array[i+1])) && (Array[i] < 0)) {
			Array[i] *= -1;
			Array[i+1] *= -1;			
		}
		OutFile << Array[i] <<" ";
	}
	OutFile << Array[n-1]; //In not gia tri cuoi cung cua mang Array.
    OutFile.close(); //Thoat file.
    return 0;
}

