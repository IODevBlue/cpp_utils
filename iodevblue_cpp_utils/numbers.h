/*
 * random_values.h
 *
 * Header responsible for creating random values.
 *
 *  Created on: 1 Oct 2023
 *      Author: IO DevBlue
 */
#include <random>
#include <sstream>
#include <bitset>
#include <string>

//********** METHODS **********//
/*
 * Converts an integer value to binary.
 */
int to_binary(int param) {
	return(std::stoi(std::bitset<64>(param).to_string().substr(64-std::log2(param)-1)));
}

/*
 * Generates hash value of a string.
 */
std::size_t generate_hash(std::string& f) {
	return (std::hash<std::string>()(f));
}


//********** CLASSES **********//
/**
 * This class generates random integers in a given range.
 * Invoke the () operator to get the random integer.
 */
class random_int {
public:
	random_int(int start, int end): dist(start, end) {}

	double operator()() { return (dist(rd)); }

private:
	std::random_device rd;
	std::uniform_int_distribution<> dist;
};

/**
 * This class generates random double in a given range.
 * Invoke the () operator to get the random double.
 */
class random_double {
public:
	random_double(double start, double end): dist(start, end) {}

	double operator()() { return (dist(rd)); }

private:
	std::random_device rd;
	std::uniform_real_distribution<> dist;
};

