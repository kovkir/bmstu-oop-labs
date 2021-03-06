#ifndef DOT_H
#define DOT_H

class Dot
{
public:
    Dot() = default;
    Dot(const double x, const double y, const double z);
    Dot(const Dot &dot) = default;
    Dot(const Dot &&dot) noexcept;
    ~Dot() = default;

    void move  (const double dx, const double dy, const double dz);
    void scale (const double kx, const double ky, const double kz);
    void rotate(const double ox, const double oy, const double oz);

    double get_x() const;
    double get_y() const;
    double get_z() const;

    void set_x(double const &x);
    void set_y(double const &y);
    void set_z(double const &z);

    bool operator == (const Dot &dot) const noexcept;
    bool operator != (const Dot &dot) const noexcept;
    bool is_equal    (const Dot &dot) const noexcept;
    bool is_not_equal(const Dot &dot) const noexcept;

    Dot &operator = (const Dot &dot) = default;
    Dot &operator = (Dot &&dot) noexcept;
    Dot  operator + (const Dot &dot);
    Dot  operator - (const Dot &dot);

    Dot with_center(const Dot &center);

private:
    void rotate_x(const double &ox);
    void rotate_y(const double &oy);
    void rotate_z(const double &oz);

    double _x;
    double _y;
    double _z;
};

#endif
