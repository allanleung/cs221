#include <iostream>
#include <fstream>
#include <sstream>
#include <string>       // provides string class
#include <cctype>       // provides isalpha() and tolower()
//#include "index.h"
#include <vector>


using namespace std;

// The following function should be moved into your skiplist.cc file when you
// write that.  It implements the random bit generation.
#include <ctime>                // for time()
#include <cstdlib>              // for rand(), srand(), and RAND_MAX

int randBit(void) {             // return a "random" bit
  static int bitsUpperBd=0;
  static int bits;              // store bits returned by rand()
  if( bitsUpperBd == 0 ) {      // refresh store when empty
    bitsUpperBd = RAND_MAX;
    bits = rand();
  }
  int b = bits & 1;
  bits >>= 1;
  bitsUpperBd >>= 1;
  return b;
}

typedef struct {
    string word;
    int count;
    std::vector<int> pages;
} dictionary_entry;

typedef std::vector<dictionary_entry> dictionary;

// Remove all characters except letters (A-Z,a-z) from line,
// except keep '-' or '\'' if they are between letters.
void lowercaseWords(string & line) {
  for( string::iterator it = line.begin(); it != line.end(); ++it ) {
    if( !isalpha(*it) ) {
      if( (*it != '-' && *it != '\'') ||
          it == line.begin() || it+1 == line.end() ||
          !isalpha(*(it-1)) || !isalpha(*(it+1)) ) {
        *it = ' ';
      }
    } else {
      *it = tolower(*it);
    }
  }
}

void print(ostream & output, string & word) {
  output << word << endl;
}


int find(dictionary & dict, string & word) {
    int entry_index = 0;

    for (dictionary::iterator dict_it = dict.begin(); dict_it != dict.end(); dict_it++, entry_index++) {
        
        if (word.compare(dict_it->word) == 0) {
            return entry_index;
            // i am at the position where its greater than the index,
            // which means it is in order
        } else if (word.compare(dict_it->word) < 0) {

            dictionary_entry new_entry;
            new_entry.word = word;
            new_entry.count = 0;

            dict.insert(dict_it, new_entry);

            return entry_index;
        }
        
    }

    // if we're here it means it should be last element in dictionar
    // entry_index is already end because to get here dict_it == dict.end() at some point
    // in that case entry_index == size dict which is one after the last element
    dictionary_entry new_entry;
    new_entry.word = word;
    new_entry.count = 0;
    
    dict.insert(dict.end(), new_entry);
    
    // entry_index is now a valid index since we just added something == *new* (size dict - 1)
    return entry_index;


//    for (int i = 0; i < (int) dict.size(); i++) {
//        if (word.compare(dict[i].word)==0)
//            return i;
//    }
//    return -1;
}


void insert(dictionary & dict, string & word, int page) {
    int entry_index = find(dict, word);
    
    dict[entry_index].count++;
    // checks if the last page is not the same as the page being added,
    // if yes, add the page.
    if (dict[entry_index].pages.empty() || dict[entry_index].pages.back() != page)
        dict[entry_index].pages.push_back(page);

}

void printInOrder(ostream & output, dictionary & dict) {
    for (std::vector<dictionary_entry>::iterator dict_it = dict.begin() ; dict_it != dict.end(); ++dict_it) {
        output  << dict_it->word <<  " (" << dict_it->count << ") ";
        for (std::vector<int>::iterator page_it = dict_it->pages.begin(); page_it != dict_it->pages.end(); page_it++) {
            if( page_it == dict_it->pages.end() - 1){
                output <<  * page_it << ".";
            } else {
                output <<  * page_it << ", ";
            }
        }
        output << std::endl;
    }
    
}

int main(int argc, char *argv[]) {
  if( argc != 3 ) {
    cerr << "Usage: " << argv[0] << " book.txt index.txt" << endl;
    exit(1);
  }

  ifstream fin;
  fin.open(argv[1]);
  if( !fin.is_open() ) {
    cerr << "Unable to open " << argv[1] << endl;
    exit(2);
  }

  ofstream fout;
  fout.open(argv[2]);
  if( !fout.is_open() ) {
    cerr << "Unable to open " << argv[2] << endl;
    exit(3);
  }

  dictionary dict;
  string line, word;
  int lines_read = 1;
  while( !fin.eof() ) {
    getline(fin,line);
    lines_read++;
    lowercaseWords(line);
    istringstream iss(line, istringstream::in);
    while( iss >> word ) {
    //find(dict, word);
    insert(dict, word, 1 + int (lines_read/40));
        
    }
  }
    printInOrder(fout, dict);

}
