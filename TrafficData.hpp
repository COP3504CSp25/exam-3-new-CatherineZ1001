#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

std::map<std::string, int> loadTrafficData(const std::string& filename) {
	std::map<std::string, int> data = {};

	std::ifstream inFile(filename);
	if (!inFile){
		std::cerr << -1 << std::endl;
		return;
	}

	std::string content;
	while (std::getline(inFile, content)){
		data[content.substr(0, 3)] = std::stoi(content.substr(4));
	}

	return data;
}

void updateTrafficData(const std::string& filename, std::map<std::string, int>& dataMap) {
	std::ifstream inFile(filename);
	if (!inFile){
		std::cerr << -1 << std::endl;
		return;
	}

	std::string content;
	while (std::getline(inFile, content)){
		dataMap[content.substr(0, 3)] = std::stoi(content.substr(4));
	}
}