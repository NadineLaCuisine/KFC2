#include <thread>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <chrono>
#include <map>
#include <set>
#include <vector>
#include "utils.h"


kmer seq2intStranded(const string& seq){
	kmer res(0);
	for(uint i(0);i<seq.size();++i){
		res<<=2;
		res+=nuc2int(seq[i]);
	}
	return res;
}


char revcomp (char s) {
	if (s == 'A') return 'T';
	else if (s == 'C') return 'G';
	else if (s == 'G') return 'C';
	else if (s == 'T') return 'A';
	else if (s == 'a') return 't';
	else if (s == 'c') return 'g';
	else if (s == 'g') return 'c';
	else if (s == 't') return 'a';
	return 'X';
}


string reversecomplement (const string &s){
	string rc;
	for (int i = (int)s.length() - 1; i >= 0; i--){
		rc += revcomp(s[i]);
	}
	return rc;
}


void updateKmer(kmer&	min, char nuc,uint  k){
	min<<=2;
	min+=nuc2int(nuc);
	min%=(1<<(2*k));
}


void updateKmerRC(kmer&	min, char nuc,uint  k){
	min>>=2;
	min+=((3-nuc2int(nuc))<<(2*k-2));
}


char nuc2int(char c){
	switch(c){
		//~ case 'a': return 0;
		//~ case 'c': return 1;
		//~ case 'g': return 2;
		//~ case 't': return 3;
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'T': return 3;
	}
	// cout<<"oups"<<endl;
	// cout<<c<<endl;
	// cin.get();
	return 0;
}


uint64_t xorshift64(uint64_t x) {
	x+=34;
	x ^= x >> 12; // a
	x ^= x << 25; // b
	x ^= x >> 27; // c
	return x * UINT64_C(2685821657736338717);
}


uint64_t hash64 (kmer key){
	uint64_t hash = 23;
	hash ^= (hash <<  7) ^  key * (hash >> 3) ^ (~((hash << 11) + (key ^ (hash >> 5))));
	hash = (~hash) + (hash << 21);
	hash = hash ^ (hash >> 24);
	hash = (hash + (hash << 3)) + (hash << 8);
	hash = hash ^ (hash >> 14);
	hash = (hash + (hash << 2)) + (hash << 4);
	hash = hash ^ (hash >> 28);
	hash = hash + (hash << 31);

	return hash;
}


uint trailing0(uint n){
	if(n){
		n=(n^(n-1))>>1;
		uint c;
		for(c=0;n;++c){
			n>>=1;
		}
		return c;
	}else{
		return CHAR_BIT*sizeof(n);
	}
}

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = b[i] & (1<<j);
            byte >>= j;
            printf("%u", byte);
        }
    }
    puts("");
}


// void sequences2dot(vector<string>& seqV, uint k)(
// 	ofstream out("out.dot");
// 	out<<"graph ham {"<<endl;
// 	unordered_map<>
// 	for(uint i(0);i<seqV.size();++i){
//
// 	}
//
//
// 	out<<"}"<<endl;
// )
