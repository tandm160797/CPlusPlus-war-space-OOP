#ifdef DataManager_hpp

template<class Type>
DataManager<Type>::DataManager(const string &path) {
	int id = 1;
	string tempPath;
	ifstream fileIn;
	fileIn.open(path);
	while (!fileIn.eof()) {
		getline(fileIn, tempPath);
		map[id].loadFromFile(tempPath);
		id++;
	}
}
template<class Type>
void DataManager<Type>::loadFromFile(const string &path) {
	int id = 1;
	string tempPath;
	ifstream fileIn;
	fileIn.open(path);
	while (!fileIn.eof()) {
		getline(fileIn, tempPath);
		map[id].loadFromFile(tempPath);
		id++;
	}
}
template<class Type>
Type& DataManager<Type>::getElementById(int id) {
	return map[id];
}
#endif //DataManager_hpp
