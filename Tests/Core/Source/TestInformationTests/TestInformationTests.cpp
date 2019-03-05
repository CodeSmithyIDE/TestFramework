/*
    Copyright (c) 2005-2019 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#include "TestInformationTests.h"

using namespace Ishiko::Tests;

void AddTestInformationTests(TestHarness& theTestHarness)
{
    TestSequence& testSequence = theTestHarness.appendTestSequence("TestInformation tests");

    testSequence.append<HeapAllocationErrorsTest>("Creation test 1", TestInformationCreationTest1);
    testSequence.append<HeapAllocationErrorsTest>("number test 1", TestInformationNumberTest1);
    testSequence.append<HeapAllocationErrorsTest>("name test 1", TestInformationNameTest1);
}

TestResult::EOutcome TestInformationCreationTest1()
{
    TestNumber number(5);
    TestInformation info(number, "TestInformationCreationTest1");
    return TestResult::ePassed;
}

TestResult::EOutcome TestInformationNumberTest1()
{
    TestNumber number(5);
    TestInformation info(number, "TestInformationCreationTest1");
    if (info.number() == number)
    {
        return TestResult::ePassed;
    }
    else
    {
        return TestResult::eFailed;
    }
}

TestResult::EOutcome TestInformationNameTest1()
{
    TestNumber number(5);
    TestInformation info(number, "TestInformationCreationTest1");
    if (info.name() == "TestInformationCreationTest1")
    {
        return TestResult::ePassed;
    }
    else
    {
        return TestResult::eFailed;
    }
}
