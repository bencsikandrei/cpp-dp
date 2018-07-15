#include <Singleton_old.hpp>
#include <iostream>

Singleton* Singleton::get() {

	if(not instance) {
		instance = new Singleton;
		std::cout << "Instanciated singleton" << '\n';
	}
	return instance;
}

Singleton::Singleton() {}

Singleton* Singleton::instance{nullptr};
