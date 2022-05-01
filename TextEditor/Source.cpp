#include "Headers/TText.h"
#include "Headers/TTextLink.h"
#include <iostream>

int main() {
	TTextLink::IntMemSystem(5);
	PTTextLink tl = new TTextLink("Hello");
	TText a(tl);
	a.InsDownLine("World");
	a.GoDownLink();
	a.InsNextLine("!");
	a.GoFirstLink();
	a.DelDownLine();
	TTextLink::MemCleaner(a);
	return 0;
}