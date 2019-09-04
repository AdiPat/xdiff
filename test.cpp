#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "diff.h"
#include "utils.h"


// utils.c


// TODO: Add actual test verification

extern int Test_read_file() {
    std::vector<std::string> *v = read_file("tests/t0-A.txt");
    //display_vector(*v);
    return 0;
}

extern int Test_split_line() {
    std::vector<std::string> *v = split_line("\nThis  is  some words!  \t\n");
    //display_vector(*v);
    return 0;
}

extern int Test_lines_to_words() {
    std::vector<std::string> *v = read_file("tests/t0-A.txt");
    //display_vector(*v);
    std::vector<std::string> words = *(lines_to_words(v));
    //display_vector(words);
    return 0;
}

// diff.c

extern int Test_normalize_words() {
    std::vector<std::string> *v = read_file("tests/t0-A.txt");
    //display_vector(*v);
    std::vector<std::string>* words = lines_to_words(v);
    //display_vector(*words);
    normalize_words(words);
    //display_vector(*words);
    return 0;
}

extern int Test_freqDist() {
    std::vector<std::string> *v = read_file("tests/t0-A.txt");
    //display_vector(*v);
    std::vector<std::string>* words = lines_to_words(v);
    //display_vector(*words);
    normalize_words(words);
    //display_vector(*words);
    std::map<std::string,int> *freq_map = freqDist(words);
    //display_freqDist(freq_map);
    return 0;
}

extern int Test_transform_dimensions() {
    std::vector<std::string> *v1 = read_file("tests/t0-A.txt");
    std::vector<std::string> *v2 = read_file("tests/t0-B.txt");
    std::vector<std::string>* words1 = lines_to_words(v1);
    std::vector<std::string>* words2 = lines_to_words(v2);
    normalize_words(words1);
    normalize_words(words2);
    std::pair<freq_map*, freq_map*>* f_vecs = transform_dimensions(words1, words2);
    //display_freqDist(f_vecs->first);
    //display_freqDist(f_vecs->second);
}

extern int Test_magnitude() {
    std::vector<std::string> *v1 = read_file("tests/t0-A.txt");
    std::vector<std::string> *v2 = read_file("tests/t0-B.txt");
    std::vector<std::string>* words1 = lines_to_words(v1);
    std::vector<std::string>* words2 = lines_to_words(v2);
    normalize_words(words1);
    normalize_words(words2);
    std::pair<freq_map*, freq_map*>* f_vecs = transform_dimensions(words1, words2);
    std::cout<<"MAGNITUDES: "<<magnitude(f_vecs->first)<<" | "<<magnitude(f_vecs->second)<<std::endl;
}

extern int Test_dot_product() {
    std::vector<std::string> *v1 = read_file("tests/t0-A.txt");
    std::vector<std::string> *v2 = read_file("tests/t0-B.txt");
    std::vector<std::string>* words1 = lines_to_words(v1);
    std::vector<std::string>* words2 = lines_to_words(v2);
    normalize_words(words1);
    normalize_words(words2);
    std::pair<freq_map*, freq_map*>* f_vecs = transform_dimensions(words1, words2);
    std::cout<<"DOT PRODUCT: "<<dot_product(f_vecs->first, f_vecs->second)<<std::endl;
}

extern int Test_angle() {
    std::vector<std::string> *v1 = read_file("tests/t0-A.txt");
    std::vector<std::string> *v2 = read_file("tests/t0-B.txt");
    std::vector<std::string>* words1 = lines_to_words(v1);
    std::vector<std::string>* words2 = lines_to_words(v2);
    normalize_words(words1);
    normalize_words(words2);
    std::pair<freq_map*, freq_map*>* f_vecs = transform_dimensions(words1, words2);
    //display_freqDist(f_vecs->first);
    //std::cout<<"SECOND.."<<std::endl;
    //display_freqDist(f_vecs->second);
    double ang = angle(f_vecs->first, f_vecs->second);
    std::cout<<"ANGLE = "<<ang<<" PERCENTAGE SIMILARITY = "<<percentage_similarity(ang)<<"%"<<std::endl;
}

int main() {
  std::cout<<"[xdiff] Launching test suite"<<std::endl;
  //Test_read_file();
  //Test_split_line();
  //Test_lines_to_words();
  //Test_normalize_words();
  //Test_freqDist();
  //Test_transform_dimensions();
  //Test_magnitude();
  //Test_dot_product();
  Test_angle();
  return 0;
}
