/*
 * objects.h
 *
 * Header file concerned with creating and managing C++ objects.
 *
 *  Created on: 1 Oct 2023
 *  Author: IO DevBlue
 */

#include <memory>
#include <iostream>
#include <memory>

namespace iodevblue_cpp_utils {

//********** METHODS **********//
/**
 * This function creates an instance of any class.
 */
template<typename T, typename... Args>
std::unique_ptr<T> create_obj(Args&&... args) {
	return (std::make_unique<T>(std::forward<Args>(args)...));
}

void print() {}
/*
 * Prints several objects to the console.
 */
template<typename T, typename... Tail>
void print(T head, Tail&&... tail) {
	std::cout<<head<<"\n";
	print(tail...);
}

template<typename E>
void exec_for_each(E func_obj){};
/**
 * Executes the function object for each object passed to the function.
 */
template<typename E, typename T, typename... T2>
void exec_for_each(E func_obj,T first, T2&&... a) {
	func_obj(first);
	exec_for_each(func_obj, (a)...);
}





//********** CLASSES **********//
template<typename T, typename... Args>
class object_creator {
public:
	static std::unique_ptr<T> create(Args... args) {
		return (std::make_unique<T>(args...));
	}
};

}
