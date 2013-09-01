#ifndef IDENTIFIABLE_H
#define IDENTIFIABLE_H

class Identifiable
{
public:
     explicit Identifiable();

    static long next_id();
    long id();

private:
    static long static_id;
    const long my_id;
};

#endif // IDENTIFIABLE_H
