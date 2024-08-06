int titleToNumber(char * columnTitle){
    int cols = 0;
    while (*columnTitle!='\0') {
        cols*=26;
        cols+=(*columnTitle-64);
        columnTitle++;
    }
    return cols;
}