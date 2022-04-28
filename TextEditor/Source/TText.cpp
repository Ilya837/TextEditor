#include "../Headers/TText.h"
#include "../Headers/TTextLink.h"

PTTextLink TText::ReadText(std::ifstream& TxtFile)
{
	PTTextLink pHead, ptl;
	char StrBuff[TextLineLength];
	pHead = ptl = new TTextLink();
	while (TxtFile.eof() == 0) {
		TxtFile.getline(StrBuff, TextLineLength, '\n');
		if (StrBuff[0] == '}') {
			//TextLevel--;
			break;
		}
		else if (StrBuff[0] == '{') {
			//TextLevel++;
			ptl->pDown = ReadText(TxtFile);
		}
		else {
			ptl->pNext = new TTextLink(StrBuff, nullptr, nullptr);
			ptl = ptl->pNext;
		}
	}
	ptl = pHead;
	if (pHead->pDown == nullptr) {
		pHead = pHead->pNext;
		delete ptl;
	}
	return pHead;
}


PTTextLink TText::GetFirstAtom(PTTextLink pl) {
	PTTextLink tmp = pl;

	while (!tmp->IsAtom()) {
		St.push(tmp);
		tmp = tmp->GetDown();
	}
	return tmp;
}

void TText::PrintText(PTTextLink ptl) {
	std::cout << ptl->Str;
}

//PTText TText::getCopy() {

//}

std::string TText::GetLine(void) {
	return pCurrent->Str;
}

void TText::SetLine(std::string s) {

	if (pCurrent == nullptr) {
		SetRetCode(TextError);
	}
	else {
		strncpy_s(pCurrent->Str, s.c_str(), TextLineLength);
		pCurrent->Str[TextLineLength - 1] = '\0';
		SetRetCode(TextOk);
	}
}

TText::TText(PTTextLink pl) {
	if (pl == nullptr) {
		pl = new TTextLink();
	}
	pFirst = pl;
	pCurrent = pl;

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

int TText::GoDownLink(void) {
	SetRetCode(TextError);
	if (pCurrent != nullptr)
		if (pCurrent->pDown != nullptr) {
			Path.push(pCurrent);
			pCurrent = pCurrent->pDown;
			SetRetCode(TextOk);
		}
	return RetCode;
}

int TText::GoPrevLink(void) {
	SetRetCode(TextError);
	if (pCurrent != nullptr)
		if (!Path.empty()) {
			pCurrent = Path.top();
			Path.pop();
			SetRetCode(TextOk);
		}
	return RetCode;
}

void TText::InsDownLine(std::string s) {
	SetRetCode(TextError);
	if (pCurrent != nullptr) {

		PTTextLink pd = pCurrent->pDown;
		pCurrent->pDown = new TTextLink(s.c_str(), pd, nullptr);

		SetRetCode(TextOk);
	}
}

void TText::InsDownSection(std::string s) {
	SetRetCode(TextError);
	if (pCurrent != nullptr) {

		PTTextLink pd = pCurrent->pDown;
		pCurrent->pDown = new TTextLink(s.c_str(), nullptr, pd);

		SetRetCode(TextOk);
	}
}

void TText::InsNextLine(std::string s) {
	SetRetCode(TextError);
	if (pCurrent != nullptr) {

		PTTextLink pn = pCurrent->pNext;
		pCurrent->pNext = new TTextLink(s.c_str(), pn, nullptr);

		SetRetCode(TextOk);
	}
}

void TText::InsNextSection(std::string s) {
	SetRetCode(TextError);
	if (pCurrent != nullptr) {

		PTTextLink pn = pCurrent->pNext;
		pCurrent->pNext = new TTextLink(s.c_str(), nullptr, pn);

		SetRetCode(TextOk);
	}
}

void TText::DelDownLine(void) {
	SetRetCode(TextError);
	if (pCurrent != nullptr) {

		PTTextLink pd = pCurrent->pDown;
		if (pd != nullptr) {
			if (pd->IsAtom()) {
				PTTextLink pdn = pd->pNext;
				pCurrent->pDown = pdn;
			}
			SetRetCode(TextOk);
		}
		else {
			SetRetCode(TextNoDown);
		}
	}
}

void TText::DelNextLine(void) {
	SetRetCode(TextError);
	if (pCurrent != nullptr) {

		PTTextLink pn = pCurrent->pNext;
		if (pn != nullptr) {
			if (pn->IsAtom()) {
				PTTextLink pnn = pn->pNext;
				pCurrent->pNext = pnn;
			}
			SetRetCode(TextOk);
		}
		else {
			SetRetCode(TextNoDown);
		}
	}
}

void TText::DelDownSection(void) {
	SetRetCode(TextError);
	if (pCurrent != nullptr) {

		PTTextLink pd = pCurrent->pDown;
		if (pd != nullptr) {
			PTTextLink pdn = pd->pNext;
			pCurrent->pDown = pdn;

			SetRetCode(TextOk);
		}
		else {
			SetRetCode(TextNoDown);
		}
	}
}

void TText::DelNextSection(void) {
	SetRetCode(TextError);
	if (pCurrent != nullptr) {

		PTTextLink pn = pCurrent->pNext;
		if (pn != nullptr) {
			PTTextLink pnn = pn->pNext;
			pCurrent->pNext = pnn;

			SetRetCode(TextOk);
		}
		else {
			SetRetCode(TextNoDown);
		}
	}
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

/*void TText::Read(char* pFileName) {

}
void TText::Write(char* pFileName) {

}
void TText::Print(void) {

}*/