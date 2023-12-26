#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
#include <iomanip>

template <class T>
struct Point
{
    T x;
    T y;
};

template <class T>
class Figure
{
public:
    using PointType = Point<T>;

    virtual ~Figure() noexcept = default;
    virtual double Area() const noexcept = 0;
    virtual PointType Center() const noexcept = 0;

    friend std::ostream &operator<<(std::ostream &os, const Figure &figure)
    {
        return os << "Vertices: ";
    }

    friend std::istream &operator>>(std::istream &is, Figure &figure)
    {
        return is;
    }

    operator double() const noexcept
    {
        return Area();
    }
};

template <class T>
class Rectangle : public Figure<T>
{
private:
    using PointType = typename Figure<T>::PointType;
    PointType _first;
    PointType _second;
    PointType _third;
    PointType _fourth;

public:
    Rectangle(PointType const &first, PointType const &second, PointType const &third, PointType const &fourth)
        : _first(first), _second(second), _third(third), _fourth(fourth)
    {
        if (!is_Valid_Rectangle(_first, _second, _third, _fourth))
        {
            throw std::logic_error("Error: Invalid rectangle coordinates.");
        }
    }

    double Area() const noexcept override
    {
        double side1 = std::sqrt(std::abs(_first.x - _second.x) * std::abs(_first.x - _second.x) + std::abs(_first.y - _second.y) * std::abs(_first.y - _second.y));
        double side2 = std::sqrt(std::abs(_second.x - _third.x) * std::abs(_second.x - _third.x) + std::abs(_second.y - _third.y) * std::abs(_second.y - _third.y));
        return side1 * side2;
    }

    PointType Center() const noexcept override
    {
        PointType center;
        center.x = (_first.x + _second.x + _third.x + _fourth.x) / 4;
        center.y = (_first.y + _second.y + _third.y + _fourth.y) / 4;
        return center;
    }

    static bool is_Valid_Rectangle(const PointType &A, const PointType &B, const PointType &C, const PointType &D)
    {
        double diagonal1 = std::sqrt((A.x - C.x) * (A.x - C.x) + (A.y - C.y) * (A.y - C.y));
        double diagonal2 = std::sqrt((B.x - D.x) * (B.x - D.x) + (B.y - D.y) * (B.y - D.y));

        double slope1 = std::sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
        double slope2 = std::sqrt((C.x - D.x) * (C.x - D.x) + (C.y - D.y) * (C.y - D.y));

        return diagonal1 == diagonal2 && slope1 == slope2;
    }

    friend std::ostream &operator<<(std::ostream &os, const Rectangle &rectangle)
    {
        os << "Rectangle Vertices: (" << rectangle._first.x << ", " << rectangle._first.y << "), "
           << "(" << rectangle._second.x << ", " << rectangle._second.y << "), "
           << "(" << rectangle._third.x << ", " << rectangle._third.y << "), "
           << "(" << rectangle._fourth.x << ", " << rectangle._fourth.y << ")";
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Rectangle &rectangle)
    {
        is >> rectangle._first.x >> rectangle._first.y >> rectangle._second.x >> rectangle._second.y >> rectangle._third.x >> rectangle._third.y >> rectangle._fourth.x >> rectangle._fourth.y;
        return is;
    }
};

template <class T>
class Trapezoid : public Figure<T>
{
private:
    using PointType = typename Figure<T>::PointType;
    PointType _first;
    PointType _second;
    PointType _third;
    PointType _fourth;

public:
    Trapezoid(PointType const &first, PointType const &second, PointType const &third, PointType const &fourth)
        : _first(first), _second(second), _third(third), _fourth(fourth)
    {
        if (!is_Valid_Trapezoid(_first, _second, _third, _fourth))
        {
            throw std::logic_error("Error: Invalid trapezoid coordinates.");
        }
    }

    double Area() const noexcept override
    {
        double base1 = std::sqrt(std::abs(_first.x - _second.x) * std::abs(_first.x - _second.x) + std::abs(_first.y - _second.y) * std::abs(_first.y - _second.y));
        double base2 = std::sqrt(std::abs(_second.x - _third.x) * std::abs(_second.x - _third.x) + std::abs(_second.y - _third.y) * std::abs(_second.y - _third.y));

        double height = std::abs(_first.y - _third.y);

        double area = ((base1 + base2) / 2) * height;

        return area;
    }

    PointType Center() const noexcept override
    {
        PointType center;
        center.x = (_first.x + _second.x + _third.x + _fourth.x) / 4;
        center.y = (_first.y + _second.y + _third.y + _fourth.y) / 4;
        return center;
    }

    static bool is_Valid_Trapezoid(const PointType &A, const PointType &B, const PointType &C, const PointType &D)
    {
        double slopeAB = std::abs(B.y - A.y) / std::abs(B.x - A.x);
        double slopeCD = std::abs(D.y - C.y) / std::abs(D.x - C.x);

        return slopeAB == slopeCD;
    }

    friend std::ostream &operator<<(std::ostream &os, const Trapezoid &trapezoid)
    {
        os << "Trapezoid Vertices: (" << trapezoid._first.x << ", " << trapezoid._first.y << "), "
           << "(" << trapezoid._second.x << ", " << trapezoid._second.y << "), "
           << "(" << trapezoid._third.x << ", " << trapezoid._third.y << "), "
           << "(" << trapezoid._fourth.x << ", " << trapezoid._fourth.y << ")";
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Trapezoid &trapezoid)
    {
        is >> trapezoid._first.x >> trapezoid._first.y >> trapezoid._second.x >> trapezoid._second.y >> trapezoid._third.x >> trapezoid._third.y >> trapezoid._fourth.x >> trapezoid._fourth.y;
        return is;
    }
};

template <class T>
class Rhombus : public Figure<T>
{
private:
    using PointType = typename Figure<T>::PointType;
    PointType _first;
    PointType _second;
    PointType _third;
    PointType _fourth;

public:
    Rhombus(PointType const &first, PointType const &second, PointType const &third, PointType const &fourth)
        : _first(first), _second(second), _third(third), _fourth(fourth)
    {
        if (!is_Valid_Rhombus(_first, _second, _third, _fourth))
        {
            throw std::logic_error("Error: Invalid rhombus coordinates.");
        }
    }

    double Area() const noexcept override
    {
        double base1 = std::sqrt(std::abs(_first.x - _third.x) * std::abs(_first.x - _third.x) + std::abs(_first.y - _third.y) * std::abs(_first.y - _third.y));
        double base2 = std::sqrt(std::abs(_second.x - _fourth.x) * std::abs(_second.x - _fourth.x) + std::abs(_second.y - _fourth.y) * std::abs(_second.y - _fourth.y));
        return base1 * base2 * 0.5;
    }

    PointType Center() const noexcept override
    {
        PointType center;
        center.x = (_first.x + _second.x + _third.x + _fourth.x) / 4;
        center.y = (_first.y + _second.y + _third.y + _fourth.y) / 4;
        return center;
    }

    static bool is_Valid_Rhombus(const PointType &A, const PointType &B, const PointType &C, const PointType &D)
    {
        double sideAB = std::sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
        double sideBC = std::sqrt((C.x - B.x) * (C.x - B.x) + (C.y - B.y) * (C.y - B.y));
        double sideCD = std::sqrt((D.x - C.x) * (D.x - C.x) + (D.y - C.y) * (D.y - C.y));
        double sideDA = std::sqrt((A.x - D.x) * (A.x - D.x) + (A.y - D.y) * (A.y - D.y));

        double diagonalAC = std::sqrt((C.x - A.x) * (C.x - A.x) + (C.y - A.y) * (C.y - A.y));
        double diagonalBD = std::sqrt((D.x - B.x) * (D.x - B.x) + (D.y - B.y) * (D.y - B.y));

        return sideAB == sideBC && sideBC == sideCD && sideCD == sideDA && diagonalAC == diagonalBD;
    }

    friend std::ostream &operator<<(std::ostream &os, const Rhombus &rhombus)
    {
        os << "Rhombus Vertices: (" << rhombus._first.x << ", " << rhombus._first.y << "), "
           << "(" << rhombus._second.x << ", " << rhombus._second.y << "), "
           << "(" << rhombus._third.x << ", " << rhombus._third.y << "), "
           << "(" << rhombus._fourth.x << ", " << rhombus._fourth.y << ")";
        return os;
    }
};

template <class T>
class Array
{
private:
    std::vector<std::shared_ptr<Figure<T>>> figures;

public:
    void AddFigure(std::shared_ptr<Figure<T>> figure)
    {
        figures.push_back(figure);
    }

    void PrintAllFigures() const
    {
        for (const auto &figure : figures)
        {
            std::cout << *figure << std::endl;
            std::cout << "Центр масс: (" << figure->Center().x << ", " << figure->Center().y << ")" << std::endl;
            std::cout << "Площадь: " << std::fixed << std::setprecision(4) << figure->Area() << std::endl;
            std::cout << "-------------------------" << std::endl;
        }
    }

    double TotalArea() const
    {
        double totalArea = 0;
        for (const auto &figure : figures)
        {
            totalArea += figure->Area();
        }
        return totalArea;
    }

    void RemoveFigure(int index)
    {
        if (index >= 0 && index < figures.size())
        {
            figures.erase(figures.begin() + index);
        }
        else
        {
            std::cout << "Неправильный индекс фигуры." << std::endl;
        }
    }
};

int main()
{
    Array<double> figuresArray;
    int choice;

    while (true)
    {
        std::cout << "Выберите:" << std::endl;
        std::cout << "1 - Добавить прямоугольник" << std::endl;
        std::cout << "2 - Добавить Трапецию" << std::endl;
        std::cout << "3 - Добавить Ромб" << std::endl;
        std::cout << "4 - Вывести все фигуры" << std::endl;
        std::cout << "5 - Вывести площадь всех фигур" << std::endl;
        std::cout << "6 - Убрать по индексу фигуру" << std::endl;
        std::cout << "0 - Выйти" << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Rectangle<double>::PointType first, second, third, fourth;
            std::cout << "Введите координаты вершин прямоугольника (x1 y1 x2 y2 x3 y3 x4 y4): ";
            std::cin >> first.x >> first.y >> second.x >> second.y >> third.x >> third.y >> fourth.x >> fourth.y;

            try
            {
                auto rectangle = std::make_shared<Rectangle<double>>(first, second, third, fourth);
                figuresArray.AddFigure(rectangle);

                std::cout << "Создан прямоугольник:" << std::endl;
                std::cout << *rectangle << std::endl;
                std::cout << "Центр масс: (" << rectangle->Center().x << ", " << rectangle->Center().y << ")" << std::endl;
                std::cout << "Площадь: " << std::fixed << std::setprecision(4) << rectangle->Area() << std::endl;
            }
            catch (const std::logic_error &e)
            {
                std::cout << e.what() << std::endl;
            }

            break;
        }
        case 2:
        {
            Trapezoid<double>::PointType first, second, third, fourth;
            std::cout << "Введите координаты вершин трапеции (x1 y1 x2 y2 x3 y3 x4 y4): ";
            std::cin >> first.x >> first.y >> second.x >> second.y >> third.x >> third.y >> fourth.x >> fourth.y;

            try
            {
                auto trapezoid = std::make_shared<Trapezoid<double>>(first, second, third, fourth);
                figuresArray.AddFigure(trapezoid);

                std::cout << "Создан трапеция:" << std::endl;
                std::cout << *trapezoid << std::endl;
                std::cout << "Центр масс: (" << trapezoid->Center().x << ", " << trapezoid->Center().y << ")" << std::endl;
                std::cout << "Площадь: " << std::fixed << std::setprecision(4) << trapezoid->Area() << std::endl;
            }
            catch (const std::logic_error &e)
            {
                std::cout << e.what() << std::endl;
            }

            break;
        }
        case 3:
        {
            Rhombus<double>::PointType first, second, third, fourth;
            std::cout << "Введите координаты вершин ромба (x1 y1 x2 y2 x3 y3 x4 y4): ";
            std::cin >> first.x >> first.y >> second.x >> second.y >> third.x >> third.y >> fourth.x >> fourth.y;

            try
            {
                auto rhombus = std::make_shared<Rhombus<double>>(first, second, third, fourth);
                figuresArray.AddFigure(rhombus);

                std::cout << "Создан ромб:" << std::endl;
                std::cout << *rhombus << std::endl;
                std::cout << "Центр масс: (" << rhombus->Center().x << ", " << rhombus->Center().y << ")" << std::endl;
                std::cout << "Площадь: " << std::fixed << std::setprecision(4) << rhombus->Area() << std::endl;
            }
            catch (const std::logic_error &e)
            {
                std::cout << e.what() << std::endl;
            }

            break;
        }
        case 4:
            std::cout << "Список фигур:" << std::endl;
            figuresArray.PrintAllFigures();
            break;
        case 5:
            std::cout << "Общая площадь всех фигур: " << std::fixed << std::setprecision(4) << figuresArray.TotalArea() << std::endl;
            break;
        case 6:
        {
            int index;
            std::cout << "Enter the index of the figure to remove: ";
            std::cin >> index;
            figuresArray.RemoveFigure(index);
            break;
        }
        case 0:
            return 0;
        default:
            std::cout << "Неверный ввод. Попробуйте снова" << std::endl;
            break;
        }
    }

    return 0;
}

