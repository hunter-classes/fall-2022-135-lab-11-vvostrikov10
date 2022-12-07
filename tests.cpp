#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

TEST_CASE("<getUsername tests>"){
    Profile test;
    Profile test2("Mario", "wahoo");
    CHECK(test.getUsername() == "");
    CHECK(test2.getUsername() == "Mario");
}

TEST_CASE("<getFullName tests>"){
    Profile test;
    Profile test2("Mario", "wahoo");
    CHECK(test.getFullName() == " (@)");
    CHECK(test2.getFullName() == "wahoo (@Mario)");
}

TEST_CASE("<setDisplayName tests>"){
    Profile testEmpty;
    testEmpty.setDisplayName("new");
    CHECK(testEmpty.getFullName() == "new (@)");
    Profile test("Mario", "wahoo");
    test.setDisplayName("M");
    CHECK(test.getFullName() == "M (@Mario)");
}

TEST_CASE("<findID tests>"){
    Network n;
    n.addUser("A", "a");
    n.addUser("B", "b");
    n.addUser("C", "c");
    CHECK(n.findID("A") == 0);
    CHECK(n.findID("B") == 1);
    CHECK(n.findID("C") == 2);
    CHECK(n.findID("D") == -1);
}

TEST_CASE("<follow tests>"){
    Network n;
    n.addUser("A", "a");
    n.addUser("B", "b");
    n.addUser("C", "c");
    CHECK(n.isFollowing(n.findID("A"), n.findID("B")) == false);
    n.follow("A", "B");
    CHECK(n.isFollowing(n.findID("A"), n.findID("B")) == true);
    CHECK(n.isFollowing(n.findID("A"), n.findID("C")) == false);
}
