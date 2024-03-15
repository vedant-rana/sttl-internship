#include<iostream>
#include <fstream>
using namespace std;

void writeInFile(){
    //to write in text file through cpp fstream we use ofstream
    ofstream write;
    string input, fileName;

    cout<<"Enter File name: ";
    cin>>fileName;

    write.open(fileName);

    cout<<"Write data to add in file(press -1 to exit.)"<<endl;

    while(write){
        getline(cin, input);

        if(input == "-1"){
            break;
        }

        write<<input<<endl;
    }   

    write.close();
    cout<<"Data added successfully !"<<endl;
}

void readFile(){
    ifstream read;
    string fileName, data;
    cout<<"Enter the Filename to read : ";
    cin>>fileName;

    read.open(fileName);

    while(getline(read, data)){
        cout<<data<<endl;
    }
    read.close();
}

int main()
{
    writeInFile();
    readFile();
    return 0;
}