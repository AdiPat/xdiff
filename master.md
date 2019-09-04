# xDiff
A command line utility that gives the tells the similarity between documents and the differences between them.

**TOOL**: http://cs.uef.fi/~zhao/Link/Similarity_strings.html
Use this tool to verify results

## FEATURES
1. Implemented Cosine Similarity Algorithm to compute similarity between the documents. **DONE**
2. Use C++ big integer library and data science libraries for fixing integer overflow problem for large files. (TODO)
3. Used GNU make for automating build process via Makefiles. **DONE**
4. Designed test cases to test performance and correctness of the program. **DONE**

## ADVANCED FEATURES
* Eliminate stop-words.
* Implement Stemming
* Print actual differences between files
* Add support for other document distance algorithms
* Add cli support to choose distance algorithm
* Add support for more document formats
* Dynamically choose best distance algorithm based on input files

## BUGS
- Segmentation fault for some tests. (t1.txt and t0-A.txt)
- Fix incorrect calculation on percentage similarity, distance seems to be calculated properly

## LEARNINGS
- Automated build process using Makefiles.
    - Fix issue where variables in header are causing duplicate error.
    - Remove files only if they exist
    - Clear all object files after compilation
- Created test cases to validate correctness of the program
    - 2 files exactly similar. (0)
    - 2 files exactly dissimilar. (180)
    - 2 files with some similarity. (use online tool)
- Used STL vector, pair, map data structures.
- Used C++ fstream class from the C++ Standard Library for File Handling.
    - utils.c - read_file(); Read a file using ifstream and store all the lines in a vector.
    - Used the new operator to dynamically allocate memory for the vector.
    - utils.c: Designed custom functions for text manipulation like splitting lines and words from raw text.
- Implemented cosine similarity algorithm for calculating similarity percentage.
    - diff.c Wrote code to normalize raw text and transform it into a frequency distribution for calculating angle between document vectors.
    - Used STL map, vector, pair, iterators for data manipulation.
    - Designed unit tests for all subroutines to test algorithm performance and correctness.

## Things to do
- Take input files as commandline arguments. **DONE**
- Separate test code. **DONE**
- Add test verification. **DONE**
- Design more test cases. **DONE**
- Pay attention to memory management and fix memory leaks. **DONE**
- Perform tokenization, stemming, lemmatization to provide more intuitive results.
- Display actual differences between the documents like diff utility.

<hr>

## TIMELINE - 5th April 2019


### GOALS

1. Prioritise how much time to spend on one function
2. Be more mindful of errors, warning messages and syntax errors.
3. Decompose the problem (subroutines, data structures, algorithm, function calls) and then start coding.

### LIBRARIES

- Text Manipulation
- Statistics
- NLP library for normalisation and stemming
- Big Integer

### WORK

**utils.c**
- **split_line()**: Split sentence into words
- **freqDist()**: Generate frequency distribution
- Fix generic display_vector() function

**diff.c**
- **normalize_words()**: Normalise: Convert to lowercase and eliminate punctuation
- **transform_dimensions()**: Transform vectors suitably to match dimension.
- **magnitude()**: Compute magnitude of vector
- **dot_product()**: Compute dot product
- **angle()**: Calculate angle between vectors
- **percentage_similarity()**: Display angle and percentage similarity

**test.c**
- **run_tests()**: Test suits to verify everything is working correctly
