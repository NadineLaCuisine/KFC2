#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <unordered_set>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <atomic>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"


using namespace std;


int main(int argc, char ** argv){
	string header,sequence;
	uint k(31);
	uint64_t countMin(UINTMAX_MAX),h,countTrail(0);
	unordered_set<kmer> kmerSet;
	ifstream in("mini.fa");
	while(not in.eof()){
		getline(in,header);
		getline(in,sequence);
		// cout<<header<<endl;
		// cout<<sequence<<endl;
		kmer kmerS(seq2intStranded(sequence.substr(0,k)));
		kmer kmerRC(seq2intStranded(reversecomplement(sequence.substr(0,k))));//TODO we can to beter here than use RC on string
		kmer kmer(min(kmerS,kmerRC));
		// cout<<coutMin<<endl;
		uint i(0);
		do{
			kmerSet.insert(kmer);
			h=(hash64(kmer));
			uint trail(trailing0(h));
			// cout<<trailing0(2)<<endl;cin.get();
			if(h<countMin){countMin=h;
				// cout<<countMin<<" "<<kmer<<endl;
			}
			// h=8;
			if(trail>countTrail){countTrail=trail;
				// cout<<countTrail<<endl;printBits(8,&h);cout<<trailing0(h)<<endl;
			}
			if(i+k<sequence.size()){
				updateKmer(kmerS, sequence[i+k], k);
				updateKmerRC(kmerRC, sequence[i+k], k);
				kmer=min(kmerRC,kmerS);
			}else{
				break;
			}
			++i;
		}while(true);
	}
	cout<<"cardinal: "<<kmerSet.size()<<endl;
	// cout<<countMin<<endl;
	cout<<"estimation mincount:"<<(double)1/countMin<<endl;
	// cout<<countTrail<<endl;
	cout<<"estimation ll: "<<(1<<(countTrail))<<endl;
	return 0;
}
