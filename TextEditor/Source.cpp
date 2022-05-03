#include "Headers/TText.h"
#include "Headers/TTextLink.h"
#include <iostream>

int main() {
	TTextLink::IntMemSystem(40);
	PTTextLink tl = new TTextLink("1");
	TText a(tl);

	a.Read("Text.txt");
	a.Print();

	//Insert and print test

	// a.InsDownLine("2");
	// a.GoDownLink();
	// a.InsNextLine("2");
	// a.GoNextLink();
	// a.InsDownLine("3");
	// a.GoPrevLink();
	// a.InsDownLine("3");
	// a.GoDownLink();
	// a.InsNextLine("3");
	// a.GoNextLink();
	// a.InsNextLine("3");
	// a.GoPrevLink();
	// a.InsDownLine("4");
	// a.GoDownLink();
	// a.InsDownLine("5");
	// a.InsNextLine("4");
	//a.Print();

	// NoMem test

	// std::cout << a.GetRetCode() << std::endl;
	// a.GoFirstLink();
	// a.InsNextLine("1");
	// std::cout << a.GetRetCode()<< std::endl;
	
	//Write test

	//a.Write("Text.txt");
	
	return 0;
}