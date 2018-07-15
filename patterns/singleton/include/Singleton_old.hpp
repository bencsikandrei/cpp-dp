#pragma once
/*
 * Old style singleton, with double IF for thread safety
 */
class Singleton {
public:
	static Singleton* get();
private:
	Singleton();
	static Singleton* instance;
};
