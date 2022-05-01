#include "Headers/TText.h"
#include "Headers/TTextLink.h"
#include <iostream>

int main() {
	TTextLink::IntMemSystem(20);
	PTTextLink tl = new TTextLink("1");
	TText a(tl);

	a.InsDownLine("2");
	a.GoDownLink();
	a.InsNextLine("2");
	a.GoNextLink();
	a.InsDownLine("3");
	a.GoPrevLink();
	a.InsDownLine("3");
	a.GoDownLink();
	a.InsNextLine("3");
	a.GoNextLink();
	a.InsNextLine("3");
	a.GoPrevLink();
	a.InsDownLine("4");
	a.GoDownLink();
	a.InsDownLine("5");
	a.InsNextLine("4");

	//TTextLink::MemCleaner(a);
	a.Print();
	return 0;
}