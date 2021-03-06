/*
    Copyright (c) 2005-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/tests/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_TESTS_CORE_TESTNUMBER_H_
#define _ISHIKO_TESTS_CORE_TESTNUMBER_H_

#include <vector>
#include <stdlib.h>

namespace Ishiko
{
namespace Tests
{

class TestNumber
{
public:
    TestNumber();
    TestNumber(int major);
    TestNumber(int major, int minor);

    size_t depth() const;
    int part(size_t i) const;

    bool operator ==(const TestNumber& other) const;
    bool operator !=(const TestNumber& other) const;

    TestNumber& operator ++();
    TestNumber operator ++(int);
    TestNumber getDeeperNumber() const;

private:
    std::vector<int> m_number;
};

}
}

#endif
