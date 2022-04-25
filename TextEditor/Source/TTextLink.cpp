#include "../Headers/TTextLink.h"
#include "../Headers/TText.h"

TTextLink::TTextLink(const TStr s, PTTextLink pn, PTTextLink pd): pNext(pn), pDown(pd), flag(false)
{
    if (s != NULL) strcpy(Str, s);
    else Str[0] = '\0';
}

void TTextLink::IntMemSystem(size_t size){
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
    pLink->pDown = nullptr;
    pLink->flag = false;
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

void TTextLink::Flaging( PTTextLink textlink) {
    textlink->flag = true;
    if(textlink->pDown != nullptr)
        Flaging(textlink->pDown);
    if(textlink->pNext != nullptr)
        Flaging(textlink->pNext);
    
}

void TTextLink::MemCleaner(PTTextLink txt) {
    Flaging(txt);
    Flaging(MemHeader.pFree);
    PTTextLink link = MemHeader.pfirst;
    PTTextLink tmplink = nullptr;
    while(link != MemHeader.plast){
        if (link->flag == false){
            tmplink = link;
            link += 1;
            delete tmplink;
        }
        else{
            link->flag = false;
            link += 1;
        }    
    }

    if (link->flag == false){
            tmplink = link;
            delete tmplink;
    }
    else{
        link->flag = false;
    } 

    link = nullptr;
    tmplink = nullptr;
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
