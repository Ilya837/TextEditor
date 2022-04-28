#include "pch.h"
#include "gtest/gtest.h"
#include "..\TextEditor\Headers\TTextLink.h"
#include "..\TextEditor\Headers\TText.h"

///Tests for TTextLink
TEST(TTextLink, TTextLink_IntMemSystem_empty)
{
    ASSERT_NO_THROW(TTextLink::IntMemSystem());
}


TEST(TTextLink, TTextLink_IntMemSystem_sized)
{
    ASSERT_NO_THROW(TTextLink::IntMemSystem(3));
}

TEST(TTextLink, TTextLink_IntMemSystem_with_1_ttextlink)
{
    TTextLink::IntMemSystem(2);
    TTextLink tlink((char*)"Test");
    ASSERT_EQ(tlink.GetpFree(), tlink.Getpfirst());
}

TEST(TTextLink, TTextLink_IntMemSystem_full)
{
    TTextLink::IntMemSystem(2);
    PTTextLink tmp = new TTextLink((char*)"Test");
    TTextLink tlink((char*)"Test", tmp, NULL);
    ASSERT_EQ(tlink.GetpFree(), tlink.Getplast());
}

TEST(TTextLink, TTextLink_ConstructorEmpty)
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

TEST(TTextLink, TTextLink_new)
{
    TTextLink::IntMemSystem(2);
    TTextLink t;
    PTTextLink t2 = new TTextLink();
    ASSERT_EQ((*t2).GetpFree(), (*t2).Getplast());
}

TEST(TTextLink, TTextLink_delete)
{
    TTextLink::IntMemSystem(2);
    TTextLink t;
    PTTextLink t2 = new TTextLink();
    delete t2;
    ASSERT_EQ(t.Getpfirst(), t.GetpFree());
}

//TEST(TTextLink, TTextLink_MemCleaner)
//{
//    TTextLink::IntMemSystem();
//    TText txt;
//    ASSERT_NO_THROW(TTextLink::MemCleaner(txt));
//}

TEST(TTextLink, TTextLink_IsAtom)
{
    TTextLink::IntMemSystem(1);
    TTextLink Atom((char*)"Test");
    ASSERT_EQ(1, Atom.IsAtom());
}

TEST(TTextLink, TTextLink_IsnotAtom)
{
    TTextLink::IntMemSystem(2);
    PTTextLink tmp = new TTextLink();
    TTextLink notAtom((char*)"Test", NULL, tmp);

    ASSERT_EQ(0, notAtom.IsAtom());
}

TEST(TTextLink, TTextLink_GetNext)
{
    TTextLink::IntMemSystem(2);
    PTTextLink tmp = new TTextLink();
    TTextLink tlink((char*)"Test", tmp, NULL);
    EXPECT_EQ(tmp, tlink.GetNext());
}

TEST(TTextLink, TTextLink_GetDown)
{
    TTextLink::IntMemSystem(2);
    PTTextLink tmp = new TTextLink();
    TTextLink tlink((char*)"Test", NULL, tmp);
    EXPECT_EQ(tmp, tlink.GetDown());
}

TEST(TTextLink, TTextLink_GetCopy)
{
    TTextLink::IntMemSystem(2);
    PTTextLink tmp_down = new TTextLink();
    PTTextLink tmp_next = new TTextLink();
    TTextLink tlink((char*)"Test", tmp_next, tmp_down);
    PTTextLink copy_ptlink = (PTTextLink)tlink.GetCopy();
    EXPECT_EQ(tmp_down, tlink.GetDown());
    EXPECT_EQ(tmp_next, tlink.GetNext());
}

TEST(TTextLink, TTextLink_GetCopy_has_own_mem)
{
    TTextLink::IntMemSystem(2);
    PTTextLink testLink = new TTextLink((char*)"Test", NULL, NULL);
    PTTextLink tmp = (PTTextLink)testLink->GetCopy();
    EXPECT_NE(tmp, testLink);
}

