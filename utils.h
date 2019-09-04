
// Reads a file at specified path and returns its lines as a vector
extern std::vector <std::string>* read_file(std::string fpath);

// Splits line into words
extern std::vector <std::string>* split_line(std::string s);

// Converts vector of lines into a vector of words
extern std::vector <std::string>* lines_to_words(std::vector<std::string>* lines);

// Template function to print contents of a 1D vector
template <class T>
extern void _display_vector(T* v, int item_count = 1);

// temporary display function
extern void display_vector(std::vector <std::string> v);

// validates cli arguments
// returns true if arguments are valid
extern bool validate_args(int argc, char* argv[]);
