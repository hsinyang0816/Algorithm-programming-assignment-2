// **************************************************************************
//  File       [maximum_planar_subset.h]
//  Author     [Hsin-Yang Chang]
//  Synopsis   [The header file for the Maximum Planar Subset Class]
//  Modify     [2020/11/16 Hsin-Yang Chang]
// **************************************************************************

#include<vector>
#include<fstream>
using namespace std;

class MPS {
    public:
	MPS(vector<int>, int); // constructor
	~MPS(); //destructor
	int maxPS(int, int);
	void findMPS(int, int, fstream&);
	int **M;	
    private:
	vector<int> dictionary;
	int N;
};

