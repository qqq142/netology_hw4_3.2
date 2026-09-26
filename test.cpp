#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "list.h"

TEST_CASE("Empty returns true for a new list") {
    List list;
    REQUIRE(list.Empty() == true);
}

TEST_CASE("Size is zero for a new list") {
    List list;
    REQUIRE(list.Size() == 0);
}

TEST_CASE("Size increases after PushFront and PushBack") {
    List list;
    list.PushFront(10);
    REQUIRE(list.Size() == 1);
    REQUIRE(list.Empty() == false);

    list.PushBack(20);
    REQUIRE(list.Size() == 2);

    list.PushFront(5);
    REQUIRE(list.Size() == 3);
}

TEST_CASE("Clear resets size to zero and makes list empty") {
    List list;
    list.PushFront(1);
    list.PushBack(2);
    list.PushFront(3);
    REQUIRE(list.Size() == 3);

    list.Clear();
    REQUIRE(list.Size() == 0);
    REQUIRE(list.Empty() == true);
}

TEST_CASE("Clear on an empty list does nothing and does not crash") {
    List list;
    list.Clear();
    REQUIRE(list.Size() == 0);
    REQUIRE(list.Empty() == true);
}

TEST_CASE("After Clear we can push elements again") {
    List list;
    list.PushFront(42);
    list.PushBack(84);
    list.Clear();

    list.PushBack(100);
    REQUIRE(list.Size() == 1);
    REQUIRE(list.Empty() == false);

    list.PushFront(200);
    REQUIRE(list.Size() == 2);
}
