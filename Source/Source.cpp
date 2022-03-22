#include <iostream>

#define TextOk 0
#define TextNoDown 101
#define TextNoNext 102
#define TextNoPrev 103

#define TextNoMem -101
#define TextError -102
#define TextLineLongth 100

#define MemSize 20

class TText;
class TTextLink;

typedef TTextLink* PTTextLink;
typedef char TStr[TextLineLongth];

class TTextMem {
	PTTextLink pfirst;
	PTTextLink plast;
	PTTextLink pFree;
	friend class TTextLink;

};

typedef TTextMem* PTTextMem;

class TTextLink /*: public TDatValue*/ {
protected:
	PTTextLink pNext;
	PTTextLink pDown;
	TStr str;
	static TTextMem MemHeader;
public:
	static void IntMemSystem(int size = MemSize){
		MemHeader.pfirst = (PTTextLink) (new char[sizeof(TTextLink) * size]);
		MemHeader.pFree = MemHeader.pfirst;
		MemHeader.plast = MemHeader.pfirst + (size - 1);
		PTTextLink plink = MemHeader.pfirst;
		for (int i = 0; i < size - 1; plink++) {
			plink->pNext = plink + 1;
		}
		plink->pNext = 0;
	}

	void PrintFreeLink() {
		PTTextLink plink = MemHeader.pfirst;
		for (; plink != nullptr; plink = plink->pNext)
			std::cout << plink->str << std::endl;
	}

	void* operator new(size_t size) {
		PTTextLink plink = MemHeader.pFree;
		if (MemHeader.pFree != nullptr)
			MemHeader.pFree = plink->pNext;
		return plink;
	}
};

int main() {
	return 0;
}
