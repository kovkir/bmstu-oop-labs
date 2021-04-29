#ifndef BASE_ITER_H
#define BASE_ITER_H

class base_iter
{
public:
    base_iter();
    explicit base_iter(const base_iter&);
    virtual ~base_iter() = default;
    
protected:
    int index = 0;
    int size  = 0;
};

#endif 
