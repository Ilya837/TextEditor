#include "pch.h"
#include "gtest/gtest.h"
#include "..\TextEditor\Headers\TTextLink.h"
#include "..\TextEditor\Headers\TText.h"

//Tests for TTextLink
TEST(TTextLink, TTextLink_EmptyConstructor)
{
    TTextLink::IntMemSystem(1);
    ASSERT_NO_THROW(new TTextLink());
}
TEST(TTextLink, TTextLink_ConstructorWithText)
{
    TTextLink::IntMemSystem(1);
    ASSERT_NO_THROW(new TTextLink((char*)"Test"));
}

TEST(TTextLink, TTextLink_PrintFreeLink)
{
    TTextLink::IntMemSystem(1);
    TTextLink tmp((char*)"Good job");
    ASSERT_NO_THROW(tmp.PrintFreeLink());
}

TEST(TTextLink, TTextLink_IsAtom)
{
    TTextLink::IntMemSystem(1);
    TTextLink Atom((char*)"Test");
    ASSERT_EQ(1, Atom.IsAtom());
}


//HOW TO CREATE PTTextLink by correct way?

//TEST(TTextLink, TTextLink_IsAtom)
//{
//    TTextLink::IntMemSystem(3);
//   // PTTextLink tmp = new TTextLink;
//   // TTextLink notAtom((char*)"Test", NULL, tmp);
//   
//   ASSERT_EQ(0,notAtom.IsAtom()); 
//}

//TEST(TTextLink, TTextLink_GetNext)
//{
//    TTextLink::IntMemSystem(2);
//    PTTextLink tmp = new TTextLink();
//    TTextLink tlink((char*)"Test", tmp, NULL);
//    EXPECT_EQ(tmp, tlink.GetNext());
////}

//TEST(TTextLink, TTextLink_GetDown)
//{
//    TTextLink::IntMemSystem(2);
//    PTTextLink tmp = new TTextLink;
//    TTextLink tlink((char*)"Test", NULL, tmp);
//    EXPECT_EQ(tmp, tlink.GetDown());
//}

//TEST(TTextLink, TTextLink_GetCopy)
//{
//    TTextLink::IntMemSystem(2);
//    PTTextLink tlink = new TTextLink((char*)"Test", NULL, NULL);
//    PTTextLink tmp = (PTTextLink)tlink->GetCopy();
//    ASSERT_TRUE(tmp->GetNext() == tlink->GetNext());
//    ASSERT_TRUE(tmp->GetDown() == tlink->GetDown());
//    EXPECT_NE(tmp, tlink);//will it compare addresses?
//}
