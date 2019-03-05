/*
    Copyright (c) 2007-2019 Xavier Leclercq

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

#include "SimpleTestClass1.h"

using namespace Ishiko::Tests;

SimpleTestClass1::SimpleTestClass1(const TestNumber& number, const std::string& name, TestResult::EOutcome outcome)
    : Test(number, name), m_outcome(outcome)
{
}

SimpleTestClass1::SimpleTestClass1(const TestNumber& number, const std::string& name, TestResult::EOutcome outcome,
    const TestEnvironment& environment)
    : Test(number, name, environment), m_outcome(outcome)
{
}

TestResult::EOutcome SimpleTestClass1::doRun(TestObserver::ptr& observer)
{
    return m_outcome;
}
