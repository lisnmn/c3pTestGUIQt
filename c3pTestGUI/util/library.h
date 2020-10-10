#ifndef LIBRARY_H
#define LIBRARY_H


class Library {
public:
    Library();
    ~Library();
    bool open(const char* path);
    bool symbol(const char* symbol, void** addr);
    void close();
    
private:
    void* mHandler;
};

#endif // LIBRARY_H
