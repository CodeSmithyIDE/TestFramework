/*
    Copyright (c) 2007-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/tests/blob/main/LICENSE.txt
*/

#include "TestHarnessTests.h"
#include "Ishiko/Tests/Core/TestHarness.h"

using namespace Ishiko::Tests;

TestHarnessTests::TestHarnessTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "TestHarness tests", environment)
{
    append<HeapAllocationErrorsTest>("Creation test 1", CreationTest1);
    append<HeapAllocationErrorsTest>("run test 1", RunTest1);
    append<HeapAllocationErrorsTest>("run test 2", RunTest2);
    append<HeapAllocationErrorsTest>("run test 3", RunTest3);
}

void TestHarnessTests::CreationTest1(Test& test)
{
    TestHarness theTestHarness("TestHarnessTests_CreationTest1");
    ISHTF_PASS();
}

void TestHarnessTests::RunTest1(Test& test)
{
    TestHarness theTestHarness("TestHarnessTests_RunTest1");
    int returnCode = theTestHarness.run();

    ISHTF_FAIL_IF_NEQ(returnCode, eTestFailure);
    ISHTF_PASS();
}

void TestHarnessTests::RunTest2(Test& test)
{
    TestHarness theTestHarness("TestHarnessTests_RunTest2");

    std::shared_ptr<Test> test1 = std::make_shared<Test>(TestNumber(1), "Test", TestResult::passed);
    theTestHarness.tests().append(test1);

    int returnCode = theTestHarness.run();

    ISHTF_FAIL_IF_NEQ(returnCode, eOK);
    ISHTF_PASS();
}

void TestHarnessTests::RunTest3(Test& test)
{
    TestHarness theTestHarness("TestHarnessTests_RunTest3");

    std::shared_ptr<Test> test1 = std::make_shared<Test>(TestNumber(1), "Test", TestResult::skipped);
    theTestHarness.tests().append(test1);

    int returnCode = theTestHarness.run();

    ISHTF_FAIL_IF_NEQ(returnCode, eOK);
    ISHTF_PASS();
}
