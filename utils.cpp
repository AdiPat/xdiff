#include <iostream>
#include <fstream> // read file
#include <vector>
#include <string>
#include <map>
#include "utils.h"

// We return a pointer because local variables are static and get deallocated once the function terminates. The pointer will store the address to the dynamically allocated vector and return this address which can be used by other parts of the program.

extern std::vector <std::string>* read_file(std::string fpath) {
    std::vector <std::string> *res = new std::vector <std::string>;
    std::ifstream inp_file;
    inp_file.open(fpath);
    if(inp_file.is_open()) {
        // perform whatever
        std::string line;
        int i = 1;
        while(getline(inp_file, line)) {
            //std::cout<<"Line "<<i<<":"<<line<<std::endl;
            res->push_back(line);
            i++;
        }
        inp_file.close();
    }
    else {
        std::cout<<"read_file(): Error opening file "<<fpath<<std::endl;
    }
    return res;
}

extern std::vector <std::string>* split_line(std::string s) {
    // strip whitespace from both ends
    int i = 0, j=s.length()-1;
    while(isspace(s[i]))
        i++;
    while(isspace(s[j]))
        j--;
    // words
    std::vector <std::string> *words = new std::vector <std::string>;

    // split at whitespaces
    int prev = i; //index where first word starts
    for(int k=i; k<=j; k++) {
        char c = s[k];
        if(isspace(c)) { // If there are multiple whitespace characters, an empty string gets appended
            std::string prev_word = s.substr(prev, k-prev);
            words->push_back(prev_word);
            prev = k+1;
        }
    }
    words->push_back(s.substr(prev, j+1-prev));
    return words;
}


// TODO: Finish this
extern std::vector <std::string>* lines_to_words(std::vector <std::string> *vptr) {
    std::vector <std::string> v = *vptr;
    std::vector <std::string>* words = new std::vector <std::string>;
    for(int i=0; i<v.size(); i++) {
            std::string line = v[i];
            std::vector <std::string> cur_words = *(split_line(line));
            words->insert(words->end(), cur_words.begin(), cur_words.end());
    }
    return words;
}


extern void display_vector(std::vector <std::string> v) {
    for(int i=0; i<v.size(); i++) {
        printf("[%d] [%s]\n", i, v[i].c_str());
    }
}

// TODO: Fix this meanwhile using temporary function above
template <class T>
extern void _display_vector(T* vptr, int item_count) {
    std::vector <std::string> v = *vptr; // dereference for easy access, might lead to slower performance

    for(int i=0; i < v.size(); i++) {
        if(item_count == 1) {
            std::cout<<"["<<i<<"] "<<"["<<v[i]<<"]"<<std::endl;
        }
        // TODO: UGLY AND DOESN'T WORK!
        // else  {
        //     std::cout<<"["<<i<<"] "<<"[";
        //     for(int j=0; j<item_count; j++) {
        //         std::cout<<","<<v[i][j];
        //     }
        //     std::cout<<"]"<<std::endl;
        // }

    }
}

// checks if the file can be opened for reading
// don't know if this is the best way to do this w.r.t performance
extern bool file_exists(std::string f) {
    std::ifstream cur_file;
    cur_file.open(f);
    if(cur_file.is_open()) {
        cur_file.close();
        return true;
    }
    return false;
}

extern bool validate_args(int argc, char* argv[]) {
    if(argc != 3) {
        std::cout<<"[error] Invalid number of arguments: Expected "<<3<<" | Got "<<argc<<std::endl;
        return false;
    }
    // check files
    std::string f1, f2;
    f1 = std::string(argv[1]);
    f2 = std::string(argv[2]);

    for(int i=1; i<argc; i++) {
        std::string f = argv[i];
        if(!file_exists(f)) {
            std::cout<<"[error] File "<<f<<" does not exist."<<std::endl;
            return false;
        }
    }
    return true;
}
