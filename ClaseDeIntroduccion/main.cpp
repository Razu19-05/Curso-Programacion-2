#include "Funciones/Funcions.hpp"

int main() {
    char comment1[MAX_COMMENT_LENGTH] = "I'm having a lot of fun here";
    char comment2[MAX_COMMENT_LENGTH] = "I don't like this stream";
    print_line(REPORT_WIDTH,'=');
    cout << "Tokenizacion Process"<<endl;
    print_line(REPORT_WIDTH,'-');
    tokenize(comment1,1);
    tokenize(comment2,2,true);
    cout<<"Tokenizacion comments complete!"<<endl;
    return 0;
}

