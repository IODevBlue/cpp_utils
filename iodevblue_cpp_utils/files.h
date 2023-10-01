/*
 * files.h
 *
 *	Header for operations concerning files and folders.
 *  Created on: 1 Oct 2023
 *      Author: IO DevBlue
 */

#include <filesystem>
#include <fstream>
#include <ctime>
#include <string>
#include <iostream>


//********** METHODS **********//
/**
 * Prints the folders and files in a particular location
 */
void print_folder_and_file_names(const std::string& folder_name) {
	std::clock_t t1 = clock();
	int x = 0; int f = 0;
	for(auto& ent: std::filesystem::recursive_directory_iterator(std::filesystem::path(folder_name))) {
		if(!ent.path().has_extension()) f++;
		else x++;
		std::cout<<ent.path()<<'\n';
	}
	std::cout<<"Number of files: "<<x<<" files."<<'\n';
	std::cout<<"Number of folders: "<<f<<" folders."<<'\n';
	std::cout<<"Total time: "<<static_cast<float>(clock()-t1)/CLOCKS_PER_SEC<<" seconds."<<'\n';
}

void read_text_file(const std::string& file_location) {
	std::clock_t t1 = clock();
	std::filesystem::path p = std::filesystem::path{file_location};
	std::ifstream ifs(file_location);
	std::cout<<"Attempting to read file: "<<p.stem()<<"....."<<'\n';
	if(ifs.is_open() && ifs.good()) {
		std::cout<<'\n';
		std::cout<<"Input stream is open. Reading starting..."<<'\n';
		std::cout<<'\n';
		std::string temp;
		while(std::getline(ifs, temp)) {
			std::cout<<temp<<'\n';
		}
		std::cout<<'\n'<<"Done!"<<'\n';
		std::cout<<"Total time: "<<static_cast<float>(clock()-t1)/CLOCKS_PER_SEC<<" seconds."<<'\n';
	}
}
