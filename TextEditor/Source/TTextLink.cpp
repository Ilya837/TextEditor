#include "../Headers/TTextLink.h"
#include "../Headers/TText.h"

TTextLink::TTextLink(const TStr s, PTTextLink pn, PTTextLink pd): pNext(pn), pDown(pd)
{
    if (s != NULL) strcpy(Str, s);
    else Str[0] = '\0';
}

void TTextLink::IntMemSystem(int size){
    MemHeader.pfirst = (PTTextLink) (new char[sizeof(TTextLink) * size]);
    MemHeader.pFree = MemHeader.pfirst;
    MemHeader.plast = MemHeader.pfirst + (size - 1);
    PTTextLink plink = MemHeader.pfirst;
    for (int i = 0; i < size - 1; plink++, i++) {
        plink->pNext = plink + 1;
    }
    plink->pNext = nullptr;
}

void TTextLink::PrintFreeLink() {
    PTTextLink plink = MemHeader.pfirst;
    for (; plink != nullptr; plink = plink->pNext)
        std::cout << plink->Str << std::endl;
}

void* TTextLink::operator new(size_t size) {
    PTTextLink plink = MemHeader.pFree;
    if (MemHeader.pFree != nullptr)
        MemHeader.pFree = plink->pNext;
    return plink;
}

void TTextLink::operator delete(void* pM)
{
    PTTextLink pLink = (PTTextLink)(pM);
    pLink->pNext = MemHeader.pFree;
    MemHeader.pFree = pLink;
}

TTextLink::~TTextLink(){
    delete[] MemHeader.pfirst;
}

bool TTextLink::IsAtom()
{

    return pDown == nullptr;
}

PTTextLink TTextLink::GetNext()
{
    return pNext;
}

PTTextLink TTextLink::GetDown()
{
    return pDown;
}

void TTextLink::MemCleaner(const TText& txt) {
    
}

PTDataValue TTextLink::GetCopy()
{
    return new TTextLink(Str,pNext,pDown);
}

std::ostream& operator<<(std::ostream& os, const TTextLink& tl)
{
    os << tl.Str << std::endl;
    return os;
}
