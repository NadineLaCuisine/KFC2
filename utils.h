#ifndef __KFC2Utils__
#define __KFC2Utils__

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <unordered_map>
#include <functional>
#include <unordered_set>
#include <set>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <cctype>
#include <atomic>
#include <random>
#include <mutex>


#define kmer uint64_t


using namespace std;


kmer seq2intStranded(const string& seq);
string revcomp (const string &s);
string reversecomplement (const string &s);
void updateKmer(kmer&	min, char nuc,uint  k);
void updateKmerRC(kmer&	min, char nuc,uint  k);
char nuc2int(char c);
uint64_t xorshift64(uint64_t x);
uint trailing0(uint n);
uint64_t hash64 (kmer key);
void printKmer(kmer n);
void printBits(size_t const size, void const * const ptr);


#endif
