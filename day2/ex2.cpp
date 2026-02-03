#include <iostream>
#include <memory>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

using namespace std;

class File
{
public:
    int fd;

    File(const char *path)
    {
        fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0664);
        if (fd < 0) {
            perror("open");
        }
    }

    void write_data(const char *p)
    {
        write(fd, p, strlen(p));
    }
};

struct File_Closer
{
    void operator()(File *f)
    {
        if (f) {
            cout << "File is closed" << endl;
            close(f.fd);
            delete f;
        }
    }
};

int main()
{
    unique_ptr<File, File_Closer> p(new File("abc.txt"));
    p->write_data("Mirafra Technologies");

}

