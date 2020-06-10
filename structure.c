/*### Handles structuring of Data ###*/

typedef struct data {
    char * name;
    
    void * head;
} data;

typedef struct node {
    // independent variable
    void * indep;
    
    // data (dependent)
    void * data;
} node;

int read_from_CSV(int has_header, char * filename) {
    int f = open(filename, "r");
   
    char * temp = malloc(128);
    while(1) {
        char c = read(temp, 1;)
        if (
    }
}
