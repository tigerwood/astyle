//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include "AStyleTest.h"

//----------------------------------------------------------------------------
// anonymous namespace
//----------------------------------------------------------------------------

namespace
{

//-------------------------------------------------------------------------
// AStyle Break Closing Brackets
// Additional tests are in the Brackets tests
//-------------------------------------------------------------------------

TEST(BreakClosingBrackets, LongOption)
{
	// test NONE_MODE brackets with break closing headers
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    }\n"
		"    else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char options[] = "break-closing-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, ShortOption)
{
	// test NONE_MODE brackets with break closing headers
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    }\n"
		"    else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char options[] = "-y";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, Break)
{
	// test BREAK_MODE brackets with break closing headers
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"    {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char options[] = "brackets=break, break-closing-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, Attach)
{
	// test ATTACH_MODE brackets with break closing headers
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    }\n"
		"    else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char options[] = "brackets=attach, break-closing-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, Linux)
{
	// test LINUX_MODE brackets with break closing headers
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    }\n"
		"    else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char options[] = "brackets=linux, break-closing-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, Stroustrup)
{
	// test STROUSTRUP_MODE brackets with break closing headers
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    }\n"
		"    else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char options[] = "brackets=stroustrup, break-closing-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, KeepBlocks)
{
	// test break closing headers with keep one line blocks
	// it shouldn't make any difference
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    }\n"
		"    else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char options[] = "brackets=attach, break-closing-brackets, keep-one-line-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, ElseSans)
{
	// test if/else without break closing brackets
	// else statement should be attached to the closing bracket
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    }\n"
		"    else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, Catch)
{
	// test try/catch with break closing brackets
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    try {\n"
		"        bar();\n"
		"    } catch (int i) {\n"
		"        cout << i << endl;\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    try {\n"
		"        bar();\n"
		"    }\n"
		"    catch (int i) {\n"
		"        cout << i << endl;\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach, break-closing-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, CatchSans)
{
	// test try/catch without break closing brackets
	// catch statement should be attached to the closing bracket
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    try {\n"
		"        bar();\n"
		"    }\n"
		"    catch (int i) {\n"
		"        cout << i << endl;\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    try {\n"
		"        bar();\n"
		"    } catch (int i) {\n"
		"        cout << i << endl;\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, While)
{
	// test do/while with break closing brackets
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    do {\n"
		"        bar();\n"
		"    } while (int x < 9);\n"
		"}\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    do {\n"
		"        bar();\n"
		"    }\n"
		"    while (int x < 9);\n"
		"}\n";
	char options[] = "brackets=attach, break-closing-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, WhileSans)
{
	// test do/while without break closing brackets
	// while statement should be attached to the closing bracket
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    do {\n"
		"        bar();\n"
		"    }\n"
		"    while (int x < 9);\n"
		"}\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    do {\n"
		"        bar();\n"
		"    } while (int x < 9);\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Break Else If
//-------------------------------------------------------------------------

TEST(BreakElseIfs, LongOption)
{
	// test break else/if
	// else/if statements should be broken
	char textIn[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        if (isBar) {\n"
		"            anotherBar();\n"
		"            } else    if (isBar) {\n"
		"                anotherBar();\n"
		"            } else {\n"
		"                if (isBar) {\n"
		"                    anotherBar();\n"
		"                }\n"
		"            }\n"
		"\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else anotherBar();\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"\n"
		"#if 0\n"
		"    foo();\n"
		"#else\n"
		"    if (bar)\n"
		"        fooBar();\n"
		"#endif\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        if (isBar) {\n"
		"            anotherBar();\n"
		"        } else\n"
		"            if (isBar) {\n"
		"                anotherBar();\n"
		"            } else {\n"
		"                if (isBar) {\n"
		"                    anotherBar();\n"
		"                }\n"
		"            }\n"
		"\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else anotherBar();\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"\n"
		"#if 0\n"
		"    foo();\n"
		"#else\n"
		"    if (bar)\n"
		"        fooBar();\n"
		"#endif\n"
		"}\n";
	char options[] = "break-elseifs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakElseIfs, ShortOption)
{
	// test break else/if short options
	// else/if statements should be broken
	char textIn[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        if (isBar) {\n"
		"            anotherBar();\n"
		"            } else    if (isBar) {\n"
		"                anotherBar();\n"
		"            } else {\n"
		"                if (isBar) {\n"
		"                    anotherBar();\n"
		"                }\n"
		"            }\n"
		"\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else anotherBar();\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"\n"
		"#if 0\n"
		"    foo();\n"
		"#else\n"
		"    if (bar)\n"
		"        fooBar();\n"
		"#endif\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        if (isBar) {\n"
		"            anotherBar();\n"
		"        } else\n"
		"            if (isBar) {\n"
		"                anotherBar();\n"
		"            } else {\n"
		"                if (isBar) {\n"
		"                    anotherBar();\n"
		"                }\n"
		"            }\n"
		"\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else anotherBar();\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"\n"
		"#if 0\n"
		"    foo();\n"
		"#else\n"
		"    if (bar)\n"
		"        fooBar();\n"
		"#endif\n"
		"}\n";
	char options[] = "-e";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakElseIfs, Sans)
{
	// test without break else/if
	// else/if statements should be joined
	// but do NOT join #else
	char textIn[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        if (isBar) {\n"
		"            anotherBar();\n"
		"            } else    if (isBar) {\n"
		"                anotherBar();\n"
		"            } else {\n"
		"                if (isBar) {\n"
		"                    anotherBar();\n"
		"                }\n"
		"            }\n"
		"\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else anotherBar();\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"\n"
		"#if fooDef1\n"
		"    foo();\n"
		"#else\n"
		"    if (bar)\n"
		"        fooBar();\n"
		"#endif\n"
		"#   if fooDef2\n"
		"    foo();\n"
		"#   else\n"
		"    fooBar();\n"
		"#   endif\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else if (isBar) {\n"
		"        anotherBar();\n"
		"    } else    if (isBar) {\n"
		"        anotherBar();\n"
		"    } else {\n"
		"        if (isBar) {\n"
		"            anotherBar();\n"
		"        }\n"
		"    }\n"
		"\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else anotherBar();\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"\n"
		"#if fooDef1\n"
		"    foo();\n"
		"#else\n"
		"    if (bar)\n"
		"        fooBar();\n"
		"#endif\n"
		"#   if fooDef2\n"
		"    foo();\n"
		"#   else\n"
		"    fooBar();\n"
		"#   endif\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakElseIfs, KeepOneLineBlocks)
{
	// test break else/if with keep one line blocks
	// else/if statements remain the same with breaking/attaching
	char text[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    { bar(); if (isBar1) anotherBar1(); else if (isBar2) anotherBar2(); }\n"
		"    { if (isBar1) anotherBar1(); else if (isBar2) anotherBar2(); }\n"
		"}\n";
	char options[] = "break-elseifs, keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakElseIfs, KeepOneLineStatements)
{
	// test break else/if with keep one line statements
	// else/if statements remain the same with breaking/attaching
	char text[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    bar(); if (isBar1) anotherBar1(); else if (isBar2) anotherBar2();\n"
		"    if (isBar1) anotherBar1(); else if (isBar2) anotherBar2();\n"
		"}\n";
	char options[] = "break-elseifs, keep-one-line-statements";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakElseIfs, Comments1)
{
	// Test break else/if with comments preceding the 'else'.
	// The should be indented the same as the following 'else'.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        bar1();\n"
		"    // comment 2\n"
		"    else if (isFoo2)\n"
		"        bar2();\n"
		"    // comment 3\n"
		"    else if (isFoo3)\n"
		"        bar3();\n"
		"    // comment 4\n"
		"    else bar4();\n"
		"    // not else-if comment\n"
		"    endBar();\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        bar1();\n"
		"    // comment 2\n"
		"    else\n"
		"        if (isFoo2)\n"
		"            bar2();\n"
		"        // comment 3\n"
		"        else\n"
		"            if (isFoo3)\n"
		"                bar3();\n"
		"            // comment 4\n"
		"            else bar4();\n"
		"    // not else-if comment\n"
		"    endBar();\n"
		"}";
	char options[] = "break-elseifs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakElseIfs, Comments2)
{
	// Test break else/if with comments preceding the 'else'.
	// The should be indented the same as the following 'else'.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        bar1(); /* comment 1A */\n"
		"    /* comment 2 */\n"
		"    else if (isFoo2) /* comment 2A */\n"
		"    { bar2(); }\n"
		"    /*  comment 3 */\n"
		"    else if (isFoo3)\n"
		"    { bar3(); }\n"
		"    /* comment 4 */\n"
		"    else bar4();\n"
		"    /*  not else-if comment */\n"
		"    endBar();\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        bar1(); /* comment 1A */\n"
		"    /* comment 2 */\n"
		"    else\n"
		"        if (isFoo2) /* comment 2A */\n"
		"        { bar2(); }\n"
		"        /*  comment 3 */\n"
		"        else\n"
		"            if (isFoo3)\n"
		"            { bar3(); }\n"
		"            /* comment 4 */\n"
		"            else bar4();\n"
		"    /*  not else-if comment */\n"
		"    endBar();\n"
		"}";
	char options[] = "break-elseifs, keep-one-line-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakElseIfs, Comments3)
{
	// Test break else/if with comments IFs with no ELSE.
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        // comment 2\n"
		"        if (isFoo2)\n"
		"            // comment 3\n"
		"            if (isFoo3)\n"
		"                bar3();\n"
		"    // not IF comment\n"
		"    endBar();\n"
		"}";
	char options[] = "break-elseifs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakElseIfs, Comments4)
{
	// Test break else/if with multiple-line comments preceding the 'else'.
	// The should be indented the same as the following 'else'.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        bar1();\n"
		"    else if (isFoo2)\n"
		"        bar2();\n"
		"    else if (isFoo3)\n"
		"        bar3();\n"
		"    // comment 4A\n"
		"    // comment 4B\n"
		"    // comment 4C\n"
		"    else bar4();\n"
		"    // not else-if commentA\n"
		"    // not else-if commentB\n"
		"    // not else-if commentC\n"
		"    endBar();\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        bar1();\n"
		"    else\n"
		"        if (isFoo2)\n"
		"            bar2();\n"
		"        else\n"
		"            if (isFoo3)\n"
		"                bar3();\n"
		"            // comment 4A\n"
		"            // comment 4B\n"
		"            // comment 4C\n"
		"            else bar4();\n"
		"    // not else-if commentA\n"
		"    // not else-if commentB\n"
		"    // not else-if commentC\n"
		"    endBar();\n"
		"}";
	char options[] = "break-elseifs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakElseIfs, Comments5)
{
	// Test break else/if with multiple-line comments preceding the 'else'.
	// The should be indented the same as the following 'else'.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        bar1();\n"
		"    else if (isFoo2)\n"
		"        bar2();\n"
		"    /** comment 3A\n"
		"      * comment 3B\n"
		"      * comment 3C */\n"
		"    else if (isFoo3)\n"
		"        bar3();\n"
		"    /** comment 4A\n"
		"      * comment 4B\n"
		"      * comment 4C\n"
		"      */\n"
		"    else bar4();\n"
		"    /* not else-if commentA\n"
		"     * not else-if commentB\n"
		"     * not else-if commentC\n"
		"     */\n"
		"    endBar();\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        bar1();\n"
		"    else\n"
		"        if (isFoo2)\n"
		"            bar2();\n"
		"        /** comment 3A\n"
		"          * comment 3B\n"
		"          * comment 3C */\n"
		"        else\n"
		"            if (isFoo3)\n"
		"                bar3();\n"
		"            /** comment 4A\n"
		"              * comment 4B\n"
		"              * comment 4C\n"
		"              */\n"
		"            else bar4();\n"
		"    /* not else-if commentA\n"
		"     * not else-if commentB\n"
		"     * not else-if commentC\n"
		"     */\n"
		"    endBar();\n"
		"}";
	char options[] = "break-elseifs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakElseIfs, CommentsInPreprocessor)
{
	// Test break else/if with comment in a preprocessor directive.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        bar1();\n"
		"    else if (isFoo4)\n"
		"        bar4();\n"
		"#ifdef IS_GUI\n"
		"    // Beg of options used by GUI\n"
		"    else if (isFoo4A)\n"
		"        bar4A();\n"
		"#else\n"
		"    // Options used by only console\n"
		"    else if (isFoo5)\n"
		"        bar5();\n"
		"#endif\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        bar1();\n"
		"    else\n"
		"        if (isFoo4)\n"
		"            bar4();\n"
		"#ifdef IS_GUI\n"
		"        // Beg of options used by GUI\n"
		"        else\n"
		"            if (isFoo4A)\n"
		"                bar4A();\n"
		"#else\n"
		"        // Options used by only console\n"
		"        else\n"
		"            if (isFoo5)\n"
		"                bar5();\n"
		"#endif\n"
		"}";
	char options[] = "break-elseifs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakElseIfs, AddBrackets)
{
	// Test break else/if with add-brackets.
	// The resulting closing brackets should align
	// with the 'if' instead of the 'else'.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo1)\n"
		"        bar1();\n"
		"    else if (isFoo2)\n"
		"        bar2();\n"
		"    else if (isFoo3)\n"
		"        bar3();\n"
		"    else bar4();\n"
		"    endBar();\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo1) {\n"
		"        bar1();\n"
		"    }\n"
		"    else\n"
		"        if (isFoo2) {\n"
		"            bar2();\n"
		"        }\n"
		"        else\n"
		"            if (isFoo3) {\n"
		"                bar3();\n"
		"            }\n"
		"            else {\n"
		"                bar4();\n"
		"            }\n"
		"    endBar();\n"
		"}";
	char options[] = "break-elseifs, add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakElseIfs, EndOfFileComments1)
{
	// Test comments at the end of file.
	// Was causing an exception in call to PeekNextText().
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    endBar();\n"
		"}"
		"// end of line comment";
	char options[] = "break-elseifs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakElseIfs, EndOfFileComments2)
{
	// Test comments at the end of file.
	// Was causing an exception in call to PeekNextText().
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    endBar();\n"
		"}"
		"/* end of line comment */";
	char options[] = "break-elseifs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakElseIfs, WithSwitch)
{
	// test break else/if with a switch statement
	// should not separate the colon from the header
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    switch (Current_Led_Toggle)\n"
		"    {\n"
		"    case LED_TOGGLE_NORMAL:\n"
		"        break;\n"
		"    default:\n"
		"        break;\n"
		"    }\n"
		"}\n";
	char options[] = "break-elseifs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakElseIfs, WithMaxCodeLength)
{
	// test break else/if with a max code length
	// should not have an empty line between the IF and the statement
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (config.chkAnnSource)                                   param << _T(\" -A\") << config.txtAnnSource;\n"
		"    if (config.chkMinCount)                                    param << _T(\" -m\") << config.spnMinCount;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (config.chkAnnSource)\n"
		"        param << _T(\" -A\") << config.txtAnnSource;\n"
		"    if (config.chkMinCount)\n"
		"        param << _T(\" -m\") << config.spnMinCount;\n"
		"}\n";
	char options[] = "break-elseifs, max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Keep One Line Statements
//-------------------------------------------------------------------------

TEST(KeepOneLineStatements, LongOption)
{
	// test keep one line statements
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        isFoo=false; isBar=true;\n"
		"    }\n"
		"}\n";
	char options[] = "keep-one-line-statements";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineStatements, ShortOption)
{
	// // test keep one line statements short option
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        isFoo=false; isBar=true;\n"
		"    }\n"
		"}\n";
	char options[] = "-o";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineStatements, WithHeader)
{
	// test keep one line statements with a header in one of the statements
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    SendEvent(0, m_editItem, &te); if (!te.IsAllowed()) return;\n"
		"    CalculatePositions();\n"
		"}";
	char options[] = "keep-one-line-statements";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineStatements, SansWithHeader1)
{
	// test without keep-one-line statements
	// one-line statements with a header in one of the statements
	// should break the statements
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    SendEvent(0, m_editItem, &te); if (!te.IsAllowed()) return;\n"
		"    CalculatePositions();\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    SendEvent(0, m_editItem, &te);\n"
		"    if (!te.IsAllowed()) return;\n"
		"    CalculatePositions();\n"
		"}";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineStatements, SansWithHeader2)
{
	// test without keep-one-line statements but with break blocks
	// one-line statements with a header in one of the statements
	// should break the statements and the header block
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    SendEvent(0, m_editItem, &te); if (!te.IsAllowed()) return;\n"
		"    CalculatePositions();\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    SendEvent(0, m_editItem, &te);\n"
		"\n"
		"    if (!te.IsAllowed()) return;\n"
		"\n"
		"    CalculatePositions();\n"
		"}";
	char options[] = "break-blocks=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineStatements, BreakBlocks1)
{
	// test with break-blocks=all and a header as the SECOND statement
	// should not change the lines
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    SendEvent(0, m_editItem, &te); if (!te.IsAllowed()) return;\n"
		"    CalculatePositions();\n"
		"}";
	char options[] = "keep-one-line-statements, break-blocks=all";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineStatements, BreakBlocks2)
{
	// Test with break-blocks=all and a header as the FIRST statement.
	// Should keep the one-line statements and break the block.
	// Adding keep-one-line-blocks would not break the block.
	// See the following test.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (!te.IsAllowed()) return; SendEvent(0, m_editItem, &te);\n"
		"    CalculatePositions();\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (!te.IsAllowed()) return; SendEvent(0, m_editItem, &te);\n"
		"\n"
		"    CalculatePositions();\n"
		"}";
	char options[] = "keep-one-line-statements, break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineStatements, BreakBlocks3)
{
	// Test with break-blocks and keep-one-line-statements.
	// Should not break the Block.
	// Without keep-one-line-statements it will break the block.
	// See the previous test.
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if ( getter ) mv.Get = _T ( \"Get\" ) + method;\n"
		"    else mv.Get = wxEmptyString;\n"
		"}";
	char options[] = "keep-one-line-statements, break-blocks, keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineStatements, BreakBlocksMaxCodeLength1)
{
	// test with break-blocks=all and max code length
	// should break the IF statement and break the block
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    SendEvent(0, m_editItem, &te); if (!te.IsAllowed()) return;\n"
		"    CalculatePositions();\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    SendEvent(0, m_editItem, &te);\n"
		"\n"
		"    if (!te.IsAllowed()) return;\n"
		"\n"
		"    CalculatePositions();\n"
		"}";
	char options[] = "keep-one-line-statements, break-blocks=all, max-code-length=60";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineStatements, BreakBlocksMaxCodeLength2)
{
	// test with break-blocks=all and without max code length
	// should NOT break the one line statement
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    SendEvent(0, m_editItem, &te); if (!te.IsAllowed()) return;\n"
		"    CalculatePositions();\n"
		"}";
	char options[] = "keep-one-line-statements, break-blocks=all";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Keep One Line Blocks
//-------------------------------------------------------------------------

TEST(KeepOneLineBlocks, LongOption)
{
	// test keep one line blocks
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!j) { j=1; i=i-10; }\n"
		"}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, ShortOption)
{
	// test keep one line blocks short option
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!j) { j=1; i=i-10; }\n"
		"}\n";
	char options[] = "-O";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, StartOfLine)
{
	// line beginning with one-line blocks do NOT get a extra indent
	char text[] =
		"\nclass Foo\n"
		"{\n"
		"public:\n"
		"    int getFoo() const\n"
		"    { return isFoo; }\n"
		"};\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, NoneBrackets)
{
	// test keep one line blocks
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (comment&&code) { ++codecomments_lines; }\n"
		"    else if (comment) { ++comment_lines; }\n"
		"    else if (code) { ++code_lines; }\n"
		"}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, BreakBrackets)
{
	// test keep one line blocks
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (comment&&code) { ++codecomments_lines; }\n"
		"    else if (comment) { ++comment_lines; }\n"
		"    else if (code) { ++code_lines; }\n"
		"}\n";
	char options[] = "keep-one-line-blocks, brackets=break";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, AttachBrackets)
{
	// test keep one line blocks
	char text[] =
		"\nvoid foo() {\n"
		"    if (comment&&code) { ++codecomments_lines; }\n"
		"    else if (comment) { ++comment_lines; }\n"
		"    else if (code) { ++code_lines; }\n"
		"}\n";
	char options[] = "keep-one-line-blocks, brackets=attach";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, LinuxBrackets)
{
	// test keep one line blocks
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (comment&&code) { ++codecomments_lines; }\n"
		"    else if (comment) { ++comment_lines; }\n"
		"    else if (code) { ++code_lines; }\n"
		"}\n";
	char options[] = "keep-one-line-blocks, brackets=linux";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, RunInBrackets)
{
	// test keep one line blocks
	char text[] =
		"\nvoid foo()\n"
		"{   if (comment&&code) { ++codecomments_lines; }\n"
		"    else if (comment) { ++comment_lines; }\n"
		"    else if (code) { ++code_lines; }\n"
		"}\n";
	char options[] = "keep-one-line-blocks, brackets=run-in";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, BreakElseIf)
{
	// test keep one line blocks and break elseifs
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!j) { j=1; if (i) i=i-10; }\n"
		"    if (!j) { j=1; if (i) i=i-10; else i=i-20; }\n"
		"    if (!j) { j=1; if (i) i=i-10; else if (j) j=j-10; }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!j) { j=1; if (i) i=i-10; }\n"
		"    if (!j) { j=1; if (i) i=i-10; else i=i-20; }\n"
		"    if (!j) { j=1; if (i) i=i-10; else if (j) j=j-10; }\n"
		"}\n";
	char options[] = "keep-one-line-blocks, break-elseifs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, KeepOneLineStatementsAndBreakElseIf)
{
	// test keep one line blocks and keep one line statements
	//     with if statement and break elseifs
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!j) { j=1; if (i) i=i-10; }\n"
		"    if (!j) { j=1; if (i) i=i-10; else i=i-20; }\n"
		"    if (!j) { j=1; if (i) i=i-10; else if (j) j=j-10; }\n"
		"}\n";
	char options[] = "keep-one-line-blocks, keep-one-line-statements, break-elseifs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, BreakBlocks1)
{
	// test keep one line blocks and break blocks
	// should NOT break the block
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    { SendEvent(0, m_editItem, &te); if (!te.IsAllowed()) return; }\n"
		"    CalculatePositions();\n"
		"}";
	char options[] = "keep-one-line-blocks, break-blocks=all";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, BreakBlocks2)
{
	// test keep one line blocks and break blocks
	// should NOT break the block
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    { if (!te.IsAllowed()) return; SendEvent(0, m_editItem, &te); }\n"
		"    CalculatePositions();\n"
		"}";
	char options[] = "keep-one-line-blocks, break-blocks=all";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, BreakBlocks3)
{
	// test keep one line blocks and break blocks
	// should NOT break the one-line block
	// should break the other IF block
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"    { if (!te.IsAllowed()) return; SendEvent(0, m_editItem, &te); }\n"
		"    CalculatePositions();\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"    { if (!te.IsAllowed()) return; SendEvent(0, m_editItem, &te); }\n"
		"\n"
		"    CalculatePositions();\n"
		"}";
	char options[] = "keep-one-line-blocks, break-blocks=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, MultipleBrackets)
{
	// test keep one line blocks with multiple brackets
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"    public string FooName { get { return Foo; } set { Foo = value; } }\n"
		"\n"
		"    public event EventHandler Cancelled { add { } remove { } }\n"
		"}\n";
	char options[] = "keep-one-line-blocks, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, Sans1)
{
	// test without keep one line blocks
	// should not break {} when break brackets
	char text[] =
		"\nclass JipeConsole\n"
		"{\n"
		"    public JipeConsole(Jipe parent)\n"
		"    {\n"
		"        jipeConsole.addKeyListener(new KeyListener()\n"
		"        {\n"
		"            public void keyReleased(KeyEvent e) {}\n"
		"            public void keyTyped(KeyEvent e) {}\n"
		"        });\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, Sans2)
{
	// test without keep one line blocks
	// test attach bracket inside comment on single line block
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())     // comment\n"
		"        { return false; }\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) {   // comment\n"
		"        return false;\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, SansMultipleBrackets)
{
	// test without keep one line blocks with multiple brackets
	char textIn[] =
		"\npublic class FooClass\n"
		"{\n"
		"    public string FooName { get { return Foo; } set { Foo = value; } }\n"
		"\n"
		"    public event EventHandler Cancelled { add { } remove { } }\n"
		"}\n";
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"    public string FooName {\n"
		"        get {\n"
		"            return Foo;\n"
		"        }\n"
		"        set {\n"
		"            Foo = value;\n"
		"        }\n"
		"    }\n"
		"\n"
		"    public event EventHandler Cancelled {\n"
		"        add { } remove { }\n"
		"    }\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, NoneRunIn)
{
	// test none brackets with keep one line blocks and run-in
	// should not indent the run-in
	char text[] =
		"\nvoid foo()\n"
		"{   if (isFoo)\n"
		"    {/*ok*/;}\n"
		"    else {bar();}\n"
		"}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, RunInRunIn)
{
	// test run-in brackets with keep one line blocks and run-in
	// should not indent the run-in
	char text[] =
		"\nvoid foo()\n"
		"{   if (isFoo)\n"
		"    {/*ok*/;}\n"
		"    else {bar();}\n"
		"}\n";
	char options[] = "keep-one-line-blocks, brackets=run-in";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, NoneClosingHeader)
{
	// test keep one line blocks followed by a closing header
	// should not attach header to the one line statement
	char text[] =
		"\nvoid foo() {\n"
		"    if (isFoo)\n"
		"    {/*ok*/;}\n"
		"    else {bar();}\n"
		"}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, BreakClosingHeader)
{
	// test keep one line blocks followed by a closing header
	// should not attach header to the one line statement
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"    {/*ok*/;}\n"
		"    else {bar();}\n"
		"}\n";
	char options[] = "keep-one-line-blocks, brackets=break";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, AttachClosingHeader)
{
	// test keep one line blocks followed by a closing header
	// should not attach header to the one line statement
	char text[] =
		"\nvoid foo() {\n"
		"    if (isFoo)\n"
		"    {/*ok*/;}\n"
		"    else {bar();}\n"
		"}\n";
	char options[] = "keep-one-line-blocks, brackets=attach";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, LinuxClosingHeader)
{
	// test keep one line blocks followed by a closing header
	// should not attach header to the one line statement
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"    {/*ok*/;}\n"
		"    else {bar();}\n"
		"}\n";
	char options[] = "keep-one-line-blocks, brackets=linux";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, IndentSwitchBlock)
{
	// test one-line blocks with switch blocks
	char text[] =
		"\nvoid Foo(int fooBar)\n"
		"{\n"
		"    switch (fooBar)\n"
		"    {\n"
		"    case 1:\n"
		"        fooBar = 1;\n"
		"        break;\n"
		"    case 2:\n"
		"    { fooBar = 2; }\n"
		"    break;\n"
		"    default:\n"
		"    { break; }\n"
		"    }\n"
		"    int bar = true;\n"
		"}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, IndentSwitchBlock_IndentSwitches)
{
	// test one-line blocks with indented switch blocks
	char text[] =
		"\nvoid Foo(int fooBar)\n"
		"{\n"
		"    switch (fooBar)\n"
		"    {\n"
		"        case 1:\n"
		"            fooBar = 1;\n"
		"            break;\n"
		"        case 2:\n"
		"        { fooBar = 2; }\n"
		"        break;\n"
		"        default:\n"
		"        { break; }\n"
		"    }\n"
		"    int bar = true;\n"
		"}\n";
	char options[] = "keep-one-line-blocks, indent-switches";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, IndentAfterHeader)
{
	// test one line blocks indentation following a header
	char text[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    { bar(); }\n"
		"    else\n"
		"    { anotherBar(); }\n"
		"}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, IndentAfterHeaderSansBrackets)
{
	// Test one line blocks indentation following a header
	// when the header does not contain brackets.
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isBar1)\n"
		"        if (isBar2)\n"
		"        { return true; }\n"
		"\n"
		"    if (isBar1)\n"
		"        if (isBar2) { return true; }\n"
		"}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, IndentSansHeader)
{
	// test one line blocks indentation withouta header
	char text[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    bar()\n"
		"    { anotherBar(); }\n"
		"}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, IndentWithConstMethod)
{
	// Test one line blocks indentation following a header
	// when the header does not contain brackets.
	char text[] =
		"\nclass FooClass\n"
		"{\n"
		"    virtual bool foo() const\n"
		"    { return false; }\n"
		"};\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, WithAccessModifier)
{
	// A one line block with an access modifier should not break after the modifier.
	char text[] =
		"\ntemplate<typename T>\n"
		"struct RunHelper<T> { public: int Run(TestCases<T>&) { return 0; } };";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, WithAccessModifierSans)
{
	// A one line block with an access modifier should break if keep is NOT used.
	char textIn[] =
		"\ntemplate<typename T>\n"
		"struct RunHelper<T> { public: int Run(TestCases<T>&) { return 0; } };";
	char text[] =
		"\ntemplate<typename T>\n"
		"struct RunHelper<T> {\n"
		"public:\n"
		"    int Run(TestCases<T>&) {\n"
		"        return 0;\n"
		"    }\n"
		"};";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Add Brackets
//-------------------------------------------------------------------------

TEST(AddBrackets, LongOption)
{
	// test add brackets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) {\n"
		"        return false;\n"
		"    }\n"
		"}\n";
	char options[] = "add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, ShortOption)
{
	// test add brackets short option
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) {\n"
		"        return false;\n"
		"    }\n"
		"}\n";
	char options[] = "-j";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST(AddBrackets, All)
{
	// test add brackets for all headers
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else\n"
		"        return true;\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i)\n"
		"        bar &= ::FooBar();\n"
		"\n"
		"    while (isFoo)\n"
		"        bar();\n"
		"\n"
		"    do\n"
		"        bar();\n"
		"    while (isFoo);\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) {\n"
		"        return false;\n"
		"    }\n"
		"\n"
		"    if (isFoo()) {\n"
		"        return false;\n"
		"    }\n"
		"    else {\n"
		"        return true;\n"
		"    }\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i) {\n"
		"        bar &= ::FooBar();\n"
		"    }\n"
		"\n"
		"    while (isFoo) {\n"
		"        bar();\n"
		"    }\n"
		"\n"
		"    do {\n"
		"        bar();\n"
		"    }\n"
		"    while (isFoo);\n"
		"}\n";
	char options[] = "add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, ElseIf)
{
	// test add brackets for "else if" statements
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else if (isFoo())\n"
		"        return false;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) {\n"
		"        return false;\n"
		"    }\n"
		"    else if (isFoo()) {\n"
		"        return false;\n"
		"    }\n"
		"}\n";
	char options[] = "add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, SemiFollows)
{
	// test add brackets when a semi-colon follows the statement
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (a == 0) ; func1(); i++;\n"
		"    while (isFoo)  // comment\n"
		"            ;\n"
		"    while (isFoo); // comment\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (a == 0) ;\n"
		"    func1();\n"
		"    i++;\n"
		"    while (isFoo)  // comment\n"
		"        ;\n"
		"    while (isFoo); // comment\n"
		"}\n";
	char options[] = "add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, Sharp)
{
	// test add brackets to C# headers
	// 'delegate' statement contans brackets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    foreach (int i in fibarray)\n"
		"        System.Console.WriteLine(i);\n"
		"\n"
		"    if (isFoo)\n"
		"        bar(delegate { fooBar* = null; });\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    foreach (int i in fibarray) {\n"
		"        System.Console.WriteLine(i);\n"
		"    }\n"
		"\n"
		"    if (isFoo)\n"
		"        bar(delegate {\n"
		"        fooBar* = null;\n"
		"    });\n"
		"}\n";
	char options[] = "add-brackets, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, KeepOneLiners)
{
	// add brackets with keep one liners
	// should break the added brackets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else\n"
		"        return true;\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i)\n"
		"        bar &= ::FooBar();\n"
		"\n"
		"    while (isFoo)\n"
		"        bar();\n"
		"\n"
		"    do\n"
		"        bar();\n"
		"        while (isFoo);\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) {\n"
		"        return false;\n"
		"    }\n"
		"\n"
		"    if (isFoo()) {\n"
		"        return false;\n"
		"    }\n"
		"    else {\n"
		"        return true;\n"
		"    }\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i) {\n"
		"        bar &= ::FooBar();\n"
		"    }\n"
		"\n"
		"    while (isFoo) {\n"
		"        bar();\n"
		"    }\n"
		"\n"
		"    do {\n"
		"        bar();\n"
		"    }\n"
		"    while (isFoo);\n"
		"}\n";
	char options[] = "add-brackets, keep-one-line-blocks, keep-one-line-statements";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, SingleLine)
{
	// add brackets to one line statements
	// should break the statements
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) return false;\n"
		"\n"
		"    if (isFoo()) return false; else return true;\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i) bar &= ::FooBar();\n"
		"\n"
		"    while (isFoo) bar();\n"
		"\n"
		"    do bar(); while (isFoo);\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) {\n"
		"        return false;\n"
		"    }\n"
		"\n"
		"    if (isFoo()) {\n"
		"        return false;\n"
		"    }\n"
		"    else {\n"
		"        return true;\n"
		"    }\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i) {\n"
		"        bar &= ::FooBar();\n"
		"    }\n"
		"\n"
		"    while (isFoo) {\n"
		"        bar();\n"
		"    }\n"
		"\n"
		"    do {\n"
		"        bar();\n"
		"    }\n"
		"    while (isFoo);\n"
		"}\n";
	char options[] = "add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, SingleLineKeepOneLiners)
{
	// add brackets to one line statements with keep one liners
	// should keep one line blocks with added brackets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) return false;\n"
		"\n"
		"    if (isFoo()) return false; else return true;\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i) bar &= ::FooBar();\n"
		"\n"
		"    while (isFoo) bar();\n"
		"\n"
		"    do bar(); while (isFoo);\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) { return false; }\n"
		"\n"
		"    if (isFoo()) { return false; } else { return true; }\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i) { bar &= ::FooBar(); }\n"
		"\n"
		"    while (isFoo) { bar(); }\n"
		"\n"
		"    do { bar(); } while (isFoo);\n"
		"}\n";
	char options[] = "add-brackets, keep-one-line-blocks, keep-one-line-statements";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, Break)
{
	// test add brackets for broken brackets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else\n"
		"        return true;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"    {\n"
		"        return false;\n"
		"    }\n"
		"    else\n"
		"    {\n"
		"        return true;\n"
		"    }\n"
		"}\n";
	char options[] = "add-brackets, brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, Attach)
{
	// test add brackets for attached brackets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else\n"
		"        return true;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) {\n"
		"        return false;\n"
		"    } else {\n"
		"        return true;\n"
		"    }\n"
		"}\n";
	char options[] = "add-brackets, brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, RunIn)
{
	// test add brackets for run-in brakets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else\n"
		"        return true;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{   if (isFoo())\n"
		"    {   return false;\n"
		"    }\n"
		"    else\n"
		"    {   return true;\n"
		"    }\n"
		"}\n";
	char options[] = "add-brackets, brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, ExtraSpaces)
{
	// extra spaces should be removed
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( str )   (*str) += \"<?xml \";\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( str ) {\n"
		"        (*str) += \"<?xml \";\n"
		"    }\n"
		"}\n";
	char options[] = "add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, ElseParen)
{
	// else statement with following paren
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) break;\n"
		"    else (numBar)--;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) {\n"
		"        break;\n"
		"    }\n"
		"    else {\n"
		"        (numBar)--;\n"
		"    }\n"
		"}\n";
	char options[] = "add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, Quote)
{
	// must bypass quote with semi-colons and escaped quote marks
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) bar = '\\'';\n"
		"    if (isFoo) bar = '\\\\';\n"
		"    if (isBar) bar = \";;version=\";\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar = '\\'';\n"
		"    }\n"
		"    if (isFoo) {\n"
		"        bar = '\\\\';\n"
		"    }\n"
		"    if (isBar) {\n"
		"        bar = \";;version=\";\n"
		"    }\n"
		"}\n";
	char options[] = "add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, QuoteSans)
{
	// must bypass multi-line quote
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"        char* bar = \"one \\\n"
		"  two \\\n"
		"      three\";\n"
		"}\n";
	char options[] = "add-brackets";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, Comment)
{
	// must bypass comment before a semi-colon
	// the last statement should be bracketed
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) bar = // comment\n"
		"            foo2;\n"
		"    if (isFoo) bar =  /* comment */\n"
		"            foo2;\n"
		"    if (isFoo) bar = /* comment\n"
		"                        comment */\n"
		"            foo2;\n"
		"    if (isFoo) bar = /* comment */ foo2;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) bar = // comment\n"
		"            foo2;\n"
		"    if (isFoo) bar =  /* comment */\n"
		"            foo2;\n"
		"    if (isFoo) bar = /* comment\n"
		"                        comment */\n"
		"            foo2;\n"
		"    if (isFoo) {\n"
		"        bar = /* comment */ foo2;\n"
		"    }\n"
		"}\n";
	char options[] = "add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, Sans)
{
	// brackets should be added to specified headers only
	char text[] =
		"\npublic unsafe int foo()\n"
		"{\n"
		"    int readCount;\n"
		"    fixed(byte* pBuffer = buffer)\n"
		"        readCount = ReadMemory(size);\n"
		"}\n";
	char options[] = "add-brackets, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Add One Line Brackets
// Implies keep-one-line-blocks
//-------------------------------------------------------------------------

TEST(AddOneLineBrackets, LongOption)
{
	// test add one line brackets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"    { return false; }\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, ShortOption)
{
	// test add one line brackets short option
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"    { return false; }\n"
		"}\n";
	char options[] = "-J";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST(AddOneLineBrackets, All)
{
	// test add one line brackets for all headers
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else\n"
		"        return true;\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i)\n"
		"        bar &= ::FooBar();\n"
		"\n"
		"    while (isFoo)\n"
		"        bar();\n"
		"\n"
		"    do\n"
		"        bar();\n"
		"    while (isFoo);\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"    { return false; }\n"
		"\n"
		"    if (isFoo())\n"
		"    { return false; }\n"
		"    else\n"
		"    { return true; }\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i)\n"
		"    { bar &= ::FooBar(); }\n"
		"\n"
		"    while (isFoo)\n"
		"    { bar(); }\n"
		"\n"
		"    do\n"
		"    { bar(); }\n"
		"    while (isFoo);\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, ElseIf)
{
	// test add one line brackets for "else if" statements
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else if (isFoo())\n"
		"        return false;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"    { return false; }\n"
		"    else if (isFoo())\n"
		"    { return false; }\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, SemiFollows)
{
	// test add brackets when a semi-colon follows the statement
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (a == 0) ; func1(); i++;\n"
		"    while (isFoo)  // comment\n"
		"            ;\n"
		"    while (isFoo); // comment\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (a == 0) ;\n"
		"    func1();\n"
		"    i++;\n"
		"    while (isFoo)  // comment\n"
		"        ;\n"
		"    while (isFoo); // comment\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, Sharp)
{
	// test add one line brackets to C# headers
	// 'delegate' statement contans brackets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    foreach (int i in fibarray)\n"
		"        System.Console.WriteLine(i);\n"
		"\n"
		"    if (isFoo)\n"
		"        bar(delegate { fooBar* = null; });\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    foreach (int i in fibarray)\n"
		"    { System.Console.WriteLine(i); }\n"
		"\n"
		"    if (isFoo)\n"
		"        bar(delegate { fooBar* = null; });\n"
		"}\n";
	char options[] = "add-one-line-brackets, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, SingleLine)
{
	// add one line brackets to one line statements
	// should keep the one line statements
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) return false;\n"
		"\n"
		"    if (isFoo()) return false; else return true;\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i) bar &= ::FooBar();\n"
		"\n"
		"    while (isFoo) bar();\n"
		"\n"
		"    do bar(); while (isFoo);\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) { return false; }\n"
		"\n"
		"    if (isFoo()) { return false; }\n"
		"    else { return true; }\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i) { bar &= ::FooBar(); }\n"
		"\n"
		"    while (isFoo) { bar(); }\n"
		"\n"
		"    do { bar(); }\n"
		"    while (isFoo);\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, SingleLineKeepOneLiners)
{
	// add one line brackets to one line statements with keep one liners
	// should keep the one liners (keep blocks is implied)
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) return false;\n"
		"\n"
		"    if (isFoo()) return false; else return true;\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i) bar &= ::FooBar();\n"
		"\n"
		"    while (isFoo) bar();\n"
		"\n"
		"    do bar(); while (isFoo);\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) { return false; }\n"
		"\n"
		"    if (isFoo()) { return false; } else { return true; }\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i) { bar &= ::FooBar(); }\n"
		"\n"
		"    while (isFoo) { bar(); }\n"
		"\n"
		"    do { bar(); } while (isFoo);\n"
		"}\n";
	char options[] = "add-one-line-brackets, keep-one-line-statements";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, Break)
{
	// test add one line brackets for broken brackets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else\n"
		"        return true;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"    { return false; }\n"
		"    else\n"
		"    { return true; }\n"
		"}\n";
	char options[] = "add-one-line-brackets, brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, Attach)
{
	// test add one line brackets for attached brackets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else\n"
		"        return true;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"    { return false; }\n"
		"    else\n"
		"    { return true; }\n"
		"}\n";
	char options[] = "add-one-line-brackets, brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, RunIn)
{
	// test add one line brackets for run-in brakets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else\n"
		"        return true;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{   if (isFoo())\n"
		"    { return false; }\n"
		"    else\n"
		"    { return true; }\n"
		"}\n";
	char options[] = "add-one-line-brackets, brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, ExtraSpaces)
{
	// extra spaces should not be removed
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( str )   (*str) += \"<?xml \";\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( str )   { (*str) += \"<?xml \"; }\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, ElseParen)
{
	// else statement with following paren
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) break;\n"
		"    else (numBar)--;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) { break; }\n"
		"    else { (numBar)--; }\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, Quote)
{
	// must bypass quote with semi-colons and escaped quote marks
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) bar = '\\'';\n"
		"    if (isFoo) bar = '\\\\';\n"
		"    if (isBar) bar = \";;version=\";\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) { bar = '\\''; }\n"
		"    if (isFoo) { bar = '\\\\'; }\n"
		"    if (isBar) { bar = \";;version=\"; }\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, QuoteSans)
{
	// must bypass multi-line quote
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"        char* bar = \"one \\\n"
		"  two \\\n"
		"      three\";\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, Comment)
{
	// must bypass comment before a semi-colon
	// the last statement should be bracketed
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) bar = // comment\n"
		"            foo2;\n"
		"    if (isFoo) bar =  /* comment */\n"
		"            foo2;\n"
		"    if (isFoo) bar = /* comment\n"
		"                        comment */\n"
		"            foo2;\n"
		"    if (isFoo) bar = /* comment */ foo2;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) bar = // comment\n"
		"            foo2;\n"
		"    if (isFoo) bar =  /* comment */\n"
		"            foo2;\n"
		"    if (isFoo) bar = /* comment\n"
		"                        comment */\n"
		"            foo2;\n"
		"    if (isFoo) { bar = /* comment */ foo2; }\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, Sans)
{
	// brackets should be added to specified headers only
	char text[] =
		"\npublic unsafe int foo()\n"
		"{\n"
		"    int readCount;\n"
		"    fixed(byte* pBuffer = buffer)\n"
		"        readCount = ReadMemory(size);\n"
		"}\n";
	char options[] = "add-one-line-brackets, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Convert Tabs
//-------------------------------------------------------------------------

TEST(ConvertTabs, LongOption)
{
	// test convert tabs
	char textIn[] =
		"\nstatic FooBar foo1[] =\n"
		"{\n"
		"    { 10000,	0,		9 },\n"
		"    { 20000, 	0, 		9 },\n"
		"    { 30000,  	0,  	9 },\n"
		"    { 40000,   	0,   	9 },\n"
		"};\n"
		"\n"
		"static FooBar foo2[] =\n"
		"{\n"
		"	{ 10000,	0,		9 },\n"
		"	{ 20000, 	0, 		9 },\n"
		"	{ 30000,  	0,  	9 },\n"
		"	{ 40000,   	0,   	9 },\n"
		"};\n"
		"\n"
		"static FooBar foo3[] =\n"
		"{\n"
		"	{ 10000,	0,		9 },\n"
		" 	{ 20000, 	0, 		9 },\n"
		"  	{ 30000,  	0,  	9 },\n"
		"   	{ 40000,   	0,   	9 },\n"
		"};\n"
		"\n"
		"static FooBar foo4[] =\n"
		"{\n"
		"	{ 100,  	0,		9 },\n"
		" 	{ 200,   	0, 		9 },\n"
		"  	{ 300,    	0,  	9 },\n"
		"   	{ 400,     	0,   	9 },\n"
		"};\n";
	char text[] =
		"\nstatic FooBar foo1[] =\n"
		"{\n"
		"    { 10000,    0,      9 },\n"
		"    { 20000,    0,      9 },\n"
		"    { 30000,    0,      9 },\n"
		"    { 40000,    0,      9 },\n"
		"};\n"
		"\n"
		"static FooBar foo2[] =\n"
		"{\n"
		"    { 10000,    0,      9 },\n"
		"    { 20000,    0,      9 },\n"
		"    { 30000,    0,      9 },\n"
		"    { 40000,    0,      9 },\n"
		"};\n"
		"\n"
		"static FooBar foo3[] =\n"
		"{\n"
		"    { 10000,    0,      9 },\n"
		"    { 20000,    0,      9 },\n"
		"    { 30000,    0,      9 },\n"
		"    { 40000,    0,      9 },\n"
		"};\n"
		"\n"
		"static FooBar foo4[] =\n"
		"{\n"
		"    { 100,      0,      9 },\n"
		"    { 200,      0,      9 },\n"
		"    { 300,      0,      9 },\n"
		"    { 400,      0,      9 },\n"
		"};\n";
	char options[] = "convert-tabs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabs, ShortOption)
{
	// test convert tabs short option
	char textIn[] =
		"\nstatic FooBar foo[] =\n"
		"{\n"
		"    { 10000,	0,		9 },\n"
		"    { 20000, 	0, 		9 },\n"
		"    { 30000,  	0,  	9 },\n"
		"    { 40000,   	0,   	9 },\n"
		"};\n"
		"\n"
		"static FooBar fooTab[] =\n"
		"{\n"
		"	{ 10000,	0,		9 },\n"
		"	{ 20000, 	0, 		9 },\n"
		"	{ 30000,  	0,  	9 },\n"
		"	{ 40000,   	0,   	9 },\n"
		"}\n";
	char text[] =
		"\nstatic FooBar foo[] =\n"
		"{\n"
		"    { 10000,    0,      9 },\n"
		"    { 20000,    0,      9 },\n"
		"    { 30000,    0,      9 },\n"
		"    { 40000,    0,      9 },\n"
		"};\n"
		"\n"
		"static FooBar fooTab[] =\n"
		"{\n"
		"    { 10000,    0,      9 },\n"
		"    { 20000,    0,      9 },\n"
		"    { 30000,    0,      9 },\n"
		"    { 40000,    0,      9 },\n"
		"}\n";
	char options[] = "-c";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabs, Misc1)
{
	// convert comments, line comments, preprocessor
	// do NOT convert quotes
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"	/*\n"
		"	 * comment		comment\n"
		"  	 * comment	 	comment\n"
		"   	 * comment	  	comment\n"
		"     * comment	   	comment\n"
		"  	 */\n"
		"\n"
		"/*\n"
		"	commentedCode();\n"
		"*/\n"
		"\n"
		"    //	line    comment\n"
		" 	//  line	comment\n"
		"  	// 	line	comment\n"
		"   	//	line	comment\n"
		"\n"
		"#ifdef	foo\n"
		"	#error is foo\n"
		"  	#endif	// end	 of	if\n"
		"\n"
		"	char* quote =\n"
		" 	    \"this	is	a	quote \\\n"
		"  	quote 		continuation  \\\n"
		"	quote  		continuation\";\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"	/*\n"
		"	 * comment      comment\n"
		"	 * comment      comment\n"
		"	 * comment      comment\n"
		"	 * comment      comment\n"
		"	 */\n"
		"\n"
		"	/*\n"
		"	    commentedCode();\n"
		"	*/\n"
		"\n"
		"	//  line    comment\n"
		"	//  line    comment\n"
		"	//  line    comment\n"
		"	//  line    comment\n"
		"\n"
		"#ifdef  foo\n"
		"#error is foo\n"
		"#endif  // end   of if\n"
		"\n"
		"	char* quote =\n"
		"	    \"this	is	a	quote \\\n"
		"  	quote 		continuation  \\\n"
		"	quote  		continuation\";\n"
		"}\n";
	char options[] = "convert-tabs, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabs, Misc2)
{
	// test convert-tabs with comments
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"	/*	comment1\n"
		"		comment2\n"
		"	*/\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    /*  comment1\n"
		"        comment2\n"
		"    */\n"
		"}\n";
	char options[] = "convert-tabs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabs, Misc3)
{
	// test convert-tabs with line comments and tabbed output
	// should NOT convert the leading tabs in a non-indent comment
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"//	comment1	comment1a\n"
		" //	comment2	comment2a\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"//	comment1 comment1a\n"
		"//	comment2    comment2a\n"
		"}\n";
	char options[] = "convert-tabs, --indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabs, Misc4)
{
	// test convert-tabs with unpad-paren and pad-paren-in
	// should replace the tab after the opening paren
	char textIn[] =
		"\nvoid foo( bool isFoo )\n"
		"{\n"
		"    if(	isFoo )\n"
		"        bar;\n"
		"}\n";
	char text[] =
		"\nvoid foo( bool isFoo )\n"
		"{\n"
		"    if( isFoo )\n"
		"        bar;\n"
		"}\n";
	char options[] = "convert-tabs, unpad-paren, pad-paren-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabs, Misc5)
{
	// test convert-tabs with comment continuation
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"	int bar1; /* comment1 */\n"
		"	int bar2; /* comment2\n"
		"				 comment3 */\n"
		"	int bar3; /* comment3 */\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    int bar1; /* comment1 */\n"
		"    int bar2; /* comment2\n"
		"                 comment3 */\n"
		"    int bar3; /* comment3 */\n"
		"}\n";
	char options[] = "convert-tabs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabs, Misc6)
{
	// verify that tabs are still present within quotes
	// should NOT have been replaced when AStyle was run
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    char* quote = \"this	is	a	quote \";\n"
		"}\n";
	// just check for the tab characters
	EXPECT_EQ('\t', text[37]);
	EXPECT_EQ('\t', text[40]);
	EXPECT_EQ('\t', text[42]);
}

TEST(ConvertTabs, ForceTabX1)
{
	// test convert-tabs in indent=force-tab-x
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    int bar1;		// comment1\n"
		"    int bar111;		/* comment2 */\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    int bar1;           // comment1\n"
		"    int bar111;         /* comment2 */\n"
		"}\n";
	char options[] = "indent=force-tab-x, convert-tabs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabs, ForceTabX2)
{
	// test convert-tabs in indent=force-tab-x with comment continuation
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    int bar1; /* comment1 */\n"
		"    int bar2; /* comment2\n"
		"		 comment3 */\n"
		"    int bar3; /* comment3 */\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    int bar1; /* comment1 */\n"
		"    int bar2; /* comment2\n"
		"                 comment3 */\n"
		"    int bar3; /* comment3 */\n"
		"}\n";
	char options[] = "indent=force-tab-x, convert-tabs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabs, PreprocessorIndent)
{
	// Test convert-tabs in a preprocessor indent.
	char textIn[] =
		"\n#if (! defined (yyoverflow) \\\n"
		"     && (! defined (__cplusplus) \\\n"
		"\t || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))\n";
	char text[] =
		"\n#if (! defined (yyoverflow) \\\n"
		"     && (! defined (__cplusplus) \\\n"
		"     || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))\n";
	char options[] = "indent-preprocessor, convert-tabs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Close Templates Tabs
//-------------------------------------------------------------------------

TEST(CloseTemplates, LongOption)
{
	// Test close-templates long option.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    vector<string<int> > vec\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    vector<string<int>> vec\n"
		"}";
	char options[] = "close-templates";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(CloseTemplates, ShortOption)
{
	// Test close-templates short option.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    vector<string<int> > vec;\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    vector<string<int>> vec;\n"
		"}";
	char options[] = "-xy";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(CloseTemplates, Sans)
{
	// Templates should NOT be closed without the option.
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    vector<string<int> > vec;\n"
		"}";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(CloseTemplates, Padded)
{
	// Test close-templates with padding inside the templates.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    vector< string< int > > vec;\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    vector<string<int>> vec;\n"
		"}";
	char options[] = "close-templates";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Max Code Length and Break After Conditional
//-------------------------------------------------------------------------

TEST(MaxCodeLength, LongOption)
{
	// Test max code length long option.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1\n"
		"            || thisVariable2 == thatVariable2\n"
		"            || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, ShortOption)
{
	// Test max code length short option.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1\n"
		"            || thisVariable2 == thatVariable2\n"
		"            || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char options[] = "-xC50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, ErrorMin)
{
	// Test max code length minimum value error.
	// Should call the error handler.
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	// use errorHandler2 to verify the error
	char options[] = "max-code-length=49";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	EXPECT_EQ(errorsIn + 1, errorsOut);
	delete [] textOut;
}

TEST(MaxCodeLength, ErrorMax)
{
	// Test max code length maximum value error.
	// Should call the error handler.
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	// use errorHandler2 to verify the error
	char options[] = "max-code-length=201";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	EXPECT_EQ(errorsIn + 1, errorsOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakAfterSemicolon1)
{
	// Test max code length breaking on a semicolon.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    for (charDistance = 1; charDistance < remainingCharNum; charDistance++)\n"
		"    {}\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    for (charDistance = 1;\n"
		"            charDistance < remainingCharNum; charDistance++)\n"
		"    {}\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakAfterSemicolon2)
{
	// Test max code length breaking on a semicolon.
	// Should not break before an end of line comment.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    toolBar->AddTool(idBtnSearch, wxBITMAP_TYPE_PNG); //Control(pBtnSearch);\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    toolBar->AddTool(idBtnSearch,\n"
		"                     wxBITMAP_TYPE_PNG); //Control(pBtnSearch);\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, PassedSemicolon)
{
	// Test max code length breaking on a passed semicolon.
	// Should not leave an empty line before the 'break' statements.
	char textIn[] =
		"\nvoid Foo() {\n"
		"    switch ( Desc->Type ) {\n"
		"    case Bar:      GenStr = _T(\"wxBarChartPoints::CreateWxBarChartPoints\"); break;\n"
		"    default:       GenStr = _T(\"wxBarChartPoints::CreateWxBarChartPoints\"); break;\n"
		"    }\n"
		"}";
	char text[] =
		"\nvoid Foo() {\n"
		"    switch ( Desc->Type ) {\n"
		"    case Bar:\n"
		"        GenStr = _T(\"wxBarChartPoints::CreateWxBarChartPoints\");\n"
		"        break;\n"
		"    default:\n"
		"        GenStr = _T(\"wxBarChartPoints::CreateWxBarChartPoints\");\n"
		"        break;\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, PassedColon)
{
	// Test max code length breaking on a passed colon.
	// Should not leave an empty line before the msWaitForIdle 'break' statement.
	char textIn[] =
		"\nvoid Foo() {\n"
		"    switch ( m_MouseState )\n"
		"    {\n"
		"        case msWaitForIdle:                                         break;\n"
		"        default:                  OnMouseIdle              (event); break;\n"
		"    }\n"
		"}";
	char text[] =
		"\nvoid Foo() {\n"
		"    switch ( m_MouseState )\n"
		"    {\n"
		"    case msWaitForIdle:\n"
		"        break;\n"
		"    default:\n"
		"        OnMouseIdle              (event);\n"
		"        break;\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakBeforeLogical1)
{
	// Test max code length break before conditional (the default).
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 && thisVariable2 == thatVariable2 && thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 or thisVariable2 == thatVariable2 or thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 and thisVariable2 == thatVariable2 and thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1\n"
		"            || thisVariable2 == thatVariable2\n"
		"            || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1\n"
		"            && thisVariable2 == thatVariable2\n"
		"            && thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1\n"
		"            or thisVariable2 == thatVariable2\n"
		"            or thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1\n"
		"            and thisVariable2 == thatVariable2\n"
		"            and thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakBeforeLogical2)
{
	// Test max code length break before conditional in a 'for' statement.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    for (charNum = 0; isWhiteSpace(currentLine[charNum]) && charNum + 1 < (int) len; charNum++)\n"
		"    {\n"
		"    }\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    for (charNum = 0; isWhiteSpace(currentLine[charNum])\n"
		"            && charNum + 1 < (int) len; charNum++)\n"
		"    {\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=80";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakAfterLogical)
{
	// Test max code length break after logical.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 && thisVariable2 == thatVariable2 && thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 or thisVariable2 == thatVariable2 or thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 and thisVariable2 == thatVariable2 and thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1 ||\n"
		"            thisVariable2 == thatVariable2 ||\n"
		"            thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 &&\n"
		"            thisVariable2 == thatVariable2 &&\n"
		"            thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 or\n"
		"            thisVariable2 == thatVariable2 or\n"
		"            thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 and\n"
		"            thisVariable2 == thatVariable2 and\n"
		"            thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char options[] = "max-code-length=50, break-after-logical";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakAfterLogical2)
{
	// Test max code length break before conditional in a 'for' statement.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    for (charNum = 0; isWhiteSpace(currentLine[charNum]) && charNum + 1 < (int) len; charNum++)\n"
		"    {\n"
		"    }\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    for (charNum = 0; isWhiteSpace(currentLine[charNum]) &&\n"
		"            charNum + 1 < (int) len; charNum++)\n"
		"    {\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=80, break-after-logical";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakAfterLogicalMisc)
{
	// Test max code length break after logical with the break coming just before
	// the "thisVariable3" (max-code-length2=70).
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariabl1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariabl1 == thatVariable1 && thisVariable2 == thatVariable2 && thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariabl1 == thatVariable1 or thisVariable2 == thatVariable2 or thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariabl1 == thatVariable1 and thisVariabl2 == thatVariabl2 and thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariabl1 == thatVariable1 || thisVariable2 == thatVariable2 ||\n"
		"            thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariabl1 == thatVariable1 && thisVariable2 == thatVariable2 &&\n"
		"            thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariabl1 == thatVariable1 or thisVariable2 == thatVariable2 or\n"
		"            thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariabl1 == thatVariable1 and thisVariabl2 == thatVariabl2 and\n"
		"            thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char options[] = "max-code-length=70, break-after-logical";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakAfterShortConcatenated)
{
	// test break after conditional short option concatenated
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1 ||\n"
		"            thisVariable2 == thatVariable2 ||\n"
		"            thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char options[] = "-xC50xL";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakAfterComma1)
{
	// Test max code length breaking on a comma.
	char textIn[] =
		"\nclass FooClass\n"
		"{\n"
		"private:\n"
		"    size_t Utf16ToUtf8(char* utf16In, size_t inLen, FileEncoding encoding, bool firstBlock, char* utf8Out) const;\n"
		"};\n"
		"\n"
		"void foo()\n"
		"{\n"
		"    size_t utf1 = Utf16ToUtf8(utf16In, inLen, encoding, firstBlock, utf8Out);\n"
		"}";
	char text[] =
		"\nclass FooClass\n"
		"{\n"
		"private:\n"
		"    size_t Utf16ToUtf8(char* utf16In, size_t inLen,\n"
		"                       FileEncoding encoding, bool firstBlock,\n"
		"                       char* utf8Out) const;\n"
		"};\n"
		"\n"
		"void foo()\n"
		"{\n"
		"    size_t utf1 = Utf16ToUtf8(utf16In, inLen,\n"
		"                              encoding, firstBlock, utf8Out);\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakAfterComma2)
{
	// Test max code length breaking on a comma.
	char textIn[] =
		"\nint ASBeautifier::getInStatementIndentAssign(const string& line) const\n"
		"{}\n"
		"\n"
		"void ASBeautifier::registerInStatementIndent(const string& line, int i, int tabIncrementIn, int minIndent)\n"
		"{}";
	char text[] =
		"\nint ASBeautifier::getInStatementIndentAssign(\n"
		"    const string& line) const\n"
		"{}\n"
		"\n"
		"void ASBeautifier::registerInStatementIndent(\n"
		"    const string& line, int i, int tabIncrementIn,\n"
		"    int minIndent)\n"
		"{}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakBeforeClosingParen)
{
	// Should not break line at an ending paren near the end of line.
	// Test with padded and unpadded paren.
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    wxCHECK_MSG (IsKindOf (wxDateProperty),\n"
		"                 wxT(\"DatePickerCtrl editor can only be used with wxDateProperty or derivative.\") );\n"
		"    wxCHECK_MSG (IsKindOf (wxDateProperty),\n"
		"                 wxT(\"DatePickerCtrl editor can only be used with wxDateProperty or derivative.\"));\n"
		"}";
	char options[] = "max-code-length=80";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakBeforeUnpaddedOperator1)
{
	// Test max code length breaking before an unpadded operator.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    TRACE(_T(\"Add token name=\")+name+_T(\", args=\")+args+_T(\", return type=\"));\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    TRACE(_T(\"Add token name=\")+name+_T(\", args=\")\n"
		"          +args+_T(\", return type=\"));\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakBeforeUnpaddedOperator2)
{
	// Test max code length breaking before an unpadded operator.
	// It should break BEFORE an unpadded operator after a quote.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (Interpreter.DEBUG)\n"
		"        Interpreter.debug(\"Time to initialize interpreter: \"+(t2-t1));\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (Interpreter.DEBUG)\n"
		"        Interpreter.debug(\"Time to initialize interpreter: \"\n"
		"                          + (t2 - t1));\n"
		"}";
	char options[] = "max-code-length=50, pad-oper";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakAfterUnpaddedComparisonOperator)
{
	// Test max code length breaking after an unpadded comparison operator.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if(data->GetKind()->GetAnotherKind()==FileTreeData::ftdkFile)\n"
		"        menu = child->GetSubMenu();\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if(data->GetKind()->GetAnotherKind()==\n"
		"            FileTreeData::ftdkFile)\n"
		"        menu = child->GetSubMenu();\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakBeforeUnpaddedComparisonOperator)
{
	// Test max code length breaking BEFORE an unpadded comparison operator
	// if the line is too long.
	char textIn[] =
		"\nprivate void Foo()\n"
		"{\n"
		"    (ControlDictionary[\"RegularExpressionCompileTextBox\"]).Text=(ControlDictionary[\"RegularExpressionTextBox\"]).Text;\n"
		"}";
	char text[] =
		"\nprivate void Foo()\n"
		"{\n"
		"    (ControlDictionary[\"RegularExpressionCompileTextBox\"]).Text\n"
		"        =(ControlDictionary[\"RegularExpressionTextBox\"]).Text;\n"
		"}";
	char options[] = "max-code-length=50, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Quote1)
{
	// Max code length should not break a quote line.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == \"a very long, long, long, long, long, quote\")\n"
		"        bar();\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 ==\n"
		"            \"a very long, long, long, long, long, quote\")\n"
		"        bar();\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Quote2)
{
	// Max code length should not break a quote line.
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    sendMsg(\"  if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3\"\n"
		"            \"thisVariable4 == thatVariable4 || thisVariable5 == thatVariable5 || thisVariable6 == thatVariable6\");\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Quote3)
{
	// Max code length should not break a quote line following a paren e.g. after wxT(.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (variable1 == wxT(\"xxxx xxx xxxxx xxxxxxx xxxxxxx\"))\n"
		"        ++mit;\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (variable1 ==\n"
		"            wxT(\"xxxx xxx xxxxx xxxxxxx xxxxxxx\"))\n"
		"        ++mit;\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Quote4)
{
	// Max code length should not break a quote line following a paren
	// when the parens are padded.
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if ( output.Contains ( _T ( \"No route\" ) ) )\n"
		"        errMsg << _ ( \"Can't connect to the remote.\\nVerify your connection.\" );\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, LineComment1)
{
	// Max code length should not break a line comment only line.
	char text[] =
		"\n//  if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3)\n"
		"void foo()\n"
		"{\n"
		"    // if (thisVariable1 == thatVariable1 && thisVariable2 == thatVariable2 && thisVariable3 == thatVariable3)\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, LineComment2)
{
	// Max code length should not break inside a line comment.
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (x == 1) // this is a long, long, long, long, long, long, long, comment\n"
		"        bar();\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, LineComment3)
{
	// Max code length should not break immediately before a line comment.
	// The break is in the whitespace before the comment.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (line[i] == '}')                                    // comment in column 60\n"
		"    {\n"
		"        foobar();\n"
		"    }\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (line[i] ==\n"
		"            '}')                                    // comment in column 60\n"
		"    {\n"
		"        foobar();\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, LineComment4)
{
	// Max code length should not break immediately before a line comment.
	// The break is within the comment.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (line[i] == '}')                     // comment in column 45\n"
		"    {\n"
		"        foobar();\n"
		"    }\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (line[i] ==\n"
		"            '}')                     // comment in column 45\n"
		"    {\n"
		"        foobar();\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, LineComment5)
{
	// Max code length should break twice on the first try.
	char textIn[] =
		"\nvoid Foo(){ return IsBuiltinOpen(filename); } // synonym of IsBuiltinOpen()";
	char text[] =
		"\nvoid Foo() {\n"
		"    return IsBuiltinOpen(\n"
		"               filename);    // synonym of IsBuiltinOpen()\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Comment1)
{
	// Max code length should not break a comment line.
	char text[] =
		"\n/*  if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3\n"
		" *  thisVariable4 == thatVariable4 || thisVariable5 == thatVariable5 || thisVariable6 == thatVariable6)\n"
		" */\n"
		"void foo()\n"
		"{\n"
		"    /*  if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3\n"
		"     *  thisVariable4 == thatVariable4 || thisVariable5 == thatVariable5 || thisVariable6 == thatVariable6)\n"
		"     */\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Comment2)
{
	// Max code length should not break inside a line comment.
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (x == 1) /* this is a long, long, long, long, long, long, long, comment */\n"
		"        bar();\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Comment3)
{
	// Max code length should not break immediately before a comment.
	// The break is in the whitespace before the comment.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (line[i] == '}')                                    /* comment in column 60 */\n"
		"    {\n"
		"        foobar();\n"
		"    }\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (line[i] ==\n"
		"            '}')                                    /* comment in column 60 */\n"
		"    {\n"
		"        foobar();\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Comment4)
{
	// Max code length should not break immediately before a comment.
	// The break is within the comment.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (line[i] == '}')                     /* comment in column 45 */\n"
		"    {\n"
		"        foobar();\n"
		"    }\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (line[i] ==\n"
		"            '}')                     /* comment in column 45 */\n"
		"    {\n"
		"        foobar();\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Comment5)
{
	// Max code length should break twice on the first try.
	char textIn[] =
		"\nvoid Foo(){ return IsBuiltinOpen(filename); } /* synonym of IsBuiltinOpen() */";
	char text[] =
		"\nvoid Foo() {\n"
		"    return IsBuiltinOpen(\n"
		"               filename);    /* synonym of IsBuiltinOpen() */\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, ExtraSpaces1)
{
	// Max code length should not add an extra line when breaking on multiple spaces.
	char textIn[] =
		"\nbool foo ()\n"
		"{\n"
		"    XRCCTRL(*this, \"spnAuiBorder\",                         SetValue(ReadInt(GetMetric)));\n"
		"}";
	char text[] =
		"\nbool foo ()\n"
		"{\n"
		"    XRCCTRL(*this, \"spnAuiBorder\",\n"
		"            SetValue(ReadInt(GetMetric)));\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, ExtraSpaces2)
{
	// Max code length should not add an extra line when breaking on multiple spaces.
	char textIn[] =
		"\nbool foo ()\n"
		"{\n"
		"    XRCCTRL(*this, \"spnAuiBorder\",          SetValue(ReadInt(GetMetric)));\n"
		"}";
	char text[] =
		"\nbool foo ()\n"
		"{\n"
		"    XRCCTRL(*this, \"spnAuiBorder\",\n"
		"            SetValue(ReadInt(GetMetric)));\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Template)
{
	// Max code length should not break within a template definition.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    RegisterEventSink ( new cbEventFunctor < AutoVersioning, CodeBlocksEvent > ( OnProjectActivated ) );\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    RegisterEventSink ( new cbEventFunctor\n"
		"                        < AutoVersioning, CodeBlocksEvent >\n"
		"                        ( OnProjectActivated ) );\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, PreprocessorDefine)
{
	// Max code length should not break a preprocessor define.
	char text[] =
		"\n#define MACRO1   if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3 \\\n"
		"                       thisVariable4 == thatVariable4 || thisVariable5 == thatVariable5 || thisVariable6 == thatVariable6\n"
		"";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, SQL)
{
	// Max code length should not break a SQL statement.
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    EXEC SQL INSERT\n"
		"             INTO   branch (branch_id, branch_name, branch_addr, branch_city)\n"
		"             VALUES (:bid, :bname, :baddr:baddr_ind1, :baddr:baddr_ind2);\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Assembler)
{
	// Max code length should not break an assembler statement.
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    asm (\"sar1 %1\n"
		"         movl %1, %0\": \"=r\"(res[i]) :\"r\" (res[i]), \"memory\");\n"
		"\n"
		"    __asm__ (\"sarl %0\"\n"
		"             : \"=r\" (res[i]) :\"r\" (num[i]), \"r\" (num[i]): \"memory\");\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, MicrosoftAssembler)
{
	// Max code length should not break an assembler statement.
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    _asm mov eax, fs:[0x8] __asm push edp  __asm push edq  __asm push edx\n"
		"\n"
		"    _asm {\n"
		"        mov eax, fs:[0x8] mov dx, 0xD007 out dx, al out dx, al out dx, al\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Array)
{
	// Max code length should not break an array.
	char text[] =
		"\nstatic BarButton bbs[] =\n"
		"{\n"
		"    { STD_FILEOPEN,  IDM_FILE_OPEN,  IDM_FILE_OPEN,  IDM_FILE_OPEN,  \"Open File\" },\n"
		"    { STD_FILESAVE,  IDM_FILE_SAVE,  IDM_FILE_SAVE,  IDM_FILE_SAVE,  \"Save File\" },\n"
		"    { STD_UNDO,      IDM_EDIT_UNDO,  IDM_EDIT_UNDO,  IDM_EDIT_UNDO,  \"Undo\"      },\n"
		"    { STD_REDOW,     IDM_EDIT_REDO,  IDM_EDIT_REDO,  IDM_EDIT_REDO,  \"Redo\"      },\n"
		"};";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, ArrayInStatement)
{
	// Max code length should not break an in-statement array.
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    static const long StyleStates[] = { wxRichText::wxRICHTEXT_STYLE_ALL,\n"
		"                                        wxRichText::wxRICHTEXT_STYLE_CHARACTER,\n"
		"                                        wxRichText::wxRICHTEXT_STYLE_LIST,\n"
		"                                        wxRichText::wxRICHTEXT_STYLE_PARAGRAPH\n"
		"                                      };\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, ParenBreak1)
{
	// Test max code length with only a paren break.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    inStatementIndentStackSizeStack->push_back(inStatementIndentStack->size());\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    inStatementIndentStackSizeStack->push_back(\n"
		"        inStatementIndentStack->size());\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, ParenBreak2)
{
	// Test max code length with a paren break after an operator.
	// Should break before the paren.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    int variable1 = variable2 + variable3 + (var4 * var5);\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    int variable1 = variable2 + variable3 +\n"
		"                    (var4 * var5);\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, ParenBreak3)
{
	// Test max code length with pad parens.
	// Should break before the paren.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    currentChar = (*newOperator) [newOperator->length() - 1];\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    currentChar =\n"
		"        ( *newOperator ) [newOperator->length() - 1];\n"
		"}";
	char options[] = "max-code-length=50, pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, ParenBreak4)
{
	// Test max code length with pad parens.
	// Should break before the 'const'.
	char textIn[] =
		"\nbool cbSmartIndentPlugin::AutoIndentEnabled()const\n"
		"{}";
	char text[] =
		"\nbool cbSmartIndentPlugin::AutoIndentEnabled()\n"
		"const\n"
		"{}";
	char options[] = "max-code-length=50, pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, ParenBreak5)
{
	// Test max code length with pad parens.
	// Should break before the minus (it is not a ->).
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"  if (current < 0 || current >= static_cast<int>(mx_Vector.size() - HelpCommon::getNumReadFromIni()))\n"
		"      bar();\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if ( current < 0\n"
		"            || current >= static_cast<int> ( mx_Vector.size()\n"
		"                    - HelpCommon::getNumReadFromIni() ) )\n"
		"        bar();\n"
		"}";
	char options[] = "max-code-length=50, pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BlockParenBreak1)
{
	// Max code length should not break within a block paren.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    languages[i].single_line_comment = languages[i+1].single_line_comment;\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    languages[i].single_line_comment =\n"
		"        languages[i+1].single_line_comment;\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BlockParenBreak2)
{
	// Max code length should not break within a padded block paren.
	char textIn[] =
		"\nconst char* TiXmlBase::errorString[ TIXML_ERROR_STRING_COUNT ] =\n"
		"{\n"
		"};";
	char text[] =
		"\nconst char*\n"
		"TiXmlBase::errorString[ TIXML_ERROR_STRING_COUNT ]\n"
		"=\n"
		"{\n"
		"};";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakBlocks1)
{
	// Test max code length with break-blocks.
	// Should have empty lines before and after the 'if' statement.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar1 = fooFunction1(longVariable1, longVariable2, longVariable3);\n"
		"    if (longVariable1x || longVariable2x || longVariable3x)\n"
		"        bar();\n"
		"    bar2 = fooFunction2(longVariable1, longVariable2, longVariable3);\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar1 = fooFunction1(longVariable1, longVariable2,\n"
		"                        longVariable3);\n"
		"\n"
		"    if (longVariable1x || longVariable2x\n"
		"            || longVariable3x)\n"
		"        bar();\n"
		"\n"
		"    bar2 = fooFunction2(longVariable1, longVariable2,\n"
		"                        longVariable3);\n"
		"}";
	char options[] = "max-code-length=50, break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakBlocks2)
{
	// Test max code length with break-blocks with 'else' statement.
	// Should have empty lines before and after the 'if-else' statement.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar1 = fooFunction1(longVariable1, longVariable2, longVariable3);\n"
		"    if (longVariable1x || longVariable2x || longVariable3x)\n"
		"        bar();\n"
		"    else\n"
		"        bar2();\n"
		"    bar2 = fooFunction2(longVariable1, longVariable2, longVariable3);\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar1 = fooFunction1(longVariable1, longVariable2,\n"
		"                        longVariable3);\n"
		"\n"
		"    if (longVariable1x || longVariable2x\n"
		"            || longVariable3x)\n"
		"        bar();\n"
		"    else\n"
		"        bar2();\n"
		"\n"
		"    bar2 = fooFunction2(longVariable1, longVariable2,\n"
		"                        longVariable3);\n"
		"}";
	char options[] = "max-code-length=50, break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakBlocks3)
{
	// Test max code length with break-blocks at the end of a line.
	// The empty line should be after the statement.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        if (isBar())\n"
		"            GetSnippetsWindow()->GetSnippetsTreeCtrlTwo()->SaveItemsToFile(GetConfig()->SettingsSnippetsXmlPath);\n"
		"    // empty line should preceed this\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        if (isBar())\n"
		"            GetSnippetsWindow()->GetSnippetsTreeCtrlTwo()->SaveItemsToFile(\n"
		"                GetConfig()->SettingsSnippetsXmlPath);\n"
		"\n"
		"    // empty line should preceed this\n"
		"}";
	char options[] = "max-code-length=100, break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakBlocksAll1)
{
	// Test max code length with break-blocks=all.
	// Should have empty lines before and after the 'if' and 'else' statements.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar1 = fooFunction1(longVariable1, longVariable2, longVariable3);\n"
		"    if (longVariable1x || longVariable2x || longVariable3x)\n"
		"        bar1();\n"
		"    else\n"
		"        bar2();\n"
		"    bar2 = fooFunction2(longVariable1, longVariable2, longVariable3);\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar1 = fooFunction1(longVariable1, longVariable2,\n"
		"                        longVariable3);\n"
		"\n"
		"    if (longVariable1x || longVariable2x\n"
		"            || longVariable3x)\n"
		"        bar1();\n"
		"\n"
		"    else\n"
		"        bar2();\n"
		"\n"
		"    bar2 = fooFunction2(longVariable1, longVariable2,\n"
		"                        longVariable3);\n"
		"}";
	char options[] = "max-code-length=50, break-blocks=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakBlocksAll2)
{
	// Test max code length with break-blocks=all at the end of a line.
	// The empty lines should be after the statements.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        if (isBar())\n"
		"            GetSnippetsWindow()->GetSnippetsTreeCtrlTwo()->SaveItemsToFile(GetConfig()->SettingsSnippetsXmlPath);\n"
		"        else\n"
		"            GetSnippetsWindow()->GetSnippetsTreeCtrlTwo()->SaveItemsToFile(GetConfig()->SettingsSnippetsXmlPath);\n"
		"    // empty line should preceed this\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        if (isBar())\n"
		"            GetSnippetsWindow()->GetSnippetsTreeCtrlTwo()->SaveItemsToFile(\n"
		"                GetConfig()->SettingsSnippetsXmlPath);\n"
		"\n"
		"        else\n"
		"            GetSnippetsWindow()->GetSnippetsTreeCtrlTwo()->SaveItemsToFile(\n"
		"                GetConfig()->SettingsSnippetsXmlPath);\n"
		"\n"
		"    // empty line should preceed this\n"
		"}";
	char options[] = "max-code-length=100, break-blocks=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakMinimum)
{
	// Test max code length with a break below the minimum (should not break).
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (x == \"xxxxxxxxxx xxxxxxxxx x xxx  xxxxxxxxxxxxxxxx xxxxxxxxxxx\")\n"
		"        bar();\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakMaximum1)
{
	// Test max code length with a break equal the maximum (should not break).
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar (variable, variable, variable, variable, var);\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakMaximum2)
{
	// Should break three times on the first try.
	char textIn[] =
		"\npublic void NewException()\n"
		"{\n"
		"    FindExpr(program2, \"oundException\", \"NotF\", ExpressionContext"			// this line is continued below
		".TypeDerivingFrom(AssemblyParserService.DefaultProjectContentRegistry.Mscorlib.SystemTypes.Exception, true));\n"
		"}";
	char text[] =
		"\npublic void NewException()\n"
		"{\n"
		"    FindExpr(program2, \"oundException\", \"NotF\",\n"
		"             ExpressionContext.TypeDerivingFrom(\n"
		"                 AssemblyParserService.DefaultProjectContentRegistry.Mscorlib.SystemTypes.Exception,\n"
		"                 true));\n"
		"}";
	char options[] = "max-code-length=80";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakMaximum3)
{
	// Should not break on a conditional if the remaining line is too long.
	char textIn[] =
		"\npublic void Foo()\n"
		"{\n"
		"    if ( left.Left.NodeType == ExpressionType.Constant && left.Right.NodeType == ExpressionType.MemberAccess\n"
		"            && right.Left.NodeType == ExpressionType.MemberAccess )\n"
		"    {}\n"
		"}";
	char text[] =
		"\npublic void Foo()\n"
		"{\n"
		"    if ( left.Left.NodeType == ExpressionType.Constant\n"
		"            && left.Right.NodeType ==\n"
		"            ExpressionType.MemberAccess\n"
		"            && right.Left.NodeType ==\n"
		"            ExpressionType.MemberAccess )\n"
		"    {}\n"
		"}";
	char options[] = "max-code-length=50, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakAfterLineBreak)
{
	// First IF line shouldbreak twice on the first try.
	// The second break is done after the following line is read into currentLine.
	char textIn[] =
		"\npublic void NewException()\n"
		"{\n"
		"    FindExpr(program2, \"oundException\", \"NotF\", ExpressionContext"			// this line is continued below
		".TypeDerivingFrom(AssemblyParserService.DefaultProjectContentRegistry.Mscorlib.SystemTypes.Exception, true));\n"
		"}";
	char text[] =
		"\npublic void NewException()\n"
		"{\n"
		"    FindExpr(program2, \"oundException\", \"NotF\",\n"
		"             ExpressionContext.TypeDerivingFrom(\n"
		"                 AssemblyParserService.DefaultProjectContentRegistry.Mscorlib.SystemTypes.Exception,\n"
		"                 true));\n"
		"}";
	char options[] = "max-code-length=80";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakMaximumWithPad)
{
	// Test max code length with a break below the max but above the max with padding.
	// The statement should break when the padding is accounted for.
	// To test for failure the long line length must be greater than 50 but less than extraCharsAllowed.
	// The current value is 52 (50 + 2).
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    m_DrawArea->Connect.threexx(wxEVT_LEFT_DOWN,0,this);\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    m_DrawArea->Connect.threexx ( wxEVT_LEFT_DOWN, 0,\n"
		"                                  this );\n"
		"}";
	char options[] = "max-code-length=50, pad-paren, pad-oper";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, KeepOneLineStatements1)
{
	// Test max code length with keep one-line statements.
	// Should break at the semicolons.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    Push(value1, value a1);Push(value2, value a2);Push(value3, value a3);Push(value4, value a4);\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    Push(value1, value a1); Push(value2, value a2);\n"
		"    Push(value3, value a3); Push(value4, value a4);\n"
		"}";
	char options[] = "max-code-length=50, keep-one-line-statements";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, KeepOneLineStatements2)
{
	// Test max code length with keep one-line statements and break blocks.
	// Should break at IF statement and break the IF block.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    SendEvent(0, m_editItem, &te); if (!te.IsAllowed()) return;\n"
		"    bar();\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    SendEvent(0, m_editItem, &te);\n"
		"\n"
		"    if (!te.IsAllowed()) return;\n"
		"\n"
		"    bar();\n"
		"}";
	char options[] = "max-code-length=50, keep-one-line-statements, break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, KeepOneLineStatements3)
{
	// Test max code length with keep one-line statements and break blocks.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    switch ( i )\n"
		"    {\n"
		"    case 1: box = 2; break;\n"
		"    case 2: while ( *constant++ != '(' ); sep = *c++; break;\n"
		"    case 3: box = 3; break;\n"
		"    }\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    switch ( i )\n"
		"    {\n"
		"    case 1: box = 2; break;\n"
		"\n"
		"    case 2: while ( *constant++ != '(' ); sep = *c++;\n"
		"        break;\n"
		"\n"
		"    case 3: box = 3; break;\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=50, keep-one-line-statements, break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, KeepOneLineStatements4)
{
	// Test max code length with keep one-line statements and break blocks.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    switch (i) {\n"
		"    case 4: box=2; break;\n"
		"    case 5: while (*c++!='('); itemsep=*c++; break;\n"
		"    case 6: while (*c++!='('); linesize=0;\n"
		"    while (isdigit(*c)) linesize=linesize*10; break;\n"
		"    default: break;\n"
		"    }\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    switch (i) {\n"
		"    case 4: box=2; break;\n"
		"\n"
		"    case 5: while (*c++!='('); itemsep=*c++; break;\n"
		"\n"
		"    case 6: while (*c++!='('); linesize=0;\n"
		"\n"
		"        while (isdigit(*c)) linesize=linesize*10; break;\n"
		"\n"
		"    default: break;\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=50, keep-one-line-statements, break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, KeepOneLineStatements5)
{
	// Test max code length with a switch keep one-line statements.
	// Should not break within a "case" statement.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch (isFoo)\n"
		"    {\n"
		"    case 0: case 1: case 2:         // in error recovery\n"
		"        println (\"shift from state\");\n"
		"    }\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch (isFoo)\n"
		"    {\n"
		"    case 0: case 1:\n"
		"    case 2:         // in error recovery\n"
		"        println (\"shift from state\");\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=50, keep-one-line-statements";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, KeepOneLineBlocks1)
{
	// Test max code length with keep one-line blocks.
	// Should NOT break the block.
	char text[] =
		"\nvoid Push(HSQUIRRELVM v, SQAnythingPtr value) { sq_pushuserpointer (v, value); }";
	char options[] = "max-code-length=50, keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, KeepOneLineBlocks2)
{
	// Test max code length with keep one-line blocks and break blocks.
	// Should NOT break the block.
	// Breaking at the "continue" statement requires special handling.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch(CUR_CHAR) {\n"
		"        case _SC('*'): { if(CUR_CHAR == _SC('/')) { done = true; NEXT(); }}; continue;\n"
		"        case _SC('&'): _currentline++; NEXT(); continue;\n"
		"        case SQUIRREL_EOB: Error(_SC(\"missing \"*/\" in comment\"));\n"
		"        default: NEXT();\n"
		"    }\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch(CUR_CHAR) {\n"
		"    case _SC('*'): { if(CUR_CHAR == _SC('/')) { done = true; NEXT(); }};\n"
		"\n"
		"        continue;\n"
		"    case _SC('&'): _currentline++; NEXT(); continue;\n"
		"\n"
		"    case SQUIRREL_EOB: Error(\n"
		"            _SC(\"missing \"*/\" in comment\"));\n"
		"\n"
		"    default: NEXT();\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=50, keep-one-line-blocks, break-blocks, keep-one-line-statements";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, KeepOneLineBlocks3)
{
	// Test max code length with keep one-line blocks.
	// Should break before the empty block.
	char textIn[] =
		"\nvoid TextCtrlTask::OnChar(wxKeyEvent& /*event*/){}";
	char text[] =
		"\nvoid TextCtrlTask::OnChar (\n"
		"    wxKeyEvent& /*event*/ ) {}";
	char options[] = "max-code-length=50, keep-one-line-blocks, pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, KeepOneLineBlocksLogical)
{
	// Test max code length with keep one-line blocks and logical operators.
	// Should NOT break the block.
	char text[] =
		"\nvoid foo() { if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2) ++mit; }";
	char options[] = "max-code-length=50, keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, KeepOneLineBlocksSans)
{
	// Test max code length without keep one-line blocks.
	// Should break the block.
	char textIn[] =
		"\nvoid Push(HSQUIRRELVM v, SQAnythingPtr value) { sq_pushuserpointer (v, value); }";
	char text[] =
		"\nvoid Push(HSQUIRRELVM v, SQAnythingPtr value) {\n"
		"    sq_pushuserpointer (v, value);\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AlignPointerToType1)
{
	// Test max code length with align-pointer=type.
	// Aborted when formatPointerOrReference() method contained a call to appendCurrentChar().
	char textIn[] =
		"\nvoid searchrangexxxxxxxxxxx(SQRex* exp, const SQChar** text_begin)\n"
		"{}";
	char text[] =
		"\nvoid searchrangexxxxxxxxxxx(SQRex* exp,\n"
		"                            const SQChar** text_begin)\n"
		"{}";
	char options[] = "max-code-length=50, align-pointer=type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AlignPointerToType2)
{
	// Test max code length with align-pointer=type.
	// Preceeding a dereference should break before the dereference.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    wxArrayString& self = *SqPlus::GetInstance<wxArrayString,false>(v, 1);\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    wxArrayString& self =\n"
		"        *SqPlus::GetInstance<wxArrayString,false>(v, 1);\n"
		"}";
	char options[] = "max-code-length=50, align-pointer=type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AlignPointerToType3)
{
	// Test max code length with align-pointer=type for a reference.
	// Preceeding a dereference should break before the dereference.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    wxArrayString* self = &SqPlus::GetInstance<wxArrayString,false>(v, 1);\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    wxArrayString* self =\n"
		"        &SqPlus::GetInstance<wxArrayString,false>(v, 1);\n"
		"}";
	char options[] = "max-code-length=50, align-pointer=type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AddBrackets2)
{
	// Test max code length with add-brackets.
	// Should break line when add-brackets is used.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(!ret)\n"
		"        cbMessageBox(_(\"Couldn't save workspace \") + _(\"(Maybe the file is write-protected?\"));\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(!ret) {\n"
		"        cbMessageBox(_(\"Couldn't save workspace \") +\n"
		"                     _(\"(Maybe the file is write-protected?\"));\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=50, add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AddBrackets3)
{
	// Test max code length with add-brackets.
	// Should NOT break on the space padding following an added bracket.
	// This will add an empty line after the conditional.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (first_multi_line_comment_xx < line.Length())\n"
		"        AnalyseLine(language);\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (first_multi_line_comment_xx < line.Length()) {\n"
		"        AnalyseLine(language);\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=50, add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AddBrackets4)
{
	// Test max code length with add-brackets.
	// Should NOT break on the the comma following the number 1.
	// This will leave a long line that will break on a subsequent run.
	// It should adjust the break point to the highest space split point.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (target == ttConsoleOnly)\n"
		"        script = script.Mid(1, script.length() - 2); // skip outmost single-quotes\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (target == ttConsoleOnly) {\n"
		"        script = script.Mid(1, script.length() -\n"
		"                            2);    // skip outmost single-quotes\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=50, add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AddBrackets5)
{
	// Test max code length with add-brackets.
	// Should break the brackets.
	// See the following test for this condition with keep-one-line-blocks.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if      (event.GetId() == idCBSortByAlpabet) bst = bstAlphabet;\n"
		"    else if (event.GetId() == idCBSortByKind)    bst = bstKind;\n"
		"    else                                         bst = bstNone;\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if      (event.GetId() == idCBSortByAlpabet) {\n"
		"        bst = bstAlphabet;\n"
		"    }\n"
		"    else if (event.GetId() == idCBSortByKind) {\n"
		"        bst = bstKind;\n"
		"    }\n"
		"    else {\n"
		"        bst = bstNone;\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=50, add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AddBrackets6)
{
	// Test max code length with add-brackets and keep-one-line-blocks.
	// Should break the brackets.
	// See the previous test for this condition without keep-one-line-blocks.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if      (event.GetId() == idCBSortByAlpabet) bst = bstAlphabet;\n"
		"    else if (event.GetId() == idCBSortByKind)    bst = bstKind;\n"
		"    else                                         bst = bstNone;\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if      (event.GetId() == idCBSortByAlpabet) { bst = bstAlphabet; }\n"
		"    else if (event.GetId() == idCBSortByKind) { bst = bstKind; }\n"
		"    else { bst = bstNone; }\n"
		"}";
	char options[] = "max-code-length=50, add-brackets, keep-one-line-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AddOneLineBrackets)
{
	// Test max code length with add-one-line-brackets.
	// Should NOT break line when add-one-line-brackets is used.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(!ret)\n"
		"        cbMessageBox(_(\"Couldn't save workspace \") + _(\"(Maybe the file is write-protected?\"));\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(!ret)\n"
		"    { cbMessageBox(_(\"Couldn't save workspace \") + _(\"(Maybe the file is write-protected?\")); }\n"
		"}";
	char options[] = "max-code-length=50, add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, PadParen1)
{
	// Test max code length with pad-paren.
	// Should not break a "wxT(" when a space is padded.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!ret)\n"
		"        MessageBox(wxT(\"Couldn't save\") + wxT(\"Write-protected?\"));\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( !ret )\n"
		"        MessageBox ( wxT ( \"Couldn't save\" ) +\n"
		"                     wxT ( \"Write-protected?\" ) );\n"
		"}";
	char options[] = "max-code-length=50, pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, PadParen2)
{
	// Test max code length with pad-paren.
	// Should not break a paren followed by a quote when the paren is padded.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( !ret )\n"
		"        MessageBox( ( \"save-file\" ) + ( \"Write-protected?\" ) );\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( !ret )\n"
		"        MessageBox ( ( \"save-file\" )\n"
		"                     + ( \"Write-protected?\" ) );\n"
		"}";
	char options[] = "max-code-length=50, pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, PadParen3)
{
	// Test max code length with pad-paren.
	// Should not break on a closing paren when a space is added.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!ret)\n"
		"        MessageBox((\"Couldn't save write protectedxxxx\") + (\"Write-protected?\"));\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( !ret )\n"
		"        MessageBox ( ( \"Couldn't save write protectedxxxx\" )\n"
		"                     + ( \"Write-protected?\" ) );\n"
		"}";
	char options[] = "max-code-length=50, pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, PadParen4)
{
	// Test max code length with pad-paren.
	// Should not break on a closing paren when paren is padded.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( !ret )\n"
		"        MessageBox ( ( \"Couldn't save write protectedxxxx\" ) + ( \"Write-protected?\" ) );\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( !ret )\n"
		"        MessageBox ( ( \"Couldn't save write protectedxxxx\" )\n"
		"                     + ( \"Write-protected?\" ) );\n"
		"}";
	char options[] = "max-code-length=50, pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, PadParen5)
{
	// Test max code length with pad-paren.
	// Should not break before the closing paren when the paren is padded.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    cbxDebuggerPlugin* debugger = (cbDebuggerPlugin*)arr[i];\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    cbxDebuggerPlugin* debugger =\n"
		"        ( cbDebuggerPlugin* ) arr[i];\n"
		"}";
	char options[] = "max-code-length=50, pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, PadParen6)
{
	// Test max code length with pad-paren.
	// Should should break before "property" when the paren is padded.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    ctrl->SetValue( *((const wxDateTime*)property->DoGetValue().GetVoidPtr()) );\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    ctrl->SetValue ( * ( ( const wxDateTime* )\n"
		"                         property->DoGetValue().GetVoidPtr() ) );\n"
		"}";
	char options[] = "max-code-length=50, pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, PadParen7)
{
	// Test max code length with pad-paren.
	// Should break before the _T when the paren is padded.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    asterisk (_T(\"font-family: Arial, Helvetica, Bitstream Vera Sans, sansFont;\"));\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    asterisk (\n"
		"        _T ( \"font-family: Arial, Helvetica, Bitstream Vera Sans, sansFont;\" ) );\n"
		"}";
	char options[] = "max-code-length=80, pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AttachBracket2)
{
	// Test max code length when a bracket is attached inside a comment.
	// Should break when the bracket is attached.
	char textIn[] =
		"\nbool QueryColour ( char* propgrid, char* primary ) // comment\n"
		"{\n"
		"}";
	char text[] =
		"\nbool QueryColour ( char* propgrid,\n"
		"                   char* primary ) { // comment\n"
		"}";
	char options[] = "max-code-length=50, style=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AttachBracket3)
{
	// Test max code length when a bracket is attached inside a comment.
	// Special problem where bracket wasn't attached on the first try
	// due to the setting of "formattedLineCommentNum".
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(     id == XRCID(\"lstLibs\")) // Link libraries\n"
		"        { myid =  wxXmlResource::GetXRCID(str_libs[myidx]); }\n"
		"    else if(id == XRCID(\"lstIncludeDirs\") || id == XRCID(\"lstLibDirs\") || id == XRCID(\"lstResDirs\")) // Directories\n"
		"       { myid =  wxXmlResource::GetXRCID(str_dirs[myidx]); }\n"
		"}";
	char text[] =
		"\nvoid foo() {\n"
		"    if(     id == XRCID(\"lstLibs\")) { // Link libraries\n"
		"        myid =  wxXmlResource::GetXRCID(str_libs[myidx]);\n"
		"    } else if(id == XRCID(\"lstIncludeDirs\") || id == XRCID(\"lstLibDirs\")\n"
		"              || id == XRCID(\"lstResDirs\")) { // Directories\n"
		"        myid =  wxXmlResource::GetXRCID(str_dirs[myidx]);\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=100, style=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AttachBracket4)
{
	// Test max code length when a bracket is changed from run-in to attached.
	char textIn[] =
		"\nvoid ClassBrowser::SetParser ( Parser* parser )\n"
		"{   if ( parser != pParser\n"
		"            || ( parser && pParser\n"
		"                 && parser->ClassBrowserOptions().displayFilter != pParser->ClassBrowserOptions().displayFilter ) )\n"
		"    {   UnlinkParser();\n"
		"\n"
		"        if ( parser )\n"
		"        {   parser->m_pClassBrowser = this;\n"
		"            pParser = parser;\n"
		"            UpdateView();\n"
		"        }\n"
		"    }\n"
		"}";
	char text[] =
		"\nvoid ClassBrowser::SetParser ( Parser* parser ) {\n"
		"    if ( parser != pParser\n"
		"            || ( parser && pParser\n"
		"                 && parser->ClassBrowserOptions().displayFilter !=\n"
		"                 pParser->ClassBrowserOptions().displayFilter ) ) {\n"
		"        UnlinkParser();\n"
		"\n"
		"        if ( parser ) {\n"
		"            parser->m_pClassBrowser = this;\n"
		"            pParser = parser;\n"
		"            UpdateView();\n"
		"        }\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=50, style=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AttachBracket5)
{
	// Splitting a line with a following comment and the line follows a closing bracket.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"}\n"
		"\n"
		"void B_driver::CorrectCygwinPath(wxString& path){/* dummy */}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"}\n"
		"\n"
		"void B_driver::CorrectCygwinPath(wxString& path) {\n"
		"    /* dummy */\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AttachBracket6)
{
	// Test max code length when a bracket is attached.
	// An array exceeds max-code-length when the bracket is attached.
	char textIn[] =
		"\nTiXmlBase::Entity TiXmlBase::entity[ NM_ENTITY ] =\n"
		"{\n"
		"    { \"&apos;\", 6, '\\'' }\n"
		"};";
	char text[] =
		"\nTiXmlBase::Entity TiXmlBase::entity[ NM_ENTITY ]\n"
		"= {\n"
		"    { \"&apos;\", 6, '\\'' }\n"
		"};";
	char options[] = "max-code-length=50, style=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, HorstmannBracket1)
{
	// Test max code length with Horstmann brackets.
	// Should split the line 3 times on the first try.
	char textIn[] =
		"\nvoid Foo()\n"
		"{   if (isFoo)\n"
		"    {   Manager::Get()->GetLogManager()->DebugLog(F(_T(\"wxSmith: Error loading wxs file (Col: %d, Row:%d): \") + cbC2U(Doc.ErrorDesc()),Doc.ErrorCol(),Doc.ErrorRow()));\n"
		"    }\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{   if (isFoo)\n"
		"    {   Manager::Get()->GetLogManager()->DebugLog(F(\n"
		"                    _T(\"wxSmith: Error loading wxs file (Col: %d, Row:%d): \")\n"
		"                    + cbC2U(Doc.ErrorDesc()),Doc.ErrorCol(),\n"
		"                    Doc.ErrorRow()));\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=50, style=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, HorstmannBracket2)
{
	// Test max code length with Horstmann brackets.
	// Should not split the line because of trailing spaces
	// when converting to attached brackets.
	char textIn[] =
		"\nDeclaration& operator= (const Declaration& copy)\n"
		"{   Clear();\n"
		"}";
	char text[] =
		"\nDeclaration& operator= (const Declaration& copy) {\n"
		"    Clear();\n"
		"}";
	char options[] = "max-code-length=50, style=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AfterClosingBracket)
{
	// Test max code length with C# brackets.
	// Should split the line after the closing bracket.
	char textIn[] =
		"\npublic void UploadUsageDataAsync () {\n"
		"    base.InvokeAsync(this.onBeginUploadUsageDataDelegate, new object[] {\n"
		"                ApplicationKey,\n"
		"                UsageData}, this.uploadUsageDataDelegate, this.uploadUsageDataCompletedDelegate, userState);\n"
		"}";
	char text[] =
		"\npublic void UploadUsageDataAsync () {\n"
		"    base.InvokeAsync(this.onBeginUploadUsageDataDelegate, new object[] {\n"
		"        ApplicationKey,\n"
		"        UsageData\n"
		"    }, this.uploadUsageDataDelegate, this.uploadUsageDataCompletedDelegate,\n"
		"    userState);\n"
		"}";
	char options[] = "max-code-length=80, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AlignToType1)
{
	// Should break on a pointer when line exceeds the limit.
	char textIn[] =
		"\nvoid Foo() {\n"
		"    const char* text1;   //< Only valid for changes to text.\n"
		"    const char * text2;  //< Only valid for changes to text.\n"
		"    const char *text3;   //< Only valid for changes to text.\n"
		"    const char &text4;   /**< Only valid for changes to text. */\n"
		"    const char ^text5;   /**< Only valid for changes to text. */\n"
		"}";
	char text[] =
		"\nvoid Foo() {\n"
		"    const char*\n"
		"    text1;   //< Only valid for changes to text.\n"
		"    const char*\n"
		"    text2;   //< Only valid for changes to text.\n"
		"    const char*\n"
		"    text3;   //< Only valid for changes to text.\n"
		"    const char&\n"
		"    text4;   /**< Only valid for changes to text. */\n"
		"    const char^\n"
		"    text5;   /**< Only valid for changes to text. */\n"
		"}";
	char options[] = "max-code-length=50, align-pointer=type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AlignToType2)
{
	// Should not break before a pointer when the pointer attached to type.
	char textIn[] =
		"\n"
		"void InsertBrickTask::OnChar1(wxKeyEvent * /*event*/) {}\n"
		"void InsertBrickTask::OnChar2(wxKeyEvent & /*event*/) {}\n"
		"";
	char text[] =
		"\n"
		"void InsertBrickTask::OnChar1(\n"
		"    wxKeyEvent* /*event*/) {}\n"
		"void InsertBrickTask::OnChar2(\n"
		"    wxKeyEvent& /*event*/) {}\n"
		"";
	char options[] = "max-code-length=50, align-pointer=type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AlignToMiddle1)
{
	// Should break on a pointer when line exceeds the limit.
	char textIn[] =
		"\nvoid Foo() {\n"
		"    const char* text1;   //< Only valid for changes to text.\n"
		"    const char * text2;  //< Only valid for changes to text.\n"
		"    const char *text3;   //< Only valid for changes to text.\n"
		"    const char &text4;   /**< Only valid for changes to text. */\n"
		"    const char ^text5;   /**< Only valid for changes to text. */\n"
		"}";
	char text[] =
		"\nvoid Foo() {\n"
		"    const char *\n"
		"    text1;  //< Only valid for changes to text.\n"
		"    const char *\n"
		"    text2;  //< Only valid for changes to text.\n"
		"    const char *\n"
		"    text3;  //< Only valid for changes to text.\n"
		"    const char &\n"
		"    text4;  /**< Only valid for changes to text. */\n"
		"    const char ^\n"
		"    text5;  /**< Only valid for changes to text. */\n"
		"}";
	char options[] = "max-code-length=50, align-pointer=middle";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AlignToMiddle2)
{
	// Should break before or after a middle pointer.
	// Doesn't work exactly right with pointers that are initially attached to type.
	// But this should be an exception.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    const char*                                        text;   //< Only valid for changes to text.\n"
		"    const char*                                             text;   //< Only valid for changes to text.\n"
		"    const char                                        &text;   //< Only valid for changes to text.\n"
		"    const char                                             &text;   //< Only valid for changes to text.\n"
		"    const char                    ^                    text;   //< Only valid for changes to text.\n"
		"    const char                    ^                         text;   //< Only valid for changes to text.\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    const char                    *\n"
		"    text;   //< Only valid for changes to text.\n"
		"    const char                       *\n"
		"    text;   //< Only valid for changes to text.\n"
		"    const char                    &\n"
		"    text;   //< Only valid for changes to text.\n"
		"    const char\n"
		"    & text;  //< Only valid for changes to text.\n"
		"    const char                    ^\n"
		"    text;   //< Only valid for changes to text.\n"
		"    const char                       ^\n"
		"    text;   //< Only valid for changes to text.\n"
		"}";
	char options[] = "max-code-length=50, align-pointer=middle";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AlignToMiddle3)
{
	// Should break before or after a middle pointer.
	// Doesn't work exactly right with pointers that are initially attached to type.
	// But this should be an exception.
	char textIn[] =
		"\ntypedef void(*fnFree)(ShellCtrlBase*); //typedef defining function to free a control widget\n";
	char text[] =
		"\ntypedef void(*fnFree)(ShellCtrlBase\n"
		"                      *); //typedef defining function to free a control widget\n";
	char options[] = "max-code-length=50, align-pointer=middle";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AlignToMiddle4)
{
	// The poiner at the end is formatted as a cast.
	// The line should break without causing an exception in debug.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    const unsigned char *uxbuf = (const unsigned char *)buf;\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    const unsigned char * uxbuf = (const unsigned char\n"
		"                                   *)buf;\n"
		"}";
	char options[] = "max-code-length=50, align-pointer=middle";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AlignToName1)
{
	// Should break on a pointer when line exceeds the limit.
	char textIn[] =
		"\nvoid Foo() {\n"
		"    const char* text1;   //< Only valid for changes to text.\n"
		"    const char * text2;  //< Only valid for changes to text.\n"
		"    const char *text3;   //< Only valid for changes to text.\n"
		"    const char& text4;   /**< Only valid for changes to text. */\n"
		"    const char^ text5;   /**< Only valid for changes to text. */\n"
		"}";
	char text[] =
		"\nvoid Foo() {\n"
		"    const char\n"
		"    *text1;   //< Only valid for changes to text.\n"
		"    const char\n"
		"    *text2;   //< Only valid for changes to text.\n"
		"    const char\n"
		"    *text3;   //< Only valid for changes to text.\n"
		"    const char\n"
		"    &text4;   /**< Only valid for changes to text. */\n"
		"    const char\n"
		"    ^text5;   /**< Only valid for changes to text. */\n"
		"}";
	char options[] = "max-code-length=50, align-pointer=name";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AlignToName2)
{
	// The poiner at the end is formatted as a cast.
	// The line should break without causing an exception in debug.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    const unsigned char *uxnbuf = (const unsigned char *)buf;\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    const unsigned char *uxnbuf = (const unsigned char\n"
		"                                   *)buf;\n"
		"}";
	char options[] = "max-code-length=50, align-pointer=name";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakPastMaxCodeLength1)
{
	// Splitting a line with a break past the line end.
	// Must use a PREVIOUS break if a break is past the maximum max-code-length.
	// The following line should break after "wxArtProvider::GetBitmap(" (the first paren)
	// instead of after "wxART_MAKE_ART_ID_FROM_STR(" (the second paren).
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    btnBack = new wxBitmapButton(Panel1, ID_BITMAPBUTTON2, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T(wxART_BUTTON))));\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    btnBack = new wxBitmapButton(Panel1,\n"
		"                                 ID_BITMAPBUTTON2,\n"
		"                                 wxArtProvider::GetBitmap(\n"
		"                                     wxART_MAKE_ART_ID_FROM_STR(_T(wxART_BUTTON))));\n"
		"}\n";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakPastMaxCodeLength2)
{
	// Splitting a line with a break past the line end.
	// Must use a PREVIOUS break if a break is past the maximum max-code-length.
	// The break past max-code-length should be used for the NEXT break.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!control)\n"
		"        control = new wxTextCtrl(parent, -1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY | wxTE_RICH | wxTE_NOHIDESEL | wxTE_AUTO_URL);\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!control)\n"
		"        control = new wxTextCtrl(parent, -1,\n"
		"                                 wxEmptyString, wxDefaultPosition, wxDefaultSize,\n"
		"                                 wxTE_MULTILINE | wxTE_READONLY | wxTE_RICH |\n"
		"                                 wxTE_NOHIDESEL | wxTE_AUTO_URL);\n"
		"}\n";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakPastMaxCodeLength3)
{
	// Splitting a line with a break past the line end.
	// Must use a PREVIOUS break if a break is past the maximum max-code-length.
	// The break past max-code-length should be used for the NEXT break.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    SetNodeText(s, TiXmlText(cbU2C(wxBase64::Encode(object.SerializeOut()))));\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    SetNodeText(s, TiXmlText(cbU2C(wxBase64::Encode(\n"
		"                                       object.SerializeOut()))));\n"
		"}\n";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakPastMaxCodeLength4)
{
	// Splitting a line with a break past the line end.
	// Must use a paren break if a whitespace break is past the maximum max-code-length.
	// Otherwise the next run will break the code at the paren.
	char textIn[] =
		"\nDebuggerBreakpoint* DebuggerState::RemoveBreakpoint(DebuggerBreakpoint* bp, bool deleteit)\n"
		"{\n"
		"    return 0;\n"
		"}\n";
	char text[] =
		"\nDebuggerBreakpoint*\n"
		"DebuggerState::RemoveBreakpoint(\n"
		"    DebuggerBreakpoint* bp, bool deleteit)\n"
		"{\n"
		"    return 0;\n"
		"}\n";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakPastMaxCodeLength5)
{
	// Splitting a line with a break past the line end
	// when the currentLine is at the end of line.
	// Tested with break blocks.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if((dir != Encrypt) && (dir != Decrypt))return RIJNDAEL_UNSUPPORTED_DIRECTION;\n"
		"    // should be preceeded by an empty line\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if((dir != Encrypt)\n"
		"            && (dir != Decrypt))return\n"
		"                    RIJNDAEL_UNSUPPORTED_DIRECTION;\n"
		"\n"
		"    // should be preceeded by an empty line\n"
		"}\n";
	char options[] = "max-code-length=50, break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakPastMaxCodeLength6)
{
	// Test max code length with a break past the maximum.
	// It should not leave an empty line after the long line.
	char text[] =
		"\nAdvancedCompilerOptionsDlg::AdvancedCompilerOptionsDlg(\n"
		"    wxWindow* parent, const wxString& compilerId)\n"
		"{\n"
		"    wxString ext = wxGetTextFromUser(\n"
		"                       _(\"Please enter a semi separated list of extensions\"),\n"
		"                       _(\"New extension\"));\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakPastMaxCodeLength7)
{
	// Test max code length with a break greater than maximum.
	// Should break on the paren after FindPageFromEditor.
	// It should not break on the ->.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (Manager::Get()->GetEditorManager()->FindPageFromEditor(m_pCodeCompletionLastEditor) == -1)\n"
		"        return;\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (Manager::Get()->GetEditorManager()->FindPageFromEditor(\n"
		"                m_pCodeCompletionLastEditor) == -1)\n"
		"        return;\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakPastMaxCodeLength8)
{
	// Test max code length with a break past max code length.
	// Should break on the first equal sign.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (frame.parent != null && (frame.parent.state == FrameState.FieldDeclAfterIdentifier\n"
		"                             || frame.parent.state == FrameState.FieldDecl))\n"
		"        isFoo();\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (frame.parent != null\n"
		"            && (frame.parent.state ==\n"
		"                FrameState.FieldDeclAfterIdentifier\n"
		"                || frame.parent.state == FrameState.FieldDecl))\n"
		"        isFoo();\n"
		"}";
	char options[] = "max-code-length=50, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, TwoBreaksWithComment1)
{
	// Test two breaks on a line with a line comment.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(old_a == a && old_b == b) // a long long comment to force a break\n"
		"        return;\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(old_a == a\n"
		"            && old_b ==\n"
		"            b) // a long long comment to force a break\n"
		"        return;\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, TwoBreaksWithComment2)
{
	// Test single line block with two breaks on a line with a line comment.
	char textIn[] =
		"\nclass TiXmlNode\n"
		"{\n"
		"    char* foo() { return IterateChildren (_value.c_str (), previous); }   ///< STL std::string form.\n"
		"}";
	char text[] =
		"\nclass TiXmlNode\n"
		"{\n"
		"    char* foo() {\n"
		"        return IterateChildren (_value.c_str (),\n"
		"                                previous);    ///< STL std::string form.\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Misc1)
{
	// Will split correctly if minimum code length is handled correctly.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    m_RegExes.Add(RegExStruct(_(\"Compiler error\"), cltError, _T(\"(^Error[ \\t]E[0-9]+)[ \\t](\") + FilePathWithSpaces + _T(\")[ \\t]([0-9]+)(:[ \\t].*)\"), 1, 2, 3, 4));\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    m_RegExes.Add(RegExStruct(_(\"Compiler error\"),\n"
		"                              cltError, _T(\"(^Error[ \\t]E[0-9]+)[ \\t](\") +\n"
		"                              FilePathWithSpaces +\n"
		"                              _T(\")[ \\t]([0-9]+)(:[ \\t].*)\"), 1, 2, 3, 4));\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Misc2)
{
	// Will not abort with pad-paren-out on the following line (checksum error).
	// The paren before "parent" was deleted (caused by the inserted space).
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    PopulateListControl ( static_cast<wxFlatNotebook*>( parent ) );\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    PopulateListControl (\n"
		"        static_cast<wxFlatNotebook*> ( parent ) );\n"
		"}";
	char options[] = "max-code-length=50, pad-paren-out";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Misc3)
{
	// OK to break after a closing block paren.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    sort (&fileName[firstEntry],&fileName[fileName.size()]);\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    sort (&fileName[firstEntry],\n"
		"          &fileName[fileName.size()]);\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Misc4)
{
	// Test max code length with pointers.
	// Should not break a pointer attached to a variable.
	char textIn[] =
		"\nTiXmlNode* TiXmlNode::ReplaceChild (TiXmlNode* replaceThis, const TiXmlNode& withThis)\n"
		"{\n"
		"};";
	char text[] =
		"\nTiXmlNode* TiXmlNode::ReplaceChild (\n"
		"    TiXmlNode* replaceThis, const TiXmlNode& withThis)\n"
		"{\n"
		"};";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Misc5)
{
	// Test max code length with pointers.
	// Should not break on the commas not a space.
	char textIn[] =
		"\nvoid ASFormatter::formatArrayBrackets(BracketType bracketType, bool isOpeningArrayBracket)\n"
		"{\n"
		"};";
	char text[] =
		"\nvoid ASFormatter::formatArrayBrackets(\n"
		"    BracketType bracketType,\n"
		"    bool isOpeningArrayBracket)\n"
		"{\n"
		"};";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Misc6)
{
	// Should not break before the closing paren of an empty paren.
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    VersionEditorDialog.SetRevision(GetVersionState().Values.Revision);\n"
		"}";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    VersionEditorDialog.SetRevision(\n"
		"        GetVersionState().Values.Revision);\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, CSharp1)
{
	// Should break twice on the first run.
	char textIn[] =
		"\npublic void CheckDataMember()\n"
		"{\n"
		"    ICSharpCode.Reports.Core.DataManager dmx = "			// this line is continued below
		"(ICSharpCode.Reports.Core.DataManager)ICSharpCode.Reports.Core.DataManager.CreateInstance(rs,da);\n"
		"}";
	char text[] =
		"\npublic void CheckDataMember()\n"
		"{\n"
		"    ICSharpCode.Reports.Core.DataManager dmx =\n"
		"        (ICSharpCode.Reports.Core.DataManager)\n"
		"        ICSharpCode.Reports.Core.DataManager.CreateInstance(rs,da);\n"
		"}";
	char options[] = "max-code-length=80, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, CSharp2)
{
	// Should break 'Data = data' on the first run.
	char textIn[] =
		"\nbool ProcessCommand(string readString)\n"
		"{\n"
		"    lock (this.dataWriter) {\n"
		"        this.dataWriter.WriteEventData(new[] { new EventDataEntry() "			// this line is continued below
		"{ DataSetId = this.dataWriter.DataSetCount, NameId = name, Type = (EventType)type, Data = data } });\n"
		"    }\n"
		"}";
	char text[] =
		"\nbool ProcessCommand(string readString)\n"
		"{\n"
		"    lock (this.dataWriter) {\n"
		"        this.dataWriter.WriteEventData(new[] { new EventDataEntry() {\n"
		"                DataSetId = this.dataWriter.DataSetCount, NameId = name, Type = (EventType)type,\n"
		"                Data = data\n"
		"            }\n"
		"        });\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=80, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------

}  // namespace
