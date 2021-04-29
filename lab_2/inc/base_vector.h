#ifndef BASE_VECTOR_H
#define BASE_VECTOR_H

class base_Vector
{
public:
    base_Vector();
    virtual ~base_Vector() = default;
    
    bool is_empty() const noexcept;
    int  get_size() const noexcept;
    
protected:
    int size = 0;
};

#endif
