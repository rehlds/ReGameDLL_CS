#include "precompiled.h"
#include "cppunitlite/TestHarness.h"

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <new>

// A new CNavArea must not be on the open list, even when the allocation
// still holds the live generation. m_masterMarker starts at 1, so filling
// the allocation with that value makes IsOpen() true unless Initialize()
// stores 0. The object is not destroyed: ~CNavArea() calls TheCSBots().
TEST(ConstructedAreaIsNotOpen, NavOpenList, 1000)
{
	void *mem = std::malloc(sizeof(CNavArea));
	CHECK("allocation", mem != nullptr);
	if (!mem)
		return;

	unsigned int live = 1;
	auto *bytes = static_cast<unsigned char *>(mem);
	for (size_t i = 0; i + sizeof(live) <= sizeof(CNavArea); i += sizeof(live))
		std::memcpy(bytes + i, &live, sizeof(live));

	CNavArea *area = new (mem) CNavArea();
	CHECK("a new area is not on the open list", !area->IsOpen());
}
