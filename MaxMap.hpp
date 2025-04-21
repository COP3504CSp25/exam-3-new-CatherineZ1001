#pragma once

#include <algorithm>
#include <map>
#include <string>
#include <vector>

float consultMax(const std::string& search_term, const std::map<std::string, std::vector<float>>& data) {
    auto target_iter = data.find(search_term);
	if (target_iter == data.end()){
		return -1.f;
	} else{
		std::vector target_data = target_iter->second;
		float max = target_data.at(0);
		for (float num : target_data){
			if (num > max) max = num;
		}
		return max;
	}
}

std::map<std::string, float> returnMaxMap(const std::map<std::string, std::vector<float>>& in_map) {
   std::map<std::string, float> return_map = {};
   for (auto iter = in_map.begin(); iter != in_map.end(); ++iter){
		return_map[iter->first] = consultMax(iter->first, in_map);
   }
   return return_map;
}