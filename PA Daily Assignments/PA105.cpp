#include<iostream>

using namespace std;

int main() {
	int cokeCount = 0;
	
	for(cokeCount = 0; cokeCount < 99; ++cokeCount) {
	cout << cokeCount << " bottle(s) of coke.\n";
	}
	
	for(cokeCount = cokeCount; cokeCount > 0; --cokeCount) {
	cout << cokeCount << " bottle(s) of coke.\n";
	}
	
	while(cokeCount < 99) {
	cout << cokeCount << " bottle(s) of coke.\n";
	cokeCount++;
	}
	
	while(cokeCount > 0) {
	cout << cokeCount << " bottle(s) of coke.\n";
	cokeCount --;
	}
	
	do {
	cout << cokeCount << " bottle(s) of coke.\n";
	cokeCount ++;
	} while(cokeCount < 99);

	return 0;
}
