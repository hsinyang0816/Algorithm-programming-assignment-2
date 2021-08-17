// **************************************************************************
//  File       [maximum_planar_subset.cpp]
//  Author     [Hsin-Yang Chang]
//  Synopsis   [The implementation of the Maximum Planar Subset Class]
//  Modify     [2020/11/16 Hsin-Yang Chang]
// **************************************************************************

#include "maximum_planar_subset.h"
#include <iostream>
// Constructor
MPS::MPS(vector<int> dictionary, int N) {
	this -> dictionary = dictionary;
	this -> N = N;
	M = new int*[N];
	for(int i = 0; i < N; ++i){
		M[i] = new int[i + 1];
		//for(int j = 0; j < i + 1; ++j)
			//*(*(M + i) + j) = -1;
		for(int j = 0; j < i; ++j)
			*(*(M + i) + j) = -1;
		*(*(M + i) + i) = 0;
	}
}

MPS::~MPS(){
	for(int i = 0; i < N; ++i)
		delete [] M[i];
	delete [] M;
}

int MPS::maxPS(int i, int j){
	if(*(*(M + j)+ i) >= 0)
		return *(*(M + j)+ i);
	if(i == j)
		return 0;
	int k = this -> dictionary[i];
	int ans = 0;
	if(k < j && k > i){
		int temp = maxPS(i + 1, k) + 1 + maxPS(k + 1, j);
		if(temp > maxPS(i + 1, j))
			ans = temp;
		else
			ans = maxPS(i + 1, j);
	}
	else if(k == j){
		ans =  maxPS(i + 1, j) + 1;
	}
	else
		ans =  maxPS(i + 1, j);
	*(*(M + j)+ i) = ans;
	return ans;
}

void MPS::findMPS(int i,int j, fstream& fout){
	int l = i;
	while(l < j ){
		if(*(*(M + j) + l) != *(*(M + j)+ l + 1)){
			fout << l << " " << dictionary[l] << endl;			
			findMPS(l+1, dictionary[l], fout);
			findMPS(dictionary[l]+1, j, fout);
			break;
		}
		++l;
	} 
}
