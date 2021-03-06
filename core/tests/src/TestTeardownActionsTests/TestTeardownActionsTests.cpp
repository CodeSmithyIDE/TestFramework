/*
    Copyright (c) 2015-2019 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/tests/blob/main/LICENSE.txt
*/

#include "TestTeardownActionsTests.h"
#include "DirectoriesTeardownActionTests.h"
#include "FilesTeardownActionTests.h"

using namespace Ishiko::Tests;

TestTeardownActionsTests::TestTeardownActionsTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "TestTeardownAction tests", environment)
{
    append<DirectoriesTeardownActionTests>();
    append<FilesTeardownActionTests>();
}
