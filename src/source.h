#include <iostream>
#include <cstring>
#include <math.h>






class Source {

  public:
    Source();
    ~Source();

    void read_source(char * input);
    int next_char();


  private:
    char * input;       // source input
    int position;       // current position in the input array
};
