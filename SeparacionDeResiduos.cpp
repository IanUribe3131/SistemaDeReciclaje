#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

int main(){

    ifstream iFile;
    string line="";
    iFile.open("waste_items_dataset.csv");

    getline(iFile, line);
    getline(iFile, line);

    cout<<line<<endl;

    return 0;
}