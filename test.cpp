#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "list.h"

TEST_CASE("PushBack increases size and stores correct value") {
    List list;
    list.PushBack(10);
    REQUIRE(list.Size() == 1);
    REQUIRE(list.Empty() == false);

    list.PushBack(20);
    REQUIRE(list.Size() == 2);

    REQUIRE(list.PopBack() == 20);
    REQUIRE(list.PopBack() == 10);
    REQUIRE(list.Empty() == true);
}

TEST_CASE("PushFront increases size and stores correct value") {
    List list;
    list.PushFront(5);
    REQUIRE(list.Size() == 1);

    list.PushFront(3);
    REQUIRE(list.Size() == 2);

    REQUIRE(list.PopFront() == 3);
    REQUIRE(list.PopFront() == 5);
    REQUIRE(list.Empty() == true);
}

TEST_CASE("PopBack throws on empty list") {
    List list;
    REQUIRE_THROWS(list.PopBack());
}

TEST_CASE("PopFront throws on empty list") {
    List list;
    REQUIRE_THROWS(list.PopFront());
}

TEST_CASE("Complex scenario with Push/Pop combinations") {
    List list;

    list.PushBack(1);
    list.PushFront(2);
    list.PushBack(3); 
    list.PushFront(4);

    REQUIRE(list.Size() == 4);

    REQUIRE(list.PopFront() == 4);
    REQUIRE(list.PopBack() == 3);
    REQUIRE(list.PopFront() == 2);
    REQUIRE(list.PopBack() == 1);

    REQUIRE(list.Size() == 0);
    REQUIRE(list.Empty() == true);

    list.PushBack(100);
    REQUIRE(list.Size() == 1);
    REQUIRE(list.PopFront() == 100);
}
