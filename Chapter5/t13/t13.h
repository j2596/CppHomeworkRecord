#ifndef t13
#define t13

class X {
private:
    int i;

public:
    X()
    {
        i = 0;
    }

    void show()
	{
		std::cout << "i = " << i << std::endl;
	}

    friend void h(X* x); 
    friend class Z;
    friend class Y;
};

class Y {
public:
    void g(X* x)
    {
        x->i += 1;
    }
};

class Z {
public:
    void f(X* x)
    {
        x->i += 5;
    }
};

void h(X* x)
{
    	x->i += 10;
}

#endif
