#ifndef _LIST_2048
#define _LIST_2048

class list_2048
{
    public:
    list_2048(int n);
    ~list_2048();
    void move_left();
    void move_right();
    void move_up();
    void move_down();
    void output();

    private:
    void _left(int n);
    void _right(int n);
    void _up(int n);
    void _down(int n);
    int cc;             //½×Êý
    int num[10][10];      //¾ØÕó´æ´¢
    void _random();
};

#endif