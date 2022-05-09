#include "pch.h"
#include "gtest/gtest.h"
#include "..\TextEditor\Headers\TTextLink.h"
#include "..\TextEditor\Headers\TText.h"

TEST(TText, TText_Conctuctor_empty)
{
    TTextLink::IntMemSystem(1);
    ASSERT_NO_THROW(TText tmp);
}
TEST(TText, TText_Conctuctor)
{
    TTextLink::IntMemSystem(1);
    PTTextLink pLink = new TTextLink((char*)"str");
    ASSERT_NO_THROW(TText tmp(pLink));
}

//get copy
TEST(TText, TText_getCopy_own_memory)
{
    TTextLink::IntMemSystem(3);
    PTTextLink pl = new TTextLink((char*)"copy", NULL, NULL);
    TText t1(pl);
    PTText cpy = t1.getCopy();
    EXPECT_NE(&t1, cpy);
}

TEST(TText, TText_getCopy)
{
    TTextLink::IntMemSystem(3);
    PTTextLink pl = new TTextLink((char*)"copy", NULL, NULL);
    TText t1(pl);
    PTText cpy = t1.getCopy();
    std::string s = t1.GetLine();
    s = cpy->GetLine();
    EXPECT_EQ(t1.GetLine(), cpy->GetLine());
}

TEST(TText, TText_SetLine)
{
    TTextLink::IntMemSystem(1);
    PTTextLink pLink = new TTextLink((char*)"str");
    TText tmp(pLink);
    tmp.SetLine((char*)"Good job");
    EXPECT_EQ("Good job", tmp.GetLine());
}
///* Insertion */
TEST(TText, TText_InsNextLine)
{
    TTextLink::IntMemSystem(2);
    PTTextLink pLink = new TTextLink((char*)"str");
    TText tmp(pLink);
    tmp.InsNextLine((char*)"Test");
    EXPECT_EQ(TextOk, tmp.GetRetCode());
}

TEST(TText, TText_InsNextSection)
{
    TTextLink::IntMemSystem(2);
    PTTextLink pLink = new TTextLink((char*)"str");
    TText tmp(pLink);
    tmp.InsNextSection((char*)"Test");
    EXPECT_EQ(TextOk, tmp.GetRetCode());
}

TEST(TText, TText_InsDownLine)
{
    TTextLink::IntMemSystem(2);
    PTTextLink pLink = new TTextLink((char*)"str");
    TText tmp(pLink);
    tmp.InsDownLine((char*)"Test");
    EXPECT_EQ(TextOk, tmp.GetRetCode());
}

TEST(TText, TText_InsDownSection)
{
    TTextLink::IntMemSystem(2);
    PTTextLink pLink = new TTextLink((char*)"str");
    TText tmp(pLink);
    tmp.InsDownSection((char*)"Test");
    EXPECT_EQ(TextOk, tmp.GetRetCode());
}

///*Navigation*/

TEST(TText, TText_GoFirstLink)
{
    TTextLink::IntMemSystem(2);
    PTTextLink pNext = new TTextLink((char*)"Next", NULL, NULL);
    PTTextLink pLink = new TTextLink((char*)"Test", pNext, NULL);
    TText tmp(pLink);
    tmp.GoFirstLink();
    EXPECT_STREQ("Test", tmp.GetLine().c_str());
    EXPECT_EQ(TextOk, tmp.GetRetCode());
}

TEST(TText, TText_GoDownLink)
{
    TTextLink::IntMemSystem(2);
    PTTextLink pDown = new TTextLink((char*)"Down", NULL, NULL);
    PTTextLink pLink = new TTextLink((char*)"Test", NULL, pDown);
    TText tmp(pLink);
    tmp.GoDownLink();
    EXPECT_STREQ("Down", tmp.GetLine().c_str());
    EXPECT_EQ(TextOk, tmp.GetRetCode());
}

TEST(TText, TText_GoNextLink)
{
    TTextLink::IntMemSystem(2);
    PTTextLink pNext = new TTextLink((char*)"Next", NULL, NULL);
    PTTextLink pLink = new TTextLink((char*)"str", pNext, NULL);
    TText tmp(pLink);
    tmp.GoNextLink();
    EXPECT_STREQ("Next", tmp.GetLine().c_str());
    EXPECT_EQ(TextOk, tmp.GetRetCode());
}

TEST(TText, TText_GoPrevLink)
{
    TTextLink::IntMemSystem(3);
    PTTextLink pNext2 = new TTextLink((char*)"Next2", NULL, NULL);
    PTTextLink pNext1 = new TTextLink((char*)"Next1", pNext2, NULL);
    PTTextLink pLink = new TTextLink((char*)"Test", pNext1, NULL);
    TText tmp(pLink);
    tmp.GoNextLink();
    tmp.GoNextLink();
    tmp.GoPrevLink();
    EXPECT_STREQ("Next1", tmp.GetLine().c_str());
}

///* Deleting */
TEST(TText, TText_DelDownLine)
{
    TTextLink::IntMemSystem(2);
    PTTextLink pDown = new TTextLink((char*)"Down", NULL, NULL);
    PTTextLink pLink = new TTextLink((char*)"str", NULL, pDown);
    TText tmp(pLink);
    tmp.DelDownLine();
    EXPECT_EQ(TextOk, tmp.GetRetCode());
    tmp.GoDownLink();
    EXPECT_EQ(TextError, tmp.GetRetCode());
}

TEST(TText, TText_DelDownSection)
{
    TTextLink::IntMemSystem(2);
    PTTextLink pDown = new TTextLink((char*)"Down", NULL, NULL);
    PTTextLink pLink = new TTextLink((char*)"Test", NULL, pDown);
    TText tmp(pLink);
    tmp.DelDownSection();
    EXPECT_EQ(TextOk, tmp.GetRetCode());
    tmp.GoDownLink();
    EXPECT_EQ(TextError, tmp.GetRetCode());
}

TEST(TText, TText_DelNextLine)
{
    TTextLink::IntMemSystem(2);
    PTTextLink pNext = new TTextLink((char*)"Next", NULL, NULL);
    PTTextLink pLink = new TTextLink((char*)"Test", pNext, NULL);
    TText tmp(pLink);
    tmp.DelNextLine();
    EXPECT_EQ(TextOk, tmp.GetRetCode());
    tmp.GoNextLink();
    EXPECT_EQ(TextError, tmp.GetRetCode());
}

TEST(TText, TText_DelNextSection)
{
    TTextLink::IntMemSystem(2);
    PTTextLink pNext = new TTextLink((char*)"Next", NULL, NULL);
    PTTextLink pLink = new TTextLink((char*)"Test", pNext, NULL);
    TText tmp(pLink);
    tmp.DelNextSection();
    EXPECT_EQ(TextOk, tmp.GetRetCode());
    tmp.GoNextLink();
    EXPECT_EQ(TextError, tmp.GetRetCode());
}

///* Iterator */

TEST(TText, TText_Reset)
{
    TTextLink::IntMemSystem(2);
    PTTextLink pNext = new TTextLink((char*)"Next", NULL, NULL);
    PTTextLink pLink = new TTextLink((char*)"Test", pNext, NULL);
    TText tmp(pLink);
    tmp.GoNextLink();
    tmp.Reset();
    EXPECT_STREQ("Test", tmp.GetLine().c_str());
    EXPECT_EQ(TextOk, tmp.GetRetCode());
}

TEST(TText, TText_IsTextEnded)
{
    TTextLink::IntMemSystem(1);
    PTTextLink pLink = new TTextLink((char*)"Test", NULL, NULL);
    TText tmp(pLink);
    EXPECT_TRUE(tmp.IsTextEnded());
}

TEST(TText, TText_GoNext)
{
    TTextLink::IntMemSystem(3);
    PTTextLink pNext2 = new TTextLink((char*)"Next2", NULL, NULL);
    PTTextLink pNext1 = new TTextLink((char*)"Next1", pNext2, NULL);
    PTTextLink pLink = new TTextLink((char*)"Test", pNext1, NULL);
    TText tmp(pLink);
    tmp.Reset();
    tmp.GoNext();
    EXPECT_STREQ("Next1", tmp.GetLine().c_str());
}

/* Work with files */

/* Work with files */

TEST(TText, TText_Read_from_file)
{
    TTextLink::IntMemSystem(10);
    PTTextLink pNext = new TTextLink((char*)"strNext", NULL, NULL);
    PTTextLink pDown = new TTextLink((char*)"strDown", NULL, NULL);
    PTTextLink pLink = new TTextLink((char*)"str", pNext, pDown);
    TText tmp(pLink);
    ASSERT_NO_THROW(tmp.Read((char*)"../TestEditor_Tests/file.txt"));
}


TEST(TText, TText_Write_to_file)
{
    TTextLink::IntMemSystem(10);
    PTTextLink pNext = new TTextLink((char*)"strNext", NULL, NULL);
    PTTextLink pDown = new TTextLink((char*)"strDown", NULL, NULL);
    PTTextLink pLink = new TTextLink((char*)"str", pNext, pDown);
    TText tmp(pLink);
    ASSERT_NO_THROW(tmp.Write((char*)"../TestEditor_Tests/file.txt"));
}

TEST(TText, TText_Print)
{
    TTextLink::IntMemSystem(5);
    PTTextLink pNext = new TTextLink((char*)"strNext");
    PTTextLink pDown = new TTextLink((char*)"strDown");
    PTTextLink pLink = new TTextLink((char*)"str", pNext, pDown);
    TText tmp(pLink);
    ASSERT_NO_THROW(tmp.Print());
}