#ifndef FIGURES_H_
#define FIGURES_H_

class figure {
public:
    figure() = default;
    virtual void draw() const = 0;
    virtual void cdraw() const = 0;
    virtual int area() const = 0;
    virtual ~figure() = default;
};

class rect : public figure {
public:
    rect(int h, int w) : figure(), _h(h), _w(w) {}
    void draw() const override;
    void cdraw() const override;
    int area() const override;

private:
    int _h;
    int _w;
};

class square : public rect {
public:
    square(int a) : rect(a, a) {}
};

#endif
