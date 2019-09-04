typedef std::vector <std::string> string_vector;
typedef std::map <std::string,int> freq_map;

// normalizes words by eliminating punctuation and transforming to lower case
extern int normalize_words(string_vector* words);

// generates frequency distribution from word list
extern freq_map* freqDist(string_vector* words);

// displays frequency distribution
extern int display_freqDist(freq_map* f);

// transforms both vectors so that they have the same dimension
extern std::pair<freq_map*, freq_map*>* transform_dimensions(string_vector* v1, string_vector* v2);

// gets magnitude of vector
extern double magnitude(freq_map* f);

// dot product
extern double dot_product(freq_map* f1, freq_map* f2);

// angle
extern double angle(freq_map* f1, freq_map* f2);

// percentage similarity between documents
extern double percentage_similarity(double angle);
extern double percentage_similarity(freq_map* f1, freq_map* f2);

// main wrapper function
extern double doc_similarity(std::string f1, std::string f2);
