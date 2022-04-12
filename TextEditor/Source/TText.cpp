#include "../Headers/TText.h"
#include "../Headers/TTextLink.h"

PTTextLink TText::ReadText(std::ifstream& TxtFile)
{
	//PTTextLink pHead, plt;
	////char StrBuff[TextLineLongth];
	//pHead = plt = new TTextLink();
	//while (TxtFile.eof() == 0) {
	//	TxtFile.getline(StrBuff, BufLength, '\n');
	//	if (StrBuff[0] == '}') {

	//	}
	//}
	return PTTextLink();
}

int TText::GoFirstLink(void)
{
	while (!Path.empty()) {
		Path.pop();
	}

	pCurrent = pFirst;

	if (pCurrent == nullptr) SetRetCode(TextError);
	else SetRetCode(TextOk);
	
	return RetCode;
}

int TText::GoNextLink(void)
{
	SetRetCode(TextError);
	if (pCurrent != nullptr)
		if (pCurrent->pNext != nullptr) {
			Path.push(pCurrent);
			pCurrent = pCurrent->pNext;
			SetRetCode(TextOk);
		}
	return RetCode;
}

bool TText::Reset(void)
{
	while (!St.empty()) St.pop();

	pCurrent = pFirst;

	if (pCurrent != nullptr) {
		//St.push(pCurrent);
		if (pCurrent->pNext != nullptr) {
			St.push(pCurrent->pNext);
		}
		if (pCurrent->pDown != nullptr) {
			St.push(pCurrent->pDown);
		}

	}
	return IsTextEnded();
}

bool TText::IsTextEnded(void) const
{
	return !St.size();
}

int TText::GoNext(void)
{
	if (!IsTextEnded()) {
		pCurrent = St.top();
		St.pop();
		//if (pCurrent != pFirst) {
			if (pCurrent->pNext != nullptr) {
				St.push(pCurrent->pNext);
			}
			if (pCurrent->pDown != nullptr) {
				St.push(pCurrent->pDown);
			}
		//}
	}
	return IsTextEnded();
}
