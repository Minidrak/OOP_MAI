#include <iostream>
#include <vector>
#include <cmath>
#include <exception>
#include <gtest/gtest.h>

class Figure
{
public:
    struct Point2D
    {
        double x;
        double y;
    };

    virtual ~Figure() noexcept = default;
    virtual double Area() const noexcept = 0;
    virtual Point2D Center() const noexcept = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& figure)
    {
        return os << "Vertices: ";
    }

    friend std::istream& operator>>(std::istream& is, Figure& figure)
    {
        return is;
    }

    operator double() const noexcept
    {
        return Area();
    }
};

class Rectangle : public Figure
{
private:
    Point2D _first;
    Point2D _second;
    Point2D _third;
    Point2D _fourth;

public:
    Rectangle(Point2D const& first, Point2D const& second, Point2D const& third, Point2D const& fourth)
        : _first(first), _second(second), _third(third), _fourth(fourth)
    {
        if (!is_Valid_Rectangle(_first, _second, _third, _fourth)) {
            throw std::logic_error("Error: Invalid rectangle coordinates.");
            std::terminate(); 
        }
    }

    double Area() const noexcept override
    {

        double side1 = std::sqrt(abs(_first.x - _second.x) * abs(_first.x - _second.x) + abs(_first.y - _second.y) * abs(_first.y - _second.y));
        double side2 = std::sqrt(abs(_second.x - _third.x) * abs(_second.x - _third.x) + abs(_second.y - _third.y) * abs(_second.y - _third.y));
        return side1 * side2;
    }

    Point2D Center() const noexcept override
    {

        Point2D center;
        center.x = (_first.x + _second.x + _third.x + _fourth.x) / 4;
        center.y = (_first.y + _second.y + _third.y + _fourth.y) / 4;
        return center;
    }
    

    static bool is_Valid_Rectangle(const Figure::Point2D& A, const Figure::Point2D& B,          //Check for figure
                      const Figure::Point2D& C, const Figure::Point2D& D)
    {

        double diagonal1 = std::sqrt((A.x - C.x) * (A.x - C.x) + (A.y - C.y) * (A.y - C.y));
        double diagonal2 = std::sqrt((B.x - D.x) * (B.x - D.x) + (B.y - D.y) * (B.y - D.y));


        double slope1 = std::sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
        double slope2 = std::sqrt((C.x - D.x) * (C.x - D.x) + (C.y - D.y) * (C.y - D.y));

        return diagonal1 == diagonal2 && slope1 == slope2;
}

    
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle)
    {
        os << "Rectangle Vertices: (" << rectangle._first.x << ", " << rectangle._first.y << "), "
           << "(" << rectangle._second.x << ", " << rectangle._second.y << "), "
           << "(" << rectangle._third.x << ", " << rectangle._third.y << "), "
           << "(" << rectangle._fourth.x << ", " << rectangle._fourth.y << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Rectangle& rectangle)
    {
        is >> rectangle._first.x >> rectangle._first.y
           >> rectangle._second.x >> rectangle._second.y
           >> rectangle._third.x >> rectangle._third.y
           >> rectangle._fourth.x >> rectangle._fourth.y;
        return is;
    }
};

class Trapezoid : public Figure
{
private:
    Point2D _first;
    Point2D _second;
    Point2D _third;
    Point2D _fourth;

public:
    Trapezoid(Point2D const &first, Point2D const &second, Point2D const &third, Point2D const &fourth)
        : _first(first), _second(second), _third(third), _fourth(fourth)
    {
        if (!is_Valid_Trapezoid(_first, _second, _third, _fourth)) {
            throw std::logic_error("Error: Invalid trapezoid coordinates.");
            std::terminate(); 
        }
    }
    
    double Area() const noexcept override
    {

        double base1 = std::sqrt(abs(_first.x - _second.x) * abs(_first.x - _second.x) + abs(_first.y - _second.y) * abs(_first.y - _second.y));
        double base2 = std::sqrt(abs(_second.x - _third.x) * abs(_second.x - _third.x) + abs(_second.y - _third.y) * abs(_second.y - _third.y));

        double height = std::abs(_first.y - _third.y);

        double area = ( (base1 + base2) /2 ) * height;

        return area;
    }

    Point2D Center() const noexcept override
    {
        Point2D center;
        center.x = (_first.x + _second.x + _third.x + _fourth.x) / 4;
        center.y = (_first.y + _second.y + _third.y + _fourth.y) / 4;
        return center;
    }

    static bool is_Valid_Trapezoid(const Figure::Point2D& A, const Figure::Point2D& B,  //check for figure
                                const Figure::Point2D& C, const Figure::Point2D& D)
    {

        double slopeAB = abs(B.y - A.y) / abs(B.x - A.x);
        double slopeCD = abs(D.y - C.y) / abs(D.x - C.x);

        return slopeAB == slopeCD;
    }

    friend std::ostream& operator<<(std::ostream& os, const Trapezoid& trapezoid)
    {
        os << "Trapezoid Vertices: (" << trapezoid._first.x << ", " << trapezoid._first.y << "), "
           << "(" << trapezoid._second.x << ", " << trapezoid._second.y << "), "
           << "(" << trapezoid._third.x << ", " << trapezoid._third.y << "), "
           << "(" << trapezoid._fourth.x << ", " << trapezoid._fourth.y << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Trapezoid& trapezoid)
    {
        is >> trapezoid._first.x >> trapezoid._first.y
           >> trapezoid._second.x >> trapezoid._second.y
           >> trapezoid._third.x >> trapezoid._third.y
           >> trapezoid._fourth.x >> trapezoid._fourth.y;
        return is;
    }
};

class Rhombus : public Figure
{
private:
    Point2D _first;
    Point2D _second;
    Point2D _third;
    Point2D _fourth;

public:
    Rhombus(Point2D const &first, Point2D const &second, Point2D const &third, Point2D const &fourth)
        : _first(first), _second(second), _third(third), _fourth(fourth)
    {
        if (!is_Valid_Rhombus(_first, _second, _third, _fourth)) {
            throw std::logic_error("Error: Invalid rhombus coordinates.");
            std::terminate(); 
        }
    }

    double Area() const noexcept override
    {

        double base1 = std::sqrt(abs(_first.x - _third.x) * abs(_first.x - _third.x) + abs(_first.y - _third.y) * abs(_first.y - _third.y));
        double base2 = std::sqrt(abs(_second.x - _fourth.x) * abs(_second.x - _fourth.x) + abs(_second.y - _fourth.y) * abs(_second.y - _fourth.y));
        return base1 * base2 * 0.5;
    }

    Point2D Center() const noexcept override
    {
        Point2D center;
        center.x = (_first.x + _second.x + _third.x + _fourth.x) / 4;
        center.y = (_first.y + _second.y + _third.y + _fourth.y) / 4;
        return center;
    }

    static bool is_Valid_Rhombus(const Figure::Point2D& A, const Figure::Point2D& B, //check for figure
                                const Figure::Point2D& C, const Figure::Point2D& D)
    {
        double sideAB = std::sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
        double sideBC = std::sqrt((C.x - B.x) * (C.x - B.x) + (C.y - B.y) * (C.y - B.y));
        double sideCD = std::sqrt((D.x - C.x) * (D.x - C.x) + (D.y - C.y) * (D.y - C.y));
        double sideDA = std::sqrt((A.x - D.x) * (A.x - D.x) + (A.y - D.y) * (A.y - D.y));

        double diagonalAC = std::sqrt((C.x - A.x) * (C.x - A.x) + (C.y - A.y) * (C.y - A.y));
        double diagonalBD = std::sqrt((D.x - B.x) * (D.x - B.x) + (D.y - B.y) * (D.y - B.y));


        return sideAB == sideBC && sideBC == sideCD && sideCD == sideDA && diagonalAC == diagonalBD;
    }


    friend std::ostream& operator<<(std::ostream& os, const Rhombus& rhombus)
    {
        os << "Rhombus Vertices: (" << rhombus._first.x << ", " << rhombus._first.y << "), "
           << "(" << rhombus._second.x << ", " << rhombus._second.y << "), "
           << "(" << rhombus._third.x << ", " << rhombus._third.y << "), "
           << "(" << rhombus._fourth.x << ", " << rhombus._fourth.y << ")";
        return os;
    }
};

TEST(RectangleTest, AreaAndCenter)
{
    Figure::Point2D A{0, 0};
    Figure::Point2D B{2, 0};
    Figure::Point2D C{2, 3};
    Figure::Point2D D{0, 3};

    Rectangle rectangle(A, B, C, D);

    EXPECT_DOUBLE_EQ(rectangle.Area(), 6.0);
    
    Figure::Point2D center = rectangle.Center();
    EXPECT_DOUBLE_EQ(center.x, 1.0);
    EXPECT_DOUBLE_EQ(center.y, 1.5);
}

TEST(TrapezoidTest, AreaAndCenter)
{
    Figure::Point2D A{1, 1};
    Figure::Point2D B{2, 3};
    Figure::Point2D C{5, 3};
    Figure::Point2D D{6, 1};

    Trapezoid trapezoid(A, B, C, D);

    EXPECT_DOUBLE_EQ(trapezoid.Area(), 5.2360679774997898);
    
    Figure::Point2D center = trapezoid.Center();
    EXPECT_DOUBLE_EQ(center.x, 3.5);
    EXPECT_DOUBLE_EQ(center.y, 2.0);
}

TEST(RhombusTest, AreaAndCenter)
{
    Figure::Point2D A{0, 0};
    Figure::Point2D B{0, 10};
    Figure::Point2D C{10, 10};
    Figure::Point2D D{10, 0};

    Rhombus rhombus(A, B, C, D);

    EXPECT_DOUBLE_EQ(rhombus.Area(), 100.0);
    
    Figure::Point2D center = rhombus.Center();
    EXPECT_DOUBLE_EQ(center.x, 5.0);
    EXPECT_DOUBLE_EQ(center.y, 5.0);
}




int main(int argc, char ** argv)
{
    const int maxFigures = 100;
    Figure * figures[maxFigures];
    int figureCount = 0;

    int choice;
    while (true)
    {
        std::cout << "Выберите действие: " << std::endl;
        std::cout << "1 - Добавить прямоугольник" << std::endl;
        std::cout << "2 - Добавить трапецию" << std::endl;
        std::cout << "3 - Добавить ромб" << std::endl;
        std::cout << "4 - Вывести все фигуры" << std::endl;
        std::cout << "5 - Вывести общую площадь фигур" << std::endl;
        std::cout << "0 - Выход" << std::endl;
        std::cin >> choice;

        switch (choice)
        {
            case 1:
            {
                Figure::Point2D first, second, third, fourth;
                std::cout << "Введите координаты вершин прямоугольника (x1 y1 x2 y2 x3 y3 x4 y4): ";
                std::cin >> first.x >> first.y >> second.x >> second.y >> third.x >> third.y >> fourth.x >> fourth.y;

                if (!Rectangle::is_Valid_Rectangle(first, second, third, fourth)) {
                    std::cout << "Wrong figure. Пожалуйста, введите корректные координаты для прямоугольника." << std::endl;
                    break;
            }

                Rectangle* rectangle = new Rectangle(first, second, third, fourth);
                figures[figureCount++] = rectangle;


                std::cout << "Создан прямоугольник:" << std::endl;
                std::cout << *rectangle << std::endl;
                std::cout << "Центр масс: (" << rectangle->Center().x << ", " << rectangle->Center().y << ")" << std::endl;
                std::cout << "Площадь: " <<std::fixed<< std::setprecision(4)<< rectangle->Area() << std::endl;

                break;
            }
            case 2:
            {
                Figure::Point2D first, second, third, fourth;
                std::cout << "Введите координаты вершин трапеции (x1 y1 x2 y2 x3 y3 x4 y4): ";
                std::cin >> first.x >> first.y >> second.x >> second.y >> third.x >> third.y >> fourth.x >> fourth.y;

                if (!Trapezoid::is_Valid_Trapezoid(first, second, third, fourth)) {
                    std::cout << "Wrong figure. Пожалуйста, введите корректные координаты для трапеции." << std::endl;
                    break;
            }

                Trapezoid* trapezoid = new Trapezoid(first, second, third, fourth);
                figures[figureCount++] = trapezoid;


                std::cout << "Создан трапеция:" << std::endl;
                std::cout << *trapezoid << std::endl; 
                std::cout << "Центр масс: (" << trapezoid->Center().x << ", " << trapezoid->Center().y << ")" << std::endl;
                std::cout << "Площадь: " << std::fixed<<std::setprecision(4) << trapezoid->Area() << std::endl;

                break;
            }

            case 3:
            {
                Figure::Point2D first, second, third, fourth;
                std::cout << "Введите координаты вершин ромба (x1 y1 x2 y2 x3 y3 x4 y4): ";
                std::cin >> first.x >> first.y >> second.x >> second.y >> third.x >> third.y >> fourth.x >> fourth.y;

                if (!Rhombus::is_Valid_Rhombus(first, second, third, fourth)) {
                    std::cout << "Wrong figure. Пожалуйста, введите корректные координаты для ромба." << std::endl;
                    break;
            }

                Rhombus* rhombus = new Rhombus(first, second, third, fourth);
                figures[figureCount++] = rhombus;


                std::cout << "Создан ромб:" << std::endl;
                std::cout << *rhombus << std::endl; 
                std::cout << "Центр масс: (" << rhombus->Center().x << ", " << rhombus->Center().y << ")" << std::endl;
                std::cout << "Площадь: " << std::fixed << std::setprecision(4) << rhombus->Area() << std::endl;

                break;
            }

            case 4:
            {     // Список фигур
                std::cout << "Список всех фигур:" << std::endl;
                for (int i = 0; i < figureCount; ++i)
                {
                    std::cout << "Фигура " << i + 1 << ": " << *figures[i] << std::endl;
                    std::cout << "Центр масс: (" << figures[i]->Center().x << ", " << figures[i]->Center().y << ")" << std::endl;
                    std::cout << "Площадь: " << figures[i]->Area() << std::endl;
                    std::cout << "-------------------------" << std::endl;
                }
                break;
            }
            case 5:
            {   // Вывод площади фигур
                double totalArea = 0;
                for (int i = 0; i<figureCount;++i)
                {
                    totalArea += figures[i]->Area();
                }
                std::cout << "Общая площадь всех фигур: " << totalArea << std::endl;
                break;
            }

            case 9:
            {
                ::testing::InitGoogleTest(&argc, argv);
                RUN_ALL_TESTS();
                return 0;
            }

            case 0:
                // Свободу памяти
                for (int i = 0; i< figureCount;++i)
                {
                    delete figures[i];
                }
                return 0;
            default:
                std::cout << "Неверный ввод. Попробуйте снова." << std::endl;
                break;
        }
    }

    return 0;
}
