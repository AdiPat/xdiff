#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include "utils.h"
#include "diff.h"

//typedef std::vector<std::string> string_vector;
// TODO: What the fuck is happening here?
extern int normalize_words(string_vector* words) {
    for(int i=0; i < words->size(); i++) {
        std::string s = words->at(i);
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);

        // eliminate punctuation at the end
        if(ispunct(s[s.length()-1]))
            s = s.substr(0,s.length()-1);

        words->at(i) = s;
    }
    return 0;
}

extern freq_map* freqDist(string_vector* words) {
    freq_map* word_freq = new freq_map;

    for(int i=0; i < words->size(); i++) {
        std::string s = words->at(i);
        // check if it exists
        if(word_freq->find(s) != word_freq->end())
            word_freq->at(s) += 1;
        else
            word_freq->insert(std::pair<std::string, int>(s,1));
    }
    return word_freq;
}

extern int display_freqDist(freq_map* fdist) {
    for(freq_map::iterator it = fdist->begin(); it != fdist->end(); it++) {
        std::cout<<"["<<(it->first)<<"]"<<" : "<<(it->second)<<std::endl;
    }
    return 0;
}

extern std::pair<freq_map*, freq_map*>* transform_dimensions(string_vector* v1, string_vector* v2) {
    freq_map *f_v1 = new freq_map;
    freq_map *f_v2 = new freq_map;
    // sort vectors
    std::sort(v1->begin(), v1->end());
    std::sort(v2->begin(), v2->end());
    // get union
    string_vector *v = new string_vector(v1->size()+v2->size());
    std::set_union(v1->begin(), v1->end(), v2->begin(), v2->end(), v->begin());

    // eliminate duplicates and empty strings from v
    // unique keeps only the first occurence and returns an iterator to where the duplicates begin
    // the erase function then erases all values till the end
    v->erase(unique(v->begin(), v->end()), v->end());
    string_vector::iterator it = std::find(v->begin(), v->end(), "");
    v->erase(it);
    // create new vectors with 0 initial count for each word with all these words
    // assign values from original vector

    // create equal dimension vectors
    for(int i=0; i<v->size(); i++) {
        f_v1->insert(std::pair<std::string, int>(v->at(i),0));
        f_v2->insert(std::pair<std::string, int>(v->at(i),0));
    }

    // update both vectors with proper counts
    for(int i=0; i<v1->size(); i++) {
        f_v1->at(v1->at(i)) += 1;
    }

    for(int j=0; j<v2->size(); j++) {
        f_v2->at(v2->at(j)) += 1;
    }

    // return dem transformed vectors - hell yeah
    return new std::pair<freq_map*, freq_map*>(f_v1, f_v2);
}


extern double magnitude(freq_map* f) {
    double mag = 0;
    for(freq_map::iterator it = f->begin(); it != f->end(); it++) {
        mag += (double) (it->second * it->second);
    }
    return sqrt(mag);
}

extern double dot_product(freq_map* f1, freq_map *f2) {
    double res = 0.0;
    for(freq_map::iterator i = f1->begin(), j = f2->begin(); i != f1->end() && j != f2->end(); i++, j++) {
        res += (i->second) * (j->second);
    }
    return res;
}

extern double angle(freq_map* f1, freq_map *f2) {
    double cosX = dot_product(f1,f2) / (magnitude(f1) * magnitude(f2));
    double angle_radians = acos(cosX);
    // convert to degree
    std::cout<<"Distance = "<<angle_radians<<std::endl;
    double angle_deg = (180/M_PI) * angle_radians;
    return angle_deg;
}

extern double percentage_similarity(double ang) {
    return 100.0 - (ang*100.0)/180.0;
}

extern double percentage_similarity(freq_map* f1, freq_map *f2) {
    return 100.0 - (angle(f1,f2)*100.0)/180.0;
}

extern double doc_similarity(std::string f1, std::string f2) {
    std::vector<std::string> *v1 = read_file(f1);
    std::vector<std::string> *v2 = read_file(f2);
    std::vector<std::string>* words1 = lines_to_words(v1);
    std::vector<std::string>* words2 = lines_to_words(v2);
    normalize_words(words1);
    normalize_words(words2);
    std::pair<freq_map*, freq_map*>* f_vecs = transform_dimensions(words1, words2);
    double res = percentage_similarity(f_vecs->first, f_vecs->second);
    // delete resources
    delete v1;
    delete v2;
    delete words1;
    delete words2;
    delete f_vecs;
    return res;
}
