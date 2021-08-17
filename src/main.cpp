#include <iostream>
#include <fstream>
#include "maximum_planar_subset.h"
#include "../lib/tm_usage.h"

using namespace std;

void help_message() {
    cout << "usage: mps <input_file> <output_file>" << endl;
}

int main(int argc, char* argv[])
{
    if(argc != 3) {
       help_message();
       return 0;
    }
    CommonNs::TmUsage tmusg;
    CommonNs::TmStat stat;

    //////////// read the input file /////////////
    fstream fin(argv[1]);
    fstream fout;
    fout.open(argv[2],ios::out);
    int num1,num2;
    int number;
    fin >> number;
    vector<int> dictionary(number);
    while (fin >> num1 >> num2){
	dictionary[num1] = num2;
	dictionary[num2] = num1;
    }

    tmusg.periodStart();
    MPS NTUMPS(dictionary, number);
    int numofMPS = NTUMPS.maxPS(0, number - 1);
    fout << numofMPS << endl;
    NTUMPS.findMPS(0, number-1, fout);
    tmusg.getPeriodUsage(stat);
    cout <<"The total CPU time: " << (stat.uTime + stat.sTime) / 1000.0 << "ms" << endl;
    cout <<"memory: " << stat.vmPeak << "KB" << endl; // print peak memory
    fin.close();
    fout.close();

    //cout << "makefile successfully" << endl;
}


