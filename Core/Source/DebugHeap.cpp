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

#include "DebugHeap.h"
#if (defined(_WIN32) && defined(_DEBUG))
#include <crtdbg.h>
#endif

namespace Ishiko
{
namespace TestFramework
{

HeapStatus::HeapStatus()
{
    update();
}

void HeapStatus::update()
{
#if (defined(_WIN32) && defined(_DEBUG))
    _CrtMemState heapState;
    _CrtMemCheckpoint(&heapState);
    m_allocatedSize = heapState.lSizes[_NORMAL_BLOCK];
#endif
}

size_t HeapStatus::allocatedSize() const
{
    return m_allocatedSize;
}

}
}