#define CATCH_CONFIG_MAIN // catch provides a main function
#include <catch2/catch.hpp>

#include <Singleton_old.hpp>

TEST_CASE("Catch works and this should fail", "[catch]") {
	Singleton* onlyInstance { Singleton::get() };

	REQUIRE(onlyInstance != nullptr);
}

