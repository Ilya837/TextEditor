#include "Headers/TDataCom.h"
#include "Headers/TDataValue.h"
#include "Headers/TText.h"
#include "Headers/TTextLink.h"
#include <iostream>

int main() {
	//asd

    TTextLink::IntMemSystem(10);
    PTTextLink pNext = new TTextLink((char*)"strNext", NULL, NULL);
    PTTextLink pDown = new TTextLink((char*)"strDown", NULL, NULL);
    PTTextLink pLink = new TTextLink((char*)"str", pNext, pDown);
    TText tmp(pLink);
   tmp.Read((char*)"../TestEditor_Tests/file.txt");
   tmp.Print();
	return 0;
}